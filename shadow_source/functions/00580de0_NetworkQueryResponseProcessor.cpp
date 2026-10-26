// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00580DE0
// Canonical corpus name: sub_580DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_580DE0_00580de0.c

void UnknownObject::NetworkQueryResponseProcessor()
{
    // Handles a network query response. Validates via a virtual accept check, builds a packet object through the vtable, sends it over the network, then searches a mutex-protected linked list of pending queries for the node matching a2. On a match it marks the result object complete, unlinks and frees the node, and conditionally re-sends follow-up packets based on query state (state 3 triggers a virtual callback, state 4 re-sends with an updated flag). Runs a secondary sweep over the list after unlink and always releases the mutex.
    // ASSIGNMENT: Initialize local flags v23 = 0 and v24 = 0, and a local result-tracking object v26. [source:raw]
    // CALL: Initialize the local object v26 via ObjectInitWithVTableFieldSet(v26, 0, 0, 0). [callee:0x0057B780, source:raw]
    // GUARD: Virtual accept check at vtable slot 208 (this->vtbl[208](this, a2, v26)); if it returns nonzero the response is processed. [field:this:0x00000000, field:obj:0x000000D0, source:raw]
    // CALL: Acquire the worker object via virtual call at vtable slot 88. [field:obj:0x00000058, field:this:0x00000000, source:raw]
    // CALL: Report a callback/event via sub_586800(0, 7, 1, 2, -1). [callee:0x00586800, source:raw]
    // CALL: Invoke a virtual method on the worker's packet object (vtable of *(v4 + 72), slot 12) with a2. [source:raw]
    // CALL: Send the packet object over the network via NetworkPacketSendWithQueryMatching(this, v4, 0). [callee:0x0057D8D0, source:raw]
    // CALL: Complete the send via virtual call at vtable slot 92 (this, v4). [field:obj:0x0000005C, field:this:0x00000000, source:raw]
    // GUARD: Guard: if the mutex handle this[694] (offset 0xAD8) is absent, or WaitForSingleObject returns a value other than 0 or 128 within this[695] (offset 0xADC), the list walk is skipped. [field:this:0x00000AD8, field:this:0x00000ADC, field:this:0x00000AC8, global:0x0059E1A0, guard:0, source:raw]
    // ASSIGNMENT: Set the list iterator v6[2] (offset 0xAD0) to the head node read from v6[0] (offset 0xAC8); head node pointer is *v6, and the iterator field at *(this+0xAC8)+0x8 is written during walks. [field:this:0x00000AC8, field:this:0x00000AD0, field:*(this+0xAC8):0x00000000, field:*(this+0xAC8):0x00000008, source:raw]
    // LOOP: Walk the pending-query list: for the current node v9, compare ReadFieldAtOffset0x14(v9) against a2; advance via node next pointer (*(current + 4)); stop on match or list end. [callee:0x005871F0, field:this:0x00000AD0, field:*(this+0xAC8):0x00000004, field:*(*(this+0xAC8)+0x4):0x00000000, field:*(*(*(this+0xAC8)+0x4)+0x0):0x00000000, source:raw]
    // CALL: On a match, check query state via sub_587220(v9); if it equals 2 set v23 = 1. [callee:0x00587220, source:raw]
    // ASSIGNMENT: Read the result-object pointer v13 from the matched node at offset 28 (0x1C); if non-null set its completion flag byte at offset 40 (0x28) to 1 and call SetterAt0x24(resultPtr, 0). [field:*(this+0xAD4):0x00000000, field:*(*(this+0xAD4)+0x0):0x0000001C, field:*(*(*(this+0xAD4)+0x0)+0x1C):0x00000028, callee:0x0057B6C0, source:raw]
    // LOOP: Unlink the matched node from the list: find the node equal to v9, update head/tail/count fields (v6[0] head, v6[1] tail at 0xACC, v6[3] count at 0xAD4), invoke the node's callback if set (*(node+8) and *node), then free the node via FreeWrapper_7bcf. [field:this:0x00000ACC, field:this:0x00000AD4, field:*(this+0xAC8):0x00000000, field:*(this+0xAC8):0x00000004, field:*(this+0xAC8):0x0000000C, callee:0x00587BCF, source:raw]
    // STATE_TRANSITION: Mark local v24 = 1 to signal that a matching node was found and processed. [source:raw]
    // LOOP: Second sweep over the remaining list via v6[2] iterator: call sub_587200(v25) for each node and CounterIncrementDecrementByFlag(1), advancing through next pointers. [callee:0x00587200, callee:0x00587230, field:this:0x00000AD0, field:*(this+0xAC8):0x00000004, source:raw]
    // CALL: Release the list mutex this[694] (offset 0xAD8) if it is non-null. [field:this:0x00000AD8, global:0x0059E1A4, source:raw]
    // GUARD: If MutexProtectedPointerReadRelease(this) returns 4, re-send the query: acquire worker again via vtable slot 88, report via sub_586800(0, 9, 1, 2, -1), invoke SingleFunctionCallWrapper_6a00(&a2, 4), set a completion byte on the worker object, send via NetworkPacketSendWithQueryMatching, and complete via vtable slot 92. [callee:0x00585D20, callee:0x00586800, callee:0x00586A00, callee:0x0057D8D0, field:obj:0x00000058, field:obj:0x0000005C, field:this:0x00000000, source:raw]
    // CALL: If v23 is set and MutexProtectedPointerReadRelease(this) returns 3, invoke the virtual callback at vtable slot 116. [callee:0x00585D20, field:obj:0x00000074, field:this:0x00000000, source:raw]
    // CALL: Teardown: mark v27 = -1 and re-initialize the local object v26 via VTablePointerInit. [callee:0x0057B7F0, source:raw]
    // RETURN: Return v24, the flag indicating whether a matching pending query was found and processed. [source:raw, function:0x00580DE0]

    // Conservative worker pseudocode:
    //   bool NetworkQueryResponseProcessor(NetObj* this, int a2) {
    //     char matched = 0, state2 = 0;
    //     Obj v26; ObjectInit(&v26, 0, 0, 0);
    //     if (!this->vtbl[208](this, a2, &v26)) return 0;
    //     void* worker = this->vtbl[88](this);
    //     sub_586800(0, 7, 1, 2, -1);
    //     (*(void(**)(void*,int))(*(void**)(*(char**)worker + 72))[12])(*(char**)worker + 72, a2);
    //     NetworkPacketSendWithQueryMatching(this, worker, 0);
    //     this->vtbl[92](this, worker);
    //     Mutex* m = this->mutex;             // this + 0xAD8
    //     List* list = this->list;            // this + 0xAC8
    //     if (m && WaitForSingleObject(m, this->timeout /* 0xADC * /) == 0 || (WaitRet == 128)) {
    //       list->current = list->head;
    //       for (Node* n = list->head; n; ) {
    //         if (ReadFieldAtOffset0x14(n) == a2) {
    //           if (sub_587220(n) == 2) state2 = 1;
    //           if (void* res = *(void**)(n + 28)) {
    //             *(char*)(res + 40) = 1;
    //             SetterAt0x24(res, 0);
    //           }
    //           UnlinkNode(list, n);   // fix head/tail/count, callback, FreeWrapper_7bcf
    //           matched = 1;
    //           break;
    //         }
    //         list->current = n->next;
    //         n = n->next ? *(Node**)n->next : 0;
    //       }
    //       for (int i = 0; Node* c = list->current; ++i) {
    //         sub_587200(i); CounterIncrementDecrementByFlag(1);
    //         list->current = *(Node**)((char*)c + 4);
    //       }
    //     }
    //     if (this->mutex) ReleaseMutex(this->mutex);
    //     if (MutexProtectedPointerReadRelease(this) == 4) {
    //       void* w2 = this->vtbl[88](this);
    //       sub_586800(0, 9, 1, 2, -1);
    //       SingleFunctionCallWrapper_6a00(&a2, 4);
    //       *(char*)(*(char**)w2 + 76) = 1;
    //       NetworkPacketSendWithQueryMatching(this, w2, 0);
    //       this->vtbl[92](this, w2);
    //     }
    //     if (state2 && MutexProtectedPointerReadRelease(this) == 3)
    //       this->vtbl[116](this);
    //     VTablePointerInit(&v26);
    //     return matched;
    //   }
    // UNRESOLVED: Interpretation of query states (2, 3, 4) is caller/system-defined.
    // UNRESOLVED: The vtable slots are read through obj fields 0x58/0x5C/0x74/0xD0; the exact packet object layout behind the worker is not resolved.
    // UNRESOLVED: Meaning of the worker completion byte at *(*(v21 + 72) + 4) is unresolved.
    // UNRESOLVED: sub_586800 numeric arguments (0, 7, 9, 1, 2, -1) encode event/severity pairs not yet decoded.
}
