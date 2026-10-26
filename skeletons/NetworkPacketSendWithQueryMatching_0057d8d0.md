## NetworkPacketSendWithQueryMatching_0057d8d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UDPSocketBind (0057e860), sub_580DE0 (00580de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAAC)+0x0) | 0x2 | R | — | [LLM] |
| *(*(this+0xAAC)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0xAAC)+0x0) | 0x12 | R | — | [LLM] |
| *(*(this+0xAAC)+0x0) | 0x14 | R | — | [LLM] |
| *(this+0xAAC) | 0x0 | R | — | [LLM] |
| *(this+0xAB8) | 0x2 | R | — | [LLM] |
| *(this+0xAB8) | 0x4 | R | — | [LLM] |
| this | 0xAAC | R | — | [LLM] |
| this | 0xAB4 | RW | — | [LLM] |
| this | 0xAB8 | R | — | [LLM] |
| this | 0xABC | R | — | [LLM] |
| this | 0xAC0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAB4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e300 | __imp_send | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b0d0 | IndexedLinkedListNodeGetter | [LLM] |
| 0057b2e0 | StructFieldGetter_b2e0 | [LLM] |
| 0057b6b0 | OffsetGetter | [LLM] |
| 0057d5d0 | StructuredMemoryCopyWithHeaderPrepend | [LLM] |
| 0057db80 | sub_57DB80 | [LLM] |
| 005871f0 | ReadFieldAtOffset0x14 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAAC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
