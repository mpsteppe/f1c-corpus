## sub_4DCBA0_004dcba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49B0A0 (0049b0a0), FloatToIntConversionDelegation (004dcc90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dcd10 | ResourceCleanup_cd10 | [LLM] |
| 004dcdd0 | PositionComputationWithAlignment | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 0054fe10 | StructInitWithZeroFill | [LLM] |
| 00550080 | D3DTextureCreation | [LLM] |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
