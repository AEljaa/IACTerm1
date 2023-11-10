// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLFSR_7B__SYMS_H_
#define VERILATED_VLFSR_7B__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vlfsr_7b.h"

// INCLUDE MODULE CLASSES
#include "Vlfsr_7b___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vlfsr_7b__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vlfsr_7b* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vlfsr_7b___024root             TOP;

    // CONSTRUCTORS
    Vlfsr_7b__Syms(VerilatedContext* contextp, const char* namep, Vlfsr_7b* modelp);
    ~Vlfsr_7b__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
