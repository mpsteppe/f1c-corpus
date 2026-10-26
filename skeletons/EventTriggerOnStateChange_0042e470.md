## EventTriggerOnStateChange_0042e470 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TrackConfig (0042e530), AIGearSelectionSet (0042eaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x19A4 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x19A4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
