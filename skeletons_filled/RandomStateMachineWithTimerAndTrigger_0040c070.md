## RandomStateMachineWithTimerAndTrigger_0040c070 — RandomCameraModeTimer

**Summary:** Countdown timer that, on expiry, picks a random camera mode (0,3,4,5) and transitions via GameActionStateMachine. Optionally targets race leader. Called per-tick from camera director.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | byte gate; if non-zero, entire function skipped |
| this | 0x30 | R | — | first argument to ShortComputation_d360 |
| this | 0x34 | R | — | second argument to ShortComputation_d360 |
| this | 0x3C | RW | — | countdown timer (float), decremented each tick; triggers random mode switch when <= 0 |

**Written-by note (persistence):**
- this 0x3C: decremented each call by ScoringGateConditionCheck result; reset externally to arm

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040c128 | jpt_40C0BD | R | jump table for random mode selection switch |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c780 | ScoringGateConditionCheck | returns delta to subtract from countdown timer |
| 0040cd60 | SessionPhaseDecode | decodes current session phase to determine transition eligibility |
| 0040cde0 | GameActionStateMachine | transitions to selected random camera mode |
| 0040d290 | CameraTargetRaceLeader | sets camera to follow race leader (1/3 probability on timer fire) |
| 0040d360 | ShortComputation_d360 | computation using fields at 0x30 and 0x34 |
| 005884ed | RandLCGRandomNumberGenerator | LCG RNG for random mode selection and race-leader target chance |

**Guard conditions:** if this+0x24 (byte at offset 36) is non-zero, function returns 0 immediately (skip all processing). Timer decrement and mode switch only occur when timer <= 0.
