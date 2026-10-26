// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005493B0
// Canonical corpus name: StringCopyNodeAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyNodeAlloc_005493b0.c

void UnknownObject::appendStringCopyNode()
{
    // Appends a 24-byte string copy node to a singly-linked list headed at this[0xFC]. Walks to the tail via node+0x14 when the head is non-null; otherwise sets the head. Allocates the node with OperatorNewNhMallocWrapper(24), initializes it via ShortComputation_8e00, copies the input string via strcpy, then returns the result of sub_589901. Same append-to-linked-list pattern as sibling string-list functions, with a different list-head offset.
    // GUARD: Read this[0xFC], the string-list head. Non-null selects the append path; null selects first-insert. [field:this:0x000000FC]
    // LOOP: When the head is non-null, walk the singly-linked list following the next pointer at node+0x14 until the last node. [field:*(*(this+0x110)+0x14):0x00000014, source:raw]
    // CALL: Allocate a 24-byte node through OperatorNewNhMallocWrapper(24). [callee:0x00587C03, abi:lead, function:0x005493B0]
    // GUARD: On successful allocation the node is initialized; on failure the node pointer stays null and the head/tail link records null. [source:raw, field:this:0x000000FC]
    // CALL: ShortComputation_8e00 zero-initializes the 24-byte node and yields its string-buffer pointer. [callee:0x00548E00]
    // ASSIGNMENT: Link the new node: store the tail node's next pointer (+0x14) to the new node, or on first insert store it as this[0xFC]. A failed first allocation writes 0 to this[0xFC]. [field:*(*(this+0x110)+0x14):0x00000014, field:this:0x000000FC, source:raw]
    // CALL: Copy the caller-supplied string into the node's buffer with strcpy. [source:raw, caller:0x0055A790]
    // CALL: Finalize/register the inserted node via sub_589901, called with the node's string buffer. [callee:0x00589901, caller:0x0055A790]
    // RETURN: Return the result of sub_589901. [callee:0x00589901, source:raw]

    // Conservative worker pseudocode:
    //   if head == 0: head = init(alloc(24)); else tail = walk_to_tail(head); tail.next = init(alloc(24));
    //   node = alloc ? init : 0;
    //   strcpy(node, a2); return normalize(node);
    // UNRESOLVED: this+0x110 is a read-only pointer per existing_analysis, but no access to this+0x110 appears in the raw source; the only +0x14 access is through the list node it reaches.
    // UNRESOLVED: Exact semantics of sub_589901 (normalization vs registration) not grounded in this packet.
}
