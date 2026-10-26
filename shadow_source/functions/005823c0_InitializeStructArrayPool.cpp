// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005823C0
// Canonical corpus name: sub_5823C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5823C0_005823c0.c

void UnknownObject::InitializeStructArrayPool()
{
    // Initializes a small fixed pool of 4 sub-objects (40 bytes each, 164-byte allocation with a 4-slot count header) via the NTimeCallbackLoopWithSEH_a6eb initializer using StructInitializationWithVTable and sub_57AEF0 callbacks, wraps the pool array in a 12-byte node marked free, and appends it to list1 (this+0x0). Then pre-allocates one 12-byte free node per sub-object slot into list2 (this+0x10), leaving every slot node free (flag 0). Returns the last list2 count.
    // CALL: Allocate a 4-byte wrapper via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // GUARD: Proceed only if the 4-byte wrapper allocation succeeded. [source:raw]
    // CALL: Allocate the 164-byte pool array (4 sub-objects of 40 bytes plus a 4-byte slot-count header). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the slot count 4 at array offset 0. [source:raw]
    // CALL: Run NTimeCallbackLoopWithSEH_a6eb over 4 slots with a 40-byte stride, invoking the StructInitializationWithVTable and sub_57AEF0 callbacks per slot under the SEH_5823C0 handler. [callee:0x0058A6EB, global:0x0057AEC0, global:0x0057AEF0, global:0x0059CC76, source:raw]
    // ASSIGNMENT: Store the initialized pool-array pointer into the wrapper; the wrapper becomes the container node. [source:raw]
    // CALL: Allocate a 12-byte list node to hold the pool container. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the node: payload = container pointer, next = 0, free flag = 1. [source:raw]
    // STATE_TRANSITION: Append the container node to list1: first node sets head this+0x0, cursor this+0x8 and tail this+0x4; later nodes link at the tail. Increment the list1 count at this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: Iterate v5 = 0; v5 < 160; v5 += 40, producing the address of each of the 4 sub-object slots. [source:raw]
    // CALL: Allocate one 12-byte free node per sub-object slot via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize each slot node: payload = slot address, next = 0, free flag = 0. [source:raw]
    // STATE_TRANSITION: Push each slot node onto the head of list2: head this+0x10, tail this+0x14 and cursor this+0x18 set on the first node, and the count at this+0x1C incremented per node. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the last list2 count value assigned in the pre-allocation loop. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5823C0(int *this) {
    //     _DWORD *wrap = OperatorNewNhMallocWrapper(4);
    //     if (wrap) {
    //       _DWORD *arr = OperatorNewNhMallocWrapper(164);
    //       if (arr) {
    //         arr[0] = 4;
    //         NTimeCallbackLoopWithSEH_a6eb(arr + 1, 40, 4, StructInitializationWithVTable, sub_57AEF0);
    //       }
    //       wrap[0] = arr;
    //       node1 = AllocNode(wrap, 1);                    // payload=wrap, next=0, free=1
    //       AppendNode(list1_head=this[0], this[1], this[2], this[3], node1);
    //       for (int off = 0; off < 160; off += 40) {      // 4 slots
    //         node = AllocNode((int)arr + 4 + off, 0);     // payload=slot, next=0, free=0
    //         PushHead(list2_head=this[4], this[5], this[6], this[7], node);
    //       }
    //     }
    //     return this[7];
    //   }
    // UNRESOLVED: The two-list structure (list1 holding one container node, list2 holding per-slot free nodes) implies a pool/queue consumer; the acquisition/release semantics live in external callers such as NetworkPacketQueueReader and are not determined here.
    // UNRESOLVED: The SEH_5823C0 exception handler wrapping the allocation/initialization path is not analyzed in this function.
}
