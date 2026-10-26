// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005567D3
// Canonical corpus name: FloatRoundToInt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatRoundToInt_005567d3.c

void UnknownObject::FloatRoundToInt()
{
    // Truncating float-to-int conversion: converts the single-precision argument a1 to a 32-bit integer with the plain C cast, which truncates toward zero rather than performing any rounding.
    // CALCULATION: Convert the float argument a1 to int via the C casting semantics of the raw source. [source:raw]
    // RETURN: Return the converted integer value. [source:raw]

    // Conservative worker pseudocode:
    //   int FloatRoundToInt(float x) {
    //     return (int)x;
    //   }
    // UNRESOLVED: The canonical name suggests rounding, but the raw source is a plain C cast which truncates toward zero; true round-half semantics are unconfirmed.
    // UNRESOLVED: No handling is evidenced for floats outside the int range or NaN/infinity inputs.
}
