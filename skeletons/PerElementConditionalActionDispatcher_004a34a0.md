## PerElementConditionalActionDispatcher_004a34a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e928 | flt_59E928 | R | FloatCompareConst [DERIVED] (also: Float comparison constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c190 | BitClear | [LLM] |
| 0054c1a0 | Bit12FlagSet | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
