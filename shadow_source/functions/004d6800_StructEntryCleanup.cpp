// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D6800
// Canonical corpus name: StructEntryCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructEntryCleanup_004d6800.c

void UnknownObject::StructEntryCleanup()
{
    // Cleans up a struct entry: reinitializes the global string buffer byte_5EA438 via StringCopyWithBufferRealloc, zeros the DWORD fields at this+0x8, this+0xC and this+0x10, then conditionally frees the heap-allocated buffer pointer at this+0x14 via FreeWrapper_7bcf when it is non-null, zeroing it afterwards. Returns the result of the conditional free. Called by ArrayBlockCleanup for per-entry teardown.
    // CALL: Calls StringCopyWithBufferRealloc(byte_5EA438) to reinitialize the global string buffer before field teardown. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Loads the pointer at this[5] (this+0x14) into a local so the free decision can be made after the field clears. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zeros the DWORD at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zeros the DWORD at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zeros the DWORD at this+0x10. [field:this:0x00000010, source:raw]
    // GUARD: If the loaded pointer at this+0x14 is non-null, the heap buffer is freed and the field zeroed. [field:this:0x00000014, source:raw]
    // CALL: Frees the heap-allocated buffer via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Sets the pointer at this+0x14 to 0 after freeing. [field:this:0x00000014, source:raw]
    // RETURN: Returns the result of the conditional free (the previously-loaded pointer or NULL). [function:0x004D6800, source:raw]

    // Conservative worker pseudocode:
    //   void *StructEntryCleanup(DWORD *this) {
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     void *result = (void *)this[5];
    //     this[2] = 0;
    //     this[3] = 0;
    //     this[4] = 0;
    //     if (result) {
    //       result = FreeWrapper_7bcf(result);
    //       this[5] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The role of the global string buffer byte_5EA438 in the cleanup path is not evidenced.
    // UNRESOLVED: The struct owning this+0x8..0x14 and the meaning of the freed buffer at this+0x14 are unknown; the only recorded caller is ArrayBlockCleanup.
}
