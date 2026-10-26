// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C086
// Canonical corpus name: SetterReturnA4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetterReturnA4_0051c086.c

void UnknownObject::SetterReturnA4()
{
    // Minimal four-argument setter. Stores the value of a3 into the dword pointed to by a4 and returns the a4 pointer unchanged. Arguments a1 and a2 are unused by the body. The ABI lead names it SetterReturnA4, consistent with a write-and-return-pointer helper.
    // ASSIGNMENT: Store a3 into the dword addressed by a4: *a4 = a3. [source:raw]
    // RETURN: return the a4 pointer (the destination address) unchanged, matching the ABI-named SetterReturnA4 pattern [abi:lead, function:0x0051C086, source:raw]

    // Conservative worker pseudocode:
    //   result = a4;
    //   *a4 = a3;
    //   return result;
    // UNRESOLVED: Arguments a1 and a2 are present in the prototype but never referenced by the body; their role is unknown.
    // UNRESOLVED: The ABI name SetterReturnA4 is a legacy heuristic; no caller or owning object is evidenced in the packet to confirm which structure field a4 addresses.
}
