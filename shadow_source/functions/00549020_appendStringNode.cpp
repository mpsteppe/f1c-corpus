// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549020
// Canonical corpus name: StringListAppend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringListAppend_00549020.c

void UnknownObject::appendStringNode()
{
    // Appends a 24-byte string node to a singly-linked string list. Lazily allocates the head node on first call; otherwise walks the chain via the next pointer at node+0x14 to reach the tail. Allocates the new node with OperatorNewNhMallocWrapper(24), initializes it via ShortComputation_8e00, copies the input string in with strcpy, then normalizes/registers it through sub_589901 and returns that result.
    // GUARD: Read this[0xE8], the string-list head. Non-null means the list is non-empty (append path); null means this call inserts the first node. [field:this:0x000000E8]
    // LOOP: When the head is non-null, walk the singly-linked list following the next pointer at node+0x14 until the last node is reached. [field:*(*(this+0xFC)+0x14):0x00000014, source:raw]
    // CALL: Allocate a 24-byte node through OperatorNewNhMallocWrapper(24). [callee:0x00587C03, abi:lead, function:0x00549020]
    // GUARD: If the allocation returned non-null, initialize the node; on allocation failure the node pointer stays null and the head/tail link records null. [source:raw, field:this:0x000000E8]
    // CALL: ShortComputation_8e00 zero-initializes the 24-byte node and yields its string-buffer pointer. [callee:0x00548E00]
    // ASSIGNMENT: Link the new node into the list: either store the tail node's next pointer (+0x14) to the new node, or on first insert store it as this[0xE8]. Failure of the first allocation writes 0 to this[0xE8]. [field:*(*(this+0xFC)+0x14):0x00000014, field:this:0x000000E8, source:raw]
    // CALL: Copy the caller-supplied string into the node's buffer with strcpy. [source:raw, caller:0x0055A790]
    // CALL: Normalize/register the new node via sub_589901, called with the node's string buffer. [callee:0x00589901, caller:0x0055A790]
    // RETURN: Return the result of sub_589901. [callee:0x00589901, source:raw]

    // Conservative worker pseudocode:
    //   if head == 0: head = init(alloc(24)); else tail = walk_to_tail(head); tail.next = init(alloc(24));
    //   node = alloc ? init : 0;
    //   strcpy(node, a2); return normalize(node);
    // UNRESOLVED: this+0xFC is a read-only container pointer per existing_analysis, but no access to this+0xFC appears in the raw source; the only +0x14 access is through the list node it reaches.
    // UNRESOLVED: Exact semantics of sub_589901 (normalization vs registration) not grounded in this packet.
}
