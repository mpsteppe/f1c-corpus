## sub_4CED00_004ced00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0xB0 | R | — | [LLM] |
| obj | 0xBC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10C | RW | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16a0 | dbl_6F16A0 | R | [LLM] |
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006f16d0 | flt_6F16D0 | R | [LLM] |
| 006f2304 | flt_6F2304 | R | [LLM] |
| 006f3510 | flt_6F3510 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cde30 | sub_4CDE30 | [LLM] |
| 0063099c | __ftol2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
