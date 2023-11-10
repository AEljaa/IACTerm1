module top #(
    parameter D_WIDTH=8,
              C_WIDTH=16
)(
input logic clk, //clk
input logic rst, //reset
input  logic [C_WIDTH-1:0] N,     	 // clock divided by N+1
output logic [D_WIDTH-1:0] data_out //semi random output
);


logic tick_time; //interconnect gerated tick wire

//first wave is not offset therefore count=count+1 (address1=address1+1)
clktick clocktick(
    .clk (clk),
    .N   (N),
    .en (1),
    .rst (rst),
    .tick (tick_time)
);

f1_fsm  f1_lights (
    .clk (clk),
    .en  (tick_time),
    .rst (rst),
    .data_out (data_out)
);

endmodule
