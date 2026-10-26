## ShortComputation_d410_0040d410 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A00A0 (004a00a0), sub_4A0250 (004a0250), PitStopProgress (004a68b0), PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x24: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408450 | SafeDivisionWithZeroGuard | [LLM] |
| 0040cd60 | SessionPhaseDecode | [LLM] |
| 0040cde0 | GameActionStateMachine | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
