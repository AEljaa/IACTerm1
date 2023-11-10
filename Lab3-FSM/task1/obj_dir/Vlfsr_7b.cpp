// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlfsr_7b.h"
#include "Vlfsr_7b__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlfsr_7b::Vlfsr_7b(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlfsr_7b__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , data_out{vlSymsp->TOP.data_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vlfsr_7b::Vlfsr_7b(const char* _vcname__)
    : Vlfsr_7b(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlfsr_7b::~Vlfsr_7b() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlfsr_7b___024root___eval_debug_assertions(Vlfsr_7b___024root* vlSelf);
#endif  // VL_DEBUG
void Vlfsr_7b___024root___eval_static(Vlfsr_7b___024root* vlSelf);
void Vlfsr_7b___024root___eval_initial(Vlfsr_7b___024root* vlSelf);
void Vlfsr_7b___024root___eval_settle(Vlfsr_7b___024root* vlSelf);
void Vlfsr_7b___024root___eval(Vlfsr_7b___024root* vlSelf);

void Vlfsr_7b::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlfsr_7b::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlfsr_7b___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vlfsr_7b___024root___eval_static(&(vlSymsp->TOP));
        Vlfsr_7b___024root___eval_initial(&(vlSymsp->TOP));
        Vlfsr_7b___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vlfsr_7b___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vlfsr_7b::eventsPending() { return false; }

uint64_t Vlfsr_7b::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vlfsr_7b::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vlfsr_7b___024root___eval_final(Vlfsr_7b___024root* vlSelf);

VL_ATTR_COLD void Vlfsr_7b::final() {
    Vlfsr_7b___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlfsr_7b::hierName() const { return vlSymsp->name(); }
const char* Vlfsr_7b::modelName() const { return "Vlfsr_7b"; }
unsigned Vlfsr_7b::threads() const { return 1; }
void Vlfsr_7b::prepareClone() const { contextp()->prepareClone(); }
void Vlfsr_7b::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vlfsr_7b::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vlfsr_7b___024root__trace_init_top(Vlfsr_7b___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlfsr_7b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr_7b___024root*>(voidSelf);
    Vlfsr_7b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vlfsr_7b___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vlfsr_7b___024root__trace_register(Vlfsr_7b___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vlfsr_7b::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vlfsr_7b::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vlfsr_7b___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
