// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1700
// Canonical corpus name: DoubleListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleListCleanup_004c1700.c

void UnknownObject::DoubleListCleanup()
{
    // Destructor-style cleanup for an object that holds two singly-linked lists. First pass walks the first list (head at this+0x0), freeing each node and, when the node's ownership flag at node+8 is set and its payload at node+0 is non-null, running PitStopMemoryCleanup on the payload before freeing it. The second pass walks the second list (head at this+0x10), freeing owned payloads with two ShortComputation_4370 calls and the nodes. A third pass re-walks the first list and calls sub_4C1E20(1) for each owned node with a payload. All list head/pointer words are zeroed afterwards.
    // ASSIGNMENT: Read the first list head pointer v2 = *this. [source:raw, field:this:0x00000000]
    // LOOP: First pass: iterate over the first list while the walk pointer is non-null, following the node next pointer at node+4. [source:raw, field:*(obj+0x4):0x00000004]
    // GUARD: Guard on the node ownership flag byte at node+8; only owned nodes have their payload released. [source:raw, field:obj:0x00000008]
    // GUARD: Guard that the node payload pointer at node+0 is non-null before touching it. [source:raw, field:obj:0x00000000]
    // CALL: Call PitStopMemoryCleanup on the owned payload pointer at node+0. [source:raw, callee:0x004C0B10, field:obj:0x00000000]
    // CALL: Call FreeWrapper_7bcf on the payload pointer to release the data block. [source:raw, callee:0x00587BCF]
    // CALL: Call FreeWrapper_7bcf on the node itself in every iteration regardless of ownership. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Zero the first list head and pointer words this[0] through this[3] (byte offsets 0x0, 0x4, 0x8, 0xC). [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // GUARD: Read the second list head this[4] (byte offset 0x10); the second pass runs only when it is non-null. [source:raw, field:this:0x00000010]
    // LOOP: Second pass: iterate over the second list following the node next pointer at node+4 until null. [source:raw, field:*(this+0x14):0x00000004]
    // GUARD: Guard on the node ownership flag byte at node+8 for second-list nodes. [source:raw, field:obj:0x00000008]
    // GUARD: Guard that the second-list node payload pointer at node+0 is non-null. [source:raw, field:obj:0x00000000]
    // CALL: Call ShortComputation_4370 on the payload pointer advanced by two dwords (payload element 2). [source:raw, callee:0x00414370]
    // CALL: Call ShortComputation_4370 on the payload base pointer. [source:raw, callee:0x00414370]
    // CALL: Call FreeWrapper_7bcf on the second-list payload to release the data block. [source:raw, callee:0x00587BCF]
    // CALL: Call FreeWrapper_7bcf on the second-list node in every iteration regardless of ownership. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Zero the second list pointer words this[4] through this[7] (byte offsets 0x10, 0x14, 0x18, 0x1C). [source:raw, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // LOOP: Third pass: re-walk the first list from *this following node next pointers at node+4. [source:raw, field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // GUARD: Guard combining ownership flag at node+8 and a non-null payload at node+0 for the third-pass sub_4C1E20 call. [source:raw, field:obj:0x00000008, field:obj:0x00000000]
    // CALL: Call sub_4C1E20(1) once for each first-list node that owns its data. [source:raw, callee:0x004C1E20]
    // CALL: Call FreeWrapper_7bcf on each third-pass node. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Zero the first list head and pointer words this[0] through this[3] a second time after the third pass. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return result; the loop-carried value is always reset to 0 so the function effectively returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int DoubleListCleanup(int* this) {
    //     int node;
    //     for (node = *this; node; node = *(int*)(node + 4)) {
    //       if (*(BYTE*)(node + 8) && *(void**)node) {
    //         PitStopMemoryCleanup(*(void**)node);
    //         FreeWrapper_7bcf(*(void**)node);
    //       }
    //       FreeWrapper_7bcf((void**)node);
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     for (node = this[4]; node; node = *(int*)(node + 4)) {
    //       if (*(BYTE*)(node + 8) && *(void**)node) {
    //         ShortComputation_4370(((int**)node)[2]);
    //         ShortComputation_4370(*(int**)node);
    //         FreeWrapper_7bcf(*(void**)node);
    //       }
    //       FreeWrapper_7bcf((void**)node);
    //     }
    //     this[4] = 0; this[5] = 0; this[6] = 0; this[7] = 0;
    //     for (node = *this; node; node = *(int*)(node + 4)) {
    //       if (*(BYTE*)(node + 8) && *(int*)node) sub_4C1E20(1);
    //       FreeWrapper_7bcf((void**)node);
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Callee UtilityFunction_1e40 (0x004C1E40) is recorded in the packet but absent from the raw source; its role is unknown.
    // UNRESOLVED: The object type owning the two linked lists (and what the payloads are) is unidentified; packet owner evidence is empty.
    // UNRESOLVED: Purpose of the sub_4C1E20(1) side-effect call in the third pass is unknown.
    // UNRESOLVED: Why the first list is re-walked a third time after both lists were already freed is unknown; the redundant passes may correspond to separate source-level cleanups.
    // UNRESOLVED: this[4..7] and this[0..3] are each zeroed twice in the raw source, consistent with two merged cleanup sites.
}
