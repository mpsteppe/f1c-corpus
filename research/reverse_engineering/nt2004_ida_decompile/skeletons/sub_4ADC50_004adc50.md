## sub_4ADC50_004adc50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4A8870 (004a8870), sub_4A9940 (004a9940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1A8)+0x54) | 0x54 | RW | — | [LLM] |
| this | 0x154 | RW | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x1A8)+0x54) 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x154: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |
| 0062a090 | dword_62A090 | R | [LLM] |
| 007d6bb0 | dword_7D6BB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004addb0 | sub_4ADDB0 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
