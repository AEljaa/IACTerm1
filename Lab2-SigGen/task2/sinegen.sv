module sinegen #(
    parameter A_WIDTH=8,
              D_WIDTH=8
)(
input logic clk, //clk
input logic rst, //reset
input logic en, //enable
input logic offset, //offset
input  logic [D_WIDTH-1:0]  incr, //increment for addr counter
output  logic [D_WIDTH-1:0]  dout1, //output data
output  logic [D_WIDTH-1:0]  dout2 //output data
);


logic [A_WIDTH-1:0] address1; //interconnect wire

//first wave is not offset therefore count=count+1 (address1=address1+1)
counter addrCounter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .count (address1)
);

rom2ports  sineRom (
    .clk (clk),
    .addr1 (address1),
    .addr2 (address1+offset),
    .dout1 (dout1),
    .dout2 (dout2)
);

endmodule
