// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536FD0
// Canonical corpus name: DelegationWrapper_6fd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWrapper_6fd0_00536fd0.c

void UnknownObject::DelegationWrapper_6fd0()
{
    // Thin __fastcall delegation wrapper: ignores its first argument a1 (in ECX) and forwards a2 and a3 to sub_58AB58, returning that callee's result unchanged.
    // CALL: Forward the call to sub_58AB58(a2, a3). [callee:0x0058AB58]
    // RETURN: Return the result of sub_58AB58 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID sub_536FD0(int a1, int a2, int a3) {
    //     return sub_58AB58(a2, a3);
    //   }
    // UNRESOLVED: Purpose of the ignored first argument a1 is unknown.
    // UNRESOLVED: Semantics of sub_58AB58 (callee) are outside this packet.
}
