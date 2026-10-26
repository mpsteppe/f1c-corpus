## PitStateUpdateMachine_004a6e50 — Pit state machine dispatcher

**Summary:** Main pit state machine that dispatches to collision detection, pit stop readiness, pit progress, and collision avoidance based on current pit state (entering/in-pit/exiting). Coordinates vehicle control enable checks and state transitions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | Collision active flag (0 = not in collision) |
| this | 0x0 | R | — | Pointer to obj struct |
| this | 0x4 | R | — | Vehicle index in global array |
| this | 0x180 | R | — | Pit state flags bitmask (bit 0 = some flag for sub_4A5F20 call) |
| this | 0x184 | R | — | Pit state (0=idle, 1=entering, 2=in-pit, 3=exiting, 4=... ) |
| this | 0x188 | R | — | Pit state timer (used in state 1 duration check against 150.0) |
| this | 0x190 | RW | 0 | Pit stop ready flag (set by PitStopReadyCheck) |
| this | 0x1AC | RW | 0 | Qualifying DSQ flag (set when disqualified in qualifying) |

**Written-by note (persistence):**
- this 0x190: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acb08 | flt_5ACB08 | R | FloatThreshold_5ACB08 [DERIVED] (also: ` — upper bound threshold (undocumented) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5698 | dword_7C5698 | R | SessionTickCounter [DERIVED] |
| 007ce258 | dword_7CE258 | W | InitZeroFieldSet [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d410 | ShortComputation_d410 | Send session event command on DSQ flag |
| 004a5c80 | StateChangeNotify | Notify state machine of pit state transition |
| 004a5f20 | sub_4A5F20 | Handle pit state flag operations |
| 004a5fa0 | VehicleProximityCollisionDetection | Check proximity collision for pit exit |
| 004a6200 | PitStopReadyCheck | Evaluate pit stop readiness |
| 004a68b0 | PitStopProgress | Update pit stop progress during state 3 |
| 004a6b80 | CollisionAvoidanceCheck | Check collision avoidance during state 4 |
| 004a6db0 | VehicleControlEnabled | Check if vehicle controls are enabled |
| 004d8840 | ConditionalIndexSetter | Set session condition index (parameter 2) |
| 004e9630 | PositionChangeMonitor | Get position change monitor data |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x184 | != | 3 | Pit state — NOT in exit mode |
| this | 0x184 | == | 2 | Pit state — in pit stop mode |

**Guard interpretation:** When this+0x184 != 3 (state is NOT "exiting pit"), PASSES into vehicle control enable check and pit entry logic; when == 3 (exiting), BLOCKED from pit entry path. When this+0x184 == 2 (state is "in pit stop"), PASSES into proximity collision detection for exit triggering; when != 2, BLOCKED from exit collision path.
