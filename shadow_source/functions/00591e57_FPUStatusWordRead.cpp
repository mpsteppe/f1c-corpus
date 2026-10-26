// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591E57
// Canonical corpus name: FPUStatusWordRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FPUStatusWordRead_00591e57.c

void UnknownObject::FPUStatusWordRead()
{
    // Reads the 16-bit FPU status word a1, clears pending FPU exceptions with fnclex, and returns the previously captured status word. The status word a1 is delivered via the FPU status register per the raw prototype; fnclex does not alter the already-captured a1 value.
    // STATE_TRANSITION: Execute fnclex, clearing the pending FPU exception flags (IE, DE, ZE, OE, UE, PE, ES) in the FPU status word. [source:raw]
    // RETURN: Return the status word a1 captured before the fnclex; the clear operation does not change the returned value. [source:raw]
    // CALL: Invoked by sub_591727 to read and clear the FPU status word in one call. [caller:0x00591727, source:raw]

    // Conservative worker pseudocode:
    //   int sub_591E57(int a1) {
    //     __asm fnclex;
    //     return a1;
    //   }
    // UNRESOLVED: Whether the caller reads the returned status word to detect a prior FPU exception before it is cleared, or uses this purely to reset exception state, is unknown here.
    // UNRESOLVED: The 16-bit argument provenance is the FPU status register per the raw prototype; the exact capturing instruction is outside this function's body.
}
