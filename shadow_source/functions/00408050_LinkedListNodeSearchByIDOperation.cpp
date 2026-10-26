// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408050
// Canonical corpus name: LinkedListNodeSearchByIDOperation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeSearchByIDOperation_00408050.c

void UnknownObject::LinkedListNodeSearchByIDOperation()
{
    // Searches a singly linked list for a node whose data's ID field (at offset 0x5C) equals a2. The list head is read from this+0x18 (this[6]) into the traversal cursor field this+0x20 (this[8]); each node stores its next pointer at +4 and its data object at +0. Returns 1 and runs ShortComputation_6a90 (0x00406A90) on the matched node, else returns 0. Called from MemoryAllocation_5160 (0x00405160) as an ID-based lookup path that outputs size/offset via a3/a4.
    // ASSIGNMENT: Initialize result to 0 (the no-match return value). [source:raw]
    // GUARD: If a2 is -1 (sentinel 'no id'), return 0 immediately without searching. [source:raw]
    // ASSIGNMENT: Read the linked-list head pointer from this[6] (offset 0x18) into the traversal cursor field this[8] (offset 0x20). [field:this:0x00000018, field:this:0x00000020, source:raw]
    // GUARD: If the head pointer is null, or the head's data object is null, return 0 (empty or degenerate list). [source:raw]
    // LOOP: While the ID field at offset 0x5C of the node data reached through the cursor at this+0x20 does not equal a2: advance the cursor to the next node via the next pointer stored at node+4, re-read its data object, and return 0 if the cursor ever becomes null. [field:*(this+0x20):0x0000005C, field:this:0x00000020, source:raw]
    // CALL: On a match, invoke ShortComputation_6a90 (0x00406A90) with the matched node data and the output parameters a3 and a4. [callee:0x00406A90, source:raw]
    // RETURN: Return 1 on a match (after the ShortComputation_6a90 call), otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   char LinkedListNodeSearchByIDOperation(void* this, int id, _DWORD* outSize, _DWORD* outOffset) {
    //     char result = 0;
    //     if (id != -1) {
    //       void** cursor = *(void***)((char*)this + 0x18);
    //       *(void***)((char*)this + 0x20) = cursor;
    //       if (cursor) {
    //         void* nodeData = *cursor;
    //         if (nodeData) {
    //           while (*(int*)((char*)nodeData + 0x5C) != id) {
    //             void** cur = *(void***)((char*)this + 0x20);
    //             if (cur) *(void***)((char*)this + 0x20) = *(void***)((char*)cur + 4);
    //             cursor = *(void***)((char*)this + 0x20);
    //             if (cursor) { nodeData = *cursor; continue; }
    //             return result;
    //           }
    //           ShortComputation_6a90(nodeData, outSize, outOffset);
    //           return 1;
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The ID field at offset 0x5C of the node data and the a2==-1 sentinel semantics are not independently confirmed.
    // UNRESOLVED: The meanings of the output parameters a3/a4 depend on ShortComputation_6a90 (0x00406A90), which is outside this packet.
    // UNRESOLVED: Field this+0x24 is listed in the packet but is not read by the raw source text.
    // UNRESOLVED: The exact record layout that the caller MemoryAllocation_5160 reads from a3/a4 is outside this function's evidence.
}
