// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB460
// Canonical corpus name: DestructorWithConditionalFree_b460
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_b460_004bb460.c

void UnknownObject::destructorWithConditionalFree()
{
    // Secondary-data destructor: frees the allocation at this+0x4 through FreeWrapper_7bcf when it is non-null, then frees the object itself through the same wrapper when flag bit 0 of a2 is set. Returns this. Called by ModelSceneFileLoader (sub_4B6C90).
    // GUARD: Guard: pointer at this+0x4 is non-null; the secondary allocation is freed only when this holds. [field:this:0x00000004, source:raw]
    // CALL: Calls FreeWrapper_7bcf on the secondary data pointer at this+0x4 to release the allocation. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // GUARD: Guard: (a2 & 1) != 0; the object itself is freed only when bit 0 of a2 is set. [source:raw]
    // CALL: Calls FreeWrapper_7bcf on this, freeing the object itself when the flag bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Returns this to the caller. [function:0x004BB460, source:raw]

    // Conservative worker pseudocode:
    //   if (this->secondary) FreeWrapper_7bcf(this->secondary);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Body of FreeWrapper_7bcf is not in the packet; its deallocation semantics are inferred from the caller set, not evidenced here.
    // UNRESOLVED: Semantics of a2 bit 0 (object self-free) are caller-defined; the pattern is consistent with a C++ delete-flag destructor but is not proven.
    // UNRESOLVED: Field this+0x4 content type and the object's own class identity are unknown.
}
