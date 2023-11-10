#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

#define MAX_SIM_CYC 1000000

int main(int argc,char **argv, char **env){
    int clk;

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vtop *top = new Vtop;
    //init trace dump

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp=new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("Vtop.vcd");

    if(vbdOpen() != 1) return(-1);
    
    vbdHeader("Lab 3:F1 FSM");
    top->clk=1;
    top->rst=1;
    top->N = 23;
    
    vbdSetMode(1);
    for (int simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (int tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }
        
        
        top->rst = (simcyc<2) ; // condition that will cause rst to = 1
       
       
        vbdHex(2, (int(top->data_out) >>4)  & 0xF);
        vbdHex(1, top->data_out & 0xF);
        vbdBar(top->data_out);
        
        vbdCycle(simcyc+1);
        
        if (Verilated::gotFinish()) exit(0);

    }
    
    vbdClose(); 
    tfp->close();
    exit(0);

}
