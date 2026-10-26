// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434090
// Canonical corpus name: LinkedListMergeSort
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListMergeSort_00434090.c

void UnknownObject::LinkedListMergeSort()
{
    // Merge sort over a singly linked list of string entries, storing the result head/tail back into a small result struct (this[0]=head, this[4]=tail, this[8]=head duplicate). Splits the list at its midpoint, recursively sorts each half via LinkedListMergeSort_4290, then merges the halves in ascending order using a byte-wise lexicographic comparison with a 2-byte stride (wide-character style); nodes whose string pointer is null fall back to byte_5EA438. Reconnects head and tail pointers after sorting. Used by DirectoryFileEnumerator during directory entry enumeration.
    // GUARD: Proceeds only when the head pointer this[0] is non-null; otherwise skips counting and sorting. [field:this:0x00000000, source:raw]
    // LOOP: Count list nodes by walking the next pointer at each node offset 4 until the null terminator. [field:obj:0x00000004, source:raw]
    // GUARD: Proceeds to split/sort only when the node count is at least 2; single-node lists need no sort. [source:raw]
    // CALCULATION: Compute the split index as (node count / 2) minus 1. [source:raw]
    // LOOP: Advance the walk pointer from the head by the split index to reach the midpoint node, following node offset 4. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Split the list: capture the right half head from the midpoint node's next pointer, then write 0 into that next pointer to null-terminate the left half. [field:*(obj+0x4):0x00000004, source:raw]
    // CALL: Recursively sort the left half via LinkedListMergeSort_4290. [callee:0x00434290, source:raw]
    // CALL: Recursively sort the right half via LinkedListMergeSort_4290. [callee:0x00434290, source:raw]
    // GUARD: Proceeds with the merge only when both sorted halves are non-null. [source:raw]
    // ASSIGNMENT: Resolve the comparison strings for the two head nodes, substituting the fallback &byte_5EA438 when a node's string pointer is null. [global:0x005EA438, source:raw]
    // LOOP: Byte-wise lexicographic comparison of the two strings in 2-byte steps, comparing low then high byte before advancing. [source:raw]
    // CALCULATION: Derive the ordering sign from the comparison carry/equality flags to decide which node precedes. [source:raw]
    // GUARD: Pick the head node of the merged output from either the left or the right half depending on the comparison sign. [source:raw]
    // LOOP: Merge the remaining nodes of both halves, relinking node next pointers (offset 4) in ascending string order until one half is exhausted. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Write the sorted head into this[0]. [field:this:0x00000000, source:raw]
    // LOOP: Walk the merged list to its last node to recover the tail. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Write the recovered tail into this[4]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the sorted head again into this[8] as a duplicate head reference. [field:this:0x00000008, source:raw]
    // RETURN: Return the trailing merge value (the remaining node reference or 0). [source:raw]
    // CALL: Invoked by DirectoryFileEnumerator to order directory entries. [caller:0x00431DB0, source:raw]

    // Conservative worker pseudocode:
    //   n = 0;
    //   p = this[0];
    //   while (p) { n++; p = node_next(p); }
    //   if (this[0] && n >= 2) {
    //     m = n/2 - 1; p = this[0];
    //     while (m > 0) { m--; p = node_next(p); }
    //     right = node_next(p);
    //     node_next(p) = 0;
    //     left = LinkedListMergeSort_4290(this[0]);
    //     right = LinkedListMergeSort_4290(right);
    //     // merge: 2-byte lexicographic string compare, null string -> &byte_5EA438
    //     merged = merge_by_string(left, right);
    //     this[0] = merged;
    //     this[4] = tail(merged);
    //     this[8] = merged;
    //   }
    //   return trailing;
    // UNRESOLVED: The a2 argument is never referenced in the visible decompilation; its purpose is unknown.
    // UNRESOLVED: The class of the sort-result object (this[0]/this[4]/this[8]) and of the list nodes (data pointer at node+0, next at node+4) is not identified from this packet.
    // UNRESOLVED: The wide-character (2-byte stride) interpretation of the string comparison is DERIVED from the comparison loop; the content of byte_5EA438 is not visible here.
}
