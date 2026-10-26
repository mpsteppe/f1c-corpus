## sub_6A5ECA_006a5eca — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x220 | RW | 0 | [LLM] |
| this | 0x224 | RW | 0 | [LLM] |
| this | 0x22C | RW | 0 | [LLM] |
| this | 0x230 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x220: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x224: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x22C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x230: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007438e8 | aCannotPerformD | R | [LLM] |
| 00743ae0 | aProgramTooBig | R | [LLM] |
| 00743c18 | aCanReadFromTex | R | [LLM] |
| 00743c68 | aTextureLoadsOr | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006a554c | sub_6A554C | [LLM] |
| 006a572c | sub_6A572C | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | [LLM] |
| this | 0xC8 | != | 260 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot perform dependent texture read which in any way is based on color inputs`
- `program too big`
- `can read from texcoord and use it for texlookup only in ps_1_4 and higher`
- `texture loads or clips cannot be from inputs not marked TEXCOORD`
