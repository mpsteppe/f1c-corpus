// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1F80
// Canonical corpus name: ArithmeticComparison_1f80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_1f80_004a1f80.c

void UnknownObject::FreeFourLinkedLists()
{
    // Destroys four singly-linked lists. The this object holds four head pointers (this[0..3]); for each non-null head the function walks the list via the next pointer stored at node offset 0x44 (element 17), freeing each node with FreeWrapper_7bcf (0x00587BCF). Returns the final traversal pointer, which is NULL after a normal walk. Invoked from sub_4A4900.
    // LOOP: Iterate the four bucket heads this[0] through this[3]. [source:raw]
    // GUARD: Skip a bucket entirely when its head pointer this[i] is NULL. [source:raw]
    // LOOP: Walk the current linked list, continuing while the current node is non-null. [source:raw]
    // ASSIGNMENT: Capture the next node from element 17 (offset 0x44) of the current node before it is freed. [source:raw]
    // CALL: Free the current node with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the last traversal pointer (NULL after a fully walked list). The caller sub_4A4900 discards or ignores the result. [caller:0x004A4900, function:0x004A1F80, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* FreeFourLinkedLists(_DWORD* this) {
    //     for (int i = 0; i < 4; ++i) {
    //       _DWORD* node = this[i];
    //       while (node) {
    //         _DWORD* next = (_DWORD*)node[17];
    //         FreeWrapper_7bcf(node);
    //         node = next;
    //       }
    //     }
    //     return node;
    //   }
    // UNRESOLVED: Identity of the owning object and what the four buckets hold (free lists, hash buckets, allocation arenas) is not established.
    // UNRESOLVED: The node next-pointer at element 17 (offset 0x44) implies a struct whose 0x44 field is the link, but the struct type is unknown.
    // UNRESOLVED: The legacy name Arithmetic_Comparison_4a1f80 does not match the deallocation behavior and was not used for the proposal.
}
