## sub_4FAE10_004fae10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_429EF0 (00429ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 006f16d0 | flt_6F16D0 | R | [LLM] |
| 006f16ec | flt_6F16EC | R | [LLM] |
| 006f1a30 | flt_6F1A30 | R | [LLM] |
| 006f2320 | flt_6F2320 | R | [LLM] |
| 006f30dc | flt_6F30DC | R | [LLM] |
| 006f314c | flt_6F314C | R | [LLM] |
| 006f3154 | flt_6F3154 | R | [LLM] |
| 006f3158 | flt_6F3158 | R | [LLM] |
| 00714a78 | flt_714A78 | R | [LLM] |
| 00714a7c | flt_714A7C | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00757c10 | dword_757C10 | R | [LLM] |
| 00b640c8 | dword_B640C8 | R | [LLM] |
| 00fade1c | flt_FADE1C | R | [LLM] |
| 00fade20 | flt_FADE20 | R | [LLM] |
| 00fb1d18 | dbl_FB1D18 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041fb10 | sub_41FB10 | [LLM] |
| 00422780 | sub_422780 | [LLM] |
| 004f1ef0 | sub_4F1EF0 | [LLM] |
| 004fb7d0 | FieldAccessor [exact] | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00631ba8 | _rand | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `fff?333?
`
