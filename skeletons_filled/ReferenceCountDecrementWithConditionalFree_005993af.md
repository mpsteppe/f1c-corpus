## ReferenceCountDecrementWithConditionalFree_005993af — RefCountDecWithConditionalFree

**Summary:** Decrements byte-sized reference count stored at data[-1]. Frees allocation if refcount reaches 0 or 0xFF. Zeroes offsets 0x4, 0x8, 0xC on completion. Skip decrement if a2 flag is 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyLocaleObjectFreeResourcesCallDtor (00598e39), sub_599560 (00599560), ConditionalStringFreeWithLengthCheck (005995e5), BufferAllocationWithSizeRounding (0059964a), CDestructorWithVTableChain (00599e71), sub_59A5FE (0059a5fe), CExceptionInitHandler (0059a69a), ExceptionCleanupWithDestructorCall (0059a728), ExceptionObjectConstructor (0059a781), DestructorWithSEHVTableReset (0059a7de), sub_59A9CA (0059a9ca), ObjectConstructorWithVTableAndStringInit (0059abcd), ObjectTeardownWithIteratorCleanup (0059ac7f), sub_59AD49 (0059ad49), CExceptionInitHandler_ada3 (0059ada3), ExceptionDestructorSEHWrapper (0059ae24), CObjectConstructorWithVtable (0059ae7d), ExceptionDestructor (0059aeda), sub_59AF68 (0059af68), ExceptionObjectDestructorWithSEH (0059afc2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | pointer to data block (refcount byte at block[-1]) |
| this | 0x8 | RW | 0 | second field zeroed on release |
| this | 0xC | RW | 0 | third field zeroed on release |

**Written-by note (persistence):**
- this 0x4: zeroed unconditionally; external poke overwritten
- this 0x8: zeroed unconditionally; external poke overwritten
- this 0xC: zeroed unconditionally; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free memory block when refcount reaches 0 or 0xFF |

**Guard conditions:** if a2 flag is 0, skip decrement (but still zero fields). If this+0x4 is NULL, skip decrement. If refcount byte at data[-1] is 0 or 0xFF, free block; else decrement byte.
