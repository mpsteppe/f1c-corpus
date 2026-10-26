## NetworkReceivePacket_0057e940 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC8) | 0x0 | R | — | [LLM] |
| *(this+0xAD4) | 0x0 | R | — | [LLM] |
| this | 0xAC8 | R | — | [LLM] |
| this | 0xAD0 | RW | — | [LLM] |
| this | 0xAD4 | R | — | [LLM] |
| this | 0xAD8 | R | — | [LLM] |
| this | 0xADC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAD0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e2d8 | __imp_htonl | R | [LLM] |
| 0059e2f4 | __imp_htons | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b840 | NetworkMessageEventComparisonWithShortMasking | [LLM] |
| 0057b9f0 | Copy4DwordsStructToStruct | [LLM] |
| 005871f0 | ReadFieldAtOffset0x14 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
