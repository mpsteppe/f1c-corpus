// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B7A00
// Canonical corpus name: QueuePop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QueuePop_004b7a00.c

void UnknownObject::QueuePop()
{
    // Queue-pop processor on an int-array object. Runs a file-size query, drains a circular buffer into a result list via sub_4B7860 until it returns zero, then guards on the result entry count at this+0x720. If empty, zeros the two accumulators at this+0xF30 and this+0xF34 and returns 0. Otherwise reads the head node pointer this+0x714 and tail node pointer this+0x718 into the scratch pointer this+0x71C, storing the head node's first dword into this+0xF30 and the tail node's first dword into this+0xF34, then returns 0.
    // CALL: FileSizeQueryWithFallback(this + 441) queries the file size or initializes a fallback on the int array at offset 441 dwords. [callee:0x00566D70, source:raw]
    // LOOP: Repeatedly call sub_4B7860(this, 1) while it returns non-zero, draining the circular buffer into the result list. [callee:0x004B7860, source:raw]
    // GUARD: If this[456] (this+0x720, result list entry count) is <= 0, take the empty-result path. [field:this:0x00000720, guard:0, source:raw]
    // ASSIGNMENT: On the empty path, zero both accumulators this[972] (this+0xF30) and this[973] (this+0xF34). [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // ASSIGNMENT: Load head node pointer from this[453] (this+0x714) into scratch this[455] (this+0x71C). [field:this:0x00000714, field:this:0x0000071C, source:raw]
    // ASSIGNMENT: If the head node pointer is non-null, read its first dword and store it into this[972] (this+0xF30); on a null head pointer the dereference reads from address zero. [field:*(this+0x714):0x00000000, field:this:0x00000F30, source:raw]
    // ASSIGNMENT: Load tail node pointer from this[454] (this+0x718) into scratch this[455] (this+0x71C). [field:this:0x00000718, field:this:0x0000071C, source:raw]
    // ASSIGNMENT: If the tail node pointer is non-null, read its first dword and store it into this[973] (this+0xF34); on a null tail pointer the read comes from address zero. [field:*(this+0x718):0x00000000, field:this:0x00000F34, source:raw]
    // RETURN: Return 0 on the empty path and on the tail-extraction path; the null-tail branch also returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   char QueuePop(int* this) {
    //     FileSizeQueryWithFallback(this + 441);
    //     while (sub_4B7860(this, 1));
    //     if (this[456] <= 0) {
    //       this[972] = 0; this[973] = 0;
    //       return 0;
    //     }
    //     int** head = (int**)this[453]; this[455] = (int)head;
    //     this[972] = head ? **(int**)head : *((int*)0);
    //     int** tail = (int**)this[454]; this[455] = (int)tail;
    //     if (tail) { this[973] = **tail; return 0; }
    //     this[973] = *((int*)0);
    //     return 0;
    //   }
    // UNRESOLVED: The null-pointer branches dereference address zero in the raw source (MEMORY[0] / *(int*)0), which is a decompiler artifact; actual behavior when head/tail are null is unproven.
    // UNRESOLVED: Relationship between the circular buffer drained by sub_4B7860 and the head/tail result list is not proven here.
    // UNRESOLVED: Type and ownership of the int-array object (this) are unknown; owner retained as UnknownObject.
    // UNRESOLVED: Semantics of the accumulators at this+0xF30 and this+0xF34 are unknown beyond 'first and last result values'.
}
