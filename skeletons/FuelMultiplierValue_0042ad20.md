## FuelMultiplierValue_0042ad20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), RacePhasePitEntryTrigger (00429eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3448 | R | — | theoricNumberOfLapsWithOneLitre [CONFIRMED] |
| this | 0x3984 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
