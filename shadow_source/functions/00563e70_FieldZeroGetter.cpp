// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563E70
// Canonical corpus name: sub_563E70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_563E70_00563e70.c

void UnknownObject::FieldZeroGetter()
{
    // Trivial __thiscall getter: returns the 32-bit value stored at field 0x0 of `this`. No side effects. Called from twelve sites concentrated in network/system dispatch paths (StartNetworkUpdate, ConditionalNetworkSystemDispatch, VehicleStateQueryAtLargeOffset, NetworkConnection, TwoStepDispatch and related), suggesting the returned field is a lightweight object state/identity query used by those dispatchers.
    // RETURN: Return the 32-bit value read from field 0x0 of `this`. No side effects. [field:this:0x00000000, source:raw]
    // CALL: Called by twelve sites including network/system dispatch paths (StartNetworkUpdate 0x00461DE0, ConditionalNetworkSystemDispatch 0x00461F90, VehicleStateQueryAtLargeOffset 0x00461FC0, NetworkConnection 0x00563260) which read this getter's result. [caller:0x00461DE0, caller:0x00461F90, caller:0x00461FC0, caller:0x00563260, source:raw]

    // Conservative worker pseudocode:
    //   int FieldZeroGetter(void *this) {
    //     return *(int *)this;
    //   }
    // UNRESOLVED: Field 0x0 semantics and the owning object type are unknown; the value is consumed across network/dispatch paths, so it likely encodes an object state or identity, but that meaning is unproven.
    // UNRESOLVED: Getter-return value is not masked or checked here; any interpretation depends on the callers.
}
