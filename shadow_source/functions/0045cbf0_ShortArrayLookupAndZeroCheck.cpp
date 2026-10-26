// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045CBF0
// Canonical corpus name: ShortArrayLookupAndZeroCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortArrayLookupAndZeroCheck_0045cbf0.c

void UnknownObject::ShortArrayLookupAndZeroCheck()
{
    // Reads a short value from a short-array member of the this object at index (a2 + 2402), converts it to float via ShortToFloatConversion into a3, and returns whether the converted float value is non-zero. Used by collision contact processing as a per-contact scalar zero check.
    // CALCULATION: Indexes the short array at this[a2 + 2402] (array element at 2-byte stride, offset 2402 elements from the array base in the this object). [source:raw, function:0x0045CBF0]
    // CALL: Calls ShortToFloatConversion on the looked-up short value, writing the converted float into a3. [callee:0x0045C7C0, source:raw, function:0x0045CBF0]
    // RETURN: Returns whether the converted float value differs from 0.0 (nonzero result indicates the checked short value was nonzero). [source:raw, function:0x0045CBF0]

    // Conservative worker pseudocode:
    //   BOOL ShortArrayLookupAndZeroCheck(_WORD *this, int a2, float *a3)
    //   {
    //     ShortToFloatConversion(this[a2 + 2402], a3);
    //     return (*a3) != 0.0f;
    //   }
    // UNRESOLVED: Decompiler shows the zero check reading through an uninitialized edx-based pointer (v3); the effective operand is assumed to be the converted float written to a3, but the exact register/pointer resolution is a compiler artifact.
    // UNRESOLVED: Global flt_59E440 is listed as a read but does not appear in the raw decompiled text; its role in this function is unclear.
}
