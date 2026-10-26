## sub_5BD0D0_005bd0d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BD390 (005bd390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0xFC | R | — | [LLM] |
| *(this+0x184) | 0x100 | R | — | [LLM] |
| *(this+0x184) | 0x104 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042fbc0 | sub_42FBC0 | [LLM] |
| 005c00f0 | sub_5C00F0 | [LLM] |
| 005c0470 | sub_5C0470 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
