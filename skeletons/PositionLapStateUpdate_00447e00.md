## PositionLapStateUpdate_00447e00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70), VehicleMainPhysicsUpdate (004441f0), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34 | RW | 6 | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x1E7C | RW | — | [LLM] |
| this | 0x1E80 | RW | — | [LLM] |
| this | 0x1E84 | R | — | [LLM] |
| this | 0x1E88 | R | — | [LLM] |
| this | 0x1E94 | R | — | [LLM] |
| this | 0x1E98 | R | — | [LLM] |
| this | 0x1EF0 | RW | 0 | [LLM] |
| this | 0x1EF4 | RW | — | [LLM] |
| this | 0x1EF8 | RW | 0 | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x1E7C: recalc every frame — external poke does NOT persist
- this 0x1E80: recalc every frame — external poke does NOT persist
- this 0x1EF0: recalc every frame — external poke does NOT persist
- this 0x1EF4: recalc every frame — external poke does NOT persist
- this 0x1EF8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f88a0 | SoundEffectTrigger | [LLM] |
| 004f89a0 | SoundEffectTrigger_89a0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
