// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_flg.h for the primary calling header

#include "verilated.h"

#include "Vcounter_flg__Syms.h"
#include "Vcounter_flg___024root.h"

void Vcounter_flg___024root___eval_act(Vcounter_flg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_flg___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vcounter_flg___024root___nba_sequent__TOP__0(Vcounter_flg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_flg___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->count = ((IData)(vlSelf->rst) ? 0U : (0xffU 
                                                  & ((IData)(vlSelf->en)
                                                      ? 
                                                     ((IData)(vlSelf->count) 
                                                      + (IData)(vlSelf->en))
                                                      : 
                                                     ((IData)(vlSelf->count) 
                                                      - 
                                                      (1U 
                                                       & (~ (IData)(vlSelf->en)))))));
}

void Vcounter_flg___024root___eval_nba(Vcounter_flg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_flg___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vcounter_flg___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vcounter_flg___024root___eval_triggers__act(Vcounter_flg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter_flg___024root___dump_triggers__act(Vcounter_flg___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter_flg___024root___dump_triggers__nba(Vcounter_flg___024root* vlSelf);
#endif  // VL_DEBUG

void Vcounter_flg___024root___eval(Vcounter_flg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_flg___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vcounter_flg___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vcounter_flg___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("counter_flg.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vcounter_flg___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vcounter_flg___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("counter_flg.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vcounter_flg___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vcounter_flg___024root___eval_debug_assertions(Vcounter_flg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_flg___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
