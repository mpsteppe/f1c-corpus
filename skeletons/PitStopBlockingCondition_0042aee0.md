## PitStopBlockingCondition_0042aee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopDecisionTireCompound (0042a3d0), PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xD18 | R | — | [LLM] |
| obj | 0xD58 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x39FA | R | — | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x45E0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
