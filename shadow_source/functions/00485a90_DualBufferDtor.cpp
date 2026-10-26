// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485A90
// Canonical corpus name: sub_485A90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_485A90_00485a90.c

void UnknownObject::DualBufferDtor()
{
    // Destructor for an object holding two buffer pointers (offsets 0x184 and 0x17C): frees each buffer if non-null, chains to DestructorWithFree for base-class sub-resource cleanup, then conditionally frees the object itself based on the flag argument a2. Returns the this pointer.
    // GUARD: If the buffer pointer at this+0x184 is non-null, free it via FreeWrapper_7bcf. [field:this:0x00000184, callee:0x00587BCF, source:raw]
    // GUARD: If the buffer pointer at this+0x17C is non-null, free it via FreeWrapper_7bcf. [field:this:0x0000017C, callee:0x00587BCF, source:raw]
    // CALL: Call DestructorWithFree(this) to chain into the base destructor that also frees sub-resources. [callee:0x00468610, source:raw]
    // GUARD: If (a2 & 1) is non-zero, free the object itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer. [function:0x00485A90, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID* sub_485A90(LPVOID* this, char a2) {
    //     if (this[97] != 0) FreeWrapper_7bcf(this[97]);
    //     if (this[95] != 0) FreeWrapper_7bcf(this[95]);
    //     DestructorWithFree(this);
    //     if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the two buffer pointers (offsets 0x17C, 0x184) and the owning class are unknown; only their conditional-free lifecycle is evidenced.
    // UNRESOLVED: Semantics of a2 bits beyond bit 0 (whether the low bit is the standard operator-delete flag) are not evidenced.
}
