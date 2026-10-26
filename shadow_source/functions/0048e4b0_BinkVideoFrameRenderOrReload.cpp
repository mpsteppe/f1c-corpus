// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E4B0
// Canonical corpus name: sub_48E4B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48E4B0_0048e4b0.c

void UnknownObject::BinkVideoFrameRenderOrReload()
{
    // Per-object video (Bink) frame render / reload driver. Compares the loaded path string at this+0xFC against the reference path at this+0xB0 (both defaulting to byte_5EA438); when they differ it invokes the vtable method at offset 160 to reload and returns 0. Otherwise, when the Bink resource at this+0xE4 is present and the byte flag at this+0xF8 is set, it renders one video frame via BinkVideoFrameRender, on success clears the flag, blits the rendered surface through Accessor()/RenderSurfaceFillCopy, then signals content changed (vtable+44) and repaints (vtable+16) with the stored source rectangle.
    // ASSIGNMENT: Resolve both path strings: v6 = this[44] (field at this+0xB0) falling back to byte_5EA438; v7 = this[63] (field at this+0xFC) falling back to byte_5EA438. [field:this:0x000000B0, field:this:0x000000FC, global:0x005EA438]
    // GUARD: When sub_588410(v7, v6) is non-zero (path strings differ), the vtable method at offset 160 is invoked on this (reload path) and the function returns 0. [callee:0x00588410, field:obj:0x000000A0, field:this:0x00000000]
    // GUARD: Frame render only proceeds when this[57] (Bink resource at this+0xE4) is non-null and the byte flag at this+0xF8 is set. [field:this:0x000000E4, field:this:0x000000F8]
    // CALL: v9 = GlobalAccessor_5150(); BinkVideoFrameRender(this[57], v9, source X from this+0xE8, source Y from this+0xEC, 32) renders the next frame. [callee:0x00495150, callee:0x00551CF0, field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC]
    // CALL: On render success the byte flag at this+0xF8 is cleared, v10 = Accessor(), and RenderSurfaceFillCopy(v10, source X, source Y, width from this+0xF0, height from this+0xF4) blits the rendered surface. [field:this:0x000000F8, callee:0x00490920, callee:0x004918D0, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4]
    // CALL: After the render block the object is refreshed: vtable method at offset 44 is invoked with (this, 1) to signal a content change, and vtable method at offset 16 is invoked with (this, source Y, height, source X, width) to repaint. [field:obj:0x0000002C, field:obj:0x00000010, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000E8, field:this:0x000000F0]
    // RETURN: Returns 0 in both the reload and render paths. [source:raw]

    // Conservative worker pseudocode:
    //   v6 = this[44] ? this[44] : byte_5EA438;
    //   v7 = this[63] ? this[63] : byte_5EA438;
    //   if (sub_588410(v7, v6)) {
    //     vtable[160](this);
    //     return 0;
    //   }
    //   if (this[57] && this[62]) {
    //     if (BinkVideoFrameRender(this[57], GlobalAccessor_5150(), this[58], this[59], 32)) {
    //       this[62] = 0;
    //       RenderSurfaceFillCopy(Accessor(), this[58], this[59], this[60], this[61]);
    //     }
    //     vtable[44](this, 1);
    //     vtable[16](this, this[59], this[61], this[58], this[60]);
    //   }
    //   return 0;
    // UNRESOLVED: unk_7CDE00 is packet-listed as a read global but has no occurrence in the raw source text.
    // UNRESOLVED: BinkVideoFrameRender argument types are partially inferred (GlobalAccessor_5150 result and the literal 32 size argument).
    // UNRESOLVED: Exact role of the byte flag at this+0xF8 (render throttle) and the object's owner class are unknown.
    // UNRESOLVED: No static callers exist in the packet, so the reload/repaint trigger conditions are external.
}
