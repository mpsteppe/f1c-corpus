// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583150
// Canonical corpus name: FlaggedDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlaggedDestructor_00583150.c

void UnknownObject::FlaggedDestructor()
{
    // Destruction dispatch on flag bits of a2. When bit 2 (0x2) is set the object is treated as placement-allocated with a prepended count header: NTimeCallbackLoopWithSEH walks the 40-byte callback entries using the header count at *(this - 1) and sub_57AEF0 as the per-entry callback, then optionally frees from the header pointer when bit 1 (0x1) is set, returning this - 1. When bit 2 is clear, sub_57AEF0 runs directly on the object, the object is optionally freed when bit 1 is set, and this is returned unchanged.
    // GUARD: Guard on a2 bit 2 (0x2): selects the placement-allocated header path (this - 1) versus the direct object path. [source:raw]
    // CALL: Placement path: NTimeCallbackLoopWithSEH(this, 40, *(this - 1), sub_57AEF0) processes all 40-byte entries in the prepended callback block, using the header count at *(this - 1) and sub_57AEF0 as the per-entry callback. [callee:0x0058A5F7, source:raw]
    // CALL: sub_57AEF0 invoked either per-entry on the placement path or directly on the object when the placement flag is clear. [callee:0x0057AEF0, global:0x0057AEF0, source:raw]
    // GUARD: Guard on a2 bit 1 (0x1): controls whether the memory is freed via FreeWrapper_7bcf on the header pointer (placement path) or on the direct object pointer. [source:raw]
    // CALL: FreeWrapper_7bcf frees the allocation, using this - 1 (header) on the placement path or this directly. [callee:0x00587BCF, source:raw]
    // RETURN: Returns this - 1 (header pointer) on the placement path, otherwise this. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* sub_583150(DWORD* this, char flags) {
    //     if ((flags & 2) != 0) {
    //       NTimeCallbackLoopWithSEH(this, 40, *(this - 1), sub_57AEF0);
    //       if ((flags & 1) != 0) FreeWrapper_7bcf(this - 1);
    //       return this - 1;
    //     } else {
    //       sub_57AEF0(this);
    //       if ((flags & 1) != 0) FreeWrapper_7bcf(this);
    //       return this;
    //     }
    //   }
    // UNRESOLVED: Identity and object type of `this` are unknown; the placement path treats this - 1 as a count header.
    // UNRESOLVED: The semantics of the 40-byte entry stride passed to NTimeCallbackLoopWithSEH are caller-defined.
    // UNRESOLVED: sub_57AEF0's exact role (per-entry destructor versus object teardown) depends on the block layout that is not described in this packet.
}
