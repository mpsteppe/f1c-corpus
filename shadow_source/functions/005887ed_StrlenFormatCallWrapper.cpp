// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005887ED
// Canonical corpus name: StrlenFormatCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StrlenFormatCallWrapper_005887ed.c

void UnknownObject::StrlenFormatCallWrapper()
{
    // Variadic wrapper that builds a small local argument descriptor v3 on the stack, fills it with the raw pointer a1, its Strlen length, the raw pointer again, and the constant 73, then forwards v3, the format-like pointer a2 and the va_list into sub_58E4D2. The wrapper's only real work is precomputing a1's byte length and packing it with a1 into the descriptor before delegating the format/argument handling.
    // ASSIGNMENT: Start the variadic frame: va_start(va, a2), and clear/size the local _DWORD v3[8] stack array. [source:raw]
    // ASSIGNMENT: Pack the descriptor: v3[0] = a1, v3[2] = a1 (the pointer stored twice), and v3[3] = 73. [source:raw]
    // CALL: Compute the byte length of a1: v3[1] = Strlen(a1). [callee:0x0058E1B0, source:raw]
    // CALL: Delegate the actual work to sub_58E4D2 with the descriptor v3, the second argument a2 and the va_list va. [callee:0x0058E4D2, source:raw]
    // RETURN: Return the result of sub_58E4D2 unchanged. [source:raw]
    // CALL: Used across unrelated subsystems, e.g. PitCrewAnimationLoader (0x004A2A90), Steward_Restart (0x004D3CF0), TireSlipCurveBuilder (0x004D5F70) and several formatting helpers in the same module, indicating a shared format/stringization utility. [caller:0x004A2A90, caller:0x004D3CF0, caller:0x004D5F70, caller:0x005651B0, caller:0x005655F0]

    // Conservative worker pseudocode:
    //   int sub_5887ED(int a1, const char *a2, ...) {
    //     _DWORD v3[8]; va_list va;
    //     va_start(va, a2);
    //     v3[0] = a1; v3[1] = Strlen(a1); v3[2] = a1; v3[3] = 73;
    //     return sub_58E4D2(v3, a2, va);
    //   }
    // UNRESOLVED: Meaning of the constant 73 written to v3[3] and the exact layout/interpretation of v3 by sub_58E4D2.
    // UNRESOLVED: Why a1 is duplicated into both v3[0] and v3[2].
    // UNRESOLVED: Whether a2 is a format string or an output buffer depends on sub_58E4D2, which is not in this packet.
}
