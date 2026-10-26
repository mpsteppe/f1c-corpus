// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053FB80
// Canonical corpus name: sub_53FB80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53FB80_0053fb80.c

void UnknownObject::FlushDirtyResources()
{
    // Flush/validate four optional vtable-backed resource slots on an object passed as a2, each selected by a flag bit in the flags dword at a2+24. For every slot whose bit is set and whose pointer is non-null, the function calls the object's vtable slot 8 (at vtable+8). A nonzero return from any slot flush is treated as failure: the function reports the 'Invalid parameter' message through sub_53C590 and returns -1. On a zero return the flag bit is cleared. Slot a2+4 is additionally gated by bit 0x40000 and, when active, first drains through sub_53F6E0(this, *(a2+4)). Returns 0 when every active slot flushes cleanly.
    // GUARD: If flag bit 0x4 in the flags dword at a2+24 is set, the first resource slot at a2+16 is dirty and must be flushed. [source:raw]
    // GUARD: Only flush the a2+16 slot if its pointer is non-null; the load is the packet-local v3. [source:raw]
    // CALL: Invoke vtable slot 8 of the object at a2+16 (call target at *(*(a2+16))+8, first arg *(a2+16)). [source:raw]
    // GUARD: If the slot flush at a2+16 returns nonzero, take the failure branch (report invalid parameter and return -1). [source:raw]
    // ASSIGNMENT: On a zero return clear flag bit 0x4 at a2+24. [source:raw]
    // GUARD: Reload the flags dword (packet-local v4) and test: if bit 0x8 is set and the slot pointer at a2+20 is non-null, the second slot is dirty. [source:raw]
    // CALL: If bit 0x40000 is set and the pointer at a2+4 is non-null, drain it first via sub_53F6E0(this, *(a2+4)). [callee:0x0053F6E0, source:raw]
    // CALL: Invoke vtable slot 8 of the object at a2+20; a nonzero return takes the failure branch. [source:raw]
    // ASSIGNMENT: On a zero return clear flag bit 0x8 at a2+24. [source:raw]
    // GUARD: If flag bit 0x1 at a2+24 is set and the slot pointer at a2+8 is non-null, the third slot is dirty. [source:raw]
    // GUARD: Invoke vtable slot 8 of the object at a2+8: a zero return clears flag bit 0x1 and continues to the remaining bit-0x2 check; a nonzero return takes the failure branch. [source:raw]
    // ASSIGNMENT: Clear flag bit 0x1 at a2+24 after a successful flush of the a2+8 slot. [source:raw]
    // CALL: Failure path: report the 'Invalid parameter' message literal aInvalidParamet via sub_53C590(-1, aInvalidParamet). [callee:0x0053C590, global:0x005DBCD0]
    // RETURN: Return -1 on any slot-flush failure. [source:raw]
    // GUARD: If flag bit 0x2 at a2+24 is set and the slot pointer at a2+12 is non-null, the fourth slot is dirty. [source:raw]
    // CALL: Invoke vtable slot 8 of the object at a2+12; a nonzero return takes the failure branch. [source:raw]
    // ASSIGNMENT: On a zero return clear flag bit 0x2 at a2+24. [source:raw]
    // RETURN: Return 0 when every active slot flushed cleanly. [source:raw]
    // CALL: Called by sub_542E50 (0x00542E50), which passes the SoundManager global dword_8B78A0 as the first argument and this object as a2. [caller:0x00542E50]

    // Conservative worker pseudocode:
    //   int FlushDirtyResources(Unused* this, ResourceOwner* a2) {
    //     if (a2->flags & 0x4) {
    //       if (a2->slot_16) {
    //         if (vtable8(a2->slot_16)) goto fail;
    //         a2->flags &= ~0x4;
    //       }
    //     }
    //     if ((a2->flags & 0x8) && a2->slot_20) {
    //       if ((a2->flags & 0x40000) && a2->slot_4)
    //         sub_53F6E0(this, a2->slot_4);
    //       if (vtable8(a2->slot_20)) goto fail;
    //       a2->flags &= ~0x8;
    //     }
    //     if (a2->flags & 0x1) {
    //       if (a2->slot_8) {
    //         if (!vtable8(a2->slot_8))
    //           a2->flags &= ~0x1;
    //         else goto fail;
    //       }
    //     }
    //     if (a2->flags & 0x2) {
    //       if (a2->slot_12) {
    //         if (vtable8(a2->slot_12)) goto fail;
    //         a2->flags &= ~0x2;
    //       }
    //     }
    //     return 0;
    //   fail:
    //     sub_53C590(-1, "Invalid parameter");
    //     return -1;
    //   }
    // UNRESOLVED: The first parameter 'this' is never dereferenced in the body; its role (beyond forwarding to sub_53F6E0) is unknown.
    // UNRESOLVED: What vtable slot 8 performs on each slot object is unknown; only the zero-on-success / nonzero-on-failure contract is observable.
    // UNRESOLVED: The a2+4 slot is only drained by sub_53F6E0 and is not itself vtable-flushed; its relation to the bit-0x8 slot flush is unclear.
}
