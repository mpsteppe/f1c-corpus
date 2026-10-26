## sub_4A4AA0_004a4aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x11C)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x11C)+0x0) | 0x10 | R | — | [LLM] |
| *(*(this+0x11C)+0x0) | 0x2C | R | — | [LLM] |
| *(*(this+0x124)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x118) | 0x14 | R | — | [LLM] |
| *(this+0x118) | 0x18 | R | — | [LLM] |
| *(this+0x11C) | 0x0 | R | — | [LLM] |
| *(this+0x11C) | 0x8 | R | — | [LLM] |
| *(this+0x124) | 0x4 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |
| this | 0x128 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x170 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |
| this | 0x17C | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1AF | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x124: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 00765b00 | unk_765B00 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cb80 | sub_49CB80 | [LLM] |
| 004a4660 | F_4FieldSetter [structural] | [LLM] |
| 004a4c90 | sub_4A4C90 | [LLM] |
| 004a50d0 | sub_4A50D0 | [LLM] |
| 004ab570 | sub_4AB570 | [LLM] |
| 004ae870 | sub_4AE870 | [LLM] |
| 005be8bc | __ftol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x12C | == | 1 | [LLM] |
| this | 0x134 | == | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
