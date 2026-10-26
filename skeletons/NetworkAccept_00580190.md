## NetworkAccept_00580190 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAB4)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xAAC) | 0x0 | R | — | [LLM] |
| *(this+0xAB4) | 0x4 | R | — | [LLM] |
| this | 0x938 | R | — | [LLM] |
| this | 0x93C | R | — | [LLM] |
| this | 0xAAC | R | — | [LLM] |
| this | 0xAB4 | RW | — | [LLM] |
| this | 0xABC | R | — | [LLM] |
| this | 0xAC0 | R | — | [LLM] |
| this | 0xBEC | R | — | [LLM] |
| this | 0xBF0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAB4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ca69 | SEH_580190 | R | [LLM] |
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e2d8 | __imp_htonl | R | [LLM] |
| 0059e2e4 | __imp_select | R | [LLM] |
| 0059e2f4 | __imp_htons | R | [LLM] |
| 0059e308 | __imp_setsockopt | R | [LLM] |
| 0059e31c | getpeername | R | [LLM] |
| 0059e32c | accept | R | [LLM] |
| ff00000000005430 | byte_FF00000000005430 | RW | [LLM] |
| ff00000000005431 | byte_FF00000000005431 | RW | [LLM] |
| ff00000000005435 | byte_FF00000000005435 | W | [LLM] |
| ff00000000005436 | byte_FF00000000005436 | W | [LLM] |
| ff00000000005438 | byte_FF00000000005438 | W | [LLM] |
| ff00000000005439 | byte_FF00000000005439 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004979c0 | Setter | [LLM] |
| 0057b6a0 | PointerAdvance | [LLM] |
| 0057b6b0 | OffsetGetter | [LLM] |
| 0057cb50 | sub_57CB50 | [LLM] |
| 0057dc10 | sub_57DC10 | [LLM] |
| 00582eb0 | LinkedListNodeRemovalWithCleanupCallback | [LLM] |
| 005830c0 | ObjectAllocationWithSEH | [LLM] |
| 00583530 | ZeroFillMemoryRegionWithStep | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAAC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
