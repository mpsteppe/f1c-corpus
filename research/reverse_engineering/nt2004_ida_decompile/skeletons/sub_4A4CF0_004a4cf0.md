## sub_4A4CF0_004a4cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| obj | 0x90 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x134 | RW | 3 | [LLM] |
| this | 0x13C | RW | 0 | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x170 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |
| this | 0x17C | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1A4 | RW | — | [LLM] |
| this | 0x1AD | RW | 1 | [LLM] |
| this | 0x1AE | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x134: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x13C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1AD: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1AE: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049d1d0 | ByteFieldGetterAt100 [exact] | [LLM] |
| 004a56d0 | sub_4A56D0 | [LLM] |
| 004a5740 | sub_4A5740 | [LLM] |
| 004ae870 | sub_4AE870 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x134 | != | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
