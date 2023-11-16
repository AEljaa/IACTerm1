#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#include <ctime>
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4:F1");

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->trigger = vbdFlag();
  int prev_trigger=top->trigger; 
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) { 
    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->N = 24;
    
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    
    top->trigger = vbdFlag();// get the trigger/vbdflag val then output the next seq
    if(!top->trigger){
        vbdInitWatch();//start timer -resets if we dont have trigger on since loop would restart
    }

    vbdBar(top->data_out);
    if(top->data_out==0 && top->trigger){
        if(vbdFlag()){//trigger has been pressed calcualte elapesed time and display it - not working
            int time=vbdElapsed();
            printf("Time elapsed: %d\n", time);
            vbdHex(1, time & 0xF);        
            vbdHex(2, int(time >> 4) & 0xF);        
            vbdHex(3, int(time >> 8)  & 0xF);        
            vbdHex(4, int(time >> 16) & 0xF);        
        }
    }
    
    vbdCycle(simcyc);
    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
