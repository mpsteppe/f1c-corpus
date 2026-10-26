## SpeedValueSetterWithGlobalMirror_004f1890 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), sub_429960 (00429960), PitStopDecisionTireCompound (0042a3d0), AISteeringRacingLineCorrection (0042b0e0), PitStopOperationTimer (004a6340), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3978 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3978: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c75c4 | dbl_7C75C4 | W | GlobalSpeedTime (double) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
