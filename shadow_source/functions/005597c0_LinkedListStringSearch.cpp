// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005597C0
// Canonical corpus name: BinaryTreeSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinaryTreeSearch_005597c0.c

void UnknownObject::LinkedListStringSearch()
{
    // Walks a singly-linked list rooted at this+0x4, comparing each node's string against the key a2 via strcmp. Returns the pointer of the node whose string matches, or 0 when the list is empty or exhausted without a match. Despite the legacy BinaryTreeSearch ABI name, the walk is linear through a next pointer at node+0x1C, not a tree descent.
    // ASSIGNMENT: Load the linked-list head pointer from this[1] (offset 0x4) into the walk pointer v2. [field:this:0x00000004]
    // GUARD: If the head pointer is null the list is empty; return 0 immediately. [source:raw]
    // LOOP: Walk the list while strcmp of the current node's string against a2 is nonzero (strings differ). [source:raw]
    // ASSIGNMENT: Advance the walk to the next node through the next pointer stored at offset 0x1C of the current node. [field:*(this+0x20):0x0000001C]
    // GUARD: If the next pointer is null, the list end was reached without a match; return 0. [source:raw]
    // RETURN: Return the matching node pointer once strcmp reports equality. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5597C0(_DWORD* this, const char* key) {
    //     int node = this[1];
    //     if (!node) return 0;
    //     while (strcmp((const char*)node, key)) {
    //       node = *(_DWORD*)(node + 0x1C);
    //       if (!node) return 0;
    //     }
    //     return node;
    //   }
    // UNRESOLVED: The legacy ABI name BinaryTreeSearch describes a tree descent, but the evidence shows a linear linked-list walk; the true owning class is unknown.
    // UNRESOLVED: Node layout: the string appears to start at the node address itself while the next pointer sits at +0x1C, but the node allocation and string storage are not visible here.
    // UNRESOLVED: The list is keyed and searched by string only; insertion and removal sites are elsewhere.
}
