// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447D00
// Canonical corpus name: BrakeBiasAdjustmentControl
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BrakeBiasAdjustmentControl_00447d00.c

void UnknownObject::BrakeBiasAdjustmentControl()
{
    // Adjusts a brake-bias index from a signed input delta (a2): decrements/clamps at 0 for negative input, increments/clamps at max-1 (this+0x157C) for positive input. Recomputes the final bias value as index * step + base (this+0x1580 * this+0x1574 + this+0x156C) and writes it to this+0x1564. Then, after a per-frame ShortComputation_bdf0 on dword_7CD204, looks up the localized 'BrakeBias' string via BinarySearchInStringTable, copies it into byte_5EC4CC, formats '<text> fwd:rear' as two 1-decimal percentages via StringFormatWithBufferOverflowCheck, and renders the result with TextLineWrappingAndRendering. Returns the render result. Vehicle setup/UI control path.
    // CALL: ShortComputation_bdf0(&dword_7CD204): per-frame helper on the resource/dispatch global. [callee:0x0045BDF0, global:0x007CD204, source:raw]
    // STATE_TRANSITION: If a2 <= 0: when a2 < 0, decrement current bias index (this+0x1580) and clamp to 0 if negative. [field:this:0x00001580, source:raw]
    // STATE_TRANSITION: Else (a2 > 0): increment current bias index (this+0x1580); if it reaches max index (this+0x157C), clamp to max-1. [field:this:0x00001580, field:this:0x0000157C, source:raw]
    // CALCULATION: v6 = (double)index * step + base = (this+0x1580) * (this+0x1574) + (this+0x156C): compute final bias value. [field:this:0x00001580, field:this:0x00001574, field:this:0x0000156C, source:raw]
    // ASSIGNMENT: *(double*)(this+0x1564) = v6: store the computed final brake-bias value. [field:this:0x00001564, source:raw]
    // LOOP: BinarySearchInStringTable(byte_5EC4C0, aBrakeBias, byte_5EC4CC); if found, copy the localized 'BrakeBias' string into byte_5EC4CC byte-by-byte until NUL. [callee:0x00423A00, global:0x005EC4C0, global:0x005C43A4, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%s %4.1f:%4.1f", byte_5EC4CC, 100.0 - v6*100.0, v6*100.0): format label plus front/rear bias percentages into the display buffer. [callee:0x0058815F, global:0x005C4394, global:0x005EC4CC, source:raw]
    // RETURN: return TextLineWrappingAndRendering(v10, 3, 16909060): render the formatted bias display and return its result. [callee:0x0045BD10, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_bdf0(&dword_7CD204);
    //   if (a2 <= 0) {
    //     if (a2 < 0 && --index < 0) index = 0;
    //   } else {
    //     new = ++index;
    //     if (new >= maxIndex) index = maxIndex - 1;
    //   }
    //   bias = index * step + base;
    //   this->finalBias = bias;
    //   if (BinarySearchInStringTable(byte_5EC4C0, aBrakeBias, byte_5EC4CC))
    //     copy aBrakeBias into byte_5EC4CC;
    //   StringFormatWithBufferOverflowCheck(buf, "%s %4.1f:%4.1f", byte_5EC4CC, 100.0 - bias*100.0, bias*100.0);
    //   return TextLineWrappingAndRendering(buf, 3, 16909060);
    // UNRESOLVED: dbl_59EA20 is listed as read by this function in the deterministic fact store but does not appear in the raw decompiled body; no operation can be grounded on it.
    // UNRESOLVED: a2 signed-delta semantics and the exact caller (sub_42C440) context are not part of this packet.
    // UNRESOLVED: Render literals 3 (mode) and 16909060 (color/coordinate) meaning unknown.
    // UNRESOLVED: ShortComputation_bdf0 purpose is opaque from this packet.
}
