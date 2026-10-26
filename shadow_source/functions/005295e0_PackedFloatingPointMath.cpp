// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005295E0
// Canonical corpus name: PackedFloatingPointMath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PackedFloatingPointMath_005295e0.c

void UnknownObject::PackedFloatingPointMath()
{
    // Computes the absolute value of the lower 32-bit lane of a packed __m64 argument by clearing its sign bit: extracts the lower lane with _mm_cvtsi64_si32, isolates the sign bit with the mask 0x80000000, and XORs it back onto the value. No branches. Packet records eleven read globals (qword_5D92D8..dword_5D9414) but the raw body references none; they are treated as context from the calling 3DNow routines.
    // CALCULATION: Extracts the lower 32-bit lane of the __m64 argument via _mm_cvtsi64_si32 [source:raw]
    // CALCULATION: Isolates the sign bit with the mask 0x80000000 and XORs it back onto the value, clearing the sign bit and yielding the absolute value of the lower lane [source:raw]
    // RETURN: Returns the sign-cleared (absolute) lower 32-bit lane [source:raw]
    // CALL: Used as a shared packed-float absolute-value helper by 3DNow math routines, e.g. QuaternionMul3DNow, F_3DVectorNormalize and SIMDQuaternionRotationArithmetic [caller:0x005214AA, caller:0x0052193C, caller:0x00524553]

    // Conservative worker pseudocode:
    //   v1 = _mm_cvtsi64_si32(a1);
    //   return v1 ^ (v1 & 0x80000000); /* clears sign bit: absolute value of lower lane * /
    // UNRESOLVED: Packet records eleven read globals (qword_5D92D8 through dword_5D9414) but the raw function body references no global; they likely belong to the calling 3DNow polynomial/trig context rather than this helper
}
