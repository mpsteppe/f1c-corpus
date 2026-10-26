## BinaryDataDeserialization_004054e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_406790 (00406790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x40 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | [LLM] |
| 00405630 | StructInitWithVTableDispatchAndZeroFill | [LLM] |
| 004056a0 | MemoryAllocation_56a0 | [LLM] |
| 00407ef0 | BitfieldExtractFromStruct | [LLM] |
| 0052d8d0 | ThreadedObjectCreatorWithSEH | [LLM] |
| 00587f64 | sub_587F64 | [LLM] |
| 0058803f | ThreadSafeReadWrapper_803f | [LLM] |
| 0058ae69 | sub_58AE69 | [LLM] |
| 0059b650 | sub_59B650 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
