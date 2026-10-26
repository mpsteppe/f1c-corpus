## sub_65A1AA_0065a1aa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_65C7B1 (0065c7b1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x268)+0x6C) | 0x6C | R | — | [LLM] |
| *(this+0x268) | 0x58 | R | — | [LLM] |
| *(this+0x268) | 0x60 | R | — | [LLM] |
| *(this+0x268) | 0x64 | R | — | [LLM] |
| *(this+0x26C) | 0x18 | R | — | [LLM] |
| this | 0x44 | RW | 1 | [LLM] |
| this | 0x48 | RW | 1 | [LLM] |
| this | 0x268 | RW | — | [LLM] |
| this | 0x26C | R | — | [LLM] |
| this | 0x270 | R | — | [LLM] |
| this | 0x278 | R | — | [LLM] |
| this | 0x280 | R | — | [LLM] |
| this | 0x298 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x268: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1238 | GetFullPathNameA | R | [LLM] |
| 006f1f34 | aSS | R | [LLM] |
| 00737814 | aSyntaxError | R | [LLM] |
| 00737824 | aTooManyNestedI | R | [LLM] |
| 00737840 | aIncludeInterfa | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00632041 | sub_632041 | [LLM] |
| 00659cd8 | sub_659CD8 | [LLM] |
| 00659d66 | sub_659D66 | [LLM] |
| 00659d87 | sub_659D87 | [LLM] |
| 0065a0b7 | sub_65A0B7 | [LLM] |
| 0065dd1f | sub_65DD1F | [LLM] |
| 0065e7a1 | sub_65E7A1 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x278 | != | 11 | [LLM] |
| this | 0x278 | == | 10 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `syntax error`
- `too many nested #includes`
- `include interface required to support #include from resource or memory`
