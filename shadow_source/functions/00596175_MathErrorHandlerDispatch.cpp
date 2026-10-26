// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596175
// Canonical corpus name: sub_596175
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596175_00596175.c

void UnknownObject::MathErrorHandlerDispatch()
{
    // MSVCRT-style math error handler dispatcher (sub_596175). Reads the error type code at *(DWORD*)a2 and maps type 1 and type 5 to action 8, type 2 to 4, type 3 to 17, type 4 to 18, type 6 to a reset (*(DWORD*)a2 = 1, handler skipped) and type 7 to 16; type 8 falls through with no handler. When sub_5919DA returns nonzero the handler is suppressed; otherwise sub_591727 builds the error-handler argument array. Afterwards the FPU control word is restored and SetErrorCodeBasedOnInputRange(*(DWORD*)a2) is returned when the error type is 8, the FPE exception flag dword_5E9AD0 is set, or StubReturning0() returns NULL.
    // ASSIGNMENT: Capture the 16-bit FPU control word at a3 into v3 and read the dispatch key from the error type code at *(DWORD*)a2. [source:raw]
    // GUARD: Sequential type dispatch: type 1 and type 5 select action 8; type 2 selects 4; type 3 selects 17; type 4 selects 18; type 6 resets *(DWORD*)a2 to 1 and skips the handler; type 7 selects 16; type 8 falls through without a handler action. [source:raw]
    // CALL: Call sub_5919DA with the selected action, the double operand at (double*)(a2 + 24) and the control word; a nonzero return suppresses the handler setup. [callee:0x005919DA, source:raw]
    // CALCULATION: When a1 is 16, 22 or 29, load v15 from (double*)(a2 + 16) and set the low flag bits in the local v16 (v16 & 0xFFFFFFE0 | 3); otherwise clear bit 0 of v16 (v16 &= ~1). [source:raw]
    // CALL: Set up the error-handler argument array via sub_591727((ULONG_PTR)Arguments, &a3, v11, a1, (double*)(a2 + 8), (double*)(a2 + 24)). [callee:0x00591727, source:raw]
    // CALL: Restore the saved FPU control word with ReturnFPUControlWord(v3). [callee:0x00591E66, source:raw]
    // GUARD: Select the error-code return path when *(DWORD*)a2 equals 8, or when the FPE exception flag dword_5E9AD0[0] is set, or when StubReturning0() returns NULL. [callee:0x0058FB7E, global:0x005E9AD0, source:raw]
    // RETURN: Return SetErrorCodeBasedOnInputRange(*(DWORD*)a2) as the resolved error code. [callee:0x00591C79, source:raw]
    // CALL: Invoked from MSVCCRTMathErrorHandler (0x0058DC57) and sub_59070A (0x0059070A) as the CRT math error dispatch entry. [caller:0x0058DC57, caller:0x0059070A, source:raw]

    // Conservative worker pseudocode:
    //   // dispatch on the error type code at *a2
    //   // type 1/5 -> action 8; 2 -> 4; 3 -> 17; 4 -> 18; 6 -> reset *a2=1; 7 -> 16; 8 -> no handler
    //   if (!sub_5919DA(action, (double*)(a2+24), ctrlWord)) {
    //       // flags per a1 branch (16/22/29 vs others)
    //       sub_591727(Arguments, &a3, action, a1, (double*)(a2+8), (double*)(a2+24));
    //   }
    //   ReturnFPUControlWord(ctrlWord);
    //   if (*a2 == 8 || dword_5E9AD0[0] || !StubReturning0()) return SetErrorCodeBasedOnInputRange(*a2);
    // UNRESOLVED: Meaning of the action codes 4, 8, 16, 17, 18 and their mapping to MSVCRT _matherr / _fpieee_flt error categories is not evidenced by the packet.
    // UNRESOLVED: The v16 flag construction (v16 & 0xFFFFFFE0 | 3 / v16 &= ~1) operates on an uninitialized local and is a decompiler artifact; the real caller-visible flag semantics are unknown.
    // UNRESOLVED: The FPU control word at a3 is a __int16 in the raw source but is passed around as an unsigned 16-bit value; its precise field meanings are not evidenced.
}
