// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F460
// Canonical corpus name: PackedFlagRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PackedFlagRead_0044f460.c

void UnknownObject::PackedFlagRead()
{
    // __thiscall reader for a single packed flag bit. Reads bit 1 of byte this[a2 + 892] and returns it as 0 or 1, unless a mode guard forces a zero result: when ConditionalFlagReturn(&dword_5EA43C) is true, dword_7C569C equals 5, and a2 is not 1, the function short-circuits to 0. Multiple callers (CollisionResultProcessing, StateTriggerCheck and three sub_* routines) use it to query a per-object packed boolean state.
    // CALL: Call ConditionalFlagReturn with a pointer to dword_5EA43C; its result truthiness participates in the early-return guard. [callee:0x00404F10, global:0x005EA43C, source:raw]
    // GUARD: Guard combining ConditionalFlagReturn(&dword_5EA43C) truthiness, dword_7C569C == 5, and a2 != 1; when all three hold the function returns 0 early. [global:0x007C569C, global:0x005EA43C, callee:0x00404F10, source:raw]
    // RETURN: Early return 0 when the guard condition is satisfied. [source:raw]
    // CALCULATION: Compute the byte index a2 + 892 into the this byte array. [source:raw]
    // CALCULATION: Extract the packed flag: shift this[a2 + 892] right by 1 and mask with 1 to isolate bit 1. [source:raw]
    // RETURN: Return (this[a2 + 892] >> 1) & 1 as the packed bit value. [source:raw]

    // Conservative worker pseudocode:
    //   char __thiscall sub_44F460(unsigned char *this, int a2) {
    //     if (ConditionalFlagReturn(&dword_5EA43C) && dword_7C569C == 5 && a2 != 1)
    //       return 0;
    //     return (this[a2 + 892] >> 1) & 1;
    //   }
    // UNRESOLVED: Semantics of the flag state read by ConditionalFlagReturn(&dword_5EA43C) are not defined by this function.
    // UNRESOLVED: Meaning of the dword_7C569C == 5 comparison (presumed a mode/session state constant).
    // UNRESOLVED: Why index a2 == 1 is excluded from the forced-zero guard.
    // UNRESOLVED: Layout of the this byte array and what bit 1 of element a2 + 892 signifies per caller.
    // UNRESOLVED: Identity of the class owning this method; callers come from collision, state-trigger and unknown paths.
}
