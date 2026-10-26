// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004081E0
// Canonical corpus name: UtilityFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_004081e0.c

void UnknownObject::conditionalCleanupAndFree()
{
    // Conditional destructor helper: reads a flag byte at offset 8; when set, runs multi-stage cleanup on the object pointer at offset 0 and then frees it through FreeWrapper_7bcf. Returns the original flag byte value. Called by ComplexDestructorWith4LinkedLists (00406ba0).
    // ASSIGNMENT: Read flag byte at offset 8 into result [field:this:0x00000008, source:raw]
    // GUARD: Guard on the flag byte: when zero, return immediately without any cleanup [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Capture the object pointer stored at offset 0 into v2 [field:this:0x00000000, source:raw]
    // GUARD: Guard on the pointer at offset 0: when null, skip cleanup and free, returning the flag byte [field:this:0x00000000, source:raw]
    // CALL: Call MultiStageCleanupWithFree on the pointer read from offset 0 to release its resources [callee:0x00405410, field:this:0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf on the captured pointer v2 to free the memory block, returning its result [callee:0x00587BCF, source:raw]
    // RETURN: Return the flag byte value (original path) or the FreeWrapper_7bcf result (cleanup path) [source:raw]
    // CALL: Invoked by ComplexDestructorWith4LinkedLists (00406ba0) as part of object teardown [caller:0x00406BA0]

    // Conservative worker pseudocode:
    //   result = this[8];
    //   if (result != 0) {
    //     v2 = *(void **)this;
    //     if (*(_DWORD *)this != 0) {
    //       MultiStageCleanupWithFree(*(_DWORD **)this);
    //       return FreeWrapper_7bcf(v2);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The semantics of the flag byte at offset 8 and the exact cleanup contract of MultiStageCleanupWithFree are not documented in this function
}
