// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlfsr_7b__Syms.h"


void Vlfsr_7b___024root__trace_chg_sub_0(Vlfsr_7b___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlfsr_7b___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7b___024root__trace_chg_top_0\n"); );
    // Init
    Vlfsr_7b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr_7b___024root*>(voidSelf);
    Vlfsr_7b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlfsr_7b___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vlfsr_7b___024root__trace_chg_sub_0(Vlfsr_7b___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr_7b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7b___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->en));
    bufp->chgBit(oldp+2,(vlSelf->rst));
    bufp->chgCData(oldp+3,(vlSelf->data_out),7);
    bufp->chgCData(oldp+4,(vlSelf->lfsr_7b__DOT__sreg),7);
}

void Vlfsr_7b___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr_7b___024root__trace_cleanup\n"); );
    // Init
    Vlfsr_7b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr_7b___024root*>(voidSelf);
    Vlfsr_7b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
