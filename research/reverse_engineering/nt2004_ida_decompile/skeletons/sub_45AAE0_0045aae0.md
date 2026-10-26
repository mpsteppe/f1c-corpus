## sub_45AAE0_0045aae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_416610 (00416610)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5914 | flt_5D5914 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c400 | F_3DVectorCrossProductRotationAccumulation [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
