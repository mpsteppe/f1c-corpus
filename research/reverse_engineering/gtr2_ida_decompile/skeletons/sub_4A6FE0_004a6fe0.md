## sub_4A6FE0_004a6fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x254)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x25C)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x254) | 0x0 | R | — | [LLM] |
| *(this+0x25C) | 0x0 | R | — | [LLM] |
| *(this+0x25C) | 0x4 | R | — | [LLM] |
| this | 0x254 | R | — | [LLM] |
| this | 0x25C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x25C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006fe91c | unk_6FE91C | R | [LLM] |
| 006fe920 | aHeader2 | R | [LLM] |
| 006fe92c | aHeader | R | [LLM] |
| 006fe948 | dword_6FE948 | R | [LLM] |
| 006fe94c | dword_6FE94C | R | [LLM] |
| 006fe950 | dword_6FE950 | R | [LLM] |
| 006fe954 | dword_6FE954 | R | [LLM] |
| 006fe958 | word_6FE958 | R | [LLM] |
| 006fe95c | dword_6FE95C | R | [LLM] |
| 006fe960 | dword_6FE960 | R | [LLM] |
| 006fe964 | dword_6FE964 | R | [LLM] |
| 006fe968 | dword_6FE968 | R | [LLM] |
| 006fe96c | dword_6FE96C | R | [LLM] |
| 006fe970 | byte_6FE970 | R | [LLM] |
| 006fe974 | dword_6FE974 | R | [LLM] |
| 006fe978 | dword_6FE978 | R | [LLM] |
| 006fe97c | dword_6FE97C | R | [LLM] |
| 006fe980 | dword_6FE980 | R | [LLM] |
| 006fe984 | byte_6FE984 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ce460 | sub_4CE460 | [LLM] |
| 004cf8c0 | sub_4CF8C0 | [LLM] |
| 004cf8e0 | sub_4CF8E0 | [LLM] |
| 004cf900 | sub_4CF900 | [LLM] |
| 004d93b0 | sub_4D93B0 | [LLM] |
| 00616480 | sub_616480 | [LLM] |
| 00630fe0 | sub_630FE0 | [LLM] |
| 00631c0d | __stricmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `<HEADER2>`
- `<HEADER>`
- `FT_Standard_VALUE`
- `FT_LISTBOX_HIGHLIGHT`
- `FT_Standard_TEXT`
