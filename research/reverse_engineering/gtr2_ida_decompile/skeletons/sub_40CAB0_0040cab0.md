## sub_40CAB0_0040cab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | [LLM] |
| obj | 0x34 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | RW | 0 | [LLM] |
| this | 0x5C | RW | 0 | [LLM] |
| this | 0x60 | RW | 0 | [LLM] |
| this | 0x70 | RW | 0 | [LLM] |
| this | 0x74 | RW | 0 | [LLM] |
| this | 0x78 | RW | 0 | [LLM] |
| this | 0x7C | RW | 0 | [LLM] |
| this | 0x80 | RW | 0 | [LLM] |
| this | 0x84 | RW | 0 | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x80: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x84: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x88: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x90: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1614 | __imp__AIL_shutdown@0 | R | [LLM] |
| 006f1628 | _AIL_set_file_callbacks@16 | R | [LLM] |
| 006f162c | _AIL_set_DirectSound_HWND@8 | R | [LLM] |
| 006f1634 | _AIL_open_digital_driver@16 | R | [LLM] |
| 006f1638 | _AIL_startup@0 | R | [LLM] |
| 006f1674 | _AIL_set_preference@8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a8800 | sub_5A8800 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
