// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F0B0
// Canonical corpus name: ShortComputation_f0b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_f0b0_0048f0b0.c

void UnknownObject::ClippedRenderBoundsForwarder()
{
    // Guarded render-bounds forwarder. Requires a nonzero second argument, a nonzero flag byte at this+0x17C (offset 380), and a nonzero pointer loaded from this+0xE4 (offset 228). It clips the requested source offset a3/a4 against the bounds stored at this+0x120 (offset 288) and this+0x140 (offset 320), clamps the source-rectangle width/height read from *(this+0xE4)+0x1C/+0x20 against this+0x124 (offset 292) and this+0x144 (offset 324), retrieves a global render value via GlobalAccessor_5150, and forwards the eight computed parameters to F_10ParamForwarder.
    // GUARD: Return immediately unless second argument a2 is nonzero. [source:raw]
    // GUARD: Return unless the flag byte at this+0x17C (offset 380) is nonzero. [field:this:0x0000017C]
    // GUARD: Return unless the pointer stored at this+0xE4 (offset 228) is nonzero. [field:this:0x000000E4]
    // ASSIGNMENT: Initialize the source x/y parameters from the arguments: v18 = a3, v19 = a4. [source:raw]
    // CALCULATION: Clip x: when a3 is below the bound at this+0x120 (offset 288), set x-offset v20 = bound - a3 and use the bound as the clipped source x; otherwise set x-offset v20 = 0. [field:this:0x00000120]
    // CALCULATION: Clip y: when a4 is at least the bound at this+0x140 (offset 320) minus 10, set y-offset v11 = 0; otherwise set v11 = bound - a4 and use the bound as the clipped source y. [field:this:0x00000140]
    // CALCULATION: Clamp source width: read source-rectangle x from *(this+0xE4)+0x1C; when it plus a3 exceeds this+0x124 (offset 292), clamp it to this+0x124 - a3. [field:*(this+0xE4):0x0000001C, field:this:0x00000124]
    // CALCULATION: Clamp source height: read source-rectangle width from *(this+0xE4)+0x20; keep it when it plus a4 fits within this+0x144 (offset 324) plus 10, otherwise reduce it to this+0x144 - a4. [field:*(this+0xE4):0x00000020, field:this:0x00000144]
    // CALL: Retrieve the global render value v16 from the global state at 0x007CDE00 via GlobalAccessor_5150. [callee:0x00495150, global:0x007CDE00]
    // CALL: Forward the computed clip parameters to F_10ParamForwarder(a2, v20, v11, v16, v18, v19, v12, v17, 0, 0) and return its result. [callee:0x00494A30]
    // RETURN: Return the forwarded result, or the blocking guard value when an early-return guard fired. [function:0x0048F0B0]

    // Conservative worker pseudocode:
    //   char ClippedRenderBoundsForwarder(int this, int a2, int a3, int a4) {
    //     if (a2 && *(char*)(this + 0x17C)) {
    //       int src = *(int*)(this + 0xE4);
    //       if (src) {
    //         int xoff, yoff, x = a3, y = a4;
    //         int mx = *(int*)(this + 0x120);
    //         if (a3 < mx) { xoff = mx - a3; x = mx; } else { xoff = 0; }
    //         int my = *(int*)(this + 0x140);
    //         if (a4 >= my - 10) { yoff = 0; } else { yoff = my - a4; y = my; }
    //         int w = *(int*)(src + 0x1C);
    //         int maxw = *(int*)(this + 0x124);
    //         if (w + a3 > maxw) w = maxw - a3;
    //         int hmax = *(int*)(this + 0x144);
    //         int h = *(int*)(src + 0x20);
    //         if (h + a4 > hmax + 10) h = hmax - a4;
    //         int g = GlobalAccessor_5150();
    //         return F_10ParamForwarder(a2, xoff, yoff, g, x, y, w, h, 0, 0);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantic identity of the flag byte at this+0x17C (offset 380) is not proven by this packet.
    // UNRESOLVED: Whether this+0x120 and this+0x140 represent scroll offsets or viewport maxima is not proven by this packet.
    // UNRESOLVED: Meaning of the constant 10 (margin) used in the y clip and height clamp is unexplained.
    // UNRESOLVED: Caller contract for the early-return value versus the forwarded F_10ParamForwarder result is unknown.
}
