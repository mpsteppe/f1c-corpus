## LocaleRefcountAcquireUnderLock_00598c1c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSEHVTableInitChain (00598bbc), ObjectInitializationWithBufferBoundsSetup (005994bc), LocaleObjectConstructorWithVTableSetup (00599cb7), ObjectInitWithBufferDataPointerAssignment (0059a473), StructFieldInitWithConditionalCall (0059a948)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4650 | dword_8D4650 | R | EncodingSingletonPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598c4a | CounterIncrementThreadSafe | [LLM] |
| 0059a54d | sub_59A54D | [LLM] |
| 0059a5e9 | sub_59A5E9 | [LLM] |
| 0059aab9 | sub_59AAB9 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
