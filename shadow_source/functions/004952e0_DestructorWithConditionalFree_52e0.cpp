// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004952E0
// Canonical corpus name: DestructorWithConditionalFree_52e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_52e0_004952e0.c

void UnknownObject::DestructorWithConditionalFree_52e0()
{
    // Destructor helper: runs object teardown via sub_495300, then conditionally frees the object memory when the delete flag a2 bit 0 is set (scalar-deleting-destructor pattern), and returns the object pointer.
    // CALL: Run object teardown/cleanup via sub_495300(this). [callee:0x00495300]
    // GUARD: Branch on (a2 & 1) != 0 before freeing; unconditional teardown runs first. [source:raw]
    // CALL: Free object memory via FreeWrapper_7bcf(this) when the delete flag bit 0 is set. [callee:0x00587BCF]
    // RETURN: Return the object pointer (this). [source:raw]

    // Conservative worker pseudocode:
    //   DestructorWithConditionalFree_52e0(this, a2) {
    //     sub_495300(this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: a2 flag semantics beyond bit 0 (delete) unknown.
    // UNRESOLVED: FreeWrapper_7bcf address lies in the low region of the image; identity as operator-delete wrapper is DERIVED from name, not independently proven.
    // UNRESOLVED: No static callers; on_frame_path=false.
}
