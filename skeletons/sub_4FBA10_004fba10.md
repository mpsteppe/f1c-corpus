## sub_4FBA10_004fba10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x48 | RW | 1 | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | 1 | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB0 | RW | — | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0xB8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0xA4: [LLM: once/conditional? does external poke survive?]
- this 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0xAC: [LLM: once/conditional? does external poke survive?]
- this 0xB0: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]
- this 0xB8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005d6f08 | aClouds | R | aClouds [DERIVED] |
| 005d6f10 | aCloudrny | R | aCloudRainy [DERIVED] |
| 005d6f1c | aCloudsny | R | String_CloudsNy [DERIVED] |
| 005d6f28 | aSkyboxi | R | SkyboxString [DERIVED] |
| 007cf914 | flt_7CF914 | R | Float7CF914 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | [LLM] |
| 005452f0 | AudioNetworkNodeCount | [LLM] |
| 00545340 | LinkedListNodeFinder | [LLM] |
| 005453a0 | EvaluateSceneNodeProperty | [LLM] |
| 00545f40 | ValueGetter | [LLM] |
| 00548890 | sub_548890 | [LLM] |
| 0054b420 | TripleFieldQuery | [LLM] |
| 0054bda0 | SelfRelativeStringCopy | [LLM] |
| 0054bdc0 | UIElementBitfieldStateSetter | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588640 | sub_588640 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
