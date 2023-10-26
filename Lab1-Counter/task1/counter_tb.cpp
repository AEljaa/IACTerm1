#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

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


    top->clk=1;
    top->rst=1;
    top->en=0;

    int k = 3;
    for (i=0; i<300; i++){

        for (clk =0; clk<2; clk++){
            tfp->dump (2*i +clk);
            top->clk= !top->clk;
            top->eval ();

        }

        top->rst = (i<2) | (i==15); // condition that will cause rst to = 1
        top->en = (i>4); // condition that will cause en to = 1
        if(top->count ==0x90 && k > 0){
            top->en=0;
            // i=i+3; // skip 3 cycles
            k--;
            top->eval ();
        }
        if(Verilated::gotFinish()) exit(0);

    }

    tfp->close();
    exit(0);

}
