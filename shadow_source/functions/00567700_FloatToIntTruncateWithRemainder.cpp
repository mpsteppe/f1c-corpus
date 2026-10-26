// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567700
// Canonical corpus name: FloatToIntTruncateWithRemainder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntTruncateWithRemainder_00567700.c

void UnknownObject::FloatToIntTruncateWithRemainder()
{
    // Converts an input value into whole seconds and a remainder: v8 = CRTFtol(a3 * 0.00027777778) is the truncated whole seconds written to *a1; the residual v7 = a3 - (double)v8 * 3600.0 is decomposed by FloatToIntConversionWithRemainder (0x005676C0) into the a2/a4 outputs, whose return value is propagated. The function reads two float globals at 0x0059E9B8 and 0x0059E9BC that do not surface as named operands in the inlined raw source.
    // CALL: v8 = CRTFtol(a3 * 0.00027777778) — scale the input by 1/3600 and truncate to an integer count of whole seconds. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: *a1 = v8 — write the whole-seconds result into the first output pointer. [source:raw]
    // CALCULATION: v7 = a3 - (double)v8 * 3600.0 — remainder left over after removing the whole seconds. [source:raw]
    // CALL: return FloatToIntConversionWithRemainder(a2, a4, v7) — decompose the remainder into the two remaining outputs and propagate its return value. [callee:0x005676C0, source:raw]

    // Conservative worker pseudocode:
    //   v8 = CRTFtol(a3 * 0.00027777778);
    //   *a1 = v8;
    //   v7 = a3 - (double)v8 * 3600.0;
    //   return FloatToIntConversionWithRemainder(a2, a4, v7);
    // UNRESOLVED: Read-only float globals flt_59E9B8 (0x0059E9B8) and flt_59E9BC (0x0059E9BC) are read but do not appear as named operands in the inlined raw source; they may hold the constants 0.00027777778 and 3600.0, but that mapping is unconfirmed.
    // UNRESOLVED: Semantic meaning of the a2/a4 outputs produced by FloatToIntConversionWithRemainder (0x005676C0) is not confirmed.
}
