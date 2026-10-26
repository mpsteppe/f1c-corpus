// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512093
// Canonical corpus name: ThreeObjectCleanupChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeObjectCleanupChain_00512093.c

void UnknownObject::ThreeObjectCleanupChain()
{
    // Guarded three-object teardown helper (structural twin of ObjectAllocator 0045bb90). Dereferences up to three pointer slots a1/a2/a3 into v6/v4/v5, partially resets the first object via LargeStructPartialReset, then delegates each non-null object through GuardedDelegate and zeroes its slot; returns the last assigned value (the first dereferenced value of a1 if nothing else ran).
    // ASSIGNMENT: If a1 is non-null, read the first dword of *a1 into v6. [source:raw]
    // ASSIGNMENT: If a2 is non-null, read the first dword of *a2 into v4. [source:raw]
    // ASSIGNMENT: If a3 is non-null, read the first dword of *a3 into v5. [source:raw]
    // CALL: If v6 is non-zero, call LargeStructPartialReset(v6, v4, v5) to partially reset the first object using all three cached values. [callee:0x00511F70, source:raw]
    // CALL: If v4 is non-zero, call GuardedDelegate(v4). [callee:0x00517E85, source:raw]
    // ASSIGNMENT: If v4 is non-zero, clear the first dword at a2 to 0. [field:this:0x00000000, source:raw]
    // CALL: If v5 is non-zero, call GuardedDelegate(v5). [callee:0x00517E85, source:raw]
    // ASSIGNMENT: If v5 is non-zero, clear the first dword at a3 to 0. [field:this:0x00000000, source:raw]
    // CALL: If v6 is non-zero, call GuardedDelegate(v6). [callee:0x00517E85, source:raw]
    // ASSIGNMENT: If v6 is non-zero, clear the first dword at a1 to 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the accumulated result, initially the address of a1. [source:raw]

    // Conservative worker pseudocode:
    //   v6 = a1 ? *a1 : 0;
    //   v4 = a2 ? *a2 : 0;
    //   v5 = a3 ? *a3 : 0;
    //   if (v6) result = LargeStructPartialReset(v6, v4, v5);
    //   if (v4) { GuardedDelegate(v4); *a2 = 0; }
    //   if (v5) { GuardedDelegate(v5); *a3 = 0; }
    //   if (v6) { GuardedDelegate(v6); *a1 = 0; }
    //   return result;
    // UNRESOLVED: Relationship between the three objects and the meaning of LargeStructPartialReset's three-argument shape is inferred from the structural twin, not proven.
}
