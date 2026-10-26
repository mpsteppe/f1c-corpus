// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486AC0
// Canonical corpus name: UIScrollViewRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScrollViewRender_00486ac0.c

void UnknownObject::RenderScrollView()
{
    // Renders a scrollable UI view. Handles the dirty-flag invalidation callback, resolves the current scroll-item node through a linked list, computes a visible rect that is clamped to the content-object limits, and dispatches either a scaled 2D quad render (F_2DScreenQuadRender with CRTFtol scale conversion) or a non-scaled forwarder path (F_10ParamForwarder plus a vtable draw). After drawing, it validates the computed bounds against a vtable query and, when the default texture source is active, blits the region onto the render surface via RenderSurfaceFillCopy (state 1) or DualDispatchWithGuard (states 2-3). Returns 0, or -1 early when the state query returns 0 and the alternate texture source is not active.
    // GUARD: Dirty-flag gate: when the byte at this+108 is non-zero, the invalidation handler runs and the flag is cleared. [field:this:0x0000006C, source:raw]
    // CALL: Dispatch the invalidation handler through vtable slot 160 (obj+0xA0) on this. [field:obj:0x000000A0, field:this:0x00000000, function:0x00486AC0, source:raw]
    // ASSIGNMENT: Clear the dirty-flag byte this+108 to zero after the handler runs. [field:this:0x0000006C, source:raw]
    // CALL: Fetch the default texture source: GlobalAccessor_5150(&unk_7CDE00); the result becomes the active texture source and the alternate-mode flag is cleared. [callee:0x00495150, global:0x007CDE00, source:raw]
    // GUARD: Scroll-mode check (guard 0): when the mode field equals 2, switch to the alternate GlobalGetter texture source and set the alternate-mode flag. The mode quantity is reached through this+64 (a1[16]) plus offset 56; the guard table attributes it to this+120. [guard:0, field:this:0x00000078, field:this:0x00000040, source:raw]
    // CALL: Alternate texture source: GlobalGetter(&unk_7CDE00) replaces the accessor result and the alternate-mode flag is raised. [callee:0x00495110, global:0x007CDE00, source:raw]
    // CALL: State query: sub_486830(this) returns a value (0-3) kept as the render-state selector. [callee:0x00486830, source:raw]
    // GUARD: Early-out: when the state query returns 0 and the alternate-mode flag is clear, return -1 immediately. [callee:0x00486830, field:this:0x00000078, source:raw]
    // GUARD: Clipping gate: the byte at this+101 (clip/active flag) decides whether the child-render body runs. [field:this:0x00000065, source:raw]
    // CALL: Dirtiness query through vtable slot 20 (obj+0x14); the result is remembered as v35. [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // CALL: When v35 is set, dispatch vtable slot 8 (obj+0x8) to write a rectangle into the out locals v46/v47/v48/v49. [field:obj:0x00000008, field:this:0x00000000, source:raw]
    // CALL: Dispatch vtable slot 12 (obj+0xC) forwarding the caller-supplied a4/a3/a2 arguments. [field:obj:0x0000000C, field:this:0x00000000, source:raw]
    // CALL: Resolve the scroll-item node: ConditionalDelegation_6460(this, index at this+132). [callee:0x00486460, field:this:0x00000084]
    // LOOP: Advance the node through its next-link pointer a number of steps given by this+136 (a1[34]); a null node terminates the walk. [field:this:0x00000088, source:raw]
    // CALCULATION: Compute the visible rectangle from the node geometry: item origin from node+0 and node+4, item width from node+8, and height as (node+12) minus (node+8). [source:raw]
    // CALCULATION: Read the texture-source coordinates this+4 and this+12 (a1[1], a1[3]) used as quad origin for the render calls. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALCULATION: Clamp the visible width and height against the content-object limits read at content+28 and content+32. [source:raw]
    // GUARD: Scale-corrected-path flag (byte 2 of a local, v38): when set, the corrected quad render runs; otherwise the non-scaled forwarder path runs. [source:raw]
    // CALL: Read global scale fields via GlobalFieldReader(&v50, &v51); these are the screen-scale factors flt_5A68E8 and flt_5A68EC. [callee:0x00495120, global:0x005A68E8, global:0x005A68EC]
    // CALCULATION: Derive pixel-scale factors: v47 = v50 * 0.00125 and v45 = v51 * 0.0016666667; coordinate conversions are truncated to integer via CRTFtol. [callee:0x00587BDC, source:raw]
    // CALL: Clip-transform setup: dispatch vtable slot 136 (obj+0x88) writing a set of out rect locals. [field:obj:0x00000088, field:this:0x00000000, source:raw]
    // CALL: Scaled path: F_2DScreenQuadRender renders the textured quad with the scale-corrected coordinates. [callee:0x00494A70, source:raw]
    // CALL: Non-scaled path: F_10ParamForwarder forwards ten quad parameters to the 2D renderer. [callee:0x00494A30, source:raw]
    // CALL: Dispatch vtable slot 16 (obj+0x10) to draw the quad with the computed rectangle; this slot is used for both the non-scaled draw and the expanded-bounds redraw. [field:obj:0x00000010, field:this:0x00000000, source:raw]
    // CALL: Query parent bounds via vtable slot 52 (obj+0x34) into out locals seeded with 600 and 800. [field:obj:0x00000034, field:this:0x00000000, source:raw]
    // GUARD: When the returned width and height both exceed their seeds, redraw the expanded bounds via vtable slot 16 (obj+0x10). [field:obj:0x00000010, source:raw]
    // CALL: Second vtable slot 8 (obj+0x8) dispatch that writes a single value into a local. [field:obj:0x00000008, field:this:0x00000000, source:raw]
    // CALL: Re-query dirtiness via vtable slot 20 (obj+0x14) to choose between clamped and raw clip coordinates. [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // CALCULATION: Select the final clip rectangle: clamp x to v46, y to v47, width to v48 and height to v49[0] when dirty; otherwise use the stored locals. [source:raw]
    // GUARD: Surface-blit gate: when the alternate-mode flag is clear (mode not 2), run the surface dispatch path. [field:this:0x00000078, source:raw]
    // CALL: Fetch the render surface handle via Accessor(); called once on each surface path (state 1 and states 2-3). [callee:0x00490920, source:raw]
    // CALL: State 1 path: RenderSurfaceFillCopy blits the computed region onto the surface. [callee:0x004918D0, callee:0x00486830, source:raw]
    // CALL: States 2-3 path: DualDispatchWithGuard performs the guarded dual-dispatch surface render. [callee:0x00491960, callee:0x00486830, source:raw]
    // CALL: End-of-render reset: dispatch vtable slot 44 (obj+0x2C) with a zero argument. [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return 0 on the normal path; -1 on the early-out state guard. [source:raw]

    // Conservative worker pseudocode:
    //   int RenderScrollView(int* this) {
    //     if (byte(this+108)) { vtable_slot160(this); byte(this+108) = 0; }
    //     v40 = GlobalAccessor_5150(&unk_7CDE00); alt = 0;
    //     if (mode_field == 2) { v40 = GlobalGetter(&unk_7CDE00); alt = 1; }
    //     state = sub_486830(this);
    //     if (state == 0 && !alt) return -1;
    //     if (byte(this+101)) {
    //       v35 = vtable_slot20(this);
    //       if (v35) vtable_slot8(this, &v46, &v47, &v48, v49);
    //       vtable_slot12(this, a4, a3, a2);
    //       node = ConditionalDelegation_6460(this, this+132);
    //       for (n = this+136; n; --n) if (node) node = node->next;
    //       if (node) {
    //         compute visible rect from node geometry; clamp to content limits;
    //         if (scaled) { GlobalFieldReader(&v50, &v51); scale; CRTFtol; vtable_slot136(this, out); F_2DScreenQuadRender(...); }
    //         else { F_10ParamForwarder(...); vtable_slot16(this, ...); }
    //         vtable_slot52(this, out seeded 600/800);
    //         if (w > seed && h > seed) vtable_slot16(this, expanded);
    //         vtable_slot8(this, &v40);
    //         if (v35) pick clamped rect per dirty query; else use locals;
    //         if (!alt) {
    //           Accessor();
    //           if (state == 1) RenderSurfaceFillCopy(x, y, w, h);
    //           else if (state == 2 || state == 3) { Accessor(); DualDispatchWithGuard(x, y, w, h); }
    //           vtable_slot44(this, 0);
    //         }
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The mode-field guard is ambiguous: raw C reaches the compared value through this+64 (a1[16]) plus offset 56, while the deterministic guard table attributes the == 2 test to this+120. Both refer to the scroll-mode quantity but the exact struct path is unresolved.
    // UNRESOLVED: The packet 'obj' offsets are interpreted as vtable dispatch slot numbers on this (slots 8/12/16/20/44/52/136/160, byte offsets 8/12/16/20/44/52/136/160). The scroll-item node reads at node+0/4/8/12 and its next-link pointer are separate offsets not represented in the packet field table.
    // UNRESOLVED: Purpose of the caller-supplied a2/a3/a4 (ebx/ebp/edi) forwarded to vtable slot 12 is unknown without caller context.
    // UNRESOLVED: The scale factors flt_5A68E8 / flt_5A68EC are recorded as read by the extractor but do not appear as direct operands in the rendered C; they are consumed around the GlobalFieldReader / CRTFtol conversion step.
    // UNRESOLVED: Semantics of callees ConditionalDelegation_6460, Accessor, RenderSurfaceFillCopy, DualDispatchWithGuard, F_10ParamForwarder and F_2DScreenQuadRender require their own packets to confirm.
    // UNRESOLVED: Origin of the locals backing v36/v37/v38/v49 used in the final clip selection is not visible in the C body; likely populated by the vtable slot 8 / slot 12 / slot 136 calls.
}
