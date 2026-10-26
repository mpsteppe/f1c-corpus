## ControllerShifterMapping_0046a9c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyBindingUIPressKeyOrController (0046b0c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F4 | R | — | [LLM] |
| this | 0x200 | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0046ac58 | jpt_46AA0C | R | [LLM] |
| 0046acdc | byte_46ACDC | R | [LLM] |
| 007d1490 | dword_7D1490 | W | ContactForceStateArray [DERIVED] (also: ` — global action active flags) |
| 007d1b08 | dword_7D1B08 | W | ActionTypeArray [DERIVED] (also: ` — global action type array) |
| 007d1b0c | dword_7D1B0C | RW | ActionValueArray [DERIVED] (also: ` — global action value array) |
| 007d1fdc | dword_7D1FDC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046a980 | IDPairMatchAndClear | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x200 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
