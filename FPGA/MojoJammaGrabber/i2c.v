/*
To use this, first pull start high then wait for busy to go low. Then you can send your data by setting data_in and pulling write high for a clock cycle. Ack is the ack bit if your write was acknowledged by the device. I believe 0 is success.

To read just pull read high for one clock cycle and set ack_read to 1 if you want to acknowledge the read (typically you do). Once the operation is complete, out_valid will go high for a clock cycle at which time you can read data_out.

Once you have finished a transaction. Pulse stop high for one clock cycle.

You must always make sure busy is low before sending a new command.
*/

module i2c #(
    CLK_DIV = 8 // divide mojo clock for i2c (MUST BE 3 OR MORE)
  )(
    input clk,
    input rst,

    // Device interface
    inout sda, // bi-directional data
    output scl, // clock

    // I2C signals
    input start, // pull high to send start
    input stop, // pull high to send stop

    // write byte
    input [7:0] data_in, //data to write
    input write, // perform write
    output ack,

    // read byte
    output [7:0] data_out, //data read
    output out_valid, // data_out is valid
    input read, // perform read
    input ack_read, // should the read be ack

    output busy // i2c module busy, can't read or write
  );

  localparam STATE_SIZE = 3;

  localparam IDLE = 0, // just chillin
             START = 1, // send start sequence
             WAIT_CMD = 2, // wait for read/write requests
             READ = 3, // read a byte
             WRITE = 4, // write a byte
             STOP = 5; // send stop sequence

  reg [STATE_SIZE-1:0] state_d, state_q;

  reg [7:0] data_d, data_q;
  reg out_valid_d, out_valid_q;
  reg [CLK_DIV-1:0] scl_d, scl_q;

  reg [3:0] bit_ctr_d, bit_ctr_q;

  reg ack_d, ack_q;
  reg ack_read_d, ack_read_q;

  reg sda_en; // drive sda signal
  reg sda_out; // value to drive sda at

  assign sda = sda_en ? sda_out : 1'bz; // tristate if not enabled
  assign scl = ~scl_q[CLK_DIV-1];

  assign busy = state_q != IDLE && state_q != WAIT_CMD; // busy when not idle or waiting for command
  assign data_out = data_q;
  assign out_valid = out_valid_q;
  assign ack = ack_q;

  always @* begin
    // default values
    out_valid_d = 1'b0;
    data_d = data_q;
    state_d = state_q;

    sda_en = 1'b0;
    sda_out = 1'bx;
    scl_d = scl_q;
    ack_d = ack_q;
    ack_read_d = ack_read_q;

    bit_ctr_d = bit_ctr_q;

    case (state_q)
      IDLE: begin
        sda_en = 1'b1; // drive sda high
        sda_out = 1'b1;
        scl_d = 1'b0;
        if (start) begin
          sda_out = 1'b0; //send start sequence
          state_d = START;
        end
      end
      START: begin
        sda_en = 1'b1; // drive sda to low
        sda_out = 1'b0;
        scl_d = scl_q + 1'b1;
        if (scl_q == {2'b11, {CLK_DIV-2{1'b0}}}) // wait for scl_q to be 3/4 full
          state_d = WAIT_CMD;
      end
      WAIT_CMD: begin
        bit_ctr_d = 4'd0;
        scl_d = {1'b1, {CLK_DIV-1{1'b0}}} + 1'b1; // set counter to just over 1/2 full
        if (write) begin // write a byte
          data_d = data_in;
          scl_d = {1'b1, 2'b11, {CLK_DIV-2{1'b0}}} + 1'd1; // set counter to just over 3/4 full
          state_d = WRITE;
        end else if (read) begin // read a byte
          ack_read_d = ack_read;
          state_d = READ;
        end else if (stop) begin // send stop sequence
          state_d = STOP;
        end
      end
      READ: begin
        if (bit_ctr_q > 4'd7) begin // last bit send ack
          sda_en = 1'b1;
          sda_out = ~ack_read_q; // ack is 0 for valid
        end

        scl_d = scl_q + 1'b1;
        if (!(|scl_q)) begin // scl_q is 0
          if (bit_ctr_q < 4'd8) // only read in first 8 bits
            data_d = {data_q[6:0],sda}; // shift in data
          bit_ctr_d = bit_ctr_q + 1'b1; // count bits read
        end else if (scl_q == {1'b1, {CLK_DIV-1{1'b0}}} && bit_ctr_q == 4'd9) begin // no more bits
          out_valid_d = 1'b1; // out valid! yay!
          state_d = WAIT_CMD; // wait for next command
        end
      end
      WRITE: begin
        if (bit_ctr_q != 4'd8) // first 8 bits we are driving sda
          sda_en = 1'b1;
        else if (!(|scl_q)) begin // last bit is ack bit
          ack_d = sda;
        end
        sda_out = data_q[7]; // write msb first
        scl_d = scl_q + 1'b1;
        if (scl_q == {2'b11, {CLK_DIV-2{1'b0}}}) begin // if scl is 3/4 full (offset to transistion only when scl is low)
          data_d = {data_q[6:0],1'bx}; // shift data
          bit_ctr_d = bit_ctr_q + 1'b1; // count bits
          if (bit_ctr_q == 4'd8) begin // no more bits
            state_d = WAIT_CMD;
          end
        end
      end
      STOP: begin
        sda_out = 1'b0; // output stop sequence
        sda_en = 1'b1;
        scl_d = scl_q + 1'b1;
        if (scl_q == {1'b0, {CLK_DIV-1{1'b1}}}) begin
          sda_out = 1'b1;
          state_d = IDLE;
          scl_d = 1'b0;
        end
      end
      default: state_d = IDLE;
    endcase
  end

  always @(posedge clk) begin
    if (rst) begin
      state_q <= IDLE;
      scl_q <= 1'b0;
    end else begin
      state_q <= state_d;
      scl_q <= scl_d;
    end

    data_q <= data_d;
    out_valid_q <= out_valid_d;
    bit_ctr_q <= bit_ctr_d;
    ack_q <= ack_d;
    ack_read_q <= ack_read_d;
  end

endmodule