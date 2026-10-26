## __ValidateEH3RN_006396f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __except_handler3 (00631f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1274 | InterlockedExchange | R | [LLM] |
| 006f1278 | VirtualQuery | R | [LLM] |
| 00fb8360 | dword_FB8360 | RW | [LLM] |
| 00fb8368 | dword_FB8368 | R | [LLM] |
| 00fb83a8 | Target | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |
| ff0000000000a61a | byte_FF0000000000A61A | R | [LLM] |
| ff0000000000a61e | byte_FF0000000000A61E | R | [LLM] |
| ff0000000000a61f | byte_FF0000000000A61F | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x8) | 0x0 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
