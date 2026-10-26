// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477160
// Canonical corpus name: LinkedListTraversalVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListTraversalVirtualCall_00477160.c

void UnknownObject::IndexedListVirtualDispatch()
{
    // Resets state, then walks a linked list (head at this+0xF0) to the node at index this[92] guarded by the list count this+0xFC. For the selected node it requires the node and its data pointer (offset 0x30) to be non-null, runs a bounds/position check, and finally dispatches a virtual call at vtable offset 0x90 (144) on the node data sub-object. Returns 0 on any guard failure.
    // CALL: StateResetConditionalVirtualCall() runs unconditionally at entry to reset state with conditional virtual dispatch [callee:0x0048F300, source:raw]
    // ASSIGNMENT: v2 = this[92] (offset 0x170) reads the target list index [field:this:0x00000170, source:raw]
    // GUARD: Proceed only when v2 >= 0 and v2 < this[63] (offset 0xFC, the list count/upper bound) [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: v3 = this[60] (offset 0xF0) reads the linked-list head node pointer [field:this:0x000000F0, source:raw]
    // GUARD: When v2 <= 0, the head node is used directly (LABEL_6); otherwise traversal is required [source:raw]
    // LOOP: When v2 > 0, advance v3 = v3[1] (next-pointer field) while v3 is non-null, decrementing v2 until it reaches <= 0, then fall through to node selection [source:raw]
    // GUARD: Selected node v3 must be non-null and its data pointer *v3 (v4) must be non-null [source:raw]
    // CALL: BoundsCheckWithPositionQuery(this, *v3) validates the node data against a position/bounds query; a non-zero result is required [callee:0x004773A0, source:raw]
    // GUARD: v5 = *(_DWORD*)(v4 + 48), the data sub-object at offset 0x30 of the node data, must be non-null for the virtual dispatch [field:*(this+0xF0):0x00000030, field:*(*(this+0xF0)+0x30):0x00000000, source:raw]
    // CALL: Indirect virtual dispatch: call through v5's vtable at offset 0x90 (entry 144), thiscall with v5 [field:*(*(*(this+0xF0)+0x30)+0x0):0x00000090, source:raw]
    // RETURN: Return the virtual call result, or 0 on any guard failure [function:0x00477160, source:raw]

    // Conservative worker pseudocode:
    //   StateResetConditionalVirtualCall();
    //   v2 = this[92];
    //   if (v2 < 0 || v2 >= this[63]) return 0;
    //   v3 = this[60];
    //   if (v2 > 0) {
    //     while (v3) {
    //       v3 = (int*)v3[1];
    //       if (--v2 <= 0) break;
    //     }
    //   }
    //   if (v3 && *v3 && BoundsCheckWithPositionQuery(this, *v3)) {
    //     v5 = *(int*)(*v3 + 48);
    //     if (v5) return call_vtable(v5, +0x90);
    //   }
    //   return 0;
    // UNRESOLVED: this[62] (offset 0xF8) is flagged as read by packet facts but does not appear in the raw decompiled source; possibly a list cursor/state read eliminated by the compiler or consumed by a callee
    // UNRESOLVED: The dispatch target's interface (virtual at vtable+0x90) and the node data type are unknown
    // UNRESOLVED: The purpose of the position/bounds check relative to the dispatched virtual call is not documented
}
