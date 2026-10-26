// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A520
// Canonical corpus name: sub_49A520
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49A520_0049a520.c

void UnknownObject::IDBasedListTraversalWithComparison()
{
    // String-keyed membership lookup. Normalizes the input string with sub_589901, then converts it to an index via CharToIndexConversion; if conversion yields -1 the function returns -1 immediately. Otherwise the index selects a bucket at this[result] in an array of linked-list heads; a null bucket returns 0. Each node's string is read through StringPointerDereference and compared with sub_588410 against the input; a match returns 1, otherwise traversal advances to the next node at v4+24, returning 0 when the list is exhausted.
    // CALL: Normalize the input string by calling sub_589901(lpSrcStr). [source:raw, callee:0x00589901]
    // CALCULATION: Convert the string to an index: result = CharToIndexConversion(lpSrcStr). [source:raw, callee:0x0049A330]
    // GUARD: If result == -1 (conversion produced no index), return -1 immediately; otherwise use result as an index into the this array. [source:raw]
    // GUARD: Load the bucket head v4 = this[result]; if it is null, return 0 (no entry). [source:raw]
    // LOOP: Traverse the bucket list: read the node's string v5 = StringPointerDereference(v4), compare it to lpSrcStr via sub_588410 and break on match (return 1); otherwise advance v4 to the next-node pointer at v4+24 (*(_DWORD*)(v4 + 24)) and return 0 if the list ends. [source:raw, callee:0x0049A2B0, callee:0x00588410]
    // RETURN: Return 1 when a node's string matches lpSrcStr, 0 on an empty or exhausted list, and -1 when CharToIndexConversion produced no index. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int IDBasedListTraversalWithComparison(int this, LPCSTR lpSrcStr) {
    //     sub_589901(lpSrcStr);
    //     unsigned int result = CharToIndexConversion(lpSrcStr);
    //     if (result == -1) return result;
    //     int v4 = this[result];
    //     if (!v4) return 0;
    //     for (;;) {
    //       char* v5 = StringPointerDereference((char**)v4);
    //       if (!sub_588410(lpSrcStr, v5)) break;
    //       v4 = *(_DWORD*)(v4 + 24);
    //       if (!v4) return 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: this is an indexed array of string-labelled node lists; the index semantics produced by CharToIndexConversion and the meaning of the -1 sentinel are unknown.
    // UNRESOLVED: Node layout is partially known: +0 holds a string pointer (via StringPointerDereference) and +24 the next-node pointer; remaining node fields are unknown.
    // UNRESOLVED: Semantics of sub_589901 and sub_588410 beyond string normalization and comparison are unverified.
}
