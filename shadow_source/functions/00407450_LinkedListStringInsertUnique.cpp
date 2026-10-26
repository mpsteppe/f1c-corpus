// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407450
// Canonical corpus name: LinkedListInsertOperation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListInsertOperation_00407450.c

void UnknownObject::LinkedListStringInsertUnique()
{
    // Inserts string a2 into a unique string linked list if it is not already present. Traverses from the head, comparing a2 against each node's string (falling back to global byte_5EA438 when a node has no string) via sub_588410; on a match it returns without inserting. When no match is found it allocates an 8-byte string node and a 12-byte list node, links the list node onto the tail (or makes it the head when the list is empty), updates head/cursor/tail and increments the node count.
    // GUARD: Guard: if the input string a2 is null the function returns immediately with no insertion. [source:raw]
    // ASSIGNMENT: Traversal cursor this[12] (offset 0x30) is initialized to the head this[10] (offset 0x28). [field:this:0x00000030, field:this:0x00000028, source:raw]
    // GUARD: Guard: traversal starts only when the head (this+0x28) is non-null and its first node is non-null; otherwise the function jumps straight to insertion. [field:this:0x00000028, source:raw]
    // LOOP: Loop walks the list from the head node; each iteration compares the current node's string to a2. [field:this:0x00000028, field:this:0x00000030, source:raw]
    // CALCULATION: Read the current node's string pointer; when it is null, global byte_5EA438 is used as the comparison string. [global:0x005EA438, source:raw]
    // CALL: sub_588410 compares a2 against the node string; a zero result means the strings match. [callee:0x00588410, source:raw]
    // GUARD: Guard: on a string match (sub_588410 returns 0) the traversal breaks and no duplicate is inserted. [callee:0x00588410, source:raw]
    // ASSIGNMENT: Advance the traversal: cursor this[12] moves to the next node stored at cursor + 4; the loop continues while the next node is non-null. [field:this:0x00000030, source:raw]
    // CALL: OperatorNewNhMallocWrapper allocates an 8-byte string node for a2. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the 8-byte string node: dword[0] set to 0 and dword[1] set to -1. [source:raw]
    // CALL: StringCopyWithBufferRealloc copies a2 into the allocated 8-byte string node buffer. [callee:0x00566650, source:raw]
    // CALL: OperatorNewNhMallocWrapper allocates a 12-byte linked-list node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the 12-byte list node: dword[0] points to the string node, dword[1] (next) is 0, and byte[8] is 1. [source:raw]
    // GUARD: Guard: if the head (this+0x28) is non-null the new node is appended to the tail (this+0x2C); otherwise it becomes the head and the cursor. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Tail this[11] (offset 0x2C) is set to the new node and the node count this[13] (offset 0x34) is incremented. [field:this:0x0000002C, field:this:0x00000034, source:raw]
    // RETURN: Void return; every path (null input, duplicate match, or insertion) reaches the end. [function:0x00407450, source:raw]

    // Conservative worker pseudocode:
    //   void LinkedListStringInsertUnique(this, char* s) {
    //     if (!s) return;
    //     this[0x30] = this[0x28];
    //     while (node = this[0x30], node && *node) {
    //       char* cur = *node ? *(char**)*node : byte_5EA438;
    //       if (sub_588410(s, cur) == 0) return;
    //       this[0x30] = *(void**)(this[0x30] + 4);
    //     }
    //     void* snode = OperatorNewNhMallocWrapper(8);
    //     if (snode) { *(int*)snode = 0; *((int*)snode + 1) = -1; StringCopyWithBufferRealloc((int)snode, s); }
    //     void* lnode = OperatorNewNhMallocWrapper(12);
    //     if (lnode) { *(void**)lnode = snode; *((void**)lnode + 1) = 0; *((char*)lnode + 8) = 1; }
    //     if (this[0x28]) *(void**)(this[0x2C] + 4) = lnode;
    //     else { this[0x28] = lnode; this[0x30] = lnode; }
    //     this[0x2C] = lnode;
    //     ++this[0x34];
    //   }
    // UNRESOLVED: The traversal pointer chain (list node -> string node -> inline string data) is visible only through decompiler type casts; the exact node layout is not independently confirmed
    // UNRESOLVED: The content and purpose of global byte_5EA438 (used as the default comparison string) are not resolved from this packet
}
