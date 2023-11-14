// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_OUT8(data_out,7,0);
    CData/*0:0*/ top__DOT__tick_time;
    CData/*0:0*/ top__DOT__cmd_seq;
    CData/*0:0*/ top__DOT__cmd_delay;
    CData/*0:0*/ top__DOT__mux_val;
    CData/*6:0*/ top__DOT__lfsr__DOT__sreg;
    CData/*6:0*/ __Vdly__top__DOT__lfsr__DOT__sreg;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(N,15,0);
    SData/*15:0*/ top__DOT__clocktick__DOT__count;
    SData/*9:0*/ top__DOT__delay__DOT__count;
    IData/*31:0*/ top__DOT__f1_lights__DOT__current_state;
    IData/*31:0*/ top__DOT__f1_lights__DOT__next_state;
    IData/*31:0*/ top__DOT__delay__DOT__current_state;
    IData/*31:0*/ top__DOT__delay__DOT__next_state;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
