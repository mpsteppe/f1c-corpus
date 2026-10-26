// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3020
// Canonical corpus name: DelegationThunk_3020
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationThunk_3020_004c3020.c

void UnknownObject::DelegationThunk_3020()
{
    // Delegation thunk: forwards the address of the global at 0x008AC368 as the single argument to the delegated routine sub_4B3DB0 and returns its void* result verbatim. Matches the packet's LEGACY ABI label Delegation_Thunk_4c3020.
    // CALL: Delegation call: invoke sub_4B3DB0 with the address of the global unk_8AC368 (0x008AC368) as the single argument. [abi:lead, global:0x008AC368, source:raw]
    // RETURN: Return the void* produced by sub_4B3DB0. [abi:lead, function:0x004C3020, source:raw]

    // Conservative worker pseudocode:
    //   void *DelegationThunk_3020(void) {
    //     return sub_4B3DB0(&unk_8AC368);
    //   }
    // UNRESOLVED: The delegated routine sub_4B3DB0 and the semantics of the forwarded global unk_8AC368 are not described anywhere in this packet.
    // UNRESOLVED: Why this function is a single-forward delegation thunk (receiver/method indirection) rather than a plain call is not determinable from the packet alone.
}
