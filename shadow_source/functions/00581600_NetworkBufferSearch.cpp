// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581600
// Canonical corpus name: NetworkBufferSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkBufferSearch_00581600.c

void UnknownObject::NetworkBufferSearch()
{
    // Mutex-protected search of a singly linked list keyed by identifier: acquires the mutex at this+0xAD8, walks from the head at this+0xAC8, and locates the first node whose data field read via ReadFieldAtOffset0x14 equals a2. On match the node data is written through the output buffer at a3+4 via BufferWriteWithParams, a counter is incremented when flag a4 is set, and 1 is returned; otherwise 0 is returned. The mutex is released on every path.
    // ASSIGNMENT: Initialize the result flag v14 to 0 (not found). [source:raw]
    // GUARD: If the mutex handle at this+0xAD8 is null, skip the wait and fall through with the traversal base set to null. [field:this:0x00000AD8]
    // CALL: Wait on the mutex with the timeout stored at this+0xADC via WaitForSingleObject; proceed when the result is 0 or 0x80. [global:0x0059E1A0, field:this:0x00000ADC]
    // ASSIGNMENT: On successful wait, set the traversal base v7 to the head field this+0xAC8; on failure set v7 to null. [field:this:0x00000AC8]
    // GUARD: Guard on the head pointer at this+0xAC8 being null; an empty list skips the search. [guard:0, field:this:0x00000AC8]
    // ASSIGNMENT: Seed the walk cursor this+0xAD0 with the head pointer and read the head node's first DWORD (its data pointer) as v10. [field:this:0x00000AD0, field:*(this+0xAC8):0x00000000]
    // LOOP: Iterate nodes while ReadFieldAtOffset0x14(node data) differs from the search key a2; advance the cursor this+0xAD0 through each node's next pointer (offset +4). The element-count field this+0xAD4 is not consumed by this search path. [callee:0x005871F0, field:this:0x00000AD0, field:this:0x00000AD4]
    // CALL: On match, write the matched node data into the output buffer via BufferWriteWithParams(a3 + 4). [callee:0x00587620]
    // GUARD: When flag a4 is set, increment a counter via CounterIncrementDecrementByFlag(1). [callee:0x00587230]
    // ASSIGNMENT: Set the found flag v14 to 1 once a matching node is processed. [source:raw]
    // CALL: If the mutex handle at this+0xAD8 is non-null, release it via ReleaseMutex. [global:0x0059E1A4, field:this:0x00000AD8]
    // RETURN: Return v14: 1 when a matching node was found and its data written, 0 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_581600(int** this_, int key, int out, char count) {
    //     char found = 0;
    //     int** base = 0;
    //     if (this_[0xAD8/4] && WaitForSingleObject(this_[0xAD8/4], this_[0xADC/4]) in {0, 0x80})
    //       base = this_ + 0xAC8/4;
    //     if (base && *base) {
    //       this_[0xAD0/4] = *base;
    //       for (node = *base; node;) {
    //         int data = *node;
    //         if (ReadFieldAtOffset0x14(data) == key) {
    //           BufferWriteWithParams(out + 4);
    //           if (count) CounterIncrementDecrementByFlag(1);
    //           found = 1; break;
    //         }
    //         node = this_[0xAD0/4] = node[1];
    //       }
    //     }
    //     if (this_[0xAD8/4]) ReleaseMutex(this_[0xAD8/4]);
    //     return found;
    //   }
    // UNRESOLVED: The exact payload layout written to a3+4 by BufferWriteWithParams is caller-defined and not visible here.
    // UNRESOLVED: Semantic of the element-count field this+0xAD4 is inferred from surrounding bookkeeping; it is not read in this path.
    // UNRESOLVED: The node data structure passed to ReadFieldAtOffset0x14 is opaque; only its identifier field at offset 0x14 is compared.
}
