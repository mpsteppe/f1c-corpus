// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD470
// Canonical corpus name: ArrayCleanupWithDestructorLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayCleanupWithDestructorLoop_004dd470.c

void UnknownObject::arrayCleanupWithDestructorLoop()
{
    // Cleanup helper: frees a single resource pointer at offset 8 through FreeWrapper_7bcf when non-null, then, when the array pointer at offset 16 is non-null, reads the element count from the allocation length header located 4 bytes before the array pointer, iterates backward through 24-byte elements calling ShortComputation_d4d0 on each (destructor), and finally frees the allocation (starting at the length header) via FreeWrapper_7bcf. Returns the single-free result when no array is present.
    // ASSIGNMENT: Read the single resource pointer stored at offset 8 [field:this:0x00000008, source:raw]
    // GUARD: Guard on the resource pointer at offset 8: when non-null, free it directly via FreeWrapper_7bcf [field:this:0x00000008, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Read the array pointer stored at offset 16 into v3 [field:this:0x00000010, source:raw]
    // GUARD: Guard on the array pointer at offset 16: when null, skip the destructor loop and array free, returning the resource-path result [field:this:0x00000010, source:raw]
    // CALCULATION: Read the element count v4 from the length header at v3 - 4 and compute the end cursor v8 = v3 + 8 * (3 * v4), i.e. v3 + 24 * v4 (24 bytes per element) [field:this:0x00000010, source:raw]
    // LOOP: Iterate backward from the end cursor over the 24-byte elements, calling ShortComputation_d4d0 on each (destructor), until all v4 elements are visited [callee:0x004DD4D0, field:this:0x00000010, source:raw]
    // CALL: Free the array allocation (base v5 = v3 - 4, the length header) via FreeWrapper_7bcf [callee:0x00587BCF, field:this:0x00000010, source:raw]
    // RETURN: Return the resource-path FreeWrapper_7bcf result on early exits; the array path returns the array free result [source:raw]
    // CALL: Invoked by sub_4E3360 (0x004E3360) as part of object teardown [caller:0x004E3360]

    // Conservative worker pseudocode:
    //   result = FreeWrapper_7bcf(this[8]) if this[8] != 0 else 0;
    //   v3 = this[16];
    //   if (v3 != 0) {
    //     v4 = *(v3 - 4);
    //     v8 = v3 + 8 * (3 * v4);
    //     for (v9 = v4; v9 > 0; --v9) {
    //       v8 -= 24;
    //       ShortComputation_d4d0(v8);
    //     }
    //     return FreeWrapper_7bcf(v3 - 4);
    //   }
    //   return result;
    // UNRESOLVED: The exact destructor contract of ShortComputation_d4d0 and what class it destroys is not documented here
    // UNRESOLVED: Relationship between the single resource pointer at offset 8 and the array at offset 16 is not established by this function
    // UNRESOLVED: The owning class of this cleanup method is not established (no RTTI or vtable evidence in the packet)
}
