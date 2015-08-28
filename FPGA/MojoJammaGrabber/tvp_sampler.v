module tvp_sampler(
	input rst,
	input clk,
	input [7:0] r,
	input [7:0] g,
	input [7:0] b,
	input sample_clock,
	output reg [22:0] addr,
	output reg rw,
	output reg [31:0] data_in,
	input [31:0] data_out,
	input busy,
	output reg in_valid,
	input out_valid,
	output [3:0] leds
	);
	
	reg [1:0] sample_clock_d, sample_clock_q;
	wire is_rising_edge_sample_clock = sample_clock_q[0] & (~sample_clock_q[1]);
	
	reg [22:0] addr_d, addr_q;
	reg [3:0] error_d, error_q;
	
	assign leds = error_q;

	always @(*) begin
		sample_clock_d[0] = sample_clock;
		sample_clock_d[1] = sample_clock_q[0];
		
		addr_d = addr_q;
		error_d = error_q;
		addr = 23'd0;
		rw = 1'b0;
		data_in = 32'h00;
		in_valid = 1'b0;
	
		if (is_rising_edge_sample_clock) begin
			// time to sample on rising edge.
			if (!busy) begin
				addr_d = addr_q + 1'b1;
				addr = addr_q;
				rw = 1'b1;
				data_in = {r, g, b, 8'b00000000};
				in_valid = 1'b1;
				if (addr_q == {23{1'b1}}) begin
					error_d = 4'b1111;
				end
			end else begin
				error_d = error_q + 1'b1;
			end
		end
	end
	
	always @(posedge clk) begin
		if (rst) begin
			sample_clock_q <= 2'b00;
			addr_q <= 8'd0;
			error_q <= 4'b0000;
		end else begin
			sample_clock_q <= sample_clock_d;
			addr_q <= addr_d;
			error_q <= error_d;
		end
	end

endmodule
