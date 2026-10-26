## sub_43DFB0_0043dfb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_43BB20 (0043bb20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1854) | 0x0 | R | — | [LLM] |
| *(this+0x1854) | 0x4 | R | — | [LLM] |
| *(this+0x1868) | 0x0 | R | — | [LLM] |
| *(this+0x1868) | 0x4 | R | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x68 | RW | 0 | [LLM] |
| this | 0x6C | RW | 0 | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0xB8 | RW | 0 | [LLM] |
| this | 0x3FC | R | — | [LLM] |
| this | 0x8E4 | R | — | [LLM] |
| this | 0x1814 | R | — | [LLM] |
| this | 0x1854 | R | — | [LLM] |
| this | 0x1858 | RW | — | [LLM] |
| this | 0x185C | RW | — | [LLM] |
| this | 0x1860 | RW | — | [LLM] |
| this | 0x1868 | R | — | [LLM] |
| this | 0x186C | RW | — | [LLM] |
| this | 0x1870 | RW | — | [LLM] |
| this | 0x1874 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1858: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x185C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1860: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x186C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1870: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1874: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54c0 | dbl_5D54C0 | R | [LLM] |
| 005d54c8 | dbl_5D54C8 | R | [LLM] |
| 005d54d0 | dbl_5D54D0 | R | [LLM] |
| 005d5fb8 | dbl_5D5FB8 | R | [LLM] |
| 005fe2e4 | aFrSteering | R | [LLM] |
| 005fe2f0 | aFlSteering | R | [LLM] |
| 005fe3d4 | aFrForeLower | R | [LLM] |
| 005fe3e4 | aFrForeUpper | R | [LLM] |
| 005fe3f4 | aFlForeLower | R | [LLM] |
| 005fe404 | aFlForeUpper | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004388f0 | F_3DVectorTransformBy33Matrix [exact] | [LLM] |
| 0043d970 | SuspensionBarLookup [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `fr_steering`
- `fl_steering`
- `fr_fore_lower`
- `fr_fore_upper`
- `fl_fore_lower`
- `fl_fore_upper`
