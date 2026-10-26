## ConditionalGate_004efac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), AIAbility (00429470), PitStopDecisionTireCompound (0042a3d0), AIStateReset (0042af40), AISteeringRacingLineCorrection (0042b0e0), sub_4A0250 (004a0250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3994 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
