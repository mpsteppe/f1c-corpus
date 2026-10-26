// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005454D0
// Canonical corpus name: DrawableObjectNodeManager
// Owner: DrawableObjectNodeManager [DERIVED]
// Raw source: functions/DrawableObjectNodeManager_005454d0.c

void DrawableObjectNodeManager::AppendDrawableNodeAndRebuildArray()
{
    // Appends drawable object node a2 to the category-selected singly-linked list (walking to the tail via next pointers at node+0x6C), increments the selected category counter, sets the total count this+0x60 to the sum of the category-4 counter (this+0x124) and category-2 counter (this+0x12C), then rebuilds the flat 56-byte-slot array: frees the old array (running per-entry cleanup on each slot), allocates count*56+4 bytes via the operator-new wrapper, stores the count in the 4-byte header, zero-initializes each slot, and stores the array pointer in this+0x138.
    // STATE_TRANSITION: Switch on a3: 1/2/4 select the (counter, head) pointer pairs this+71/this+72, this+75/this+76 or this+73/this+74; the default case selects a2 itself and skips list management. [source:raw]
    // GUARD: Read the selected list head; branch on whether the list is non-empty. [field:this:0x00000128, source:raw]
    // LOOP: Walk the singly-linked list to its tail by following the next pointers stored at node+0x6C. [field:*(this+0x128):0x0000006C]
    // ASSIGNMENT: Append to a non-empty list: set the tail's next pointer (tail+0x6C) to a2 and store the tail back-pointer in a2+0x68. [field:*(*(*(this+0x128)+0x6C)+0x6C):0x0000006C, source:raw]
    // ASSIGNMENT: Append to an empty list: store a2 as the new head and clear the a2 back-pointer at a2+0x68. [field:this:0x00000128, source:raw]
    // ASSIGNMENT: Increment the selected category counter and clear a2's next pointer at a2+0x6C. [source:raw]
    // CALCULATION: Set the total count at this+0x60 to the category-4 counter (this+0x124) plus the category-2 counter (this+0x12C). [field:this:0x00000060, field:this:0x00000124, field:this:0x0000012C]
    // GUARD: If the existing flat array pointer at this+0x138 is non-null, tear the array down. [field:this:0x00000138, source:raw]
    // LOOP: Iterate every existing 56-byte slot (count read from the 4-byte array header) running the per-entry cleanup stub on each. [callee:0x004B0170, source:raw]
    // CALL: Free the old array header block via the free wrapper. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the array pointer at this+0x138 and the flag at this+0x134 after the old array is freed. [field:this:0x00000138, field:this:0x00000134]
    // CALL: Allocate the new flat array block (count*56+4 bytes) via the operator-new wrapper. [callee:0x00587C03]
    // GUARD: If the allocation is non-null, store the count in the 4-byte header and zero-initialize every 56-byte slot; otherwise store 0 in this+0x138. [source:raw]
    // LOOP: Run the per-slot zero-initializer over each 56-byte entry (14 dwords per slot). [callee:0x0055D200, source:raw]
    // ASSIGNMENT: Store the new array pointer in this+0x138 on success; leave it at 0 on allocation failure. [field:this:0x00000138]
    // RETURN: Return the result of the last slot zero-init (or 0 when the allocation failed). [source:raw]

    // Conservative worker pseudocode:
    //   switch (a3) { case 1: c=&this[71]; h=&this[72]; break; case 2: c=&this[75]; h=&this[76]; break; case 4: c=&this[73]; h=&this[74]; break; default: c=h=a2; break; }
    //   if (*h) { walk to tail via +0x6C; tail->next = a2; a2->back = tail; } else { *h = a2; a2->back = 0; }
    //   (*c)++; a2->next = 0; this[24] = this[73] + this[75];
    //   if (this[78]) { run cleanup per old slot; free(old); this[78] = 0; this[77] = 0; }
    //   block = alloc(this[24]*56 + 4); if (block) { *block = count; zero-init each 56-byte slot; this[78] = block+1; } else this[78] = 0;
    // UNRESOLVED: Case 1 selects the counter/head pair at this+71/this+72 and case 2 the pair at this+75/this+76, but only the case-4 pair (this+0x124/this+0x128) and the case-2 counter (this+0x12C) are covered by this packet's field evidence.
    // UNRESOLVED: Only the category-4 and category-2 counters are summed into the total; the category-1 counter is excluded by the raw source.
    // UNRESOLVED: The per-entry cleanup semantics (EmptyStub_0170) and the slot layout beyond the 56-byte stride are not recoverable from this packet.
}
