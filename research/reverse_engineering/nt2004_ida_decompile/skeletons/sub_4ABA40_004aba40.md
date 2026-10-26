## sub_4ABA40_004aba40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AD050 (004ad050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x188) | 0x4 | R | — | [LLM] |
| *(this+0x188) | 0x8 | R | — | [LLM] |
| *(this+0x188) | 0xC | R | — | [LLM] |
| *(this+0x188) | 0x10 | R | — | [LLM] |
| *(this+0x188) | 0xB8 | R | — | [LLM] |
| *(this+0x188) | 0xC0 | R | — | [LLM] |
| *(this+0x188) | 0xC8 | R | — | [LLM] |
| *(this+0x188) | 0xD0 | R | — | [LLM] |
| *(this+0x188) | 0xD4 | R | — | [LLM] |
| *(this+0x188) | 0xDC | R | — | [LLM] |
| *(this+0x188) | 0xE8 | R | — | [LLM] |
| *(this+0x188) | 0xEC | R | — | [LLM] |
| *(this+0x188) | 0xF0 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0xFC | RW | 0 | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x18C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xB4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d54f8 | flt_5D54F8 | R | [LLM] |
| 005d6598 | flt_5D6598 | R | [LLM] |
| 005d659c | flt_5D659C | R | [LLM] |
| 005fb7e8 | Format | R | [LLM] |
| 00601114 | aOptionsMas | R | [LLM] |
| 006152e8 | dword_6152E8 | R | [LLM] |
| 006152ec | dword_6152EC | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a098 | dword_62A098 | R | [LLM] |
| 0076887c | dword_76887C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506960 | ConditionalCall [exact] | [LLM] |
| 005069a0 | sub_5069A0 | [LLM] |
| 00506ae0 | sub_506AE0 | [LLM] |
| 00506c20 | sub_506C20 | [LLM] |
| 005070d0 | AudioNoteParamIndexSearchLoop [structural] | [LLM] |
| 005a3fd0 | sub_5A3FD0 | [LLM] |
| 005a41f0 | sub_5A41F0 | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xF8 | == | 0 | [LLM] |
| this | 0xF8 | >= | 2 | [LLM] |
| this | 0xF8 | >= | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `Options.mas`
