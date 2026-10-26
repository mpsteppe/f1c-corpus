// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516853
// Canonical corpus name: TwoIterationCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoIterationCleanup_00516853.c

void UnknownObject::TwoIterationCleanup()
{
    // Allocator-state cleanup: runs sub_516772 for category indices 1 then 0, frees the state base block at offset 0x4 via FreeWrapper_9351, clears that pointer to 0, and returns the result of EmptyStub_7b96.
    // LOOP: For i = 1 down to 0, call sub_516772(a1, i) to clean up each category's free list. [callee:0x00516772]
    // CALL: FreeWrapper_9351(a1, *(a1 + 4)) frees the allocator state base block referenced at offset 0x4. [callee:0x00519351, field:this:0x00000004]
    // ASSIGNMENT: Set *(a1 + 4) = 0 (clear the freed base pointer at offset 0x4). [field:this:0x00000004]
    // CALL: EmptyStub_7b96(a1) performs the final operation; its result becomes the function result. [callee:0x00587B96]
    // RETURN: Return the value produced by EmptyStub_7b96. [function:0x00516853]

    // Conservative worker pseudocode:
    //   for (i = 1; i >= 0; --i)
    //       sub_516772(a1, i);
    //   FreeWrapper_9351(a1, *(void**)(a1 + 4));
    //   *(DWORD*)(a1 + 4) = 0;
    //   return EmptyStub_7b96(a1);
    // UNRESOLVED: The meaning of the two category indices passed to sub_516772 is not evidenced.
    // UNRESOLVED: The owner object holding the base pointer at offset 0x4 is unknown.
}
