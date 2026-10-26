// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD400
// Canonical corpus name: NormalizedCoordinateCalculator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NormalizedCoordinateCalculator_004dd400.c

void UnknownObject::NormalizedCoordinateCalculator()
{
    // Computes two normalized scalar outputs from values produced by the TwoOutputPassthrough helper (0x004DD3A0). Calls TwoOutputPassthrough(this, a2, a3, a4, &a7, a4, a7), which leaves a first result readable through a7 (reinterpreted as int) and a second value in a4. When the output pointers are non-null, writes *a5 = (int)a7 / dword_5D6D60 and *a6 = a4 / dword_5D6D64, each divided by a read-only global scale. Returns the a6 output pointer.
    // CALL: Invoke TwoOutputPassthrough(this, a2, a3, a4, &a7, a4, a7); a7 is reused as the first integer output slot and a4 carries the second output value. [callee:0x004DD3A0, source:raw]
    // GUARD: Write the first output only when a5 is non-null. [source:raw]
    // ASSIGNMENT: First normalized output: *a5 = (double)(int)a7 / (double)dword_5D6D60, scaling the helper's integer result by the read-only global divisor at 0x005D6D60. [global:0x005D6D60, source:raw]
    // CALCULATION: Division by the global divisor dword_5D6D60 normalizes the integer result a7 into a scaled float coordinate. [global:0x005D6D60, source:raw]
    // GUARD: Write the second output only when a6 is non-null. [source:raw]
    // ASSIGNMENT: Second normalized output: *a6 = (double)a4 / (double)dword_5D6D64, scaling the helper's second value by the read-only global divisor at 0x005D6D64. [global:0x005D6D64, source:raw]
    // CALCULATION: Division by the global divisor dword_5D6D64 converts the value a4 into the second scaled coordinate. [global:0x005D6D64, source:raw]
    // RETURN: result = a6; return a6, the second output pointer. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_4DD400(int a2, float a3, int a4, float* a5, float* a6, int* a7) {
    //     TwoOutputPassthrough(this, a2, a3, a4, &a7, &a4, a7);
    //     if (a5) *a5 = (int)a7 / dword_5D6D60;
    //     if (a6) *a6 = a4 / dword_5D6D64;
    //     return a6;
    //   }
    // UNRESOLVED: Semantics of TwoOutputPassthrough (0x004DD3A0) are unknown; the way the raw source reuses a7 and a4 as output slots is a Hex-Rays artifact of the call.
    // UNRESOLVED: Meaning of the read-only global divisors dword_5D6D60 and dword_5D6D64 (e.g. a world/track dimension used to normalize coordinates) and the units of the resulting values are not evidenced.
    // UNRESOLVED: The coordinate domain of the caller sub_45B5C0 (0x0045B5C0) is unknown, so treating the two outputs as normalized x/y coordinates is unproven.
}
