// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464930
// Canonical corpus name: SingleFunctionCallWrapper_4930
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_4930_00464930.c

void UnknownObject::AllocateAndInitLargeStruct()
{
    // Allocate a 58832-byte buffer, initialize a large struct into global dword_7CD2A8, and return its address.
    // CALL: Allocate 58832 bytes via OperatorNewNhMallocWrapper. [source:raw]
    // GUARD: Branch on the allocation result to distinguish success from failure. [source:raw]
    // ASSIGNMENT: On success set dword_7CD2A8 to the result of LargeStructInitialization(v0); on failure set dword_7CD2A8 to 0. [global:0x007CD2A8, source:raw]
    // RETURN: Return the address of dword_7CD2A8. [global:0x007CD2A8, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *AllocateAndInitLargeStruct() {
    //       int v0 = OperatorNewNhMallocWrapper(58832);
    //       dword_7CD2A8 = v0 ? LargeStructInitialization(v0) : 0;
    //       return &dword_7CD2A8;
    //   }
    // UNRESOLVED: Semantics and layout of the 58832-byte large struct are unknown.
    // UNRESOLVED: Packet labels global dword_7CD2A8 as rw=R even though the source writes it.
}
