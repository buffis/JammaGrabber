module sample_checker_tb();

	reg rst;
	reg clk;
	reg vsync, hsync, pixel_clock;
	reg start_button;
	reg [7:0] r,g,b;

	wire [2:0] internal_state;
	wire [3:0] leds;

	wire [22:0] addr;
	wire rw;
	wire [31:0] data_in;
	reg busy;
	reg out_valid;
	wire in_valid;

	sample_checker DUT (
		.rst(rst),
		.clk(clk),
		.pixel_clock(pixel_clock),
		.r(r),
		.g(g),
		.b(b),
		.vsync(vsync),
		.hsync(hsync),
		.start_button(start_button),
		.internal_state(internal_state),
		.addr(addr),
		.rw(rw),
		.data_in(data_in),
		.data_out(data_out),
		.busy(busy),
		.in_valid(in_valid),
		.out_valid(out_valid),
		.leds(leds)
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
		busy = 1'b0;
		hsync = 1'b0;
		vsync = 1'b0;
		@(negedge rst);
		
		forever begin
			repeat(20) begin // draw 20 lines
				#600 // each pixel period is 20, wait 30 pixels = 600 time
				hsync = 1'b1;
				#60 // hsync for 3 pixels (20*3)
				hsync = 1'b0;
			end
			
			vsync = 1'b1;
			repeat (2) begin // vsync pulse
				#600 // each pixel period is 20, wait 30 pixels = 600 time
				hsync = 1'b1;
				#60 // hsync for 3 pixels (20*3)
				hsync = 1'b0;
			end
			vsync = 1'b0;
		end
	end
	
	initial begin
		pixel_clock = 1'b0;
		@(negedge rst);
		forever #10 pixel_clock = ~pixel_clock;
	end
	
	initial begin
		start_button = 1'b0;
		@(negedge rst);
		@(negedge vsync);
		@(negedge vsync);
		start_button = 1'b1;
		@(negedge vsync);
		@(negedge vsync);
		@(negedge vsync);
		$finish;
	end

endmodule
