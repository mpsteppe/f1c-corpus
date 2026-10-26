// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B370
// Canonical corpus name: F_2DTextRenderingWithScissorRectangle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DTextRenderingWithScissorRectangle_0049b370.c

void UnknownObject::F_2DTextRenderingWithScissorRectangle()
{
    // 2D text rendering bounded by a scissor rectangle. Computes the text size via sub_5531F0, scales it by the layout divisors at a4+92 and a4+96 with CRTFtol, and only renders when both scaled dimensions are positive. It then computes an anchored text region from the layout centers this+0x8/this+0xC, runs a six-call FloatToIntConversionChain batch (five against the constant -2002081110, one against -1999844148) over the shrinking layout array, and, when the UI flag dword_7CE23C[0] is set, draws a background widget through PositionComputationWithAlignment, TwoFieldSetterUpdate, FieldSetterCall_cf20 and ConditionalCall. Text is emitted via sub_553070 with a render-device global dword_8B8DC8 between FieldSetterAt0x48 save/restore of a4+72. When a6 and dword_7CE240 are set, a second widget draws a time-varied highlight color from RandomColorGenerator. Finally the caller-relative width cursor *a3 is advanced by the scaled height plus 8, which is also returned.
    // CALL: sub_5531F0 queried for the text dimensions (width and height) of a2 [callee:0x005531F0, source:raw]
    // CALCULATION: Scales the reported dimensions: v8 = CRTFtol(v16 * *(a4+92)) and v9 = CRTFtol(v15 * *(a4+96)) [callee:0x00587BDC, source:raw]
    // GUARD: Rendering block is entered only when both scaled dimensions are positive [source:raw]
    // CALCULATION: Computes the anchored text region: anchor X from this+0x8 minus half the scaled width, offset Y from this+0xC minus the cursor *a3, and fills the float layout scratch array [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Six-call FloatToIntConversionChain batch over the shrinking layout array: five calls against -2002081110 and a final call against -1999844148 [callee:0x00553A20, source:raw]
    // GUARD: Background widget drawn only when the UI flag dword_7CE23C[0] is set [global:0x007CE23C, source:raw]
    // CALL: Background widget emitted: PositionComputationWithAlignment at the anchor, TwoFieldSetterUpdate with the scaled size, FieldSetterCall_cf20 with 1728053247, and ConditionalCall with 0 [callee:0x004DCDD0, callee:0x004DCD80, callee:0x004DCF20, callee:0x004DCD60, source:raw]
    // CALCULATION: Reverses the scale for placement: v13 from v17 divided by *(a4+92) and the cursor from *a3 divided by *(a4+96), both via CRTFtol; saves v19 = *(a4+72) [callee:0x00587BDC, source:raw]
    // CALL: Text rendered by sub_553070 with the recomputed position and the render-device global dword_8B8DC8, bracketed by FieldSetterAt0x48(-1) before and FieldSetterAt0x48(v19) restore after [callee:0x00553070, callee:0x00552FC0, global:0x008B8DC8, source:raw]
    // GUARD: Highlight widget drawn only when both a6 and dword_7CE240 are set [global:0x007CE240, source:raw]
    // CALL: Highlight widget emitted with a time-varied color from RandomColorGenerator(0xFFFFFF, -1, 0.0): PositionComputationWithAlignment, TwoFieldSetterUpdate, FieldSetterCall_cf20 and ConditionalCall [callee:0x0049B200, callee:0x004DCDD0, callee:0x004DCD80, callee:0x004DCF20, callee:0x004DCD60, source:raw]
    // ASSIGNMENT: Advances the cursor *a3 by the scaled height plus 8 and returns that same value [source:raw]
    // CALL: Invoked by the UI render driver sub_49F870 [caller:0x0049F870, source:raw]

    // Conservative worker pseudocode:
    //   v16 = 0; v15 = 0;
    //   sub_5531F0(a2, &v16, &v15, 0);
    //   v8 = CRTFtol(v16 * *(float*)(a4 + 92));
    //   v9 = CRTFtol(v15 * *(float*)(a4 + 96));
    //   if (v8 > 0 && v9 > 0) {
    //     anchor_x = this[2] - v8 / 2;
    //     v17 = anchor_x;
    //     layout[0] = this[2];
    //     layout[1] = *a3 + v9 + 4;
    //     layout[3] = layout[0];
    //     layout[4] = (double)(this[3] - *a3) * 0.94999999 + (double)(*a3 + 4);
    //     FloatToIntConversionChain(layout, -2002081110);
    //     for (k = 1; k <= 5; ++k) {
    //       layout[0] = this[2] - k;
    //       FloatToIntConversionChain(layout, (k == 5) ? -1999844148 : -2002081110);
    //     }
    //     if (dword_7CE23C[0]) {
    //       PositionComputationWithAlignment(anchor_x - 4, *a3 - 4, 1, 0);
    //       TwoFieldSetterUpdate(v8 + 8, v9 + 8);
    //       FieldSetterCall_cf20(1728053247);
    //       ConditionalCall(0);
    //     }
    //     pos_x = CRTFtol(1.0 / *(float*)(a4 + 92) * v17);
    //     pos_y = CRTFtol(1.0 / *(float*)(a4 + 96) * *a3);
    //     saved = *(dword*)(a4 + 72);
    //     FieldSetterAt0x48(-1);
    //     sub_553070(a2, pos_x, pos_y, dword_8B8DC8);
    //     FieldSetterAt0x48(saved);
    //     if (a6 && dword_7CE240) {
    //       v14 = v9 + 8;
    //       color = RandomColorGenerator(0xFFFFFF, -1, 0.0);
    //       PositionComputationWithAlignment(anchor_x + v8 + 5, *a3 - 4, 1, 0);
    //       TwoFieldSetterUpdate(v14, v14);
    //       FieldSetterCall_cf20(color);
    //       ConditionalCall(0);
    //     }
    //     *a3 += v9 + 8;
    //     return v9 + 8;
    //   }
    //   return result;
    // UNRESOLVED: dbl_59E420 and flt_59EE8C appear in packet facts but nowhere in the raw decompiled source
    // UNRESOLVED: The exact role of the two FloatToIntConversionChain constants (-2002081110 and -1999844148) is unknown
    // UNRESOLVED: The layout descriptor a4 field at +72 and the FieldSetterAt0x48(-1) sentinel value have unknown meanings without the callee contracts
}
