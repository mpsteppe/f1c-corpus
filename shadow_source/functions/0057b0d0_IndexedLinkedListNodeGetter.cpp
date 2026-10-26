// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B0D0
// Canonical corpus name: IndexedLinkedListNodeGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedLinkedListNodeGetter_0057b0d0.c

void UnknownObject::IndexedLinkedListNodeGetter()
{
    // Returns the data stored in the node at index a2 of an indexed singly linked list. Bounds-checks a2 against the stored counter at this[5] (byte offset 0x14); returns 0 on failure. Starts at the head pointer this[2] (byte offset 0x8) and walks forward via each node's next pointer at node[1]. For index 0 the head itself is used; for a2 greater than 0 the list is walked a2 times. Returns the first 32-bit value of the target node, or 0 when the walk exhausts the list.
    // GUARD: If a2 is negative or a2 >= this[5] (the counter at byte offset 0x14), return 0 immediately. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Load the list head node pointer from this[2] (byte offset 0x8). [field:this:0x00000008, source:raw]
    // LOOP: When a2 is greater than 0, walk the list by following each node's next pointer (node[1]) while decrementing the index; if the walk reaches a null next pointer the list is exhausted. [source:raw]
    // GUARD: If the target node pointer is null after the bounds check and walk, return 0. [source:raw]
    // RETURN: Return the first 32-bit value stored in the target node; this is the node payload accessed at node offset 0. [source:raw]

    // Conservative worker pseudocode:
    //   int IndexedLinkedListNodeGetter(_DWORD *list, int index) {
    //     int i = index;
    //     if (index < 0 || index >= list[5]) return 0;
    //     _DWORD *node = (_DWORD *)list[2];
    //     if (index > 0) {
    //       while (node) {
    //         node = (_DWORD *)node[1];
    //         if (--i <= 0) break;
    //       }
    //       if (!node) return 0;
    //     }
    //     if (!node) return 0;
    //     return *node;
    //   }
    // UNRESOLVED: The container fields at byte offsets 0xC and 0x10 (this[3], this[4]) are not read by this function; their purpose is unevidenced here.
    // UNRESOLVED: The meaning of the returned node payload depends on the caller's node layout; caller is NetworkPacketSendWithQueryMatching (0057d8d0).
}
