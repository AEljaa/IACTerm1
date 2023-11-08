module sigdelay #(
    parameter A_WIDTH=9,
              D_WIDTH=8
)(
input logic clk, //clk
input logic rst, //reset
input logic en, //enable
input logic wr, //write enable
input logic rd, //read enable
input logic [A_WIDTH-1:0] offset, //offset
input  logic [D_WIDTH:0]  incr, //increment for addr counter
input  logic [D_WIDTH-1:0] mic_signal, //input data
output  logic [D_WIDTH-1:0] delayed_signal //output data
);

logic [A_WIDTH-1:0] address; //interconnect wire

counter addrCounter (
    .clk (clk),
    .rst (rst),
    .en (1),
    .count (address)
);

ram2ports sigRam (
    .clk (clk),
    .rd_en (rd),
    .wr_en (wr),
    .rd_addr (address-offset),
    .wr_addr (address),
    .din (mic_signal),
    .dout (delayed_signal)
);

endmodule
