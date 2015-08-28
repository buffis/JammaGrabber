//`default_nettype none

module sample_checker(
   input rst,
	input clk,
	input pixel_clock,
	input vsync,
	input hsync,
	input start_button,
	input [7:0] r,
	input [7:0] g,
	input [7:0] b,
	output [2:0] internal_state,
	output reg [22:0] addr,
	output reg rw,
	output reg [31:0] data_in,
	input [31:0] data_out,
	input busy,
	input out_valid,
	output reg in_valid,
	output reg [7:0] tx_data,
	output reg new_tx_data,
	input tx_busy,
	output [7:0] last_addr
	);

	// Internal states.
	reg [2:0] state_d, state_q;
	assign internal_state = state_q;
	localparam CAN_SAMPLE = 0,
		WAIT_VSYNC_START = 1,
		WAIT_VSYNC_END = 2,
		IS_SAMPLE = 3,
		DONE_SAMPLE = 4,
		DONE_ALL = 5;
		
	reg [2:0] read_state_d, read_state_q;
	localparam WAITING_RAM = 0,
		WAITING_TX_1 = 1,
		WAITING_TX_2 = 2,
		WAITING_TX_3 = 3,
		WAITING_TX_4 = 4;
	
	// TVP7002 inputs.
	reg start_button_d, start_button_q;
	reg vsync_d, vsync_q;
	reg hsync_d, hsync_q;
	reg [1:0] pixel_clock_d, pixel_clock_q;
	reg [7:0] r_d, r_q;
	reg [7:0] g_d, g_q;
	reg [7:0] b_d, b_q;
	wire is_falling_edge_pixel_clock = (~pixel_clock_q[0]) & (pixel_clock_q[1]);
	wire sample_clk = (state_q == IS_SAMPLE) & is_falling_edge_pixel_clock;
	
	// RAM.
	reg [22:0] addr_d, addr_q;
	reg [22:0] read_addr_d, read_addr_q;
	reg [31:0] data_out_copy_d, data_out_copy_q;

	// Error handling.
	reg [3:0] error_d, error_q;
	assign last_addr = addr_q[7:0];

	always @(*) begin
		state_d = state_q;
		read_state_d = read_state_q;
		
		new_tx_data = 1'b0;
		tx_data = 8'b00000000;
		
		start_button_d = start_button;
		vsync_d = vsync;
		hsync_d = hsync;
		pixel_clock_d[1] = pixel_clock_q[0];  // last pixel clock
		pixel_clock_d[0] = pixel_clock;       // current pixel clock
		
		r_d = r;
		g_d = g;
		b_d = b;

		error_d = error_q;
		addr_d = addr_q;
		read_addr_d = read_addr_q;
		addr = 23'd0;
		rw = 1'b0;
		data_in = 32'h00;
		in_valid = 1'b0;
		data_out_copy_d = data_out_copy_q;
		
		case (state_q)
			CAN_SAMPLE: begin
				if (start_button_q) begin
					state_d = WAIT_VSYNC_START;
					if (!tx_busy) begin
						new_tx_data = 1'b1;
						tx_data = "!";
					end
				end
			end
			WAIT_VSYNC_START : begin
				if (~vsync_q) begin
					state_d = WAIT_VSYNC_END;
				end
			end
			WAIT_VSYNC_END : begin
				if (vsync_q) begin
					state_d = IS_SAMPLE;
				end
			end
			IS_SAMPLE: begin
				if (~vsync_q) begin
					state_d = DONE_SAMPLE;
				end
			end
			DONE_SAMPLE: begin
				if (read_addr_q > addr_q) begin
					state_d = DONE_ALL;
				end else begin
					case (read_state_q)
						WAITING_RAM: begin
							if (!busy) begin
								read_addr_d = read_addr_q + 1'b1;
								addr = read_addr_q;
								in_valid = 1'b1;
							end
							if (out_valid) begin
								data_out_copy_d = data_out;
								read_state_d = WAITING_TX_1;
							end
						end
						WAITING_TX_1: begin
							if (!tx_busy) begin
								new_tx_data = 1'b1;
								tx_data = data_out[7:0];
								read_state_d = WAITING_TX_2;
							end
						end
						WAITING_TX_2: begin
							if (!tx_busy) begin
								new_tx_data = 1'b1;
								tx_data = data_out[15:8];
								read_state_d = WAITING_TX_3;
							end
						end
						WAITING_TX_3: begin
							if (!tx_busy) begin
								new_tx_data = 1'b1;
								tx_data = data_out[23:16];
								read_state_d = WAITING_TX_4;
							end
						end
						WAITING_TX_4: begin
							if (!tx_busy) begin
								new_tx_data = 1'b1;
								tx_data = data_out[31:24];
								read_state_d = WAITING_RAM;
							end
						end
					endcase
				end
			end
			DONE_ALL : begin
				// nop
			end
		endcase
		
		if (sample_clk) begin
			if (!busy) begin
				addr_d = addr_q + 1'b1;
				addr = addr_q;
				rw = 1'b1;
				data_in = {r_q, g_q, b_q, 7'b00000000, hsync_q};
				in_valid = 1'b1;
				if (addr_q == {23{1'b1}}) begin
					error_d = 4'b1011;
				end
			end else begin
				error_d = error_q + 1'b1;
			end
		end
	end
		
	always @(posedge clk) begin
		if (rst) begin
			state_q <= CAN_SAMPLE;
			read_state_q <= WAITING_RAM;
			start_button_q <= 1'b0;
			vsync_q <= 1'b1;
			hsync_q <= 1'b0;
			pixel_clock_q <= 2'b00;
			error_q <= 4'b0000;
			addr_q <= 23'b0;
			read_addr_q <= 23'b0;
			r_q <= 8'b00000000;
			g_q <= 8'b00000000;
			b_q <= 8'b00000000;
			data_out_copy_q <= 32'b0;
		end else begin
			state_q <= state_d;
			read_state_q <= read_state_d;
			start_button_q <= start_button_d;
			vsync_q <= vsync_d;
			hsync_q <= hsync_d;
			pixel_clock_q <= pixel_clock_d;
			error_q <= error_d;
			addr_q <= addr_d;
			read_addr_q <= read_addr_d;
			r_q <= r_d;
			g_q <= g_d;
			b_q <= b_d;
			data_out_copy_q <= data_out_copy_d;
		end
	end

endmodule
