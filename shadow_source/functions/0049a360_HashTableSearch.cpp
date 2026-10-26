// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A360
// Canonical corpus name: HashTableSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableSearch_0049a360.c

void UnknownObject::HashTableSearch()
{
    // Hash-table bucket-chain lookup by string key: normalizes the key via sub_589901, converts it to a bucket index with CharToIndexConversion (returning 0 when the conversion yields -1 or the bucket head this[index] is null), then walks the singly-linked chain at node+24, reading each node's string pointer via StringPointerDereference and comparing with sub_588410; returns the node whose string compares equal, or 0 when the chain ends. Prelabel marks it a structural twin of sub_45B5C0 (DERIVED).
    // CALL: Call sub_589901(lpSrcStr) first; a key-normalization helper applied to the search string. [callee:0x00589901, source:raw]
    // CALL: Call CharToIndexConversion(lpSrcStr) to obtain the bucket index v3 for the key. [callee:0x0049A330, source:raw]
    // GUARD: If v3 == -1, the key did not convert to a valid bucket index; return 0. [source:raw]
    // ASSIGNMENT: Read the bucket head v4 = this[v3], the dword at index v3 of the bucket array. [source:raw]
    // GUARD: If the bucket head v4 is null, the bucket is empty; return 0. [source:raw]
    // LOOP: Walk the chain of nodes starting at v4: read the node's string, test equality, and advance through the next-node link at v4+24 until a match or a null link. [source:raw]
    // CALL: Read the node's string pointer v5 via StringPointerDereference((char**)v4). [callee:0x0049A2B0, source:raw]
    // CALL: Compare the node's string against the key with sub_588410(v5, lpSrcStr); a zero return breaks the loop. [callee:0x00588410, source:raw]
    // GUARD: On a match (sub_588410 returns 0) break; otherwise advance v4 = *(DWORD*)(v4+24) to the next node and, if that link is null, return 0. [source:raw]
    // RETURN: Return v4, the chain node whose string matched the key, or 0 when no match exists in the bucket. [source:raw]

    // Conservative worker pseudocode:
    //   sub_589901(key);
    //   index = CharToIndexConversion(key);
    //   if (index == -1) return 0;
    //   node = this[index];
    //   if (node == 0) return 0;
    //   while (node != 0) {
    //       s = StringPointerDereference((char**)node);
    //       if (sub_588410(s, key) == 0) break;
    //       node = *(node + 24);
    //   }
    //   return node;
    // UNRESOLVED: sub_588410 is not in this packet; a zero return breaks the loop so it behaves as a string-equality test, but its exact contract is corpus-side knowledge, not packet evidence.
    // UNRESOLVED: The dword at node+24 is treated as the next-node chain link; the node layout (string pointer field and link field) is not evidenced beyond these two accesses.
    // UNRESOLVED: CharToIndexConversion's transform (hash or first-char index) is not evidenced; -1 signals an invalid or unconvertible key.
    // UNRESOLVED: Owner is unknown; prelabel marks it a structural twin of sub_45B5C0 (DERIVED), and callers StringNormalizeLookup_a460 and StringReverseCopyLookup use it as a keyed lookup.
}
