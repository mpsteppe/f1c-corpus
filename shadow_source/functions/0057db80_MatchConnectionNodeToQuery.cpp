// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057DB80
// Canonical corpus name: sub_57DB80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57DB80_0057db80.c

void UnknownObject::MatchConnectionNodeToQuery()
{
    // Secondary match validator for connection-ID queries. Reads a DWORD field at this+0x4 and compares it against a3, and reads a WORD field at this+0x2 and compares it against HIWORD(a2); returns TRUE only when both comparisons succeed. Called by NetworkPacketSendWithQueryMatching (0x0057D8D0).
    // CALCULATION: Compare the DWORD connection-node field at this+0x4 against argument a3. [field:this:0x00000004, source:raw]
    // CALCULATION: Compare the WORD connection-node field at this+0x2 against HIWORD(a2), the high word of the query identifier. [field:this:0x00000002, source:raw]
    // RETURN: Return TRUE when both comparisons hold; the function is a pure boolean predicate with no side effects. [abi:lead, function:0x0057DB80, source:raw]

    // Conservative worker pseudocode:
    //   BOOL MatchConnectionNodeToQuery(int this, int a2, int a3) {
    //       return *(DWORD *)(this + 4) == a3
    //           && *(WORD *)(this + 2) == HIWORD(a2);
    //   }
    // UNRESOLVED: The semantics of the query identifier split across a2 (high word matched at +0x2) and a3 (full DWORD matched at +0x4) are caller-established and not evidenced here.
    // UNRESOLVED: The node structure layout and whether this predicate is called against multiple candidates or a single node is not evidenced.
}
