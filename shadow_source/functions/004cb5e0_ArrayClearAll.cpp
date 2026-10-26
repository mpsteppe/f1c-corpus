// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CB5E0
// Canonical corpus name: sub_4CB5E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CB5E0_004cb5e0.c

void UnknownObject::ArrayClearAll()
{
    // Clears a flat pointer array owned by the this object: loops while the element count at this+0x64 is positive, each iteration pops the last element (count-1), decrements the count, reads the element pointer from the array base at this+0x68 at index*4, passes the element handle (v5[0]) to sub_558B30 for release, and marks the element invalid by writing -1 to v5[1]. Returns the final count (0). Called by sub_4CD8D0, ArraySearchByIDWithCleanup (004CF010) and RepeatedCallLoop_f040 (004CF040).
    // LOOP: Iterate while the element count at this+0x64 is greater than 0; on exit the count has reached 0. [field:this:0x00000064, source:raw]
    // CALCULATION: Compute the last index as count-1 and decrement this+0x64 by 1 (pop from the back of the array). [field:this:0x00000064, source:raw]
    // CALCULATION: Read the popped element pointer from the array base at this+0x68 at offset index*4. [field:this:0x00000068, source:raw]
    // ASSIGNMENT: Read the element handle from v5[0] into v6, then write -1 to v5[1] to mark the element as invalid/free. [source:raw]
    // CALL: sub_558B30(v6) releases or deletes the resource associated with the popped element's handle. [callee:0x00558B30, source:raw]
    // RETURN: Return the final count (this+0x64, now 0); the function is invoked by sub_4CD8D0, ArraySearchByIDWithCleanup (004CF010) and RepeatedCallLoop_f040 (004CF040). [field:this:0x00000064, function:0x004CB5E0, caller:0x004CD8D0, caller:0x004CF010, caller:0x004CF040, source:raw]

    // Conservative worker pseudocode:
    //   int ArrayClearAll(void* this) {
    //     for (int count = this[25]; count > 0; count = this[25]) {
    //       int idx = count - 1;
    //       this[25] = idx;
    //       int* elem = *(int**)(this[26] + 4 * idx);
    //       int handle = *elem;
    //       elem[1] = -1;
    //       sub_558B30(handle);
    //     }
    //     return this[25];
    //   }
    // UNRESOLVED: The element structure layout (handle at v5[0], invalidation marker at v5[1]) is accessed by raw offsets and not defined in this function.
    // UNRESOLVED: Whether sub_558B30 deletes the element object or only releases a reference is not established by the packet.
}
