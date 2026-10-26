## SuspensionVibration_004471f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440), Gearbox (00443b70), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C59 | RW | 1 | [LLM] |
| this | 0x1C5C | RW | — | [LLM] |
| this | 0x1C60 | RW | — | [LLM] |
| this | 0x1C84 | R | — | [LLM] |
| this | 0x1C88 | R | — | [LLM] |
| this | 0x1D10 | RW | — | [LLM] |
| this | 0x1D18 | R | — | [LLM] |
| this | 0x1D20 | R | — | [LLM] |
| this | 0x1D28 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C59: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1D10: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
