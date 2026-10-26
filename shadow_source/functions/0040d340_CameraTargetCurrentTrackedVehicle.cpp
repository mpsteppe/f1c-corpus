// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D340
// Canonical corpus name: CameraTargetCurrentTrackedVehicle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraTargetCurrentTrackedVehicle_0040d340.c

void UnknownObject::CameraTargetCurrentTrackedVehicle()
{
    // Thin camera/game-state wrapper that targets the currently tracked vehicle. Reads the tracked-vehicle index global dword_7C54E4, indexes the vehicle pointer array dword_7C54F0 with it, reads the value at byte offset 18580 of that vehicle, and dispatches a game-state change targeting it through GameStateDispatchChain.
    // CALCULATION: Read the tracked-vehicle index global dword_7C54E4, index the vehicle pointer array dword_7C54F0 with it, and read the int value at byte offset 18580 of the tracked vehicle (the finish-position value consumed by the dispatch). [global:0x007C54E4, global:0x007C54F0, function:0x0040D340, source:raw]
    // CALL: Dispatch the game-state change targeting the tracked vehicle through GameStateDispatchChain(this, vehicle value). [callee:0x0040D240, source:raw]
    // RETURN: Return the result of GameStateDispatchChain. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40D340(void* this) {
    //     int value = *(int*)(dword_7C54F0[dword_7C54E4] + 18580);
    //     return GameStateDispatchChain(this, value);
    //   }
    // UNRESOLVED: The exact meaning of the value at vehicle byte offset 18580 is inferred as a finish position from the parallel camera-target function using the same offset; its field name is unknown.
    // UNRESOLVED: The meaning of the tracked-vehicle index global dword_7C54E4 (distinct from the player index dword_7C54DC used by the race-leader camera target) is unknown.
    // UNRESOLVED: Identity and purpose of the this object (no fields recovered) are unknown.
    // UNRESOLVED: Whether the game-state dispatch targets a vehicle, a team, or a derived entity is decided inside GameStateDispatchChain and is unresolved here.
}
