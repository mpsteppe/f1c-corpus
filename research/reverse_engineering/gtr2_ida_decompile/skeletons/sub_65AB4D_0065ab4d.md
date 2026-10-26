## sub_65AB4D_0065ab4d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_65B3D1 (0065b3d1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3C)+0x28) | 0x4 | R | — | [LLM] |
| *(this+0x3C) | 0x28 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | RW | 1 | [LLM] |
| this | 0x26C | R | — | [LLM] |
| this | 0x278 | R | — | [LLM] |
| this | 0x280 | R | — | [LLM] |
| this | 0x298 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x3C) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f34cc | asc_6F34CC | R | [LLM] |
| 006f34d4 | asc_6F34D4 | R | [LLM] |
| 006fbe80 | word_6FBE80 | R | [LLM] |
| 0072c5a0 | dbl_72C5A0 | R | [LLM] |
| 00737934 | asc_737934 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 0065d86a | sub_65D86A | [LLM] |
| 0065e7a1 | sub_65E7A1 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x278 | != | 1 | [LLM] |
| this | 0x278 | == | 1 | [LLM] |
| this | 0x278 | == | 9 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
