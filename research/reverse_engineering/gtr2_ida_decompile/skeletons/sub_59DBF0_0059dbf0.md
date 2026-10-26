## sub_59DBF0_0059dbf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAE4)+0x0) | 0x1C | R | — | [LLM] |
| *(this+0xAE4) | 0x0 | R | — | [LLM] |
| this | 0xAA0 | R | — | [LLM] |
| this | 0xAA4 | R | — | [LLM] |
| this | 0xAA8 | R | — | [LLM] |
| this | 0xAAC | R | — | [LLM] |
| this | 0xAE4 | R | — | [LLM] |
| this | 0xAEC | RW | — | [LLM] |
| this | 0xAF0 | R | — | [LLM] |
| this | 0xAF4 | R | — | [LLM] |
| this | 0xAF8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1184 | ReleaseMutex | R | [LLM] |
| 006f1188 | WaitForSingleObject | R | [LLM] |
| 006f159c | htonl | R | [LLM] |
| 006f15a0 | htons | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059c230 | sub_59C230 | [LLM] |
| 005a6e90 | ReadFieldAtOffset0x14 [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAE4 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
