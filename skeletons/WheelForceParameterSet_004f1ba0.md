## WheelForceParameterSet_004f1ba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3664 | RW | — | [LLM] |
| this | 0x375C | RW | — | [LLM] |
| this | 0x3854 | RW | — | [LLM] |
| this | 0x394C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3664: recalc every frame — external poke does NOT persist
- this 0x375C: recalc every frame — external poke does NOT persist
- this 0x3854: recalc every frame — external poke does NOT persist
- this 0x394C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
