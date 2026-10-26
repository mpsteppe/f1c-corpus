// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D240
// Canonical corpus name: GameStateDispatchChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameStateDispatchChain_0040d240.c

void UnknownObject::GameStateDispatchChain()
{
    // Unconditional game-state change dispatch chain. Sets the player vehicle index to a2, refreshes the camera target and camera view for the change, dispatches conditional audio/virtual state, emits an AI out-of-track event for the new target, then calls the completion handler sub_4D8760(1, 0) and returns its result. No guards; every step runs in sequence.
    // CALL: Set the player vehicle index to a2 (the newly selected vehicle). [callee:0x0042BBD0, source:raw]
    // CALL: Update the camera target to the player on player change, using the this context. [callee:0x0040C7A0, source:raw]
    // CALL: Assign the camera view based on this context and the new target a2. [callee:0x0040C650, source:raw]
    // CALL: Dispatch conditional audio/virtual state for the player-change context. [callee:0x0040D090, source:raw]
    // CALL: Trigger the AI out-of-track event for the new vehicle a2. [callee:0x0041A0C0, source:raw]
    // CALL: Call the completion handler sub_4D8760 with constant arguments (1, 0). [callee:0x004D8760, source:raw]
    // RETURN: Return the result of the completion handler sub_4D8760(1, 0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40D240(void *this, int vehicleIndex) {
    //     SetPlayerVehicleIndex(vehicleIndex);
    //     CameraTargetUpdateOnPlayerChange(this);
    //     CameraViewAssignment(this, vehicleIndex);
    //     VirtualDispatchConditionalAudio(this);
    //     AIOutOfTrackEvent(vehicleIndex);
    //     return sub_4D8760(1, 0);
    //   }
    // UNRESOLVED: Globals dword_5EB978, unk_5EC6D0 and dword_8AD298 appear in the deterministic global facts for this function but are not referenced by the shown pseudocode; their exact role in the real body is unknown.
    // UNRESOLVED: Identity and purpose of the this object is unknown (no fields were recovered).
    // UNRESOLVED: Semantics of the completion handler sub_4D8760(1, 0) and of the constants 1 and 0 are unknown.
}
