## SimpleSetterWithFlag_00431a50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDynamicsInit (0043e230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1CB8 | RW | 1 | [LLM] |
| this | 0x1CBC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1CB8: recalc every frame — external poke does NOT persist
- this 0x1CBC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
