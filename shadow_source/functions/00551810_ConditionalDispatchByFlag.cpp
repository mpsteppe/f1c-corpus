// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551810
// Canonical corpus name: ConditionalDispatchByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatchByFlag_00551810.c

void UnknownObject::ConditionalDispatchByFlag()
{
    // __thiscall dispatch guard: when the second argument a2 is non-null, forwards the call to sub_551210(a2, this, a3), passing the caller-supplied a2 as that callee's this/primary object, this as its second argument, and the float a3 unchanged. When a2 is null the function does nothing. The name and semantics of a3 (a float scale or magnitude) are not evident here.
    // GUARD: Guard on a2 being non-null; the dispatch only happens when a2 is valid. [source:raw, function:0x00551810]
    // CALL: Call sub_551210(a2, (int)this, a3) passing a2 as the callee's primary object, this as its second argument and a3 as the float parameter. [source:raw, function:0x00551810]
    // RETURN: Implicit void return after the conditional dispatch. [source:raw]
    // CALL: Invoked by AudioDSPStateUpdate (0x00448330), VehicleRespawnReset (0x004E0800) and VehicleStateUpdate_19d0 (0x004E19D0) as a conditional step in each caller's frame/state update. [caller:0x00448330, caller:0x004E0800, caller:0x004E19D0]

    // Conservative worker pseudocode:
    //   void sub_551810(void *this, _DWORD *a2, float a3) {
    //     if (a2) sub_551210(a2, (int)this, a3);
    //   }
    // UNRESOLVED: Meaning of the float a3 and of the a2 pointer are caller-dependent; the callee sub_551210 is not profiled in this packet.
    // UNRESOLVED: The dispatch may select behavior by a flag/object in a2, hence the working name, but that flag is not visible in this function alone.
}
