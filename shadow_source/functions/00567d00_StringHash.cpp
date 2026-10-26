// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567D00
// Canonical corpus name: StringHash
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringHash_00567d00.c

void UnknownObject::StringHash()
{
    // Stdcall string hashing helper. Returns -1 for a null pointer, 0 for an empty string, and otherwise hashes four sampled characters (first, one-sixth, midpoint, last) run through a per-character transform helper sub_589A35, then reduces the result modulo 9, so the returned value is a 0..8 bucket index. Called by hash-table lookup and file-data processing paths.
    // GUARD: Null input guard: if (!a1) return -1. [source:raw, function:0x00567D00]
    // CALCULATION: Compute string length: v3 = strlen(a1). [source:raw]
    // GUARD: Only hash when the string is non-empty: if (v3 > 0). [source:raw]
    // CALL: Run the first character through the per-character transform helper: v4 = sub_589A35(*a1) (the a1[0] dereference recorded as field this+0x0). [callee:0x00589A35, field:this:0x00000000, source:raw]
    // CALL: Sample a character near the front of the string: v5 = sub_589A35(a1[v3 / 6]). [callee:0x00589A35, source:raw]
    // CALCULATION: Partial sum: v6 = v4 + 10 * v5 + v5. [source:raw]
    // CALL: Sample the midpoint character: v7 = sub_589A35(a1[v3 / 2]). [callee:0x00589A35, source:raw]
    // RETURN: Return (189 * v7 + v6 + 756 * v7 + 10097 * sub_589A35(a1[v3 - 1])) % 9, i.e. the weighted sum of the four transformed samples reduced modulo 9. [callee:0x00589A35, source:raw]
    // RETURN: Return v2 (0) when the string is empty (v3 == 0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_567D00(const char* s) {
    //     if (!s) return -1;
    //     int len = strlen(s);
    //     if (len > 0) {
    //       int c0 = sub_589A35(s[0]);
    //       int c1 = sub_589A35(s[len / 6]);
    //       int cm = sub_589A35(s[len / 2]);
    //       int cl = sub_589A35(s[len - 1]);
    //       return (c0 + 11 * c1 + 945 * cm + 10097 * cl) % 9;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: sub_589A35 is a per-character transform (likely case folding or normalization) whose exact behavior is outside this packet.
    // UNRESOLVED: Reducing modulo 9 yields a 0..8 result, consistent with a fixed 9-bucket hash table, but the table/bucket usage is not in this packet.
    // UNRESOLVED: The field evidence field:this:0x00000000 is a decompiler artifact of the a1[0] dereference; this stdcall function has no this pointer.
    // UNRESOLVED: strlen is an external CRT routine referenced only in the raw source; it is not in the packet callee table.
}
