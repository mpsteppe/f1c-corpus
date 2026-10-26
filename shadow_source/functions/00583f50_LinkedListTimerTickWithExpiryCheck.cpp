// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583F50
// Canonical corpus name: sub_583F50
// Owner: EventTimerManager [DERIVED]
// Raw source: functions/sub_583F50_00583f50.c

void EventTimerManager::LinkedListTimerTickWithExpiryCheck()
{
    // Walks two timer-node lists (list control at this+0x57C and a second list at this+0x598), decrementing each node's deadline at node+0x4C by a time budget computed as CRTFtol(a2*1000+0.5). Nodes whose deadline drops to zero or below are unlinked from the list, cleaned via ConditionalListNodeCleanup, freed via FreeWrapper_7bcf, and appended to a free list under a short (1 ms) mutex wait. Each list walk is protected by a per-list mutex acquired with a bounded timeout.
    // ASSIGNMENT: v20 = CRTFtol(a2 * 1000.0 + 0.5): convert the float seconds budget a2 to integer milliseconds. [callee:0x00587BDC, global:0x0059E450, global:0x0059E874, source:raw]
    // LOOP: Two iterations (v19 = 0, 1) over the timer list control blocks at this+0x57C and this+0x598. [source:raw]
    // GUARD: Acquire the list-walk mutex (this+0x58C for list 1) via WaitForSingleObject with timeout this+0x590; on unavailable or timeout skip the list. [global:0x0059E1A0, field:this:0x0000058C, field:this:0x00000590]
    // GUARD: If the list head *(this+0x57C) is 0 the list is empty; skip the iteration. [guard:0, field:*(this+0x57C):0x00000000]
    // LOOP: Per node: decrement the deadline at node+0x4C by the time budget v20 and store it back. [field:*(*(this+0x57C)+0x0):0x0000004C, source:raw]
    // GUARD: If the deadline is still greater than 0 (or the append mutex this+0x570 is busy), advance the iterator at list control offset +8 and continue the walk. [source:raw, field:*(this+0x57C):0x00000008]
    // STATE_TRANSITION: Expired node is unlinked from the list: head/tail/count at control offsets +0/+4/+8 are updated. [field:*(this+0x57C):0x00000000, field:*(this+0x57C):0x00000004, field:*(this+0x57C):0x00000008]
    // CALL: ConditionalListNodeCleanup(node) performs node teardown before freeing. [callee:0x005864E0]
    // CALL: FreeWrapper_7bcf(node) frees the expired node's memory. [callee:0x00587BCF]
    // CALL: LinkedListNodeAppend_6000(node, 0) appends the expired node to a free list, guarded by WaitForSingleObject on mutex this+0x570 with a 1 ms timeout. [callee:0x00586000, field:this:0x00000570, global:0x0059E1A0]
    // STATE_TRANSITION: ReleaseMutex for the append mutex (this+0x570) and for the list-walk mutex (this+0x58C) after the iteration. [global:0x0059E1A4, field:this:0x00000570, field:this:0x0000058C]
    // RETURN: Returns the ReleaseMutex result for the last processed list's mutex. [source:raw]

    // Conservative worker pseudocode:
    //   budget_ms = CRTFtol(a2 * 1000.0 + 0.5);
    //   for (i = 0; i < 2; i++) {
    //     ctrl = (i == 0) ? this + 0x57C : this + 0x598;
    //     amutex = (i == 0) ? this + 0x560 : this + 0x544;
    //     if (!WaitForSingleObject(ctrl[4], ctrl[5])) continue;
    //     ctrl[2] = ctrl[0];
    //     for (node = ctrl[0]; node; ) {
    //       node[0x4C] -= budget_ms;
    //       if (node[0x4C] > 0 || WaitForSingleObject(amutex[4], 1) == 258/WAIT_FAILED) {
    //         node = advance iterator;
    //       } else {
    //         unlink(node);
    //         ConditionalListNodeCleanup(node);
    //         FreeWrapper_7bcf(node);
    //         LinkedListNodeAppend_6000(node, 0);
    //         if (amutex[4]) ReleaseMutex(amutex[4]);
    //         node = advance iterator;
    //       }
    //     }
    //     if (ctrl[4]) ReleaseMutex(ctrl[4]);
    //   }
    //   return result;
    // UNRESOLVED: Second list control block at this+0x598 and its append mutex at this+0x544 (handle at +4) are used in the body but absent from the packet field evidence set.
    // UNRESOLVED: this+0x580, this+0x584, this+0x588 and the dereferenced fields of *(this+0x584) are reported by deterministic facts but not visible in the decompiled body.
    // UNRESOLVED: Free-list target and second argument 0 of LinkedListNodeAppend_6000 unconfirmed.
}
