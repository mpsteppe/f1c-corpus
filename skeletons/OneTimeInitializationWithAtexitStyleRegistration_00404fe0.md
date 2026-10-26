## OneTimeInitializationWithAtexitStyleRegistration_00404fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSaveWrapper (00405030), ShortComputation_5050 (00405050), MemoryAllocation_5160 (00405160), BinaryDataDeserialization (004054e0), ShortComputation_6100 (00406100), FileLoadWithRetryLoop (004f9b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00405020 | InitLoadPathWrapper | R | [LLM] |
| 005ea440 | unk_5EA440 | R | StaticBufferHandle [DERIVED] |
| 005ea4e0 | byte_5EA4E0 | RW | InitGateFlag [DERIVED] (also: ` — init flag (bit 0=initialized) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406ab0 | GenericObjectConstructorWithVTable | [LLM] |
| 00587b3e | BooleanToIntConversion | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
