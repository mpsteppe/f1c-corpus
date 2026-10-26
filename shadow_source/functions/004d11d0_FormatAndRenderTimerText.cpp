// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D11D0
// Canonical corpus name: sub_4D11D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D11D0_004d11d0.c

void UnknownObject::FormatAndRenderTimerText()
{
    // Formats a float elapsed-time value a1 into a "%s%02d:%02d" (prefix:MM:SS) string and submits it to the render context dword_7CD204 via ShortComputation_bde0 and TextLineWrappingAndRendering. When the prefix argument a2 is null it is replaced by the default string at byte_5EA438. The function formats and renders the text twice: first from v4 = a1 + 2.0 (both two-digit fields drawn from the same truncated value), then from v11 = a1 + 1.0 with the minute field computed as CRTFtol(v11 * 0.016666668) and the second field as CRTFtol(v11 - minutes * 60.0). Returns the result of the final TextLineWrappingAndRendering call. Called by PitTimer (0x004D2E50) for on-screen time display.
    // GUARD: If a2 is null, the prefix is replaced with the default string at byte_5EA438. [global:0x005EA438, source:raw]
    // CALCULATION: Computes v11 = a1 + 1.0, then v4 = v11 + 1.0 (i.e. a1 + 2.0); v11 is saved for the second format pass. [source:raw]
    // CALL: CRTFtol(v4) is evaluated twice into v5 and v6, truncating the float to integer for the first two-digit fields. [callee:0x00587BDC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", prefix, v5, v6) formats the prefix and two two-digit fields into the 128-byte buffer v10. [callee:0x0058815F, global:0x005D3BCC, source:raw]
    // CALL: ShortComputation_bde0(&dword_7CD204, v10, 0) submits the formatted text to the render context at dword_7CD204. [callee:0x0045BDE0, global:0x007CD204, source:raw]
    // CALCULATION: Second pass: v9 = CRTFtol(v11 * 0.016666668) derives whole minutes; v7 = CRTFtol(v11 - (double)v9 * 60.0) derives remaining seconds. [callee:0x00587BDC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", prefix, v9, v7) reformats the buffer with the recomputed minutes and seconds. [callee:0x0058815F, global:0x005D3BCC, source:raw]
    // RETURN: Returns TextLineWrappingAndRendering(&dword_7CD204, (int)v10, 3, 16909060), rendering the wrapped text line with literal arguments 3 and 16909060. [callee:0x0045BD10, global:0x007CD204, function:0x004D11D0, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) a2 = byte_5EA438;
    //   v11 = a1 + 1.0; v4 = v11 + 1.0;
    //   v5 = v6 = CRTFtol(v4);
    //   StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", a2, v5, v6);
    //   ShortComputation_bde0(&dword_7CD204, v10, 0);
    //   v9 = CRTFtol(v11 * 0.016666668); v7 = CRTFtol(v11 - (double)v9 * 60.0);
    //   StringFormatWithBufferOverflowCheck(v10, "%s%02d:%02d", a2, v9, v7);
    //   return TextLineWrappingAndRendering(&dword_7CD204, (int)v10, 3, 16909060);
    // UNRESOLVED: The globals flt_59E43C, flt_59E9C0 and flt_59F118 are listed in the packet as read globals but do not appear in the raw source text; their role in this function is unconfirmed.
    // UNRESOLVED: The first format pass writes both two-digit fields from the same truncated value of a1 + 2.0, producing a duplicated-field string; the intended display semantic of that pass is not confirmed.
    // UNRESOLVED: The literal arguments 3 and 16909060 to TextLineWrappingAndRendering are unexplained by the source; the +1.0/+2.0 adjustments to a1 are likewise not semantically confirmed.
    // UNRESOLVED: The interpretation of a2 as an optional path/prefix string and of dword_7CD204 as a render context is DERIVED from existing analysis; only the null-default to byte_5EA438 is confirmed from source.
}
