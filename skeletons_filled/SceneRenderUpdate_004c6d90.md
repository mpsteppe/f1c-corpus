## SceneRenderUpdate_004c6d90 — VehicleSceneRenderUpdate

**Summary:** Per-vehicle scene render update each frame. Coordinates vehicle physics prep, AI driver state, render dispatch (grid position / path data), force feedback update, and optional collision check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), PitStopDecisionTireCompound (0042a3d0), DynMan_Restart (0042c3b0), NetCommPlayerSlotSync (0045fc50), sub_4A00A0 (004a00a0), sub_4A0250 (004a0250), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48B4 | RW | 18446744073701163007 | render flag bitmask (clears bit 23 each frame) |

**Written-by note (persistence):**
- this 0x48B4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea408 | flt_5EA408 | R | SessionMaxTime [DERIVED] (also: ` — threshold) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410b60 | DelegationWrapperToFUN0040ed10 | delegate to session manager callback |
| 00424790 | AIDriverStructInit | initialize AI driver structure for this vehicle |
| 004bb810 | sub_4BB810 | reset vehicle substate (called when a2 flag set) |
| 004c6b60 | sub_4C6B60 | vehicle frame update (AI, suspension, state) |
| 004d10e0 | SingleFunctionDispatch_10e0 | read grid position data from setup scene |
| 004d1100 | ConditionalDelegateDispatch | conditionally recalc grid position, then copy data |
| 004d1140 | RenderCallWithGuard | read indexed struct data with guard |
| 004d1180 | sub_4D1180 | dispatch render call with session-type guard |
| 004d1670 | sub_4D1670 | update force feedback state |
| 004e0800 | VehicleRespawnReset | reset vehicle respawn state |
| 004e45b0 | LargeConfigFunctionWithPhysicsConstants | configure physics constants for vehicle |
| 004e4910 | CollisionWrapperWithLock | collision check (called when session max time <= 0) |
| 004ef7c0 | AIVehiclePathPositionTracking | track AI vehicle path position |

**Guard conditions:** a2 (float, LOBYTE used as flag). If a2 != 0, runs additional setup: sub_4BB810, sub_4D1180, and AI path tracking. If a2 == 0, skips those.
