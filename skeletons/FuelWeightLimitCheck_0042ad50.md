## FuelWeightLimitCheck_0042ad50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3448 | R | — | theoricNumberOfLapsWithOneLitre [CONFIRMED] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4040 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
