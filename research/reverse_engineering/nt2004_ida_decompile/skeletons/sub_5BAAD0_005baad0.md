## sub_5BAAD0_005baad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_45E840 (0045e840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00624908 | unk_624908 | R | [LLM] |
| 00624a10 | off_624A10 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bb940 | sub_5BB940 | [LLM] |
| 005bdbb0 | WSACleanupThunk [exact] | [LLM] |
| 005c1b88 | sub_5C1B88 | [LLM] |
| 005d26f8 | closesocket [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
