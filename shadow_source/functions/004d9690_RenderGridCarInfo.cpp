// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9690
// Canonical corpus name: sub_4D9690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D9690_004d9690.c

void UnknownObject::RenderGridCarInfo()
{
    // Renders one starting-grid car's on-screen info for owner object 'this': a position-number character (built from this+0x4060 and base byte_5D4AE8), the driver name string (this+0x46F8), the team name string (this+0x46B8), and the qualifying time (this+0x405C) formatted as minutes/seconds '%.2d:%06.3f' via SpatialGridCell, or a placeholder string when the time is negative. Position display is guarded to grid rows 1-25. Returns 1 when 'this' is NULL, otherwise 0.
    // GUARD: When owner pointer a1 is NULL, return 1 immediately; rendering only proceeds for a non-null owner object. [source:raw, function:0x004D9690]
    // GUARD: Read grid start position from this+0x4060; compute v4 = (position - 1) and display the position number only when v4 <= 0x18, i.e. grid rows 1-25. [field:this:0x00004060, source:raw]
    // CALL: Build the one-character position label with StringFormatWithBufferOverflowCheck using '%c' format and character (v4 + base character byte_5D4AE8). [callee:0x0058815F, global:0x005D4AE8, global:0x005CCEF0, source:raw]
    // CALL: Render the position label with UITextRenderWithScale at (CRTFtol(a2), CRTFtol(a3)) using color 0xFFFFFF, alpha 0, type 3, scale 3.0 x 3.0. [callee:0x004D7E40, callee:0x00587BDC, source:raw]
    // CALL: Copy the driver-name string from byte offset 0x46F8 (18168) of 'this' into the label buffer via sub_587DD0 with max length 127, then reset the trailing byte and call sub_589901. [callee:0x00587DD0, callee:0x00589901, source:raw]
    // CALL: Render the driver name with UITextRenderWithScale at (CRTFtol(a2 + 110.0), CRTFtol(a3)) using color 0xFFFFFF, alpha 0, type 0, scale 1.0 x 1.0. [callee:0x004D7E40, callee:0x00587BDC, source:raw]
    // CALL: Copy the team-name string from byte offset 0x46B8 (18104) of 'this' into the label buffer via sub_587DD0 with max length 127, then reset the trailing byte and call sub_589901. [callee:0x00587DD0, callee:0x00589901, source:raw]
    // CALL: Render the team name with UITextRenderWithScale at (CRTFtol(a2 + 110.0), CRTFtol(a3 + 40.0)) using color 4762291, alpha 0, type 0, scale 1.0 x 1.0. [callee:0x004D7E40, callee:0x00587BDC, source:raw]
    // GUARD: Read qualifying time float from this+0x405C; when it is >= 0.0, split it into whole minutes and fractional seconds via SpatialGridCell and format the label with '%.2d:%06.3f' (a2d063f_2) through StringFormatWithBufferOverflowCheck; otherwise copy the placeholder string asc_5CCE18 via sub_587DD0. [field:this:0x0000405C, callee:0x0049B630, callee:0x0058815F, global:0x005D4B14, global:0x005CCE18, callee:0x00587DD0, source:raw]
    // CALL: Render the formatted time with UITextRenderWithScale at (CRTFtol(a2 + 110.0), CRTFtol(a3 + 80.0)) using color 16776960, alpha 0, type 0, scale 1.0 x 1.0. [callee:0x004D7E40, callee:0x00587BDC, source:raw]
    // RETURN: Return 0 on the success path after all lines are rendered. [source:raw]

    // Conservative worker pseudocode:
    //   int RenderGridCarInfo(int this, float a2, float a3) {
    //     if (!this) return 1;
    //     unsigned int v4 = *(unsigned int*)(this + 0x4060) - 1;
    //     if (v4 <= 0x18) {
    //       StringFormatWithBufferOverflowCheck(SrcStr, "%c", (char)(v4 + byte_5D4AE8));
    //       UITextRenderWithScale(SrcStr, CRTFtol(a2), CRTFtol(a3), 0xFFFFFF, 0, 3, 3.0f, 3.0f);
    //     }
    //     sub_587DD0(SrcStr, (char*)(this + 0x46F8), 127);
    //     sub_589901(SrcStr);
    //     UITextRenderWithScale(SrcStr, CRTFtol(a2 + 110.0f), CRTFtol(a3), 0xFFFFFF, 0, 0, 1.0f, 1.0f);
    //     sub_587DD0(SrcStr, (char*)(this + 0x46B8), 127);
    //     sub_589901(SrcStr);
    //     UITextRenderWithScale(SrcStr, CRTFtol(a2 + 110.0f), CRTFtol(a3 + 40.0f), 4762291, 0, 0, 1.0f, 1.0f);
    //     float t = *(float*)(this + 0x405C);
    //     if (t >= 0.0f) {
    //       int minutes = 0; float frac = 0.0f;
    //       SpatialGridCell(t, &minutes, &frac);
    //       StringFormatWithBufferOverflowCheck(SrcStr, "%.2d:%06.3f", minutes, frac);
    //     } else {
    //       sub_587DD0(SrcStr, asc_5CCE18, 127);
    //     }
    //     UITextRenderWithScale(SrcStr, CRTFtol(a2 + 110.0f), CRTFtol(a3 + 80.0f), 16776960, 0, 0, 1.0f, 1.0f);
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_59E440, flt_59E86C, flt_5ACB04, flt_5ACF60 and unk_7CE234 are listed by the packet as referenced but appear in the decompiled body only as address operands; their exact semantic role in this function is unconfirmed.
    // UNRESOLVED: The driver-name (this+0x46F8) and team-name (this+0x46B8) string buffers are read in the decompiled body but have no field evidence entries in this packet; those byte offsets are DERIVED from the raw source text only.
    // UNRESOLVED: sub_587DD0 followed by sub_589901 is treated as 'copy string into the 127-byte label buffer then finalize it'; the precise contract of the two helpers is inferred.
    // UNRESOLVED: CRTFtol's float-to-int transform (round vs truncate) is not evidenced in this packet.
}
