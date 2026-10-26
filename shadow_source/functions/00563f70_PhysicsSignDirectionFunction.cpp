// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563F70
// Canonical corpus name: PhysicsSignDirectionFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsSignDirectionFunction_00563f70.c

void UnknownObject::PhysicsSignDirectionFunction()
{
    // Sign/direction helper on a double argument. Computes v2 = a1 - a1 (a zeroed FPU quantity whose sign/zero status flags drive the result), negates v2 when the dword at dword_8D46B4 + 132 is zero, then returns 1, 0 or -1 according to the FPU comparison of v2 against 0.0. Two AudioMixerSampleGetWithFallback(0.0) calls precede the computation with unused results.
    // CALL: AudioMixerSampleGetWithFallback(0.0) called first; result unused. [callee:0x00564580, source:raw]
    // CALL: AudioMixerSampleGetWithFallback(0.0) called second; result unused. [callee:0x00564580, source:raw]
    // CALCULATION: v2 = a1 - a1: a zeroed FPU value whose sign/zero status flags drive the subsequent return selection. [source:raw]
    // GUARD: If the dword at dword_8D46B4 + 132 is zero, negate v2, reversing the polarity of the sign test. [global:0x008D46B4, source:raw]
    // CALCULATION: Compare v2 against 0.0 and capture the FPU status-word bits (v1 & 0x4100) plus the less-than and zero compare flags. [source:raw]
    // RETURN: If neither the zero nor the less-than bits of the FPU status word are set (v1 & 0x4100 == 0), return 1. [source:raw]
    // RETURN: If v2 >= 0.0, return 0. [source:raw]
    // RETURN: Otherwise return -1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_563F70(a1) {
    //     AudioMixerSampleGetWithFallback(0.0);
    //     AudioMixerSampleGetWithFallback(0.0);
    //     v2 = a1 - a1;
    //     if (!*(DWORD*)(dword_8D46B4 + 132)) v2 = -v2;
    //     if ((v1 & 0x4100) == 0) return 1;
    //     if (v2 >= 0.0) return 0;
    //     return -1;
    //   }
    // UNRESOLVED: The two AudioMixerSampleGetWithFallback(0.0) calls have unused results and appear unrelated to the sign computation; possibly a decompiler artifact of mis-merged adjacent code.
    // UNRESOLVED: Exact meaning of the FPU status-word test (v1 & 0x4100) and of the offset-132 flag on dword_8D46B4 controlling negation are unknown; v2 = a1 - a1 is a zeroed quantity, so the value whose sign is actually tested may come from an FPU operation not rendered by the decompiler.
    // UNRESOLVED: flt_59E440 appears in the packet global set but not in the raw source text; role unresolved.
    // UNRESOLVED: No callers are recorded; the function's consumer is unknown.
}
