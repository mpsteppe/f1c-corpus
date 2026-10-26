## LocaleRefcountAcquireUnderLock_00598c1c — LocaleRefcountAcquireUnderLock

**Summary:** Stores a value (from sub_59AAB9) into this-owned storage, then under lock increments a global reference counter on the encoding singleton. Part of the CRT locale reference-counting mechanism for stream buffer objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSEHVTableInitChain (00598bbc), ObjectInitializationWithBufferBoundsSetup (005994bc), LocaleObjectConstructorWithVTableSetup (00599cb7), ObjectInitWithBufferDataPointerAssignment (0059a473), StructFieldInitWithConditionalCall (0059a948)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | locale facet reference pointer (set from sub_59AAB9 return value) |

**Written-by note (persistence):**
- this 0x0: once — set to result of sub_59AAB9; persists as locale facet reference for the object

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4650 | dword_8D4650 | R | EncodingSingletonPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598c4a | CounterIncrementThreadSafe | thread-safe increment of reference counter |
| 0059a54d | sub_59A54D | acquire lock/synchronization primitive |
| 0059a5e9 | sub_59A5E9 | release lock/synchronization primitive |
| 0059aab9 | sub_59AAB9 | retrieve locale facet reference value |

**Guard conditions:** None unconditional.
