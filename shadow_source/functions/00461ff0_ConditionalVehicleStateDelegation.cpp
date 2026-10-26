// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461FF0
// Canonical corpus name: ShortComputation_1ff0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1ff0_00461ff0.c

void UnknownObject::ConditionalVehicleStateDelegation()
{
    // Guards a single delegation: calls VehicleStateQueryAtLargeOffset(this) and returns 0 immediately when it is nonzero; otherwise loads the delegate pointer from the object chain *(this) + offset 0x1B79C (112540 decimal) and returns the result of calling SingleDelegationCall on it. Structural twin of ConditionalNetworkSystemDispatch (00461f90).
    // CALL: Call VehicleStateQueryAtLargeOffset(this) to obtain the guard predicate. [callee:0x00461FC0, source:raw]
    // GUARD: When the query result is nonzero, return 0 immediately and skip the delegation. [source:raw]
    // CALCULATION: Dereference this+0x0 to get the object pointer, then load the delegate pointer from object offset 0x1B79C (112540 decimal). [field:this:0x00000000, field:obj:0x0001B79C, source:raw]
    // CALL: Call SingleDelegationCall with the loaded delegate pointer and return its result. [source:raw]
    // RETURN: Return the delegation result, or 0 when the query guard fired. [source:raw]
    // CALL: Called by sub_475150 (0x00475150). [caller:0x00475150, source:raw]

    // Conservative worker pseudocode:
    //   int sub_461FF0(void* this) {
    //     if (VehicleStateQueryAtLargeOffset(this))
    //       return 0;
    //     return SingleDelegationCall(*(_DWORD*)(*(_DWORD*)this + 112540));
    //   }
    // UNRESOLVED: SingleDelegationCall appears in the raw source text but has no callee address in the deterministic packet; its target address is unknown.
    // UNRESOLVED: Semantics of the object at offset 0x1B79C and of the query performed by VehicleStateQueryAtLargeOffset are not established here.
    // UNRESOLVED: Owner object type is unknown (owner left UNKNOWN).
}
