## ShortComputation_d3c0_0040d3c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | [LLM] |
| this | 0x24 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007d0350 | dword_7D0350 | R | SessionActiveFlag [DERIVED] (also: ` — session active flag (near GameState DAT_007d00ec) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cd60 | SessionPhaseDecode | [LLM] |
| 0040cde0 | GameActionStateMachine | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
