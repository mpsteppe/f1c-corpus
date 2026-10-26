// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496E90
// Canonical corpus name: sub_496E90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_496E90_00496e90.c

void UnknownObject::updateDamageUi()
{
    // Updates the car crash-damage / repair UI state. First calls CarCrashDamageProcessing(this, a2) and returns 0 immediately when it reports active damage processing. Otherwise, when a damage-state pointer at this+24 (0x18) is set, it runs the render path: flushes the render surface (RenderSurfaceFillCopy, 800 by 600) when a draw-count gate triggers, then walks up to 8 chained damage nodes (linked through node[26]) invoking a vtable+8 coordinate getter and rendering each damage rectangle via sub_4919C0, then walks the remaining chain destroying nodes (CollisionProxyListBuilder, vtable+52 virtual, LinkedListNodeUnlinkByContent) and renders the damage sub-screen, text dialog and combo list. It manages a state step at this+56 (0x38) set to 1 then 2, and a UI timer float at this+68 (0x44) decremented by FloatFieldAccessor that drives a string-table lookup (BinarySearchInStringTable into byte_5EC4CC) and sub_4989E0 message processing. With no damage state it dispatches a no-draw-stack message via UIMessageDispatch and returns -1.
    // ASSIGNMENT: Set state step (this+56, offset 0x38) to 1 to enter the damage-processing/init state. [field:this:0x00000038, source:raw]
    // GUARD: Call CarCrashDamageProcessing(this, a2); if nonzero (damage processing active), skip to the early return 0. [callee:0x00496030, source:raw]
    // RETURN: Early return 0 when CarCrashDamageProcessing reports active damage processing. [callee:0x00496030, source:raw]
    // ASSIGNMENT: Load damage-state pointer v4 = *(this+24) (offset 0x18). [field:this:0x00000018, source:raw]
    // GUARD: If v4 (damage state at this+24) is nonzero, run the damage-render path; otherwise run the no-state cleanup path. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Store this+52 (offset 0x34) = sub_498E40(v4), the damage-state value derived from the node head. [field:this:0x00000034, callee:0x00498E40, field:this:0x00000018, source:raw]
    // GUARD: If dword_5CC9E8 != 5 (session state not in the expected value), bail out. [global:0x005CC9E8, source:raw]
    // RETURN: Return -1 when the session-state guard dword_5CC9E8 != 5 fails. [global:0x005CC9E8, source:raw]
    // GUARD: Trigger a redraw flush when ByteGetter0x25(this) is nonzero, or dword_7CE03C is set, or dword_5CC9E4 > 0. [callee:0x00497240, global:0x007CE03C, global:0x005CC9E4, source:raw]
    // CALCULATION: Saturating decrement of dword_5CC9E4 toward 0: (dword_5CC9E4 - 1) masked so the result never drops below 0. [global:0x005CC9E4, source:raw]
    // CALL: Fill the render surface black: v8 = Accessor(); RenderSurfaceFillCopy(v8, 0, 0, 800, 600). [callee:0x00490920, callee:0x004918D0, source:raw]
    // CALL: ShortComputation_7250(0) after the surface fill. [callee:0x00497250, source:raw]
    // GUARD: If the byte at this+36 (offset 0x24) is zero, run the render/cleanup block over the damage node chain. [field:this:0x00000024, source:raw]
    // CALL: v9 = Accessor(); SubListWalkDestruction(v9): walk and destroy sub-list nodes before rendering. [callee:0x00490920, callee:0x00491BD0, source:raw]
    // LOOP: Walk up to 8 primary damage nodes: v10 = *(this+24) (node head at offset 0x18); advance v10 = v10[26] (node next pointer at +0x68); stop when v10 becomes null or after 8 iterations. [field:this:0x00000018, field:*(this+0x18):0x00000068, source:raw]
    // GUARD: Inside the loop, break early when v10[26] (node next pointer at +0x68) is zero. [field:*(this+0x18):0x00000068, source:raw]
    // CALL: Virtual dispatch on node v10 through the vtable pointer at *(*(this+0x18)+0x0), slot offset 8: retrieves screen coordinates into locals v24/v23/v22 and a2. [field:*(this+0x18):0x00000000, field:*(*(this+0x18)+0x0):0x00000008, field:this:0x00000018, source:raw]
    // CALCULATION: Compute rectangle deltas from the returned coordinates: v21 = v23 - v24; v19 = a2 - v22; v18 = v24; v17 = v22. [source:raw]
    // CALL: v12 = Accessor(); sub_4919C0(v12, v17, v18, v19, v21): render the damage rectangle at the computed coordinates. [callee:0x00490920, callee:0x004919C0, source:raw]
    // LOOP: Second chain walk while v10: build collision proxy list (v13 = Accessor(); CollisionProxyListBuilder(v13)), invoke the virtual at vtable+52, advance v10 = v10[25], then unlink the current node (v14 = Accessor(); LinkedListNodeUnlinkByContent(v14)). [callee:0x00490920, callee:0x00491AD0, callee:0x00491A40, source:raw]
    // CALL: sub_495B60(this): damage sub-screen render. [callee:0x00495B60, source:raw]
    // CALL: UITextDialogRendering((char*)this): render the text dialog overlay. [callee:0x00495BD0, source:raw]
    // CALL: sub_4973D0(this): additional damage UI render. [callee:0x004973D0, source:raw]
    // CALL: UIComboListRender(this): render the combo list. [callee:0x00495580, source:raw]
    // STATE_TRANSITION: Set state step (this+56, offset 0x38) to 2: move to the render/process state. [field:this:0x00000038, source:raw]
    // GUARD: v15 = *(float*)(this+68) (offset 0x44, UI timer); if v15 > 0.0, process the timed message lookup. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: v16 = *(const char**)(this+60) (offset 0x3C); when v16 is null, fall back to the byte_5EA438 default string. [field:this:0x0000003C, global:0x005EA438, source:raw]
    // GUARD: If BinarySearchInStringTable(byte_5EC4C0, v16, byte_5EC4CC) returns nonzero (string matched), copy the message into the buffer. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: If v16 is nonzero, strcpy(byte_5EC4CC, v16); otherwise byte_5EC4CC[0] = 0 to reset the message buffer. [global:0x005EC4CC, source:raw]
    // CALL: sub_4989E0(byte_5EC4CC): process the buffered message string. [callee:0x004989E0, global:0x005EC4CC, source:raw]
    // CALCULATION: Decrement the UI timer: *(float*)(this+68) -= FloatFieldAccessor(this). [callee:0x00498730, field:this:0x00000044, source:raw]
    // CALL: SceneEntityCleanup(1) after rendering. [callee:0x00497100, source:raw]
    // ASSIGNMENT: Clear the byte at this+36 (offset 0x24) to 0 (render-disabled flag). [field:this:0x00000024, source:raw]
    // RETURN: Return 0 at the end of the damage-render path. [source:raw]
    // CALL: No-state path: v5 = GlobalAccessor_5150(); DelegationWrapper(v5, 0, 0, *(v5+28), *(v5+32), 656386). [callee:0x00495150, callee:0x00494BF0, source:raw]
    // GUARD: If strlen((const char*)(this+5740)) is nonzero (message buffer at this+5740 non-empty), dispatch a UI message. [source:raw]
    // CALL: v6 = GlobalAccessor_5150(); UIMessageDispatch(this+5740, aNoDrawStackAva, 0, 0, v6, 1): report no draw stack available. [callee:0x00495150, callee:0x00494F10, global:0x005CCA30, source:raw]
    // CALL: SceneEntityCleanup(v2): cleanup using the original short argument. [callee:0x00497100, source:raw]
    // RETURN: Return -1 from the no-state cleanup path. [source:raw]

    // Conservative worker pseudocode:
    //   int updateDamageUi(int this, __int16 a2) {
    //     this[0x38] = 1;
    //     if (CarCrashDamageProcessing(this, a2)) return 0;
    //     head = this[0x18];
    //     if (head) {
    //       this[0x34] = sub_498E40(head);
    //       if (dword_5CC9E8 != 5) return -1;
    //       if (ByteGetter0x25(this) || dword_7CE03C || dword_5CC9E4 > 0) {
    //         dword_5CC9E4 = saturating_decrement(dword_5CC9E4);
    //         RenderSurfaceFillCopy(Accessor(), 0, 0, 800, 600);
    //         ShortComputation_7250(0);
    //       }
    //       if (!this[0x24]) {
    //         SubListWalkDestruction(Accessor());
    //         node = this[0x18];
    //         for (i = 0; i < 8; ++i) {
    //           if (!node[26]) break;
    //           node->vtable[2](&v24, &v23, &v22, &a2);
    //           sub_4919C0(Accessor(), v22, v24, a2 - v22, v23 - v24);
    //           node = node[26];
    //         }
    //         while (node) {
    //           CollisionProxyListBuilder(Accessor());
    //           node->vtable[13]();
    //           node = node[25];
    //           LinkedListNodeUnlinkByContent(Accessor());
    //         }
    //         sub_495B60(this);
    //         UITextDialogRendering(this);
    //         sub_4973D0(this);
    //         UIComboListRender(this);
    //       }
    //       this[0x38] = 2;
    //       if (this[0x44] > 0.0) {
    //         msg = this[0x3C];
    //         if (!msg) msg = byte_5EA438;
    //         if (BinarySearchInStringTable(byte_5EC4C0, msg, byte_5EC4CC)) {
    //           if (msg) strcpy(byte_5EC4CC, msg);
    //           else byte_5EC4CC[0] = 0;
    //         }
    //         sub_4989E0(byte_5EC4CC);
    //         this[0x44] -= FloatFieldAccessor(this);
    //       }
    //       SceneEntityCleanup(1);
    //       this[0x24] = 0;
    //       return 0;
    //     }
    //     DelegationWrapper(GlobalAccessor_5150(), 0, 0, global[28], global[32], 656386);
    //     if (strlen(this + 5740)) {
    //       UIMessageDispatch(this + 5740, aNoDrawStackAva, 0, 0, GlobalAccessor_5150(), 1);
    //     }
    //     SceneEntityCleanup(a2);
    //     return -1;
    //   }
    // UNRESOLVED: The `this` object type is unknown; the packet owner is UnknownObject/UNKNOWN and no RTTI or constructor evidence was provided.
    // UNRESOLVED: Damage-node child field at *(*(this+0x18)+0x68)+0x34 is read per static facts but does not appear in the rendered Hex-Rays body.
    // UNRESOLVED: Damage-node fields at *(this+0x18)+0xD0 and *(this+0x18)+0x130 are read per static facts but do not appear in the rendered Hex-Rays body.
    // UNRESOLVED: flt_59E440 and unk_7CDE00 are referenced by static facts but not visible in the Hex-Rays body; purpose unresolved.
    // UNRESOLVED: Virtual dispatch targets at vtable+8 (coordinate getter) and vtable+52 (per-node cleanup) are not resolvable from the packet; the receiver node type is unknown.
    // UNRESOLVED: In the second chain walk the next-node pointer v10[25] (byte offset 100) has no packet field evidence ref; only v10[26] (offset 0x68) is listed.
    // UNRESOLVED: Callers sub_46BF10, sub_485B90, sub_4977E0 are known but no frame path was established (on_frame_path false).
}
