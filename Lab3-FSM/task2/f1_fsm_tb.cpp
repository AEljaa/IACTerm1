#include "Vf1_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
int main(int argc,char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vf1_fsm *top = new Vf1_fsm;
    //init trace dump

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp=new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("Vf1_fsm.vcd");

    if(vbdOpen() != 1) return(-1);
    
    vbdHeader("Lab 3: LFSR");
    top->clk=1;
    top->rst=1;

    vbdSetMode(1);
    for (i=0; i<10000; i++){

        for (clk =0; clk<2; clk++){
            tfp->dump (2*i +clk);
            top->clk= !top->clk;
            top->eval ();

        }
        
        
        top->rst = (i<2) ; // condition that will cause rst to = 1
       
        top->en=vbdFlag(); // we want the our pushing down ot be the signal 
       
        vbdHex(2, (int(top->data_out) >>4)  & 0xF);
        vbdHex(1, top->data_out & 0xF);
        vbdBar(top->data_out & 0xFF);
        
        vbdCycle(i+1);
        
        if (Verilated::gotFinish()) exit(0);

    }
    
    vbdClose(); 
    tfp->close();
    exit(0);

}
