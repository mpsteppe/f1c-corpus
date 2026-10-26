// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553CD0
// Canonical corpus name: ClampedPixelSpanFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClampedPixelSpanFill_00553cd0.c

void UnknownObject::ClampedPixelSpanFill()
{
    // Orders the pixel span endpoints a1/a2 (swapping if a1 > a2 so the span runs ascending), then fills the 16-bit span starting at a1 + a5*a3 for a2 - a1 + 1 elements with value a4 using F_16BitShortArrayFill(a1 + a5*a3, a2 - a1 + 1, a4, a6). Returns the fill helper's result.
    // GUARD: If a1 > a2, swap a1 and a2 so the span endpoints are ascending (clamped ordering). [source:raw]
    // CALCULATION: Compute destination pointer a1 + a5*a3 (start plus row_index * row_stride) and element count a2 - a1 + 1. [source:raw]
    // CALL: Call F_16BitShortArrayFill(a1 + a5*a3, a2 - a1 + 1, a4, a6) to fill the 16-bit span. [callee:0x005619F1]
    // RETURN: Return the result of F_16BitShortArrayFill. [source:raw]

    // Conservative worker pseudocode:
    //   int ClampedPixelSpanFill(int span_start, int span_end, int row_index, int fill_value, int row_stride, int fill_argument) {
    //       if (span_start > span_end) {
    //           int tmp = span_start;
    //           span_start = span_end;
    //           span_end = tmp;
    //       }
    //       return F_16BitShortArrayFill(span_start + row_index * row_stride, span_end - span_start + 1, fill_value, fill_argument);
    //   }
    // UNRESOLVED: Semantic meaning of the last fill argument a6 (color, pattern, or mask) is unconfirmed.
    // UNRESOLVED: Whether the filled buffer is a framebuffer, shadow buffer, or scratch pixel array is unknown.
}
