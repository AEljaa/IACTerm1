// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"trigger", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBus(c+14,"N", false,-1, 15,0);
    tracep->declBus(c+15,"data_out", false,-1, 7,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+20,"D_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"C_WIDTH", false,-1, 31,0);
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+12,"trigger", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBus(c+14,"N", false,-1, 15,0);
    tracep->declBus(c+15,"data_out", false,-1, 7,0);
    tracep->declBit(c+1,"tick_time", false,-1);
    tracep->declBit(c+6,"cmd_seq", false,-1);
    tracep->declBit(c+7,"cmd_delay", false,-1);
    tracep->declBit(c+8,"random_num", false,-1);
    tracep->declBit(c+2,"time_out", false,-1);
    tracep->declBit(c+16,"mux_val", false,-1);
    tracep->pushNamePrefix("clocktick ");
    tracep->declBus(c+21,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBit(c+6,"en", false,-1);
    tracep->declBus(c+14,"N", false,-1, 15,0);
    tracep->declBit(c+1,"tick", false,-1);
    tracep->declBus(c+3,"count", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("delay ");
    tracep->declBus(c+22,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBit(c+7,"trigger", false,-1);
    tracep->declBus(c+9,"n", false,-1, 9,0);
    tracep->declBit(c+2,"time_out", false,-1);
    tracep->declBus(c+4,"count", false,-1, 9,0);
    tracep->declBus(c+5,"current_state", false,-1, 31,0);
    tracep->declBus(c+17,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("f1_lights ");
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+16,"en", false,-1);
    tracep->declBit(c+12,"trigger", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBus(c+15,"data_out", false,-1, 7,0);
    tracep->declBit(c+6,"cmd_seq", false,-1);
    tracep->declBit(c+7,"cmd_delay", false,-1);
    tracep->declBus(c+18,"current_state", false,-1, 31,0);
    tracep->declBus(c+19,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lfsr ");
    tracep->declBit(c+11,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBus(c+10,"data_out", false,-1, 7,1);
    tracep->declBus(c+10,"sreg", false,-1, 7,1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top__DOT__tick_time));
    bufp->fullBit(oldp+2,(((0U != vlSelf->top__DOT__delay__DOT__current_state) 
                           & ((1U != vlSelf->top__DOT__delay__DOT__current_state) 
                              & (2U == vlSelf->top__DOT__delay__DOT__current_state)))));
    bufp->fullSData(oldp+3,(vlSelf->top__DOT__clocktick__DOT__count),16);
    bufp->fullSData(oldp+4,(vlSelf->top__DOT__delay__DOT__count),10);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__delay__DOT__current_state),32);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__cmd_seq));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__cmd_delay));
    bufp->fullBit(oldp+8,((1U & (IData)(vlSelf->top__DOT__lfsr__DOT__sreg))));
    bufp->fullSData(oldp+9,((1U & (IData)(vlSelf->top__DOT__lfsr__DOT__sreg))),10);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__lfsr__DOT__sreg),7);
    bufp->fullBit(oldp+11,(vlSelf->clk));
    bufp->fullBit(oldp+12,(vlSelf->trigger));
    bufp->fullBit(oldp+13,(vlSelf->rst));
    bufp->fullSData(oldp+14,(vlSelf->N),16);
    bufp->fullCData(oldp+15,(vlSelf->data_out),8);
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__mux_val));
    bufp->fullIData(oldp+17,(((0U == vlSelf->top__DOT__delay__DOT__current_state)
                               ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                   ? 1U : vlSelf->top__DOT__delay__DOT__current_state)
                               : ((1U == vlSelf->top__DOT__delay__DOT__current_state)
                                   ? ((0U == (IData)(vlSelf->top__DOT__delay__DOT__count))
                                       ? 2U : vlSelf->top__DOT__delay__DOT__current_state)
                                   : ((2U == vlSelf->top__DOT__delay__DOT__current_state)
                                       ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                           ? 3U : 0U)
                                       : ((3U == vlSelf->top__DOT__delay__DOT__current_state)
                                           ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                               ? vlSelf->top__DOT__delay__DOT__current_state
                                               : 0U)
                                           : 0U))))),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__f1_lights__DOT__current_state),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__f1_lights__DOT__next_state),32);
    bufp->fullIData(oldp+20,(8U),32);
    bufp->fullIData(oldp+21,(0x10U),32);
    bufp->fullIData(oldp+22,(0xaU),32);
}
