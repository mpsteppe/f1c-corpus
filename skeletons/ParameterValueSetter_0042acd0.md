## ParameterValueSetter_0042acd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), AIAbility (00429470), CommandQueueResponseHandler (00429ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4538 | RW | — | maxSpeed [CONFIRMED] |

**Written-by note (persistence):**
- this 0x4538: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
