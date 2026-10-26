## sub_5AD5F0_005ad5f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BD160 (004bd160), TimerBasedStateUpdateWithCap [structural] (005ad8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54d0 | dbl_5D54D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00590820 | ??0Iostream_init@@QAE@XZ_0 | [LLM] |
| 00590830 | nullsub_11 [exact] | [LLM] |
| 00590850 | sub_590850 | [LLM] |
| 00590940 | sub_590940 | [LLM] |
| 0059dfd0 | sub_59DFD0 | [LLM] |
| 005be8bc | __ftol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18 | != | 255 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
