// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1100
// Canonical corpus name: ConditionalDelegateDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDelegateDispatch_004d1100.c

void UnknownObject::ConditionalDelegateDispatch()
{
    // Conditional grid-position sync: when the vehicle's grid position index at this+0x48A4 is negative (not yet allocated), recalculate it via sub_4C6F10; then unconditionally copy grid slot data from the setup-scene array (dword_5EA2C0) via ArrayOfStructIndexedFieldCopy and return its result.
    // GUARD: Guard (packet guard:0): when the signed grid position index at this+0x48A4 is < 0 (unallocated), recalculate it. [guard:0, field:this:0x000048A4, function:0x004D1100, source:raw]
    // CALL: sub_4C6F10(a1): allocate/find a free grid position for this vehicle, storing the index at +0x48A4. [callee:0x004C6F10, function:0x004D1100, source:raw]
    // CALL: Return ArrayOfStructIndexedFieldCopy(dword_5EA2C0, a1[0x48A4], a2, a3): copy the grid slot data from the setup-scene array (global dword_5EA2C0) indexed by the vehicle's grid position index. [callee:0x00403F70, global:0x005EA2C0, field:this:0x000048A4, function:0x004D1100, source:raw]
    // RETURN: The function's result is the pointer returned by ArrayOfStructIndexedFieldCopy. [callee:0x00403F70, function:0x004D1100, source:raw]

    // Conservative worker pseudocode:
    //   if ((int)a1[4649] < 0) sub_4C6F10(a1);
    //   return ArrayOfStructIndexedFieldCopy(dword_5EA2C0, a1[4649], a2, a3);
    // UNRESOLVED: The owner object is unidentified; callers span physics (VehicleMainPhysicsUpdate), AI (AIStateMachineWithModeDispatch), pit-crew (PitCrewAnimationLoader) and render (SceneRenderUpdate) paths.
    // UNRESOLVED: The exact layout of the copied struct from dword_5EA2C0 is not visible in this function.
}
