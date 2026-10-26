// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004995E0
// Canonical corpus name: DestructorWithDataFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithDataFree_004995e0.c

void UnknownObject::DestructorWithDataFree()
{
    // Destructor helper: when the flag byte at offset 8 is set, captures the pointer at offset 0 and, if non-null, calls FreeIfNonNull on it and then frees the captured block via FreeWrapper_7bcf. When the caller flag bit (a2 & 1) is set, additionally frees the object itself via FreeWrapper_7bcf. Returns this. Invoked by sub_495300 (0x00495300); the packet prelabel identifies it as a structural twin of UtilityFunction (004081e0).
    // GUARD: Guard on the flag byte at offset 8: when zero, the inner data-cleanup path is skipped entirely. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Capture the pointer stored at offset 0 into v3. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the pointer at offset 0: when null, skip FreeIfNonNull and the FreeWrapper_7bcf of the captured block. [field:this:0x00000000, source:raw]
    // CALL: Call FreeIfNonNull on the pointer at offset 0 to release the object's resources. [callee:0x00499AE0, field:this:0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf on the captured block v3 to free its memory. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: Guard on the caller flag (a2 & 1): when bit 0 is set, the object itself is freed. [source:raw]
    // CALL: Call FreeWrapper_7bcf on this when the caller requests deletion of the object itself. [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]
    // CALL: Invoked by sub_495300 (0x00495300) as part of object teardown. [caller:0x00495300]

    // Conservative worker pseudocode:
    //   _DWORD *DestructorWithDataFree(_DWORD *this, char a2) {
    //       if (*(_BYTE *)this + 8) {
    //           void *v3 = *(void **)this;
    //           if (*this) {
    //               FreeIfNonNull(*this);
    //               FreeWrapper_7bcf(v3);
    //           }
    //       }
    //       if (a2 & 1)
    //           FreeWrapper_7bcf(this);
    //       return this;
    //   }
    // UNRESOLVED: The exact meaning of the flag byte at offset 8 (ownership/state marker) is not stated in the packet.
    // UNRESOLVED: The packet prelabel clusters this with 004081e0 as a structural twin, but the callee sets differ (FreeIfNonNull + FreeWrapper_7bcf here versus MultiStageCleanupWithFree + FreeWrapper there) and this function additionally implements the a2 bit-0 self-free; class identity is not established.
    // UNRESOLVED: The distinction between FreeIfNonNull and FreeWrapper_7bcf (a dedicated null-checking wrapper coexisting with a plain free wrapper) is not documented.
}
