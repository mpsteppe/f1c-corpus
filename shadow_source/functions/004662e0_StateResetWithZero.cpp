// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004662E0
// Canonical corpus name: StateResetWithZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateResetWithZero_004662e0.c

void UnknownObject::StateResetWithZero()
{
    // State-reset helper for an unknown object. Calls ResourceCleanup (0x0048E890) to release attached resources, then zeroes the dword field at this+0xF0 (array index 60) as part of the reset. Returns 1 as a success indicator. Called from ShortComputation_6140 (0x00466140).
    // CALL: Call ResourceCleanup at 0x0048E890 to release resources attached to the object. [callee:0x0048E890]
    // ASSIGNMENT: Zero the dword field at this+0xF0 (array index 60), clearing the stored state as part of the reset. [field:this:0x000000F0, source:raw]
    // RETURN: Return 1 as a success indicator; invoked by ShortComputation_6140 (0x00466140). [function:0x004662E0, caller:0x00466140, abi:lead]

    // Conservative worker pseudocode:
    //   char sub_4662E0(void* this) {
    //     ResourceCleanup();
    //     this[60] = 0;
    //     return 1;
    //   }
    // UNRESOLVED: The object class owning this reset is not evidenced in this packet; the owner is UnknownObject.
    // UNRESOLVED: ResourceCleanup (0x0048E890) is called without an explicit receiver in the raw source; its exact side effects are outside this function.
}
