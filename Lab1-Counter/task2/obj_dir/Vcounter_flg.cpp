// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcounter_flg.h"
#include "Vcounter_flg__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcounter_flg::Vcounter_flg(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcounter_flg__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcounter_flg::Vcounter_flg(const char* _vcname__)
    : Vcounter_flg(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcounter_flg::~Vcounter_flg() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcounter_flg___024root___eval_debug_assertions(Vcounter_flg___024root* vlSelf);
#endif  // VL_DEBUG
void Vcounter_flg___024root___eval_static(Vcounter_flg___024root* vlSelf);
void Vcounter_flg___024root___eval_initial(Vcounter_flg___024root* vlSelf);
void Vcounter_flg___024root___eval_settle(Vcounter_flg___024root* vlSelf);
void Vcounter_flg___024root___eval(Vcounter_flg___024root* vlSelf);

void Vcounter_flg::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcounter_flg::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcounter_flg___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcounter_flg___024root___eval_static(&(vlSymsp->TOP));
        Vcounter_flg___024root___eval_initial(&(vlSymsp->TOP));
        Vcounter_flg___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcounter_flg___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcounter_flg::eventsPending() { return false; }

uint64_t Vcounter_flg::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcounter_flg::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcounter_flg___024root___eval_final(Vcounter_flg___024root* vlSelf);

VL_ATTR_COLD void Vcounter_flg::final() {
    Vcounter_flg___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcounter_flg::hierName() const { return vlSymsp->name(); }
const char* Vcounter_flg::modelName() const { return "Vcounter_flg"; }
unsigned Vcounter_flg::threads() const { return 1; }
void Vcounter_flg::prepareClone() const { contextp()->prepareClone(); }
void Vcounter_flg::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vcounter_flg::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcounter_flg___024root__trace_init_top(Vcounter_flg___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter_flg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcounter_flg___024root*>(voidSelf);
    Vcounter_flg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcounter_flg___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcounter_flg___024root__trace_register(Vcounter_flg___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcounter_flg::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcounter_flg::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcounter_flg___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
