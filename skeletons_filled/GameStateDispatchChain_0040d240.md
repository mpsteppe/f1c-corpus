## GameStateDispatchChain_0040d240 — GameStateDispatchChain

**Summary:** Coordinates game state change: sets player vehicle index, updates camera target to player, assigns camera view, resets camera effect, triggers AI out-of-track event, and calls completion handler.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraTargetRaceLeader (0040d290), VehicleSelectionCyclicShift (0040d2ca), CameraTargetCurrentTrackedVehicle (0040d340), sub_4A0250 (004a0250), sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c650 | CameraViewAssignment | assigns camera view mode based on target and current vehicle |
| 0040c7a0 | CameraTargetUpdateOnPlayerChange | updates camera target if player changed |
| 0040d090 | VirtualDispatchConditionalAudio | resets camera effect object and collision geometry state |
| 0041a0c0 | AIOutOfTrackEvent | triggers AI out-of-track event for the target |
| 0042bbd0 | SetPlayerVehicleIndex | sets the player vehicle index to the new target |
| 004d8760 | sub_4D8760 | completion handler called with (1, 0) |

**Guard conditions:** none — unconditional execution of all chain steps
