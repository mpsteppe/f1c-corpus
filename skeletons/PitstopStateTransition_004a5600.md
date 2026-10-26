## PitstopStateTransition_004a5600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitPartStateCopy (004a5330), ConditionalDispatch_55e0 (004a55e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a3390 | sub_4A3390 | [LLM] |
| 004a3440 | FlagBasedLoopConditionalCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
