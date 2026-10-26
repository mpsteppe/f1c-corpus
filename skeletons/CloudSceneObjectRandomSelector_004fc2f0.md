## CloudSceneObjectRandomSelector_004fc2f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FC550 (004fc550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6F | RW | 0 | [LLM] |
| this | 0xA3 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x6F: [LLM: once/conditional? does external poke survive?]
- this 0xA3: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6f08 | aClouds | R | aClouds [DERIVED] |
| 005d6f30 | aCloudr | R | CloudRString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |
| 00588640 | sub_588640 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
