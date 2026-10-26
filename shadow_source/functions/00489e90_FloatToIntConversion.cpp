// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489E90
// Canonical corpus name: FloatToIntConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntConversion_00489e90.c

void UnknownObject::FloatToIntConversion()
{
    // Converts a scroll index (this+0x14C) to a pixel position (this+0x150) via round(scroll_index / max_scroll * display_size) using CRTFtol for float-to-int conversion. Skips conversion and clears the output when max scroll (this+0x160) is zero. Called by DecrementCounterVirtualCall (00489500), UINavigationAdvanceHandler (00489530), StateUpdateWithDecrement (00489560), sub_4895B0 (004895b0), UIListSelectionHandler (00489ab0), sub_489D00 (00489d00) and UIScrollbarThumbDragHandler (0048a650).
    // ASSIGNMENT: result = this[88] (max scroll value at this+0x160); this[84] (pixel position output at this+0x150) is cleared to 0 before the guard [field:this:0x00000160, field:this:0x00000150]
    // GUARD: If result (max scroll) is non-zero the ratio conversion runs; otherwise the function skips conversion and returns the zero-cleared result [field:this:0x00000160, source:raw]
    // CALCULATION: Builds the ratio term: (double)this[83] (scroll index at this+0x14C) divided by (double)result (max scroll) times (double)this[85] (display size at this+0x154), plus 0.5 to round [field:this:0x0000014C, field:this:0x00000154, source:raw]
    // CALL: CRTFtol converts the rounded float ratio to an integer pixel position (truncation) [callee:0x00587BDC]
    // ASSIGNMENT: this[84] (pixel position at this+0x150) is set to the integer returned by CRTFtol [field:this:0x00000150]
    // RETURN: Return the computed pixel position (result), which is 0 when the guard skipped the conversion [source:raw]

    // Conservative worker pseudocode:
    //   result = this[88];
    //   this[84] = 0;
    //   if (result != 0) {
    //     result = CRTFtol((double)this[83] / (double)result * (double)this[85] + 0.5);
    //     this[84] = result;
    //   }
    //   return result;
    // UNRESOLVED: The semantic roles of this+0x14C / this+0x150 / this+0x154 / this+0x160 (scroll index, pixel position, display size, max scroll) are grounded in the existing analysis but not proven by the raw source alone
    // UNRESOLVED: flt_59E450 is flagged as a read global by the packet facts but does not appear in the raw decompiled source; its role here is not verifiable
}
