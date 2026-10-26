// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C8F0
// Canonical corpus name: sub_49C8F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C8F0_0049c8f0.c

void UnknownObject::StringTableLookupToBuffer()
{
    // String-table lookup and copy keyed on the global pointer table off_5CCBF8: binary-searches the string table rooted at byte_5EC4C0 with key byte_5EC4CC; on a match, copies the found string (or an empty string when null) into byte_5EC4CC, then copies byte_5EC4CC into the caller-supplied buffer a1 with a cap of a2 - 1 and null-termination. Returns 0.
    // ASSIGNMENT: Load v2 = off_5CCBF8[0], the candidate string taken from the global pointer table entry. [function:0x0049C8F0, global:0x005CCBF8, source:raw]
    // GUARD: Call BinarySearchInStringTable(byte_5EC4C0, off_5CCBF8[0], byte_5EC4CC); when it returns non-zero (match found), take the copy branch; otherwise the lookup branch is skipped. [callee:0x00423A00, global:0x005CCBF8, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // GUARD: Within the match branch, when v2 is non-null copy it with strcpy into byte_5EC4CC; when v2 is null, write a terminating NUL into byte_5EC4CC[0]. [global:0x005EC4CC, source:raw]
    // CALL: Copy from byte_5EC4CC into the output buffer a1 with a maximum length of a2 - 1 via sub_587DD0. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Null-terminate the output buffer at byte offset a2 - 1 within a1. [source:raw]
    // RETURN: Return 0 on every completion path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49C8F0(int a1, int a2) {
    //     const char *v2 = off_5CCBF8[0];
    //     if (BinarySearchInStringTable(byte_5EC4C0, off_5CCBF8[0], byte_5EC4CC)) {
    //       if (v2) strcpy(byte_5EC4CC, v2);
    //       else byte_5EC4CC[0] = 0;
    //     }
    //     sub_587DD0(a1, byte_5EC4CC, a2 - 1);
    //     *(_BYTE *)(a2 - 1 + a1) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The string table referenced by off_5CCBF8 has no identified purpose; its content domain (e.g. driver, team, or generic text) is unresolved.
    // UNRESOLVED: byte_5EC4C0 as a string-table root and byte_5EC4CC as a key/output message buffer are DERIVED from the fill and the call pattern, not proven by the packet.
    // UNRESOLVED: BinarySearchInStringTable's binary-search semantics are assumed from its name; its argument ordering is only inferred.
    // UNRESOLVED: The three callers (TimestampedRenderStringUpdate, TextRenderWithShadow, MultiLayerTextRendering) all render text, suggesting a text/string-table role, but that link is not evidenced inside the packet.
}
