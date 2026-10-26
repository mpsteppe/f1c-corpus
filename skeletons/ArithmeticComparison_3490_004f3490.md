## ArithmeticComparison_3490_004f3490 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | RW | — | [LLM] |
| this | 0x98 | RW | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x90: recalc every frame — external poke does NOT persist
- this 0x98: recalc every frame — external poke does NOT persist
- this 0xA0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565aa0 | sub_565AA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
