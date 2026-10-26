## sub_59FFB0_0059ffb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_409E80 (00409e80), sub_40A0D0 (0040a0d0), sub_4AB0E0 (004ab0e0), sub_4B48F0 (004b48f0), sub_4B5400 (004b5400), sub_4B5CCD (004b5ccd), sub_4B5D70 (004b5d70), sub_4B6FD0 (004b6fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007e6b48 | dword_7E6B48 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a00b0 | sub_5A00B0 | [LLM] |
| 005a7610 | sub_5A7610 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
