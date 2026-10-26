// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544F50
// Canonical corpus name: TwoLevelWideStringSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoLevelWideStringSearch_00544f50.c

void UnknownObject::TwoLevelWideStringSearch()
{
    // Searches a two-level linked list for a node whose string (at node+0x8C) matches a2. Starts from head this[62] (this+0xF8). For each first-level node, first compares its string at +0x8C and returns the node on match; otherwise checks a second-level child node at +0x1B0 and returns that child on match; then advances to the next first-level node via +0x1B8. Returns 0 when the list is exhausted.
    // ASSIGNMENT: Load the first-level list head from this[62] (this+0xF8) into the walking pointer v2. [field:this:0x000000F8]
    // GUARD: Guard on v2 == 0 (empty list); returns 0 immediately. [source:raw, field:this:0x000000F8]
    // LOOP: Iterate the first-level linked list until a match is found or the list is exhausted. [source:raw]
    // CALCULATION: Compare the current first-level node's string at +0x8C with a2 via strcmp. [source:raw]
    // RETURN: Return the current first-level node pointer when its string matches a2. [source:raw]
    // ASSIGNMENT: Load the second-level child pointer from the current node at offset 0x1B0. [field:*(this+0x2B0):0x000001B0]
    // GUARD: Guard on the second-level child being non-null; when present, compare its string at +0x8C with a2 via strcmp. [field:*(this+0x2B0):0x000001B0, source:raw]
    // RETURN: On a second-level string match, break out of the walk and return the second-level child pointer at +0x1B0. [field:*(this+0x2B0):0x000001B0, source:raw]
    // ASSIGNMENT: Advance to the next first-level node via the next pointer at offset 0x1B8. [field:*(this+0x2B0):0x000001B8]
    // GUARD: Guard on the next first-level node being null; returns 0 (not found) when the walk ends without a match. [source:raw, field:*(this+0x2B0):0x000001B8]

    // Conservative worker pseudocode:
    //   int sub_544F50(_DWORD *this, const char *needle) {
    //     int node = this[62]; /* this+0xF8, first-level head * /
    //     if (!node) return 0;
    //     for (;;) {
    //       if (!strcmp((const char *)(node + 0x8C), needle)) return node;
    //       int child = *(int *)(node + 0x1B0);
    //       if (child && !strcmp((const char *)(child + 0x8C), needle)) return child;
    //       node = *(int *)(node + 0x1B8);
    //       if (!node) return 0;
    //     }
    //   }
    // UNRESOLVED: Object type of this and node layout (string field at +0x8C, child at +0x1B0, next at +0x1B8) is unknown.
    // UNRESOLVED: Semantics of the two-level structure (why a node carries one second-level child) are not evident from this function alone.
    // UNRESOLVED: field:this:0x000002A8 (this[170]) is not accessed anywhere in the raw source; its role in this function is unknown.
}
