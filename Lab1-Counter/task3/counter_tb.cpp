#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
int main(int argc,char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //init top verilog instance
    Vcounter *top = new Vcounter;
    //init trace dump

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp=new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("Vcounter.vcd");

    if(vbdOpen() != 1) return(-1);
    
    vbdHeader("Lab 1: Counter");
    top->clk=1;
    top->rst=1;
    top->ld=0;
    top->v=0;

    for (i=0; i<10000; i++){

        for (clk =0; clk<2; clk++){
            tfp->dump (2*i +clk);
            top->clk= !top->clk;
            top->eval ();

        }
        
        vbdPlot(int(top->count), 0, 255);
        vbdCycle(i+1);
        
        top->rst = (i<2) | (i==15); // condition that will cause rst to = 1
        top->v=vbdValue();
        if (Verilated::gotFinish()) exit(0);

    }
    
    vbdClose(); 
    tfp->close();
    exit(0);

}
