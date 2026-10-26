## ActorMotionPostProcessingUpdate_004ed030 — ActorMotionPostProcessingUpdate

**Summary:** Post-processing update for actor motion. Runs lazy initialization on two subsystems, transitions state, resets one-shot flag, interpolates mismatched damping values, selects force feedback source based on contact state, solves tire-brush forces, and optionally clamps velocity via global time. Physics/timing update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD0C | R | — | contact state pointer, checked for non-null |
| this | 0xD4C | R | — | contact ready flag byte, must be 0 |
| this | 0x32BC | R | — | input flag, checked for zero to enable velocity clamping |
| this | 0x3A6C | RW | — | active force feedback value (selected between two sources) |
| this | 0x3A70 | RW | — | inactive force feedback value (selected between two sources) |
| this | 0x3A78 | R | — | force feedback source A (inactive contact) |
| this | 0x3A7C | R | — | force feedback source B (active contact) |
| this | 0x3A80 | R | — | damping target value (interpolated toward) |
| this | 0x3D60 | RW | 0 | one-shot reset flag, cleared if == 1 |

**Written-by note (persistence):**
- this 0x3A6C: overwritten each call; no persistence
- this 0x3A70: overwritten each call; no persistence
- this 0x3D60: cleared to 0 if == 1; otherwise unchanged

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a56b0 | StateTransition | transition state machine with input flag |
| 004e0d00 | LazyInitCallback | lazy-initialize sub-system with parameter pair |
| 004e8010 | TireBrushModelForceSolver | solve tire brush model forces for current state |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D60 | == | 1 | resetFlag |

**Guard interpretation:** If resetFlag (this+0x3D60) == 1, clear to 0 (one-shot). If damping value (this+0x3A80) != current (this+0x3A6C), interpolate toward target. If contact pointer (this+0xD0C) non-null AND ready flag (this+0xD4C) zero, select force from active contact source; otherwise select from inactive. If input flag (this+0x32BC) zero, clamp velocity using global race time.
