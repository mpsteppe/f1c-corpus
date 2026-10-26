## sub_4EEA90_004eea90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x198 | RW | — | [LLM] |
| this | 0x19C | RW | — | [LLM] |
| this | 0x1A0 | RW | — | [LLM] |
| this | 0x1A4 | RW | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x198: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x19C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004eebc0 | jpt_4EEAFC | R | [LLM] |
| 006f16e8 | flt_6F16E8 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00b70a44 | flt_B70A44 | R | [LLM] |
| 00be08a0 | dword_BE08A0 | RW | [LLM] |
| 00be08a4 | flt_BE08A4 | R | [LLM] |
| 00fb1d18 | dbl_FB1D18 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x180 | == | 2139095039 | [LLM] |
| this | 0x184 | == | 2139095039 | [LLM] |
| this | 0x188 | == | 2139095039 | [LLM] |
| this | 0x18C | == | 2139095039 | [LLM] |
| this | 0x1A8 | == | 2139095039 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
