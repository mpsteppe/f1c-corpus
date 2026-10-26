// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585130
// Canonical corpus name: sub_585130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585130_00585130.c

void UnknownObject::DrainTwoListsWithMutexCleanup_B()
{
    // Drains two queues guarded by a mutex. First, repeatedly pops queued items via sub_584E30 and dispatches each through the object's vtable method at offset 0x5C (thiscall(this, item)). Then, if the mutex handle at this+0x58C is non-null and WaitForSingleObject(this+0x58C, this+0x590) returns 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), drains an embedded singly linked list control block at this+0x57C (head/tail/iterator/count): walks the list matching a node's data pointer, unlinks the node updating head/tail/iterator/count, runs SEH-guarded cleanup (0x005867B0) on flagged node payloads, and frees payload and node via FreeWrapper_7bcf. Finally releases the mutex (ReleaseMutex) when the handle is non-null. Called from AudioStreamingThreadShutdown (0x0057FDE0).
    // LOOP: First drain loop: while sub_584E30(this, &v11) returns nonzero, a queued item is popped into v11; the loop terminates when the first queue is empty. [callee:0x00584E30, source:raw]
    // CALL: Dispatch each popped item: virtual call at this->vtable[23] (offset 0x5C, +92) invoked as thiscall(this, v11). [field:this:0x00000000, field:obj:0x0000005C, source:raw]
    // CALL: Acquire the second-list mutex: WaitForSingleObject(handle at this+0x58C, timeout at this+0x590). [global:0x0059E1A0, field:this:0x0000058C, field:this:0x00000590]
    // GUARD: Second-list access guard: when the mutex handle is non-null and the wait result equals 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), v5 is set to this+0x57C (the list control block); otherwise v5=0 and the second drain is skipped. [global:0x0059E1A0, field:this:0x0000058C]
    // GUARD: Second-list drain loop condition: node count at this+0x588 (equivalently *(this+0x57C)+0xC) is greater than 0. [guard:0, field:this:0x00000588, field:*(this+0x57C):0x0000000C]
    // LOOP: Walk the embedded list from head (*v5) following each node's next pointer (node[1]), comparing each node's data pointer (*node) against the first node's data (v7); v8 tracks the previous node. Falling off the end of the list restarts the count check (LABEL_8). [field:*(this+0x57C):0x00000000, source:raw]
    // ASSIGNMENT: Unlink the located node: if the iterator v5[2] points at it, advance it to the node's next; splice the previous node's next (or the head *v5) past the removed node; if the removed node was the tail v5[1], set the tail to the previous node. These writes correspond to the list control fields at this+0x57C/0x580/0x584 (and their *(this+0x57C)+0x0/0x4/0x8 aliases). [field:this:0x0000057C, field:this:0x00000580, field:this:0x00000584, field:*(this+0x57C):0x00000000, field:*(this+0x57C):0x00000004, field:*(this+0x57C):0x00000008]
    // CALCULATION: Decrement the node count (this+0x588, equivalently *(this+0x57C)+0xC). [field:this:0x00000588, field:*(this+0x57C):0x0000000C]
    // CALL: If the node's flag byte (node+8) is set and the node's data pointer (*node) is non-null, run SEHGuardedFunctionWithExceptionHandling (0x005867B0) on the payload under an exception guard. [callee:0x005867B0, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) releases the node's data payload when it was non-null. [callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) releases the unlinked node itself. [callee:0x00587BCF]
    // RETURN: Return path: re-read the mutex handle at this+0x58C; when non-null, call ReleaseMutex on it and return its result; otherwise return 0. [global:0x0059E1A4, field:this:0x0000058C, function:0x00585130, source:raw]

    // Conservative worker pseudocode:
    //   while (sub_584E30(this, &item))
    //       (this->vtbl[23])(this, item);
    //   mutex = this[0x58C];
    //   if (mutex && ((wait = WaitForSingleObject(mutex, this[0x590])) == 0 || wait == 128))
    //       drain_list(this + 0x57C);
    //   if (mutex)
    //       ReleaseMutex(mutex);
    // UNRESOLVED: The vtable method at this+0x5C (offset +92) dispatched per drained item has an unknown identity and semantic target.
    // UNRESOLVED: The first-drain queue managed by sub_584E30 is not structurally identified; the meaning of its nonzero return (item available) and of the popped value is unknown.
    // UNRESOLVED: Node payload layout (node[0] data pointer, node[1] next, byte at node+8 flag) is inferred from the decompiler and has no dedicated evidence references in the packet.
    // UNRESOLVED: The semantic role of SEHGuardedFunctionWithExceptionHandling (0x005867B0) invoked on node payloads (cleanup callback vs. notification) is unknown.
    // UNRESOLVED: Treating the WaitForSingleObject result 128 (WAIT_ABANDONED) as access-granted along with 0 (WAIT_OBJECT_0) is a code-level observation; its intended behavior is unconfirmed.
    // UNRESOLVED: Whether the two drain paths (sub_584E30 queue and the embedded list at this+0x57C) share the same underlying data structure or service different queues is unresolved.
}
