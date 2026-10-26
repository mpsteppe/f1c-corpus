// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAE20
// Canonical corpus name: LinkedListRemoveByValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListRemoveByValue_004bae20.c

void UnknownObject::LinkedListRemoveByValue()
{
    // Singly-linked-list remove-by-value operating on a list object this (head +0, tail +4, current/iterator +8, count +0xC). Captures the head node's data value, clears the head node's free-flag byte at obj+8 so its data is never freed, then walks the list from the head following next pointers (obj+4) until a node whose data (obj+0) equals the captured value is found. Unlinks the matched node, updates head/tail/current/count as needed, conditionally frees the data (path suppressed by the cleared flag) and unconditionally frees the node itself. Returns the removed node's data pointer, or 0 on any empty-list/not-found case.
    // ASSIGNMENT: Capture head node v1 = *this and seed the current/iterator slot this+8 with the head before any null checks. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Guard: when the head node's data pointer (obj+0) is null the function aborts and returns 0. [field:obj:0x00000000, guard:0, source:raw]
    // ASSIGNMENT: Clear the free-flag byte at obj+8 to 0 on the head node so its data is not freed by the later conditional path. [field:obj:0x00000008, source:raw]
    // RETURN: Return 0 when the head node's data pointer is null. [guard:0, source:raw]
    // GUARD: Guard: re-read the head; when this+0 is null the function returns 0. [field:this:0x00000000, guard:1, source:raw]
    // LOOP: Walk the list from the head following next pointers (obj+4) while the node's data (obj+0) differs from the captured value v4; return 0 if the walk reaches a null node. [field:obj:0x00000000, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: If the matched node v5 is the current/iterator node this+8, advance this+8 to v5's next pointer (obj+4). [field:this:0x00000008, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Unlink v5: if a predecessor exists, set its next (obj+4) to v5's next; otherwise move the list head this+0 to v5's next. [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: If the removed node was the tail (this+4 == v5), move the tail to the predecessor node. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Decrement the node count this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: If the removed node's free-flag (obj+8) is set, run EmptyStub_0170 then free the node's data pointer (obj+0) via FreeWrapper_7bcf; the flag was cleared at entry so this path normally does not run. [field:obj:0x00000008, field:obj:0x00000000, callee:0x004B0170, callee:0x00587BCF, source:raw]
    // CALL: Free the removed node itself with FreeWrapper_7bcf(v5). [callee:0x00587BCF, source:raw]
    // RETURN: Return the removed node's data pointer (obj+0). Invoked by NetworkMessageDispatch (004b54e0). [field:obj:0x00000000, caller:0x004B54E0, function:0x004BAE20, source:raw]

    // Conservative worker pseudocode:
    //   void* LinkedListRemoveByValue(List* list) {
    //     Node* head = list->head;
    //     list->current = list->head;
    //     if (head == 0 || head->data == 0) return 0;
    //     int key = head->data;
    //     head->freeFlag = 0;
    //     Node* prev = 0;
    //     Node* n = list->head;
    //     while (n && n->data != key) { prev = n; n = n->next; }
    //     if (!n) return 0;
    //     if (n == list->current) list->current = n->next;
    //     if (prev) prev->next = n->next; else list->head = n->next;
    //     if (list->tail == n) list->tail = prev;
    //     list->count--;
    //     if (n->freeFlag) { EmptyStub_0170(); FreeWrapper_7bcf(n->data); }
    //     FreeWrapper_7bcf(n);
    //     return (void*)key;
    //   }
    // UNRESOLVED: Read-only node field obj+0xC is referenced by packet facts but absent from the decompiled logic; its meaning is unknown.
    // UNRESOLVED: The list owner object (head/tail/current/count struct) has no identified class; owner is UnknownObject.
    // UNRESOLVED: Purpose of EmptyStub_0170 is undocumented; the stub is a no-op before the conditional data free.
}
