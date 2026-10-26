## sub_59A9CA_0059a9ca — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionInitHandler (0059a69a), ExceptionObjectConstructor (0059a781), CExceptionInitHandler_ada3 (0059ada3), CObjectConstructorWithVtable (0059ae7d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d34 | unk_5B9D34 | R | Buf_NullStringSentinel [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058cc00 | MemoryCopy_cc00 | [LLM] |
| 00599348 | BufferTruncationShrink | [LLM] |
| 005993af | ReferenceCountDecrementWithConditionalFree | [LLM] |
| 00599560 | sub_599560 | [LLM] |
| 0059af68 | sub_59AF68 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
