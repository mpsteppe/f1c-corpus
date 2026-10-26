// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415550
// Canonical corpus name: LinkedListIndexScannerWithValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListIndexScannerWithValidation_00415550.c

void UnknownObject::LinkedListIndexScannerWithValidation()
{
    // Scans a linked list (head at this[4], node count at this[7]) to find the index of the node whose string matches a2, using sub_566810 for comparison. Returns the matching index, or -1 when a2 is null, the list is empty, or no node matches. Null node strings fall back to the global byte_5EA438 before comparison.
    // ASSIGNMENT: Initialize the result to -1 (not found) before any validation. [source:raw]
    // GUARD: Guard on a2 being non-null; a null search string returns -1 immediately. [source:raw]
    // ASSIGNMENT: Read the list node count from this[7] and bail when it is not positive. [field:this:0x0000001C]
    // LOOP: Iterate candidate indices starting at 0, validating each index against the stored count at this[7]. [field:this:0x0000001C]
    // ASSIGNMENT: Load the list head from this[4] and walk forward via the next pointer at node+0x4 to reach the requested index. [field:this:0x00000010, field:*(this+0x14):0x00000004]
    // ASSIGNMENT: Dereference the node data pointer to obtain the node string; when the string pointer is null, fall back to byte_5EA438. [field:*(this+0x10):0x00000000, global:0x005EA438]
    // CALL: Compare the candidate node string against a2 via sub_566810. [callee:0x00566810]
    // RETURN: Return the current index when the string comparison succeeds. [source:raw, function:0x00415550]
    // RETURN: Return -1 when the index runs past the stored count without a match. [field:this:0x0000001C]

    // Conservative worker pseudocode:
    //   int LinkedListIndexScannerWithValidation(_DWORD *this, char *needle) {
    //     if (!needle) return -1;
    //     int count = this[7];
    //     if (count <= 0) return -1;
    //     for (int idx = 0; idx < count; ++idx) {
    //       int node = this[4];
    //       for (int step = idx; node && step > 0; --step) node = *(int *)(node + 4);
    //       if (!node) continue;
    //       char *s = **(char ***)node;
    //       if (!s) s = &byte_5EA438;
    //       if (sub_566810(s, needle)) return idx;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The return convention of sub_566810 (truthy on match versus zero on match) is inferred only from usage.
    // UNRESOLVED: Whether the first node's data slot is itself the string or a containing structure is unresolved.
    // UNRESOLVED: Out-of-bounds indices compare against the byte_5EA438 fallback string in the raw control flow, which is preserved rather than interpreted.
}
