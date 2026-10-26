## MainCameraDirectorUpdate_0040ca30 — CameraDirectorPerFrameUpdate

**Summary:** Per-frame update tick for the main camera director — processes player input (keyboard or AI random state machine), switches camera modes, tracks player vehicle position and velocity, and renders particle effects on mode transitions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0xC | R | — | Virtual function at vtable+12 — get current camera state/result |
| *(*(this+0x8)+0x0) | 0x10 | R | — | Virtual function at vtable+16 — on camera mode change callback |
| *(*(this+0x8)+0x0) | 0x18 | R | — | Virtual function at vtable+24 — get entity position (returns float*) |
| *(this+0x8) | 0x0 | R | — | Pointer to the camera entity/controller object (used for virtual dispatch) |
| this | 0x8 | R | — | Current camera entity pointer |
| this | 0x18 | R | — | Previous camera entity pointer (compared against current for change detection) |
| this | 0x25 | RW | 0 | Camera update skip flag — if set, clears and returns early (skip this frame) |
| this | 0x28 | RW | 0 | State counter, reset to 0 each non-skip frame |
| this | 0x2D | RW | 1 | First-time initialization guard — set to 1 after initial sub_409890 call |
| this | 0x2E | R | — | Camera AI mode flag — if non-zero uses RandomStateMachine, else uses keyboard input |

**Written-by note (persistence):**
- this 0x25: Conditional write — cleared to 0 once per call when set; external poke would be overwritten next frame
- this 0x28: Conditional write — set to 0 each non-skip frame; survives external poke but reset every tick
- this 0x2D: Once — set to 1 on first call when previously 0; persistent after init, external reset would re-trigger init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e6d8 | dbl_59E6D8 | R | dbl_59E6D8 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007cfe28 | flt_7CFE28 | R | Unknown_Float_7CFE28 [DERIVED] |
| 007cfe4c | dword_7CFE4C | R | UnknownSteerState [DERIVED] |
| 007cfe54 | dword_7CFE54 | R | Unknown_VehicleState [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008acebc | dword_8ACEBC | R | PhysicsEventCounter [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409890 | sub_409890 | Initialize sub-camera or sub-controller object on first frame (called with camera entity) |
| 0040be70 | KeyboardInputActionMapper | Process keyboard/gamepad input and map to camera movement actions |
| 0040c070 | RandomStateMachineWithTimerAndTrigger | AI-driven camera movement via random state machine with timer triggers |
| 0040c5b0 | CameraModeChangeRequest | Request a camera mode transition (called after input processing) |
| 0040c7a0 | CameraTargetUpdateOnPlayerChange | Update camera target reference when player vehicle changes |
| 0040c870 | VirtualDispatchHelper | Get float value at offset 92 from camera entity via virtual dispatch |
| 0040c910 | ShortComputation_c910 | Update camera internal state computation at start of each tick |
| 004ccdc0 | ParticlePositionAdd | Add particle effect at the delta between old and new camera position |
| 004d8860 | ConditionalBranchByFlag | Conditional branch helper based on a flag value |
| 004f0d20 | sub_4F0D20 | Apply per-vehicle physics/camera update (called on mode change for all vehicles) |
| 0053d450 | ShortComputation_d450 | Compute camera speed value from float (store as int) |
| 00542420 | TwoCallDelegation_2420 | Forward 3 float values through two internal calls (negate + delegate) |
| 00542460 | TripleFieldGetter_2460 | Get 3 float fields from a structure and store in output pointers |

**Guard conditions:**
- `this+0x2D == 0` (offset 45): First-time initialization. PASSES on first ever call — calls `sub_409890` and sets byte to 1. BLOCKED (skipped) on all subsequent calls.
- `this+0x25 != 0` (offset 37): Camera update skip. PASSES when flag is set — clears it to 0 and returns early (entire frame skipped for camera). BLOCKED (proceeds normally) when flag is already 0.
- `this+0x2E != 0` (offset 46): Camera AI mode selection. PASSES — uses `RandomStateMachineWithTimerAndTrigger` for AI-driven camera. BLOCKED (false) — uses `KeyboardInputActionMapper` for player-controlled camera.
- `v3 == 1` (camera mode change result): Mode transition path. PASSES — iterates all vehicles calling `sub_4F0D20`, fires virtual `+16` callback, then virtual `+12`. BLOCKED (v3 != 1) — normal update path with position/velocity tracking.
- `dword_8AC4C4 != 0` (InitStatus): Main rendering/position block. PASSES — runs position computation, virtual calls on camera object, and particle effects. BLOCKED — skips the entire rendering block (returns early).
- `v9 == *(this+0x18)` (camera entity unchanged): Position source selection. PASSES — reads position from `dword_7C54E0` (postProcessInput). BLOCKED — calls virtual `+24` on entity to get position.
- `!byte_7C56AC` (enable flag off): Speed computation. PASSES — computes velocity magnitude with `sqrt`, division by `0.44704` (mph to m/s conversion), clamping between min/max thresholds. BLOCKED — sets velocity to 0.0.