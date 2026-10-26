## WheelStateHistoryShift_004412f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StateAccumulateDelta (00441360), PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x338 | RW | — | [LLM] |
| this | 0x33C | RW | — | [LLM] |
| this | 0x340 | R | — | [LLM] |
| this | 0x344 | R | — | [LLM] |
| this | 0x348 | RW | — | [LLM] |
| this | 0x34C | RW | — | [LLM] |
| this | 0x350 | R | — | [LLM] |
| this | 0x354 | R | — | [LLM] |
| this | 0x1C5C | RW | — | [LLM] |
| this | 0x1C60 | RW | — | [LLM] |
| this | 0x1C64 | R | — | [LLM] |
| this | 0x1C68 | R | — | [LLM] |
| this | 0x1E38 | RW | — | [LLM] |
| this | 0x1E3C | RW | — | [LLM] |
| this | 0x1E40 | R | — | [LLM] |
| this | 0x1E44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x338: recalc every frame — external poke does NOT persist
- this 0x33C: recalc every frame — external poke does NOT persist
- this 0x348: recalc every frame — external poke does NOT persist
- this 0x34C: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1E38: recalc every frame — external poke does NOT persist
- this 0x1E3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
