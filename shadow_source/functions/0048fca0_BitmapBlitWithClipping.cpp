// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FCA0
// Canonical corpus name: BitmapBlitWithClipping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapBlitWithClipping_0048fca0.c

void UnknownObject::BitmapBlitWithClipping()
{
    // Guarded bitmap blit with source/destination rectangle clipping for a UI rendering system. Requires the pointer this[14] (offset 0x38) to be nonzero and the source bitmap descriptor it resolves to (recorded base *(this+0x44)) to be nonzero. It clips the requested source offset a2/a3 against the destination bounds this[9] (offset 0x24) and this[7] (offset 0x1C), clamps the source width/height read from the descriptor at +0x1C/+0x20 against this[10] (offset 0x28) and this[8] (offset 0x20), retrieves a global render value via GlobalAccessor_5150, and forwards the eight computed parameters to F_10ParamForwarder.
    // GUARD: Return immediately unless this[14] (offset 0x38) is nonzero. [field:this:0x00000038]
    // GUARD: Load the source bitmap descriptor (recorded base *(this+0x44)) and return unless it is nonzero. [field:this:0x00000044]
    // ASSIGNMENT: Initialize the destination x/y parameters from the arguments: v17 = a2, v19 = a3. [source:raw]
    // CALCULATION: Clip x: when a2 is below this[9] (offset 0x24), set x-offset v20 = bound - a2 and use the bound as the clipped destination x; otherwise set x-offset v20 = 0. [field:this:0x00000024]
    // CALCULATION: Clip y: when a3 is at least this[7] (offset 0x1C), set y-offset v10 = 0; otherwise set v10 = bound - a3 and use the bound as the clipped destination y. [field:this:0x0000001C]
    // CALCULATION: Clamp source width: read source width from the descriptor at +0x1C; when it plus a2 exceeds this[10] (offset 0x28), clamp it to this[10] - a2. [field:*(this+0x44):0x0000001C, field:this:0x00000028]
    // CALCULATION: Clamp source height: read source height from the descriptor at +0x20; keep it when it plus a3 fits within this[8] (offset 0x20), otherwise reduce it to this[8] - a3. [field:*(this+0x44):0x00000020, field:this:0x00000020]
    // CALL: Retrieve the global render value v15 from the global state at 0x007CDE00 via GlobalAccessor_5150. [callee:0x00495150, global:0x007CDE00]
    // CALL: Forward the computed clip parameters to F_10ParamForwarder(v18, v20, v10, v15, v17, v19, v11, v16, 0, 0) and return its result. [callee:0x00494A30]
    // RETURN: Return the forwarded blit result, or the blocking guard value when an early-return guard fired. [function:0x0048FCA0]

    // Conservative worker pseudocode:
    //   int BitmapBlitWithClipping(int* this, int a2, int a3) {
    //     int src = this[14];
    //     if (src) {
    //       int* desc = *(int**)(this + 0x44);
    //       if (desc) {
    //         int xoff, yoff, x = a2, y = a3;
    //         int mx = this[9];
    //         if (a2 < mx) { xoff = mx - a2; x = mx; } else { xoff = 0; }
    //         int my = this[7];
    //         if (a3 >= my) { yoff = 0; } else { yoff = my - a3; y = my; }
    //         int w = *(int*)(desc + 0x1C);
    //         if (w + a2 > this[10]) w = this[10] - a2;
    //         int hmax = this[8];
    //         int h = *(int*)(desc + 0x20);
    //         if (h + a3 > hmax) h = hmax - a3;
    //         int g = GlobalAccessor_5150(&unk_7CDE00);
    //         return F_10ParamForwarder(desc, xoff, yoff, g, x, y, w, h, 0, 0);
    //       }
    //     }
    //     return src;
    //   }
    // UNRESOLVED: Relationship between this[14] (offset 0x38) and the *(this+0x44) descriptor base is extractor-inferred and not independently proven.
    // UNRESOLVED: Semantic roles of this+0x1C/0x20/0x24/0x28 clip boundaries (top/bottom/left/right ordering) are not proven by this packet.
    // UNRESOLVED: Meaning of the source bitmap descriptor's +0x1C/+0x20 fields as width/height is derived from usage, not proven.
    // UNRESOLVED: Caller contract for the early-return value versus the forwarded F_10ParamForwarder result is unknown.
}
