// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052803A
// Canonical corpus name: DelegationWrapper_803a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWrapper_803a_0052803a.c

void UnknownObject::DelegationWrapper_803a()
{
    // Thin __cdecl delegation wrapper: ignores its first argument a1 and forwards a2 and a3 to sub_58AB58, returning that callee's result unchanged.
    // CALL: Forward the call to sub_58AB58(a2, a3). [callee:0x0058AB58]
    // RETURN: Return the result of sub_58AB58 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_52803A(int a1, int a2, int a3) {
    //     return sub_58AB58(a2, a3);
    //   }
    // UNRESOLVED: Purpose of the ignored first argument a1 is unknown.
    // UNRESOLVED: Semantics of sub_58AB58 (callee) are outside this packet.
}
