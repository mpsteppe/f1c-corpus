// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AFA0
// Canonical corpus name: Wrapper_afa0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Wrapper_afa0_0049afa0.c

void UnknownObject::Call4B3DB0On7CE048()
{
    // Trivial single-call wrapper. Passes the address of global dword_7CE048 as the sole argument to sub_4B3DB0 and returns that callee's result unchanged. No branches, no local computation, no own parameters.
    // CALL: Call sub_4B3DB0 with the address of global dword_7CE048 as its single argument. [global:0x007CE048, source:raw]
    // RETURN: Return the value produced by sub_4B3DB0 without modification. [function:0x0049AFA0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49AFA0() {
    //     return sub_4B3DB0(&dword_7CE048);
    //   }
    // UNRESOLVED: Callee sub_4B3DB0 is not listed in the packet callees; its signature and behavior are unknown here.
    // UNRESOLVED: Semantic purpose of global dword_7CE048 passed as the argument is unknown.
}
