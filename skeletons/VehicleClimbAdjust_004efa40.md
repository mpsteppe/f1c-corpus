## VehicleClimbAdjust_004efa40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), AISteeringRacingLineCorrection (0042b0e0), sub_4A00A0 (004a00a0), sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3994 | RW | — | [LLM] |
| this | 0x399C | R | — | [LLM] |
| this | 0x39B8 | RW | — | [LLM] |
| this | 0x39BC | R | — | [LLM] |
| this | 0x39C0 | R | — | [LLM] |
| this | 0x39C4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3994: recalc every frame — external poke does NOT persist
- this 0x39B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
