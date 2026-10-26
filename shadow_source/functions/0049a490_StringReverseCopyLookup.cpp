// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A490
// Canonical corpus name: StringReverseCopyLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringReverseCopyLookup_0049a490.c

void UnknownObject::StringReverseCopyLookup()
{
    // Lookup helper keyed by a transformed copy of a string. Copies argument a2 into a 256-byte stack buffer, passes the copy through sub_589901 (the named string transform step), then looks the result up with HashTableSearch(this, SrcStr). On a hit it invokes FunctionCallWrapper_a2e0(a3); on a miss it calls ResourceLookupOrCreate(this, SrcStr, a3) to obtain or create the resource. Always returns 0.
    // ASSIGNMENT: Initialize the stack buffer by zeroing its first character. [source:raw]
    // CALL: Copy argument a2 into the 256-byte stack buffer with strcpy. [source:raw]
    // CALL: Transform the buffer contents with sub_589901 before it is used as a lookup key. [callee:0x00589901, source:raw]
    // GUARD: Branch on the result of HashTableSearch(this, SrcStr): non-zero selects the hit path, zero selects the miss path. [callee:0x0049A360, source:raw]
    // CALL: On a hash-table hit, dispatch argument a3 through FunctionCallWrapper_a2e0. [callee:0x0049A2E0, source:raw]
    // CALL: On a hash-table miss, call ResourceLookupOrCreate(this, SrcStr, a3) to fetch or create the resource. [callee:0x0049A3B0, source:raw]
    // RETURN: Return the constant zero from both branches. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49A490(void* this, const char* a2, int a3) {
    //     char buf[256];
    //     buf[0] = 0;
    //     strcpy(buf, a2);
    //     sub_589901(buf);
    //     if (HashTableSearch(this, buf))
    //       FunctionCallWrapper_a2e0(a3);
    //     else
    //       ResourceLookupOrCreate(this, buf, a3);
    //     return 0;
    //   }
    // UNRESOLVED: What sub_589901 does to the string (reverse, case-normalize, or other transform) and whether it matches the class implied by the ABI name is unverified.
    // UNRESOLVED: The nature of the lookup key and the value produced by ResourceLookupOrCreate is caller-dependent; callers span UI event and scrollbar handling paths.
}
