// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553D70
// Canonical corpus name: DrawRectangle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DrawRectangle_00553d70.c

void UnknownObject::DrawRectangle()
{
    // Fastcall raster primitive that fills a horizontal pixel run in a strided framebuffer. Normalizes the boundary arguments a2/a3 so a2 <= a3, then calls PixelFillWithStride at base offset a1 + a5 * a2 with count v6 - a2 + 1, pixel value a4, stride a5, and pass-through a6. Legacy ABI name Draw_Rectangle. Shape is a 1-pixel-tall horizontal line drawn at stride a5 starting from boundary a2.
    // ASSIGNMENT: Hold the a3 endpoint in v6 before normalization. [source:raw]
    // GUARD: If a2 > a3, swap: v6 = a2 and a2 = a3, so the run start a2 is the smaller boundary. [source:raw]
    // CALCULATION: Compute the destination base offset as a1 + a5 * a2 (start boundary a2 times stride a5). [source:raw]
    // CALCULATION: Compute the run length as v6 - a2 + 1 (inclusive pixel count between the boundaries). [source:raw]
    // CALL: Call PixelFillWithStride(a1 + a5 * a2, v6 - a2 + 1, a4, a5, a6) to fill the strided run. [callee:0x00561AF8, source:raw]
    // RETURN: Return the result of PixelFillWithStride. [source:raw]

    // Conservative worker pseudocode:
    //   int DrawRectangle(int a1, int a2, int a3, int a4, int a5, int a6) {
    //     int v6 = a3;
    //     if (a2 > a3) { v6 = a2; a2 = a3; }
    //     return PixelFillWithStride(a1 + a5 * a2, v6 - a2 + 1, a4, a5, a6);
    //   }
    // UNRESOLVED: Despite the name, the shape produced is a single horizontal run, not a filled rectangle; whether callers loop this over rows is not visible from the packet.
    // UNRESOLVED: Whether a1 is a framebuffer base address and a5 a per-pixel stride is inferred from the call shape only.
    // UNRESOLVED: Semantics of a4 and a6 depend on PixelFillWithStride's contract.
}
