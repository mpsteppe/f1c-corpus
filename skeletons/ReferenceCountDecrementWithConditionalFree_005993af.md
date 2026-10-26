## ReferenceCountDecrementWithConditionalFree_005993af — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyLocaleObjectFreeResourcesCallDtor (00598e39), sub_599560 (00599560), ConditionalStringFreeWithLengthCheck (005995e5), BufferAllocationWithSizeRounding (0059964a), CDestructorWithVTableChain (00599e71), sub_59A5FE (0059a5fe), CExceptionInitHandler (0059a69a), ExceptionCleanupWithDestructorCall (0059a728), ExceptionObjectConstructor (0059a781), DestructorWithSEHVTableReset (0059a7de), sub_59A9CA (0059a9ca), ObjectConstructorWithVTableAndStringInit (0059abcd), ObjectTeardownWithIteratorCleanup (0059ac7f), sub_59AD49 (0059ad49), CExceptionInitHandler_ada3 (0059ada3), ExceptionDestructorSEHWrapper (0059ae24), CObjectConstructorWithVtable (0059ae7d), ExceptionDestructor (0059aeda), sub_59AF68 (0059af68), ExceptionObjectDestructorWithSEH (0059afc2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
