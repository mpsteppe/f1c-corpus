## AudioDriverInit_00406cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

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
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x90: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00405050 | ShortComputation_5050 | R | [LLM] |
| 0059e390 | _AIL_set_DirectSound_HWND@8 | R | [LLM] |
| 0059e394 | __imp__AIL_shutdown@0 | R | [LLM] |
| 0059e398 | _AIL_open_digital_driver@16 | R | [LLM] |
| 0059e39c | _AIL_set_preference@8 | R | [LLM] |
| 0059e3a0 | _AIL_startup@0 | R | [LLM] |
| 0059e3e4 | _AIL_set_file_callbacks@16 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534ac0 | CallbackRegistration_4ac0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
