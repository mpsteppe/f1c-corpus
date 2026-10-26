// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005676C0
// Canonical corpus name: FloatToIntConversionWithRemainder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntConversionWithRemainder_005676c0.c

void UnknownObject::FloatToIntConversionWithRemainder()
{
    // Splits a float seconds value a3 into whole minutes and a seconds remainder. It multiplies a3 by 0.016666668 (flt_59E9C0, ~1/60), truncates with CRTFtol, stores the integer minutes into *a1 (this+0x0), stores the remainder (a3 - minutes * 60.0, using flt_59F118) into *a2, and returns the minute count. Timing/time-display helper.
    // CALL: Convert a3 seconds to whole minutes by calling CRTFtol on a3 * 0.016666668 (flt_59E9C0), truncating the scaled value toward zero. [callee:0x00587BDC, global:0x0059E9C0, source:raw]
    // ASSIGNMENT: Store the truncated integer minute count into *a1 (this+0x0). [field:this:0x00000000, source:raw]
    // CALCULATION: Compute and store the seconds remainder into *a2 as a3 - (float)minutes * 60.0 (flt_59F118). [global:0x0059F118, source:raw]
    // RETURN: Return the integer minute count produced by the conversion. [source:raw, function:0x005676C0]

    // Conservative worker pseudocode:
    //   int FloatToIntConversionWithRemainder(int* out_minutes, float* out_seconds, float a3) {
    //     int minutes = CRTFtol(a3 * 0.016666668f);
    //     *out_minutes = minutes;
    //     *out_seconds = a3 - (float)minutes * 60.0f;
    //     return minutes;
    //   }
    // UNRESOLVED: The conversion is assumed to be seconds to minutes/remainder based on the 1/60 scale and 60.0 recomposition constants; the calling context is timing-related but unproven.
    // UNRESOLVED: The return value is both written to *a1 and returned; its consumers at sub_4D24D0 and FloatToIntTruncateWithRemainder are not analyzed here.
}
