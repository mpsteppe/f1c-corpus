// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477810
// Canonical corpus name: UtilityFunction_7810
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_7810_00477810.c

void UnknownObject::dispatchSceneCommandByMode()
{
    // Conditional dispatch through the interface pointer dword_7CD8C0: if the discriminator at this+0x180 equals 24, calls vtable slot +28 with command ID 23; otherwise calls the same slot with command ID 21. The dispatch result is returned. Called by ShortComputation_75f0 (0x004775F0) and SeasonSceneInitialization (0x00477720).
    // GUARD: If this+0x180 equals 24, take the command-23 dispatch path; otherwise the command-21 path. [guard:0, field:this:0x00000180]
    // CALL: Invoke vtable slot +28 of dword_7CD8C0 with command ID 23 (mode == 24 branch). [global:0x007CD8C0, function:0x00477810, source:raw]
    // CALL: Invoke vtable slot +28 of dword_7CD8C0 with command ID 21 (mode != 24 branch). [global:0x007CD8C0, function:0x00477810, source:raw]
    // RETURN: Return the dispatch result. [function:0x00477810]

    // Conservative worker pseudocode:
    //   int cmd = (this[96] == 24) ? 23 : 21;
    //   return dword_7CD8C0->slot28(dword_7CD8C0, cmd);
    // UNRESOLVED: The interface behind dword_7CD8C0 (proposed GameCommandDispatchInterface elsewhere) and the meaning of command IDs 21/23 are not established by this function alone.
    // UNRESOLVED: The type of the object owning this+0x180 is unknown.
}
