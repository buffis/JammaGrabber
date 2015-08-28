module tvp_sampler_tb();

	reg rst;
	reg clk;
	reg [7:0] r,g,b;
	reg sample_clock;
	
	
	reg [22:0] addr;
	reg rw;
	reg [31:0] data_in;
	reg busy;
	reg out_valid;
	wire in_valid;
	wire [7:0] leds;

	tvp_sampler DUT(
		.rst(rst),
		.clk(clk),
		.r(r),
		.g(g),
		.b(b),
		.sample_clock(sample_clock),
		.addr(addr),
		.rw(rw),
		.data_in(data_in),
		.data_out(data_out),
		.busy(busy),
		.in_valid(in_valid),
		.out_valid(out_valid),
		.leds(led)
	);
	
	initial begin
		clk = 1'b0;
		rst = 1'b1;
		repeat(4) #1 clk = ~clk;
		rst = 1'b0;
		forever #1 clk = ~clk;
	end
	
	initial begin
		r = 8'b00000000;
		g = 8'b00000000;
		b = 8'b00000000;
		@(negedge rst);
		forever begin
			#10
			r = r + 1'b1;
			g = g + 2'b10;
			b = b + 2'b11;
		end
	end
	
	initial begin
		sample_clock = 1'b0;
		busy = 1'b0;
		#50
		
		// Pulse the clock
		sample_clock = ~sample_clock;
		#4
		sample_clock = ~sample_clock;
		
		#20
		
		// Pulse clock again
		sample_clock = ~sample_clock;
		#4
		sample_clock = ~sample_clock;
		
		#20
		$finish;
	end

endmodule
