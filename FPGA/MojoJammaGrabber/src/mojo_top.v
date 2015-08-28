module mojo_top(
        input clk,
        input rst_n,
        input cclk,
        output[7:0]led,
        output spi_miso,
        input spi_ss,
        input spi_mosi,
        input spi_sck,
        output [3:0] spi_channel,
        input avr_tx,
        output avr_rx,
        input avr_rx_busy,
        output sdram_clk,
        output sdram_cle,
        output sdram_dqm,
        output sdram_cs,
        output sdram_we,
        output sdram_cas,
        output sdram_ras,
        output [1:0] sdram_ba,
        output [12:0] sdram_a,
        inout [7:0] sdram_dq,
		  input pixel_clock,
		  input vsync,
		  input hsync,
		  input [7:0] red,
		  input [7:0] green,
		  input [7:0] blue,
		  input start_button
    );

wire fclk;
wire rst = ~rst_n;

assign spi_miso = 1'bz;
assign avr_rx = 1'bz;
assign spi_channel = 4'bzzzz;

wire [22:0] addr;
wire rw;
wire [31:0] data_in, data_out;
wire busy;
wire in_valid, out_valid;


/*sdram_clk_gen clkram_clk_gen (
        .clk_in(clk),
        .clk_out(fclk)
    );*/
assign fclk = clk;

sdram sdram (
	.clk(fclk),
	.rst(rst),
	.sdram_clk(sdram_clk),
	.sdram_cle(sdram_cle),
	.sdram_cs(sdram_cs),
	.sdram_cas(sdram_cas),
	.sdram_ras(sdram_ras),
	.sdram_we(sdram_we),
	.sdram_dqm(sdram_dqm),
	.sdram_ba(sdram_ba),
	.sdram_a(sdram_a),
	.sdram_dq(sdram_dq),
	.addr(addr),
	.rw(rw),
	.data_in(data_in),
	.data_out(data_out),
	.busy(busy),
	.in_valid(in_valid),
	.out_valid(out_valid)
	);

wire is_sampling;
wire sample_clk;
wire [2:0] internal_state;

assign led[0] = tx_busy;
assign led[1] = avr_rx_busy;
assign led[2] = new_rx_data;
assign led[3] = cclk;
assign led[6:4] = internal_state;
assign led[7] = start_button;


wire [7:0] last_addr;
wire [7:0] tx_data;
wire new_tx_data;
wire tx_busy;
wire [7:0] rx_data;
wire new_rx_data;
 
avr_interface avr_interface (
	.clk(fclk),
	.rst(rst),
	.cclk(cclk),
	.spi_miso(spi_miso),
	.spi_mosi(spi_mosi),
	.spi_sck(spi_sck),
	.spi_ss(spi_ss),
	.spi_channel(spi_channel),
	.tx(avr_rx), // FPGA tx goes to AVR rx
	.rx(avr_tx),
	.channel(4'd15), // invalid channel disables the ADC
	.new_sample(),
	.sample(),
	.sample_channel(),
	.tx_data(tx_data),
	.new_tx_data(new_tx_data),
	.tx_busy(tx_busy),
	.tx_block(avr_rx_busy),
	.rx_data(rx_data),
	.new_rx_data(new_rx_data)
	);

sample_checker sample_checker (
	.rst(rst),
	.clk(fclk),
	.pixel_clock(pixel_clock),
	.vsync(vsync),
	.hsync(hsync),
	.start_button(start_button),
	.r(red),
	.g(green),
	.b(blue),
	.internal_state(internal_state),
	.addr(addr),
	.rw(rw),
	.data_in(data_in),
	.data_out(data_out),
	.busy(busy),
	.out_valid(out_valid),
	.in_valid(in_valid),
	.tx_data(tx_data),
   .new_tx_data(new_tx_data),
   .tx_busy(tx_busy),
	.last_addr(last_addr)
	);
	

wire	[11:0]	address;
wire	[17:0]	instruction;
wire			bram_enable;
wire	[7:0]		port_id;
wire	[7:0]		out_port;
reg	[7:0]		in_port;
wire			write_strobe;
wire			k_write_strobe;
wire			read_strobe;
reg			interrupt = 1'b0;           
wire			interrupt_ack;
wire			kcpsm6_sleep = 1'b0;       
wire			kcpsm6_reset;         //See note above

wire			cpu_reset;
wire			rdl;
  
 kcpsm6 #(
	.interrupt_vector	(12'h3FF),
	.scratch_pad_memory_size(64),
	.hwbuild		(8'h00))
  processor (
	.address 		(address),
	.instruction 	(instruction),
	.bram_enable 	(bram_enable),
	.port_id 		(port_id),
	.write_strobe 	(write_strobe),
	.k_write_strobe 	(k_write_strobe),
	.out_port 		(out_port),
	.read_strobe 	(read_strobe),
	.in_port 		(in_port),
	.interrupt 		(interrupt),
	.interrupt_ack 	(interrupt_ack),
	.reset 		(kcpsm6_reset),
	.sleep		(kcpsm6_sleep),
	.clk 			(fclk)); 
	
  nop #(
	.C_FAMILY		   ("S6"),   	//Family 'S6' or 'V6'
	.C_RAM_SIZE_KWORDS	(2),  	//Program size '1', '2' or '4'
	.C_JTAG_LOADER_ENABLE	(1))  	//Include JTAG Loader when set to '1' 
  program_rom (    				//Name to match your PSM file
 	.rdl 			(kcpsm6_reset),
	.enable 		(bram_enable),
	.address 		(address),
	.instruction 	(instruction),
	.clk 			(fclk));




endmodule