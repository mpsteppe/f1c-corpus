// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495810
// Canonical corpus name: StringNormalizeLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringNormalizeLookup_00495810.c

void UnknownObject::StringNormalizeLookup()
{
    // Normalizes a copy of the input string via sub_589901, then tests membership in a hash table through sub_587C20 against the head dword_5CC79C. On a miss it extends the string at its terminator with the raw 4-byte hash head value dword_5CC79C followed by the single-byte value byte_5CC7A0 to form a compound key. The resulting string is passed to CollisionNodeAllocator and its result returned. A NULL input returns -1 immediately.
    // GUARD: Guard on the input pointer a1: when it is NULL, return -1 immediately without processing. [field:this:0x00000000, source:raw]
    // LOOP: Copy the input string into the 80-byte local buffer SrcStr, advancing both pointers and including the terminating NUL byte. [source:raw]
    // CALL: Call sub_589901 on the local copy SrcStr to normalize the string. [callee:0x00589901, source:raw]
    // CALL: Call sub_587C20(SrcStr, &dword_5CC79C) to test whether the normalized string is already present in the hash table addressed by dword_5CC79C. [callee:0x00587C20, global:0x005CC79C, source:raw]
    // GUARD: When the lookup returns 0 (string not found), build a compound key: write the raw 4-byte value dword_5CC79C at the string terminator, then the single byte byte_5CC7A0 immediately after it. [global:0x005CC79C, global:0x005CC7A0, source:raw]
    // RETURN: Return CollisionNodeAllocator(SrcStr), handing the (possibly extended) string to the collision node allocator and propagating its result. [callee:0x00494DE0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_495810(char *a1) {
    //     if (!a1) return -1;
    //     char SrcStr[80];
    //     char *s = a1, *d = SrcStr;
    //     do { *d = *s; ++d; } while (*s++);
    //     sub_589901(SrcStr);
    //     if (!sub_587C20(SrcStr, &dword_5CC79C)) {
    //       char *end = SrcStr + strlen(SrcStr);
    //       *(unsigned int *)end = dword_5CC79C;
    //       end[4] = byte_5CC7A0;
    //     }
    //     return CollisionNodeAllocator(SrcStr);
    //   }
    // UNRESOLVED: global:0x007CDE00 is listed as a referenced global but does not appear in the raw source text; its role is unknown.
    // UNRESOLVED: The exact normalization performed by sub_589901 is not defined in this function.
    // UNRESOLVED: The compound-key layout (4-byte hash head value plus extension byte) is DERIVED from the raw write pattern; the interpretation of byte_5CC7A0 as a file-extension tag comes from existing analysis and is not proven here.
    // UNRESOLVED: The semantics of the sub_587C20 return contract (non-zero meaning 'present') are DERIVED from the branch structure.
    // UNRESOLVED: Caller DriverNameStringHandler (0x00497EC0) suggests a driver/name resolution context, but the linkage is external to this function.
}
