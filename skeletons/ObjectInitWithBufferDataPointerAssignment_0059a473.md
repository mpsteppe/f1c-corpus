## ObjectInitWithBufferDataPointerAssignment_0059a473 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleObjectConstructorWithVTableSetup (00599cb7), ConditionalCallbackWithNullCheck (0059a44c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d5a60 | dword_8D5A60 | R | BufferCapacity [DERIVED] (also: ` — capacity/limit global constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598c1c | LocaleRefcountAcquireUnderLock | [LLM] |
| 00598c70 | NullCheckWithVirtualDispatch | [LLM] |
| 0059a4c9 | SelfReferentialPointerRingInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
