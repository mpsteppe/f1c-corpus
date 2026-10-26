// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475D90
// Canonical corpus name: F_2DRectangleDrawingWithOutline
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DRectangleDrawingWithOutline_00475d90.c

void UnknownObject::CollisionDebugRectangleDraw()
{
    // Draws a 2D debug rectangle outline plus a collision-parameter visualization inside it. Reads the screen rectangle bounds via UtilityFunction_7160, normalizes min/max, draws the four edges, syncs collision config, then selects a collision parameter value from this[70] (a parameter selector) and renders either horizontal red bars or a center gauge line representing that value.
    // CALL: UtilityFunction_7160(0, &v24, &v22) and UtilityFunction_7160(1, &v23, &v21) fetch the screen rectangle bounds; if either fails the function returns 0 immediately. [callee:0x00487160, source:raw]
    // GUARD: Normalize the rectangle: swap x coords when v24 > v23 and swap y coords when v22 > v21 so (v24,v22) is the min corner and (v23,v21) the max corner. [source:raw]
    // CALL: GlobalAccessor_5150(&unk_7CDE00) fetches the render/draw context handle used by the line-drawing calls. [callee:0x00495150, global:0x007CDE00, source:raw]
    // CALL: FloatVectorWithConditionalTransform draws the four rectangle outline edges using the normalized corners with color 0. [callee:0x00494C20, source:raw]
    // CALL: CollisionConfigurationSync syncs the collision configuration before the parameter values are read for visualization. [callee:0x00475D30, source:raw]
    // GUARD: Read collision parameter selector this[70]; when nonzero, branch to the bar-drawing path, otherwise fall through to the center gauge path. [field:this:0x00000118, source:raw]
    // CALCULATION: Select the visualization double by selector value: flt_7CD45C for selector 1, flt_7CD2B0 for selector 2, flt_7CD610 for selector 3, and 0.0 otherwise. [global:0x007CD45C, global:0x007CD2B0, global:0x007CD610, source:raw]
    // CALL: CRTFtol converts the selected double into an integer used to size the horizontal bars. [callee:0x00587BDC, source:raw]
    // LOOP: Draw horizontal red bars (color 16711680) between the inner x bounds at each y step up to v21. [callee:0x00494C20, source:raw]
    // RETURN: Both the bar path and the failure path return 0. [source:raw]
    // CALCULATION: Center gauge column position computed as the midpoint of the x bounds: v10 = (v23 + v24) >> 1. [source:raw]
    // CALL: FloatVectorWithConditionalTransform draws the center gauge line (color 255) between the inner y bounds. [callee:0x00494C20, source:raw]
    // GUARD: flt_7CD458 sign branch chooses the gauge offset direction: negative grows the gauge leftward/upward, non-negative grows it rightward/downward. [global:0x007CD458, source:raw]
    // LOOP: Draw the gauge as vertical bars (color 16711680) between v11 and v12 across each y step up to v21. [callee:0x00494C20, source:raw]

    // Conservative worker pseudocode:
    //   int sub_475D90(int *this) {
    //     int x0, x1, y0, y1;
    //     if (!UtilityFunction_7160(0, &x0, &y0) || !UtilityFunction_7160(1, &x1, &y1)) return 0;
    //     if (x0 > x1) swap(x0, x1); if (y0 > y1) swap(y0, y1);
    //     void *rc = GlobalAccessor_5150(&unk_7CDE00);
    //     FloatVectorWithConditionalTransform(x0, y0, x0, y1-1, 0, rc);
    //     FloatVectorWithConditionalTransform(x0, y1, x1-1, y1, 0, rc);
    //     FloatVectorWithConditionalTransform(x1, y1, x1, y0+1, 0, rc);
    //     FloatVectorWithConditionalTransform(x1, y0, x0+1, y0, 0, rc);
    //     CollisionConfigurationSync();
    //     if (this[70]) {
    //       double v = pick(this[70]); // flt_7CD45C / flt_7CD2B0 / flt_7CD610 / 0.0
    //       int t = CRTFtol(v);
    //       for (int y = y1 - t; y < y1; ++y)
    //         FloatVectorWithConditionalTransform(x0+1, y, x1-1, y, 16711680, rc);
    //       return 0;
    //     }
    //     int cx = (x1 + x0) >> 1;
    //     FloatVectorWithConditionalTransform(cx, y0+1, cx, y1-1, 255, rc);
    //     int a, b;
    //     if (flt_7CD458 < 0.0) { a = cx-1; b = cx-1-CRTFtol((x0-(cx-1)+1)*flt_7CD458+0.5); }
    //     else { a = cx+1; b = cx+1+CRTFtol((x1-(cx+1)-1)*flt_7CD458+0.5); }
    //     for (int y = y0+1; y < y1; ++y)
    //       FloatVectorWithConditionalTransform(a, y, b, y, 16711680, rc);
    //     return 0;
    //   }
    // UNRESOLVED: glbals flt_59E440 and flt_59E450 are listed as referenced by this function in the deterministic facts but do not appear in the raw decompiled text; their role is unresolved.
    // UNRESOLVED: Semantic meaning of the selector values mapped to flt_7CD45C/flt_7CD2B0/flt_7CD610 (collision parameter sets) is inherited from existing analysis, not independently verified here.
}
