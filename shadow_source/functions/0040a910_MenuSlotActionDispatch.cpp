// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040A910
// Canonical corpus name: MenuSlotActionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuSlotActionDispatch_0040a910.c

void UnknownObject::MenuSlotActionDispatch()
{
    // Matches a menu slot selection id a2 against stored slot entries and dispatches ViewCameraModeDispatch with the matching camera mode index (0-3 and 5-8 for the eight fixed slots, 4 for a variable-length array entry found by a stride-200 linear scan). Records the matched variable array index in this[15] and, when a3 is set, invokes a virtual update callback from vtable+16. Returns 1 after any successful dispatch, 0 otherwise.
    // GUARD: Returns 0 immediately when a2 (the slot id) is zero. [source:raw]
    // CALL: Slot 0: when a2 equals the dword stored at this[4], dispatches ViewCameraModeDispatch(this, 0, 1, 1). [callee:0x00409440, field:this:0x00000010, source:raw]
    // CALL: Slot 1: when a2 equals the dword stored at this[5], dispatches ViewCameraModeDispatch(this, 1, 1, 1). [callee:0x00409440, field:this:0x00000014, source:raw]
    // CALL: Slot 2: when a2 equals the dword stored at this[6], dispatches ViewCameraModeDispatch(this, 2, 1, 1). [callee:0x00409440, field:this:0x00000018, source:raw]
    // CALL: Slot 3: when a2 equals the dword stored at this[7], dispatches ViewCameraModeDispatch(this, 3, 1, 1). [callee:0x00409440, field:this:0x0000001C, source:raw]
    // CALL: Slot 5: when a2 equals the dword stored at this[9], dispatches ViewCameraModeDispatch(this, 5, 1, 1). [callee:0x00409440, field:this:0x00000024, source:raw]
    // CALL: Slot 6: when a2 equals the dword stored at this[10], dispatches ViewCameraModeDispatch(this, 6, 1, 1). [callee:0x00409440, field:this:0x00000028, source:raw]
    // CALL: Slot 7: when a2 equals the dword stored at this[11], dispatches ViewCameraModeDispatch(this, 7, 1, 1). [callee:0x00409440, field:this:0x0000002C, source:raw]
    // CALL: Slot 8: when a2 equals the dword stored at this[12], dispatches ViewCameraModeDispatch(this, 8, 1, 1). [callee:0x00409440, field:this:0x00000030, source:raw]
    // GUARD: Variable-slot branch: the entry count v5 is read from this[14]; when it is not positive the function returns 0 without dispatching. [field:this:0x00000038, source:raw]
    // LOOP: Scans the variable-length slot array starting at this[8] in 200-byte strides until the stored slot id equals a2 or the scan count passes this[14]; on a match it dispatches ViewCameraModeDispatch(this, 4, 1, 1) and records the matched index in this[15]. [field:this:0x00000020, field:this:0x0000003C, callee:0x00409440, source:raw]
    // CALL: When a3 is non-zero, invokes the virtual update callback stored at vtable+16 (the vtable read through this[0]) on this, then the function returns 1. [field:this:0x00000000, source:raw]
    // RETURN: Returns 1 after any successful dispatch; returns 0 for a zero slot id, an empty variable array, or a variable scan that exhausts the entry count without a match. [source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a2 == 0) return 0;
    //   if (a2 == this[4]) ViewCameraModeDispatch(this, 0, 1, 1);
    //   else if (a2 == this[5]) ViewCameraModeDispatch(this, 1, 1, 1);
    //   else if (a2 == this[6]) ViewCameraModeDispatch(this, 2, 1, 1);
    //   else if (a2 == this[7]) ViewCameraModeDispatch(this, 3, 1, 1);
    //   else if (a2 == this[9]) ViewCameraModeDispatch(this, 5, 1, 1);
    //   else if (a2 == this[10]) ViewCameraModeDispatch(this, 6, 1, 1);
    //   else if (a2 == this[11]) ViewCameraModeDispatch(this, 7, 1, 1);
    //   else if (a2 == this[12]) ViewCameraModeDispatch(this, 8, 1, 1);
    //   else { if (this[14] <= 0) return 0;
    //          for (i = this[8]; i != a2; i += 200) { if (++index >= this[14]) return 0; }
    //          ViewCameraModeDispatch(this, 4, 1, 1); this[15] = index; }
    //   if (a3) virtual_update_callback_at_vtable_plus_16(this);
    //   return 1;
    // UNRESOLVED: Sub-object field at +0x10 (vtable variable-check context per the existing analysis) is not directly dereferenced by this function; its role is unconfirmed.
    // UNRESOLVED: The meaning of the camera mode indices 0-8 and of the trailing (1, 1) dispatch arguments is caller-side semantics not resolved here.
}
