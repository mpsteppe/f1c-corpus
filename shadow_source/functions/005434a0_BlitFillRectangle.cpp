// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005434A0
// Canonical corpus name: sub_5434A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5434A0_005434a0.c

void UnknownObject::BlitFillRectangle()
{
    // Fills a 2D rectangle on a surface. Reads integer width and height dimensions from this[7] (this+0x1C) and this[8] (this+0x20), converts them with CRTFtol, scales them by factors a4 and a5, validates/clamps the rectangle via sub_543540, and, when the clipped width and height are positive, calls F_2DSurfaceBlitFill with the global surface dword_8B78A0 and clears the 0x400 flag in the flags field this[6] (this+0x18).
    // CALCULATION: Read source rectangle dimensions: width from this[7] (this+0x1C) and height from this[8] (this+0x20), each taken as an integer value. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALCULATION: Convert both dimensions with CRTFtol, storing the width into v12 and the height into a2. [callee:0x00587BDC, source:raw]
    // CALCULATION: Apply scale factors: compute the scaled clipped width from width * a4 and the scaled clipped height from height * a5, each converted with CRTFtol. [callee:0x00587BDC, source:raw]
    // CALL: Call sub_543540 with the computed rectangle coordinates and dimensions to validate or clamp the fill rectangle. [callee:0x00543540]
    // GUARD: Skip the blit when the clipped width (a3) is not greater than zero. [source:raw]
    // GUARD: Skip the blit when the clipped height (a2) is not greater than zero. [source:raw]
    // CALL: Call F_2DSurfaceBlitFill(dword_8B78A0, this, x, y, clippedWidth, clippedHeight, a6) to fill the rectangle on the surface. [callee:0x005404D0, global:0x008B78A0, source:raw]
    // STATE_TRANSITION: Clear the 0x400 bit in the flags field this[6] (this+0x18) after the fill. [field:this:0x00000018, source:raw]
    // RETURN: Return the result of sub_543540, or of the blit fill when performed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5434A0(this, float scaleX, int clipWidth, float scaleY, float clipHeight, int a6) {
    //     int x = CRTFtol((double)this[7]);
    //     int y = CRTFtol((double)this[8]);
    //     clipWidth = CRTFtol((double)this[7] * scaleX);
    //     clipHeight = CRTFtol((double)this[8] * scaleY);
    //     int r = sub_543540(&x, &y, &clipWidth, &clipHeight);
    //     if (clipWidth > 0 && clipHeight > 0) {
    //       r = F_2DSurfaceBlitFill(dword_8B78A0, this, x, y, clipWidth, clipHeight, a6);
    //       this[6] &= ~0x400;
    //     }
    //     return r;
    //   }
    // UNRESOLVED: Object type of `this` and identity of the surface owner are unknown.
    // UNRESOLVED: Semantics of the a6 parameter passed through to F_2DSurfaceBlitFill are unknown.
    // UNRESOLVED: Meaning of the scale factors a4/a5 and how they are derived by callers is unresolved.
}
