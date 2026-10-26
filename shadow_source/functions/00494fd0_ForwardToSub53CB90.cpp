// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494FD0
// Canonical corpus name: ThunkToFUN0053cb90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN0053cb90_00494fd0.c

void UnknownObject::ForwardToSub53CB90()
{
    // Pure __stdcall thunk: passes its single argument a1 unchanged to sub_53CB90 and returns that function's result. Called from sub_4963D0, LinkedListNodeRemovalByStringKey, and ResourceFileLoader. A read of global dword_8AFE64 is recorded by the static facts but is not visible in the raw source body.
    // CALL: Forward argument a1 unchanged to sub_53CB90 as a tail call. [source:raw, function:0x00494FD0]
    // RETURN: Return the value produced by sub_53CB90 without modification. [source:raw, caller:0x004963D0, caller:0x00497C40, caller:0x004F9D60]

    // Conservative worker pseudocode:
    //   int ForwardToSub53CB90(int a1) {
    //     return sub_53CB90(a1);
    //   }
    // UNRESOLVED: The packet records a read of global dword_8AFE64 (evidence global:0x008AFE64) that is not visible in the raw source body; its role in this thunk is unresolved.
    // UNRESOLVED: The purpose of sub_53CB90 is unknown here; only the forwarding relationship is evidenced.
}
