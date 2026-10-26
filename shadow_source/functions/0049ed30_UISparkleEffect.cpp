// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ED30
// Canonical corpus name: UISparkleEffect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UISparkleEffect_0049ed30.c

void UnknownObject::UISparkleEffect()
{
    // Renders a 4-point sparkle/star graphic. Guards on the enabled flag at this+0x04. Reads the rotation mode (this+0x10) and current angle (this+0x14), steps the angle toward the target angle (this+0x18) by the speed ratio (this+0x1C)/(this+0x20), handling 360-degree wraparound. Converts the stepped angle to radians (v32 = angle * 0.01745433), computes the sparkle extent from this+0x44 and this+0x48, derives four vertex positions around the center (this+0x3C, this+0x40), and draws each vertex with sub_553650 using color-coded parameters, returning the last draw result.
    // GUARD: If the enabled flag at this+0x04 is zero, return zero immediately (render skipped). [field:this:0x00000004, source:raw]
    // CALCULATION: Clockwise mode (this+0x10 == 0): step the current angle this+0x14 toward the target this+0x18 by subtracting (this+0x1C)/(this+0x20) times the wrap-corrected angular delta, choosing the 360-degree complement based on the comparison flags. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALCULATION: Counterclockwise mode (this+0x10 == 1): step the current angle this+0x14 by adding (this+0x1C)/(this+0x20) times the wrap-corrected angular delta to the target this+0x18. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALCULATION: Convert the stepped angle to radians: v32 = angle * 0.01745433. [source:raw]
    // CALCULATION: Compute the sparkle extent: v30 = sqrt( (this+0x44 * (this+0x44/2)/2) + (this+0x48 * (this+0x48/2)/2) ), then the normalized ratio v13 = (this+0x44/2) / v30. [field:this:0x00000044, field:this:0x00000048, source:raw]
    // CALL: Convert the intermediate values with FloatConvertWrapper and CRTFtol, deriving four integer vertex positions around the center (this+0x3C, this+0x40) from the angle, the extent and sine/cosine of the radian value. [callee:0x00588570, callee:0x00587BDC, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // CALL: Draw the four sparkle vertices with sub_553650 (vertex indices 0..3, color-coded RGB parameters, final argument -1); return the last call's result. [callee:0x00553650, field:this:0x0000003C, field:this:0x00000040, source:raw]

    // Conservative worker pseudocode:
    //   int UISparkleEffect(int this) {
    //     if (*(DWORD*)(this + 0x04) == 0) return 0;
    //     int mode = *(DWORD*)(this + 0x10);
    //     float angle = *(float*)(this + 0x14);
    //     float step = *(float*)(this + 0x1C) / *(float*)(this + 0x20);
    //     if (mode == 1) {
    //       float d = (angle >= *(float*)(this + 0x18)) ? (*(float*)(this + 0x18) - angle)
    //                                                     : (360.0f - (angle - *(float*)(this + 0x18)));
    //       angle += step * d;
    //     } else if (mode == 0) {
    //       float d = (angle >= *(float*)(this + 0x18)) ? (360.0f - (*(float*)(this + 0x18) - angle))
    //                                                     : (angle - *(float*)(this + 0x18));
    //       angle -= step * d;
    //     }
    //     float rad = angle * 0.01745433f;
    //     float extent = sqrt((float)(*(DWORD*)(this + 0x44) * (*(DWORD*)(this + 0x44) / 2) / 2
    //                        + *(DWORD*)(this + 0x48) * (*(DWORD*)(this + 0x48) / 2) / 2));
    //     float ratio = (float)(*(DWORD*)(this + 0x44) / 2) / extent;
    //     FloatConvertWrapper();
    //     int cx = *(DWORD*)(this + 0x3C), cy = *(DWORD*)(this + 0x40);
    //     int p0 = CRTFtol(ratio), p1 = CRTFtol(ratio), p2 = CRTFtol(rad - ratio);
    //     int p3 = CRTFtol(sin(rad - ratio) * extent);
    //     sub_553650(0, p0 + cy, cy - p1, 1.0f, 0.0f, 0.0f, -1);
    //     sub_553650(1, cx + p3, cy - p2, 1.0f, 0.0f, 1.0f, -1);
    //     sub_553650(2, cx + p1, cy - p0, 1.0f, 1.0f, 1.0f, -1);
    //     return sub_553650(3, cx - p3, cy + p2, 1.0f, 1.0f, 0.0f, -1);
    //   }
    // UNRESOLVED: The globals flt_59E65C and flt_5ACB0C are recorded as referenced but do not appear in the decompiled body text; likely conversion constants consumed by the conversion helpers.
    // UNRESOLVED: The comparison flags that choose the 360-degree wraparound direction are implicit float-compare status flags from the decompiler; exact rounding semantics are unresolved.
    // UNRESOLVED: The exact drawing behavior of sub_553650 (quad vs line, color semantics of its parameters) is unresolved.
}
