// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496930
// Canonical corpus name: UILargeRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UILargeRender_00496930.c

void UnknownObject::UILargeRender()
{
    // Per-frame UI render/dispatch handler. Sets a mode flag at this+0x28 to 2, gates the whole body on sub_496E20, then resolves the active UI element (this+0x156C) via collision classification, manages element and viewport lifecycle, dispatches per-element-type rendering through vtable calls plus string accessors and alpha-blend setters, copies a click/key event array from global word_7CB21C into this+0x159C, dispatches clicks via UIClickEventDispatch, and copies the viewport rectangle into a scratch rect. Returns 0. Called by sub_485B90.
    // CALL: Calls CollisionSpeedSetter() with no arguments as the first action of the frame handler [callee:0x00498720, source:raw]
    // GUARD: Mode flag: if this+0x28 (mode/state) is not 2, write 2 into it [field:this:0x00000028, guard:0, source:raw]
    // CALL: Gate: if sub_496E20(this) returns false, run the render body; otherwise skip to return [callee:0x00496E20, source:raw]
    // CALL: Calls InitViewportDimensions(this) to (re)compute viewport dimensions [callee:0x00498740, source:raw]
    // ASSIGNMENT: Caches this+0x5C, this+0x156C, this+0x18 and this+0x60 into locals (v2, v3, v4, v35) for later comparison [field:this:0x0000005C, field:this:0x0000156C, field:this:0x00000018, field:this:0x00000060, source:raw]
    // CALL: CollisionResponseTypeClassification(this) result stored into this+0x74; switch on that value zeroes this+0x156C for cases 1, 2, 4, 6 and 9 [callee:0x004987B0, field:this:0x00000074, field:this:0x0000156C, source:raw]
    // CALL: If this+0x156C is still zero, resolve the active element: this+0x156C = ObjectSearchWithDoubleIteration(this) [callee:0x00495980, field:this:0x0000156C, source:raw]
    // CALL: Element teardown: if the cached v3 differs from the resolved this+0x156C and v3 is non-null, call vtable slot 0x4C on v3 (destroy/release old element) [field:*(*(this+0x156C)+0x0):0x0000004C, field:*(this+0x156C):0x00000000, field:this:0x0000156C, source:raw]
    // CALL: Sub-element update: if cached v4 differs from this+0x18 and v4 is non-null, call vtable slot 0x3C on v4 passing (v4, v2, v35) [field:*(*(this+0x18)+0x0):0x0000003C, field:*(this+0x18):0x00000000, field:this:0x00000018, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // CALCULATION: Element fade transition: when the element changed, compute v6 = (this+0xCC) - 2*(this+0xC0), clamp to 0.0; otherwise v6 = this+0xC0 + this+0xCC; write v6 back to this+0xCC [field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000CC, field:this:0x000000D0, field:this:0x000000D4, source:raw]
    // GUARD: If this+0x74 == 1 and this+0x156C is non-null, call Setter(this+0x156C) [callee:0x004979C0, field:this:0x00000074, field:this:0x0000156C, guard:1, source:raw]
    // CALL: Case 1: call vtable slot 0x8C on the active element; if it returns false, get UIStringAccessor(this+0x156C), pass through sub_497E80 and RendererAlphaBlendSetter [callee:0x00486240, callee:0x00497E80, callee:0x00498030, field:*(*(this+0x156C)+0x0):0x0000008C, field:this:0x0000156C, source:raw]
    // GUARD: Case 2: if this+0x74 == 2 after case 1, call vtable slot 0x5C on the active element [field:*(*(this+0x156C)+0x0):0x0000005C, field:this:0x00000074, guard:2, source:raw]
    // CALL: Case 3: call vtable slot 0x90 on the active element; if false, run UIStringAccessor_6260 -> sub_497E80 -> RendererAlphaBlendSetter; when this+0xC4 > 0.2, resolve element again via ObjectSearchWithDoubleIteration and, if present and this+0x1560 non-null, call vtable slots 0x80/0x84 with string this+0x1558 (fallback byte_5EA438) and values this+0x1560/this+0x1564 [callee:0x00486260, callee:0x00497E80, callee:0x00498030, callee:0x00495980, field:*(*(this+0x156C)+0x0):0x00000090, field:this:0x000000C4, field:this:0x00001558, field:this:0x00001560, field:this:0x00001564, global:0x005EA438, source:raw]
    // CALL: Case 4: call vtable slot 0x38 on this+0x18 element when it changed; call vtable slot 0x48 on the active element to test visibility; if it reports visible, run UIStringAccessor_6280 -> sub_497E80 -> RendererAlphaBlendSetter [callee:0x00486280, callee:0x00497E80, callee:0x00498030, field:*(*(this+0x18)+0x0):0x00000038, field:*(*(this+0x156C)+0x0):0x00000048, field:this:0x00000018, field:this:0x0000156C, source:raw]
    // CALL: Case 5/8: when this+0xC4 == 0.0 call vtable slot 0x50; call vtable slot 0x94 on the active element; then UIStringAccessor_62a0 -> sub_497E80 -> RendererAlphaBlendSetter [callee:0x004862A0, callee:0x00497E80, callee:0x00498030, field:*(*(this+0x156C)+0x0):0x00000050, field:*(*(this+0x156C)+0x0):0x00000094, field:this:0x000000C4, field:this:0x0000156C, source:raw]
    // CALL: Case 6: call vtable slot 0x60 on the active element; if false, run UIStringAccessor -> sub_497E80 -> RendererAlphaBlendSetter; when this+0x74 == 2 also call vtable slot 0x5C (LABEL_30) [callee:0x00486240, callee:0x00497E80, callee:0x00498030, field:*(*(this+0x156C)+0x0):0x00000060, field:*(*(this+0x156C)+0x0):0x0000005C, field:this:0x00000074, source:raw]
    // CALL: Case 7: call vtable slot 0x64 on the active element; if false, run UIStringAccessor_6260 -> sub_497E80 -> RendererAlphaBlendSetter; when this+0xC4 > 0.2 repeat the object-search slot 0x80/0x84 string dispatch, then LABEL_48 calls RenderStateReset(this) [callee:0x00486260, callee:0x00497E80, callee:0x00498030, callee:0x00495980, callee:0x004986A0, field:*(*(this+0x156C)+0x0):0x00000064, field:this:0x000000C4, field:this:0x00001558, field:this:0x00001560, field:this:0x00001564, global:0x005EA438, source:raw]
    // CALL: Cases 0xC and 0xD: call vtable slots 0x78 and 0x7C respectively on the active element [field:*(*(this+0x156C)+0x0):0x00000078, field:*(*(this+0x156C)+0x0):0x0000007C, field:this:0x0000156C, source:raw]
    // ASSIGNMENT: Reset event counter: this+0x1598 = 0 before copying the event array [field:this:0x00001598, source:raw]
    // LOOP: If global dword_7CB218 > 0, copy word_7CB21C[this+0x1598] into *(WORD*)(this + 2*this+0x1598 + 5532), incrementing this+0x1598 until it reaches dword_7CB218 [field:this:0x00001598, global:0x007CB218, global:0x007CB21C, source:raw]
    // GUARD: If this+0x20 is non-null and this+0x1598 > 0, call vtable slot 0x58 on this+0x20 passing the event buffer this+0x159C and count this+0x1598; store result as the click flag [field:*(*(this+0x20)+0x0):0x00000058, field:*(this+0x20):0x00000000, field:this:0x00000020, field:this:0x00001598, guard:4, source:raw]
    // CALL: UIClickEventDispatch(this, this+0x1598, this+0x159C, click-flag) dispatches collected input events [callee:0x004957A0, field:this:0x00001598, source:raw]
    // CALL: If global dword_5CC9E8 == 5, call sub_496880(this) [callee:0x00496880, global:0x005CC9E8, source:raw]
    // ASSIGNMENT: Fade accumulator: if this+0x74 == 5 then this+0xC4 = this+0xC0 + this+0xC4, else this+0xC4 = 0 [field:this:0x000000C0, field:this:0x000000C4, field:this:0x00000074, guard:3, source:raw]
    // CALL: FPSOverlayDraw(this) renders the FPS overlay [callee:0x00495440, source:raw]
    // ASSIGNMENT: Copy viewport rect into scratch rect: this+0x78=this+0x58, this+0x7C=this+0x5C, this+0x80=this+0x60, this+0x84=this+0x64, this+0x88=this+0x68, this+0x8C=this+0x6C, this+0x94=this+0x74 [field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000094, source:raw]
    // RETURN: Return 0 unconditionally [function:0x00496930, source:raw]
    // CALL: Invoked by sub_485B90 as part of the UI frame dispatch path [caller:0x00485B90, source:raw]

    // Conservative worker pseudocode:
    //   CollisionSpeedSetter();
    //   if (this+0x28 != 2) this+0x28 = 2;
    //   if (sub_496E20(this)) return 0;
    //   InitViewportDimensions(this);
    //   v2 = this+0x5C; v3 = this+0x156C; v4 = this+0x18; v35 = this+0x60;
    //   this+0x74 = CollisionResponseTypeClassification(this);
    //   switch (this+0x74) { case 1: case 2: case 4: case 6: case 9: this+0x156C = 0; }
    //   if (this+0x156C == 0) this+0x156C = ObjectSearchWithDoubleIteration(this);
    //   if (v3 != this+0x156C && v3) vtable(v3)[0x4C](v3);
    //   if (v4 != this+0x18 && v4) vtable(v4)[0x3C](v4, v2, v35);
    //   if (v3 && v3 == this+0x156C) { if (this+0xD4 + this+0xD0 <= this+0xCC) goto label21; v6 = this+0xC0 + this+0xCC; }
    //   else { v6 = this+0xCC - (this+0xC0 + this+0xC0); if (v6 < 0.0) v6 = 0.0; }
    //   this+0xCC = v6;
    //   label21: if (this+0x74 == 1 && this+0x156C) Setter(this+0x156C);
    //   // switch (this+0x74) dispatches element vtable slots 0x8C/0x90/0x48/0x50/0x60/0x64/0x78/0x7C/0x94 per type,
    //   // with UIStringAccessor* -> sub_497E80 -> RendererAlphaBlendSetter chains
    //   this+0x1598 = 0;
    //   if (dword_7CB218 > 0) do { *(WORD*)(this + 2*this+0x1598 + 5532) = word_7CB21C[this+0x1598]; } while (++this+0x1598 < dword_7CB218);
    //   if (this+0x20 && this+0x1598 > 0) vtable(this+0x20)[0x58](this+0x20, this+0x159C, this+0x1598);
    //   UIClickEventDispatch(this, this+0x1598, this+0x159C, flag);
    //   if (dword_5CC9E8 == 5) sub_496880(this);
    //   if (this+0x74 == 5) this+0xC4 = this+0xC0 + this+0xC4; else this+0xC4 = 0;
    //   FPSOverlayDraw(this);
    //   this+0x78 = this+0x58; this+0x7C = this+0x5C; this+0x80 = this+0x60; this+0x84 = this+0x64;
    //   this+0x88 = this+0x68; this+0x8C = this+0x6C; this+0x94 = this+0x74;
    //   return 0;
    // UNRESOLVED: Five read-only globals are flagged by packet facts but do not appear in the raw decompiled source: flt_59E440 and flt_5AC994 (float constants, possibly timing thresholds), and the switch-related tables jpt_49698B, jpt_496A74, byte_496DE0 used by the this+0x74 dispatch switch
    // UNRESOLVED: The destination buffer at this+5532 (event array base) is not itself in the packet field list; it is implied by the loop that writes word_7CB21C entries
    // UNRESOLVED: Vtable slots 0x80/0x84 on the element-object returned by ObjectSearchWithDoubleIteration are called but not present in the packet field list
    // UNRESOLVED: The meaning of the this+0x74 enum values (1,2,3,4,5,6,7,8,0xC,0xD) is inferred from dispatch behavior only
}
