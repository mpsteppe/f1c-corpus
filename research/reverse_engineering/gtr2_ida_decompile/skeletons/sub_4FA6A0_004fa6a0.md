## sub_4FA6A0_004fa6a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4FA820 (004fa820)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | RW | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0x57C4 | R | — | [LLM] |
| obj | 0x5814 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 105 | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00757c10 | dword_757C10 | R | [LLM] |
| 0091e088 | dword_91E088 | R | [LLM] |
| 00fadd40 | dword_FADD40 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00416420 | sub_416420 | [LLM] |
| 004f1b60 | sub_4F1B60 | [LLM] |
| 004f4510 | sub_4F4510 | [LLM] |
| 004f7ec0 | sub_4F7EC0 | [LLM] |
| 004fb7d0 | FieldAccessor [exact] | [LLM] |
| 0054fdb0 | sub_54FDB0 | [LLM] |
| 005773f0 | sub_5773F0 | [LLM] |
| 005db320 | sub_5DB320 | [LLM] |
| 00614a90 | EulerToRotationMatrix [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
