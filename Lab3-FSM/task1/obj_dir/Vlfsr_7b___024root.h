// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlfsr_7b.h for the primary calling header

#ifndef VERILATED_VLFSR_7B___024ROOT_H_
#define VERILATED_VLFSR_7B___024ROOT_H_  // guard

#include "verilated.h"


class Vlfsr_7b__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlfsr_7b___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(data_out,7,1);
    CData/*6:0*/ lfsr_7b__DOT__sreg;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlfsr_7b__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vlfsr_7b___024root(Vlfsr_7b__Syms* symsp, const char* v__name);
    ~Vlfsr_7b___024root();
    VL_UNCOPYABLE(Vlfsr_7b___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
