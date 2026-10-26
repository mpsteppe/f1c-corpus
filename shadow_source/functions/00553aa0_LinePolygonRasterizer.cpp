// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553AA0
// Canonical corpus name: sub_553AA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553AA0_00553aa0.c

void UnknownObject::LinePolygonRasterizer()
{
    // Bresenham-style line/polygon rasterizer. Selects a pixel-format conversion (RGB555, RGB565 or direct color) from a6[12], then chooses a 16-bit or 32-bit fill pipeline from a6[9]. Computes horizontal and vertical extents between two endpoints (a1,a2)-(a3,a4); zero-extent cases draw a single vertical or horizontal span, and diagonal cases run error-term driven fills through the selected fill functions with a per-row stride derived from a6[10].
    // CALCULATION: Read pixel-format selector v6 = a6[12] and cache v7 = a5. [source:raw]
    // GUARD: If v6 == 6 convert the packed color a5 to RGB555: v9 = ((a5 >> 3) & 0x1F) + ((a5 >> 5) & 0x7E0) + ((a5 >> 8) & 0xF800). [source:raw]
    // GUARD: Else if v6 == 5 convert a5 to RGB565: v9 = ((a5 >> 3) & 0x1F) + ((a5 >> 6) & 0x3E0) + ((a5 >> 9) & 0x7C00). [source:raw]
    // ASSIGNMENT: Otherwise v9 = a4: the caller-supplied color value is used directly. [source:raw]
    // CALL: Retrieve the destination surface v24 = ThunkWithArgReorder(a6, 0, 0). [callee:0x00543210]
    // GUARD: If a6[9] == 16 select the 16-bit fill pipeline. [source:raw]
    // ASSIGNMENT: 16-bit pipeline: v26 = ClampedPixelSpanFill, v25 = sub_553D00, v27 = F_16BitPixelRectangleFill, v29 = PixelFillWithStrideStepCalculation; per-row stride v10 = (int)a6[10] >> 1 and shift amount v11 = 1. [global:0x00553CD0, global:0x00553D00, global:0x00561970, global:0x005619AF]
    // ASSIGNMENT: 32-bit pipeline: v26 = sub_553D40, v25 = DrawRectangle, v27 = F_2DArrayFillWithStrideSupport, v29 = NestedLoopArrayFillWithStride; stride v10 = (int)a6[10] >> 2 and shift amount v11 = 2. [global:0x00553D40, global:0x00553D70, global:0x00561A41, global:0x00561A86]
    // CALCULATION: Horizontal extent v13 = abs32(a3 - a1). [source:raw]
    // GUARD: If v13 == 0 the endpoints share a column: draw a vertical span through v25 with the converted color and stride, then return ArgumentReorderWrapper_3230(a6, 0, 0). [global:0x00553D00, global:0x00553D70, callee:0x00543230]
    // CALCULATION: Vertical extent v14 = abs32(a4 - a2). [source:raw]
    // GUARD: If v14 == 0 the endpoints share a row: draw a horizontal span through v26 with the converted color and stride, then return ArgumentReorderWrapper_3230(a6, 0, 0). [global:0x00553CD0, global:0x00553D40, callee:0x00543230]
    // CALCULATION: Steep branch (v13 >= v14): compute error terms v15 = v14 << v11 and v16/v30 = (v14 - v13) << v11; pick the start pixel from (a1,a2) or (a3,a4) depending on the slope direction and optionally negate the stride v10. [source:raw]
    // CALL: Fill the steep diagonal line via v27 with the span parameters, run length, color and stride. [global:0x00561970, global:0x00561A41]
    // CALCULATION: Shallow branch (v13 < v14): compute error terms v18 = v13 << v11 and v28/v31 = (v13 - v14) << v11; choose the start pixel by comparing a2 against a4 and a3 against a1. [source:raw]
    // CALL: Fill the shallow diagonal line via v29 with span parameters, direction (2 * v20 - 1), stride and color. [global:0x005619AF, global:0x00561A86]
    // RETURN: Both diagonal paths finish by returning ArgumentReorderWrapper_3230(a6, 0, 0). [callee:0x00543230]

    // Conservative worker pseudocode:
    //   int sub_553AA0(int x0, int y0, int x1, int y1, int color, _DWORD *cfg) {
    //     int v9 = (cfg[12] == 6) ? (((color>>3)&0x1F) + ((color>>5)&0x7E0) + ((color>>8)&0xF800))
    //               : (cfg[12] == 5) ? (((color>>3)&0x1F) + ((color>>6)&0x3E0) + ((color>>9)&0x7C00)) : y1;
    //     int surf = ThunkWithArgReorder(cfg, 0, 0);
    //     if (cfg[9] == 16) { span = ClampedPixelSpanFill; diag = sub_553D00; rect = F_16BitPixelRectangleFill; run = PixelFillWithStrideStepCalculation; row = cfg[10] >> 1; sh = 1; }
    //     else { span = sub_553D40; diag = DrawRectangle; rect = F_2DArrayFillWithStrideSupport; run = NestedLoopArrayFillWithStride; row = cfg[10] >> 2; sh = 2; }
    //     int h = abs(x1 - x0), v = abs(y1 - y0);
    //     if (!h) { diag(x0, y0, y1, v9, row, surf); return ArgumentReorderWrapper_3230(cfg, 0, 0); }
    //     if (!v) { span(x0, x1, y0, v9, row, surf); return ArgumentReorderWrapper_3230(cfg, 0, 0); }
    //     if (h >= v) { int e = v << sh, d = (v - h) << sh; int start = (x0 <= x1 && y1 > y0) ? x0 + y0 * row : x3 + y3 * row; if (needs_neg) row = -row; rect(d, h + 1, e, d - h, row, start, color, surf); }
    //     else { int e = h << sh, d = (h - v) << sh; int start; int dir = ((y0 <= y1) ? (x1 > x0) : (x1 <= x0)) ? 1 : 0; run(d, v + 1, e, d, 2 * dir - 1, start, color, row, surf); }
    //     return ArgumentReorderWrapper_3230(cfg, 0, 0);
    //   }
    // UNRESOLVED: Semantics of cfg[9] and cfg[10] beyond the 16/32-bit dispatch and stride derivation are unknown.
    // UNRESOLVED: Identity of the surface object wrapped by ThunkWithArgReorder and ArgumentReorderWrapper_3230 is not established.
    // UNRESOLVED: Pixel format enums other than 6 and 5 fall through to a direct color path whose exact meaning depends on the surface format.
}
