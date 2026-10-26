// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7CA0
// Canonical corpus name: NetworkMessageReceiveAndDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkMessageReceiveAndDispatch_004c7ca0.c

void UnknownObject::NetworkMessageReceiveAndDispatch()
{
    // Receives and dispatches network messages from audio network nodes into a linked-list message queue on this object. Optionally sets a render flag when a global sentinel is set, counts audio network nodes, iterates each node by index, checks a 4096 flag property, allocates a message vtable entry, and either frees the entry via an indirect vtable call (when the node dispatch rejects it or the queue head is missing) or enqueues it as a 12-byte node on the list headed at this+0xC (tail this+0x10, cursor this+0x14, count this+0x18).
    // GUARD: If global sentinel dword_8ACFCC is non-zero, set a render flag before dispatching. [global:0x008ACFCC, callee:0x0054C110]
    // CALL: RenderFlagSetter(7, 4096) sets render state with value 7 and mask 4096. [callee:0x0054C110]
    // ASSIGNMENT: Stash audio network node handle dword_8AFE88 into local buffer slot v8[1]. [global:0x008AFE88, source:raw]
    // GUARD: Only process network nodes while dword_8AFE88 handle is non-zero. [global:0x008AFE88]
    // CALL: AudioNetworkNodeCount(dword_8AFE88) returns total node count into v10. [callee:0x005452F0, global:0x008AFE88]
    // GUARD: Skip the node loop entirely when node count v10 is not positive. [callee:0x005452F0]
    // LOOP: Iterate node index v1 from 0 while v1 is below v10, advancing v1 by 1 each pass. [callee:0x00545340, callee:0x005452F0, source:raw]
    // CALL: LinkedListNodeFinder(v1) returns the node at index v1 into v2. [callee:0x00545340]
    // GUARD: Skip to next index when the found node v2 is null. [callee:0x00545340]
    // ASSIGNMENT: Clear flag buffer slot v8[0] to 0 before querying the flag property. [source:raw]
    // CALL: FlagPropertyGetter(v8, 4096) reads the flag property; result lands in v8[0]. [callee:0x0054C150]
    // GUARD: Only process the node when flag bit 4096 is set (v8[0] non-zero). [callee:0x0054C150]
    // CALL: MemoryAllocation_9a50() allocates a message vtable entry object into v3. [callee:0x004C9A50]
    // GUARD: Skip node when message entry allocation v3 failed (null). [callee:0x004C9A50]
    // CALL: VTableDispatchWithNegation(v2) dispatches the message on the node; non-zero result rejects/consumes it. [callee:0x004C8F80]
    // STATE_TRANSITION: On non-zero VTableDispatchWithNegation result, jump to LABEL_22 to release entry v3 via indirect vtable call (**v3)(v3, 1). [callee:0x004C8F80, callee:0x004C9A50, source:raw]
    // GUARD: If list head at this+0xC is null, allocate a zeroed 16-byte list node as the new head. [field:this:0x0000000C, callee:0x00587C03]
    // ASSIGNMENT: Store the freshly allocated list head into this+0xC. [field:this:0x0000000C, callee:0x00587C03]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a 12-byte message node v7; when allocated, [0]=v3 entry, [4]=0, byte [8]=1. [callee:0x00587C03, callee:0x004C9A50]
    // GUARD: When the list head at this+0xC is still null after the ensure step, fall to LABEL_22 and release entry v3 via indirect vtable call. [field:this:0x0000000C, source:raw]
    // GUARD: When the list is non-empty (head v6[0] non-null), append the new node by writing it into the tail node's next slot at (this+0x10 tail value + 4). [field:this:0x00000010, field:this:0x0000000C]
    // ASSIGNMENT: On an empty list, set both head (this+0xC) and cursor/current (this+0x14) to the new node. [field:this:0x0000000C, field:this:0x00000014]
    // ASSIGNMENT: Advance tail (this+0x10) to the new node. [field:this:0x00000010]
    // CALCULATION: Increment the item count at this+0x18 by 1. [field:this:0x00000018]
    // RETURN: Void function; returns implicitly after the node loop finishes. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8ACFCC)
    //       RenderFlagSetter(7, 4096);
    //   v8[1] = dword_8AFE88;
    //   if (dword_8AFE88)
    //   {
    //       v10 = AudioNetworkNodeCount(dword_8AFE88);
    //       v1 = 0;
    //       while (v1 < v10)
    //       {
    //           v2 = LinkedListNodeFinder(v1);
    //           if (v2)
    //           {
    //               v8[0] = 0;
    //               FlagPropertyGetter(v8, 4096);
    //               if (v8[0])
    //               {
    //                   v3 = MemoryAllocation_9a50();
    //                   if (v3)
    //                   {
    //                       if (VTableDispatchWithNegation(v2))
    //                           goto LABEL_22;
    //                       if (!this[0xC])
    //                           this[0xC] = OperatorNewNhMallocWrapper(16);
    //                       v6 = this[0xC];
    //                       if (!v6)
    //                       {
    //   LABEL_22:
    //                           (**v3)(v3, 1);
    //                       }
    //                       else
    //                       {
    //                           v7 = OperatorNewNhMallocWrapper(12);
    //                           if (v7) { v7[0] = v3; v7[1] = 0; *(v7 + 8) = 1; }
    //                           if (*v6)
    //                               *(v6[1] + 4) = v7;
    //                           else
    //                           {
    //                               *v6 = v7;
    //                               v6[2] = v7;
    //                           }
    //                           v6[1] = v7;
    //                           ++v6[3];
    //                       }
    //                   }
    //               }
    //           }
    //           ++v1;
    //       }
    //   }
    // UNRESOLVED: Exact semantics of the VTableDispatchWithNegation(v2) return: rejected messages versus internally consumed messages is unproven.
    // UNRESOLVED: Purpose of the indirect vtable call (**v3)(v3, 1): likely an object release/decrement, not evidenced beyond the call shape.
    // UNRESOLVED: Relationship between the audio network handle dword_8AFE88 and node indices passed to LinkedListNodeFinder is unverified.
}
