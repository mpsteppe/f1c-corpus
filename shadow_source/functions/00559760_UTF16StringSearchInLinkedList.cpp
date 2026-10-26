// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559760
// Canonical corpus name: UTF16StringSearchInLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UTF16StringSearchInLinkedList_00559760.c

void UnknownObject::UTF16StringSearchInLinkedList()
{
    // Walks a singly-linked list of string nodes starting from the head stored at this+0x00. Each node's string is compared with the target a2 via strcmp; the first matching node pointer is returned, or 0 if the list is empty or the target is not found. A null next pointer at node+0x1C terminates the walk.
    // ASSIGNMENT: Seed the walk cursor with the list head: v2 = *this (this 0x0). [source:raw, field:this:0x00000000]
    // GUARD: If the head (*this) is null the list is empty and the function returns 0 immediately. [source:raw, field:this:0x00000000]
    // LOOP: While the current node's string does not match the target (strcmp(v2, a2) != 0), keep advancing through the list. [source:raw]
    // CALL: Compare the current node's string against the target with strcmp. [source:raw]
    // CALCULATION: Advance the cursor to the next node: v2 = *(_DWORD *)(v2 + 28), i.e. the next pointer at node offset 0x1C. [source:raw, field:*(obj+0x1C):0x0000001C]
    // GUARD: If the next pointer is null the end of the list was reached without a match and the function returns 0. [source:raw, field:*(obj+0x1C):0x0000001C]
    // RETURN: Return the matching node pointer, or 0 when the list is empty or exhausted without a match. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_559760(int *this, const char *target) {
    //     int node = *this;
    //     if (!node) return 0;
    //     while (strcmp((const char *)node, target)) {
    //       node = *(_DWORD *)(node + 28);
    //       if (!node) return 0;
    //     }
    //     return node;
    //   }
    // UNRESOLVED: The node payload at the cursor itself is treated as a string by strcmp, but its exact layout beyond the next pointer at 0x1C is not established.
    // UNRESOLVED: The caller-provided target a2 semantics depend on the three callers sub_5594B0, sub_559820 and sub_5598B0.
}
