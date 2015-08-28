
module sample_tester(
	input clk,
	input rst,
	input [3:0] leds,
	input done_sampling,
	input start,
	input busy,
	output reg [22:0] addr,
	output reg in_valid,
	input out_valid
   );
	
	localparam WAITING = 0,
		DOING = 1,
		DONE = 2;
		
	reg [2:0] state_d, state_q;
	
	reg [22:0] addr_d, addr_q;
	
	always @(*) begin
		state_d = state_q;
		case (state_q)
			WAITING: begin
				if (start) begin
					state_d = DOING;
				end
			end
			DOING : begin
				if (!busy) begin
					addr_d = addr_q + 1'b1;
					addr = addr_q;
					in_valid = 1'b1;
					if (addr_q == {23{1'b1}}) begin
						state_d = DONE;
					end
				end

				if (out_valid) begin
					// handle data_out
				end
			end
			DONE : begin
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

endmodule
