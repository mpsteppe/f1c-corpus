// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A210
// Canonical corpus name: StringMatchedLinkedListSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringMatchedLinkedListSearch_0049a210.c

void UnknownObject::StringMatchedLinkedListSearch()
{
    // Searches a linked list whose head is stored at this+0x00 (v2 = *this) for a node whose string matches key a2. For each node, reads its string via StringPointerAccessor (00499E20), compares it with sub_588410 (0 result = match), and advances to the next node via sub_499E00 (00499E00). Returns the matching node pointer, or 0 when a2 is null, the list is empty, or the list is exhausted. Invoked by sub_492A40, sub_493060 and sub_493480 for name-keyed lookups.
    // GUARD: Null-guard on the search key a2: if (!a2) return 0 immediately [source:raw]
    // ASSIGNMENT: v2 = *this reads the head of the linked list stored at this+0x00 [field:this:0x00000000, source:raw]
    // GUARD: Empty-list guard: if the head *this is null, return 0 (no nodes to search) [field:this:0x00000000, source:raw]
    // LOOP: Infinite search loop over the list: read the node string, compare it, and break on match; otherwise advance via sub_499E00 and return 0 when the next node is null [source:raw]
    // CALL: Call StringPointerAccessor(v2) (00499E20) to obtain the current node's string pointer [callee:0x00499E20, source:raw]
    // CALL: Call sub_588410(a2, v3) (00588410) as a string comparison; a 0 result (match) breaks the loop [callee:0x00588410, source:raw]
    // CALL: Call sub_499E00(v2) (00499E00) to get the next node; a null result returns 0 (key not found) [callee:0x00499E00, source:raw]
    // RETURN: Return the matching node pointer v2, or 0 when a2 is null, the list is empty, or the list is exhausted [function:0x0049A210, source:raw]
    // CALL: Invoked by sub_492A40 (00492A40), sub_493060 (00493060) and sub_493480 (00493480) for name-keyed lookups [caller:0x00492A40, caller:0x00493060, caller:0x00493480, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   v2 = *this;
    //   if (!*this) return 0;
    //   while (1) {
    //     v3 = StringPointerAccessor(v2);
    //     if (!sub_588410(a2, v3)) break;
    //     v2 = sub_499E00(v2);
    //     if (!v2) return 0;
    //   }
    //   return v2;
    // UNRESOLVED: The traversal helpers sub_499E00 (next-node accessor) and StringPointerAccessor are not described in this packet; their node-advance/string-read roles are inferred from the loop structure
    // UNRESOLVED: The exact comparison semantics of sub_588410 (0 = match) are inferred from the loop-exit condition only, not proven independently
    // UNRESOLVED: The list-head slot at this+0x00 and the node field layout are not further documented; the prelabel names this a structural twin of UtilityFunction_3d50 (00463d50) via cluster_copy
}
