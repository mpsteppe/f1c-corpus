## ReferencesGlobalState_33a0_004733a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x31C | RW | — | [LLM] |
| this | 0x324 | RW | 3 | [LLM] |
| this | 0x328 | RW | 0 | [LLM] |
| this | 0x32C | RW | 3 | [LLM] |
| this | 0x330 | RW | 3 | [LLM] |
| this | 0x334 | RW | 270 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x31C: [LLM: once/conditional? does external poke survive?]
- this 0x324: [LLM: once/conditional? does external poke survive?]
- this 0x328: [LLM: once/conditional? does external poke survive?]
- this 0x32C: [LLM: once/conditional? does external poke survive?]
- this 0x330: [LLM: once/conditional? does external poke survive?]
- this 0x334: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a27c0 | off_5A27C0 | R | [LLM] |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] (also: ` — UI/text handle) |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] (also: ` — UI/text handle (near VehicleCount) |
| 007d02e4 | dword_7D02E4 | R | UIControl_RefStore [DERIVED] (also: ` — global reference stored in object) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
