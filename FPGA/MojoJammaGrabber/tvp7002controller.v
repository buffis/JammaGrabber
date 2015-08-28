`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:38:21 08/22/2015 
// Design Name: 
// Module Name:    tvp7002controller 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module tvp7002controller(
	input clk,
	input rst,
	inout sda,
	output scl
	);
	
	// i2c inputs
	wire start; // pull high to send start
	wire stop; // pull high to send stop
	wire [7:0] data_in;
	wire write;
	wire read;
	wire ack_read;
	
	// i2c outputs
	wire ack;
	wire [7:0] data_out;
	wire out_valid;
	wire busy;
	
	localparam WAITING = 0,
				  WRITING = 1,
				  READING = 2,
				  DONE    = 3;
	reg [1:0] state_d, state_q;

	always @* begin
		case (state_q) begin
			WAITING: begin
			end
			WRITING: begin
			end
			READING: begin
			end
			DONE: begin
				// nop
			end
		
		endcase
	
	end
	
	always @(posedge clk) begin
		if (rst) begin
			state_q <= WAITING;
		end else begin
			state_q <= state_d;
		end
	
	end


	i2c i2c (
		.clk(clk),
		.rst(rst),
		.sda(sda),
		.scl(scl),
		.start(start),
		.stop(stop),
		.data_in(data_in),
		.write(write),
		.ack(ack),
		.data_out(data_out),
		.out_valid(out_valid),
		.rad(read),
		.ack_read(ack_read),
		.busy(busy)
	  );

endmodule
