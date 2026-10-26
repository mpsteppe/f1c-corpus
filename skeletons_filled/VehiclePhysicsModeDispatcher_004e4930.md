## VehiclePhysicsModeDispatcher_004e4930 — VehiclePhysicsModeDispatcher

**Summary:** Dispatches vehicle physics integration based on mode flag at offset 0x32BC — full init+step (mode 0), sub-step integration (mode 1), or pit/team-color update (mode 2). Central physics mode router.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneObjectLoaderStateMachine (0040f1c0), MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Mode/state flag: 0=full init, 1=sub-step, 2=pit-only |
| this | 0x34AC | RW | — | Session/race time updated from input a2 |

**Written-by note (persistence):**
- this 0x34AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00441650 | VehiclePhysicsIntegrationStep | Runs full vehicle physics integration step |
| 004a6e50 | PitStateUpdateMachine | Updates pit stop state machine |
| 004e49b0 | VehicleSetupInitialization | Initializes vehicle setup from configuration |
| 004e4e60 | PhysicsIntegrationStateMachine | Runs sub-step physics integration loop |
| 004f03e0 | TeamColorLoader | Loads team color/livery data |

**Guard conditions:** Switch on this+0x32BC (mode): 0 -> full init (PitState + VehiclePhysicsIntegrationStep + VehicleSetupInitialization); 1 -> sub-step (PitState + PhysicsIntegrationStateMachine); 2 -> session time update + TeamColorLoader. Non-matching returns immediately.
