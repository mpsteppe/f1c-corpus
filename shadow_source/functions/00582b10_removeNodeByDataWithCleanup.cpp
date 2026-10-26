// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582B10
// Canonical corpus name: LinkedListElementRemovalWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListElementRemovalWithCleanup_00582b10.c

void UnknownObject::removeNodeByDataWithCleanup()
{
    // Removes a node from a linked list whose data value equals the head node's data value. Sets the iterator pointer (this+0x8) to the head on entry, walks the list from the head searching for the node whose data matches the captured head data, unlinks the matched node, updates head/tail/iterator pointers, decrements the node count, and frees the node. If the removed node's cleanup flag (obj+0x8) is set and its data is non-null, an SEH-guarded cleanup callback runs on the data before the data is freed. Returns the matched data value on success, or 0 when the list is empty or the node is not found.
    // GUARD: Empty-list early exit: if head pointer (this 0x0) is 0, return 0 immediately. [guard:0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set iterator/current pointer (this 0x8) equal to head (this 0x0). [field:this:0x00000008, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Capture v4 = data value of the head node (obj 0x0); this value is used to match the node to remove. [field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Clear the head node cleanup flag: obj 0x8 = 0, suppressing later re-cleanup of that node. [field:obj:0x00000008, source:raw]
    // GUARD: Proceed only when the match value v4 is non-zero and head (this 0x0) is non-null; otherwise return 0. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // LOOP: Walk the list from the head: while node data (obj 0x0) != v4, record prev (result) and advance v5 to the next node; if v5 becomes 0, return 0 (not found). [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // ASSIGNMENT: If the matched node equals the iterator (this 0x8), advance the iterator to the matched node's next pointer. [field:this:0x00000008, source:raw]
    // CALCULATION: v6 = next pointer of the matched node, saved before unlinking. [source:raw]
    // ASSIGNMENT: Unlink the node: if prev (result) is non-null set prev->next = v6; otherwise set head (this 0x0) = v6. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: If tail (this 0x4) equals the matched node, set tail = prev. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Decrement the node count (this 0xC) by one. [field:this:0x0000000C, source:raw]
    // CALL: If the node cleanup flag (obj 0x8) is set and node data (obj 0x0) is non-null, call SEHGuardedFunctionWithExceptionHandling on the data. [callee:0x005867B0, field:obj:0x00000008, field:obj:0x00000000, source:raw]
    // CALL: If the node cleanup flag (obj 0x8) is set and node data (obj 0x0) is non-null, free the data via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000008, field:obj:0x00000000, source:raw]
    // CALL: Free the removed node memory via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the matched data value v4 on successful removal. [source:raw]
    // RETURN: Return 0 when the list is empty or the node is not found. [guard:0, source:raw]

    // Conservative worker pseudocode:
    //   head = this[0];
    //   this[2] = head;
    //   if (head == 0) return 0;
    //   matchValue = head->data;
    //   head->cleanupFlag = 0;
    //   if (matchValue && head) {
    //     prev = 0; current = head;
    //     while (current->data != matchValue) {
    //       prev = current;
    //       current = current->next;
    //       if (!current) return 0;
    //     }
    //     if (current == this[2]) this[2] = current->next;
    //     next = current->next;
    //     if (prev) prev->next = next; else this[0] = next;
    //     if (this[1] == current) this[1] = prev;
    //     this[3]--;
    //     if (current->cleanupFlag) {
    //       data = current->data;
    //       if (data) {
    //         SEHGuardedFunctionWithExceptionHandling(data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(current);
    //     return matchValue;
    //   }
    //   return 0;
    // UNRESOLVED: The match value v4 is the head node's data captured before the walk, so the first node examined already matches in the nominal path; whether the intended semantic is 'remove head' or 'remove first node whose data equals head data' is ambiguous.
    // UNRESOLVED: The exact meaning of the node byte obj 0x8 (cleanup flag) and which subsystem owns the node data are not established from this function alone.
}
