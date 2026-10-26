## StateInitializerWithFlagCheck_00466300 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSceneLoadAndPositionTires (004681b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | [LLM] |
| this | 0x124 | RW | 18446744072627421184 → -1.0f | [LLM] |

**Written-by note (persistence):**
- this 0x124: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466350 | sub_466350 | [LLM] |
| 00466650 | sub_466650 | [LLM] |
| 0048e8d0 | CUBESceneLoaderEntry | [LLM] |
| 004988a0 | FieldSetterCall | [LLM] |
| 00541ca0 | sub_541CA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
