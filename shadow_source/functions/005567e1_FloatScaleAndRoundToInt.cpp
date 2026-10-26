// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005567E1
// Canonical corpus name: FloatScaleAndRoundToInt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatScaleAndRoundToInt_005567e1.c

void UnknownObject::FloatScaleAndRoundToInt()
{
    // Cdecl scalar helper that multiplies a float argument by the global scale factor flt_5DC164 and converts the product to int. The (int) cast truncates toward zero, so the name's "round" is C truncation rather than nearest rounding. Reads the global at 0x005DC164; no callees.
    // CALCULATION: Multiply the float argument a1 by the global float scale factor flt_5DC164 (read-only global at 0x005DC164). [global:0x005DC164, source:raw]
    // RETURN: Cast the scaled product to int (truncating toward zero) and return it. [source:raw]

    // Conservative worker pseudocode:
    //   int FloatScaleAndRoundToInt(float a1) {
    //     return (int)(a1 * flt_5DC164);
    //   }
    // UNRESOLVED: The value and meaning of the global scale factor flt_5DC164 are not established; it is only read here.
    // UNRESOLVED: The int cast truncates toward zero, so whether callers depend on rounding vs truncation for negative inputs is unknown.
}
