## sub_53EEE0_0053eee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_51C0B0 (0051c0b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x39E4 | R | — | [LLM] |
| this | 0x57C4 | R | — | [LLM] |
| this | 0x5830 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x5830: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f30d8 | flt_6F30D8 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0082f4a0 | dword_82F4A0 | RW | [LLM] |
| 009034a4 | off_9034A4 | RW | [LLM] |
| 00b6cba8 | dword_B6CBA8 | R | [LLM] |
| 00fb1d08 | dbl_FB1D08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004735a0 | sub_4735A0 | [LLM] |
| 00474b10 | ClampedPhysicsScaleWithThreshold [structural] | [LLM] |
| 0053ec40 | sub_53EC40 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39E4 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
