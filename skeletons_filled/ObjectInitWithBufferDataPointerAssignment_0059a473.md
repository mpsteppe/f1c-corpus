## ObjectInitWithBufferDataPointerAssignment_0059a473 — Buffer/stream object init with data pointer and capacity

**Summary:** Initializes buffer/stream object: stores flag at offset 0x48 based on a3 parameter, conditionally acquires locale reference count on facet at offset 0x4C, calls SelfReferentialPointerRingInit, stores external buffer data pointer at offset 0x50, and sets capacity boundaries from global dword_8D5A60.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleObjectConstructorWithVTableSetup (00599cb7), ConditionalCallbackWithNullCheck (0059a44c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | 0 | buffer start position, initialized to 0 |
| this | 0x3C | RW | — | buffer end position, initialized to dword_8D5A60 |
| this | 0x40 | RW | — | buffer capacity, initialized to dword_8D5A60 |
| this | 0x44 | RW | 0 | pointer field, cleared to 0 when a3==0 |
| this | 0x48 | RW | — | flag byte set to (a3==1) — distinguishes final vs incremental init |
| this | 0x50 | RW | — | external buffer data pointer, set to a2 parameter |

**Written-by note (persistence):**
- this 0x38: written once to 0; persists until overwritten
- this 0x3C: written once to dword_8D5A60; persists until overwritten
- this 0x40: written once to dword_8D5A60; persists until overwritten
- this 0x44: written once to 0 only when a3==0; persists until overwritten
- this 0x48: written once to (a3==1); persists until overwritten
- this 0x50: written once to a2; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d5a60 | dword_8D5A60 | R | BufferCapacity [DERIVED] (also: ` — capacity/limit global constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598c1c | LocaleRefcountAcquireUnderLock | acquires reference count on locale facet under lock |
| 00598c70 | NullCheckWithVirtualDispatch | checks for null then dispatches virtual call |
| 0059a4c9 | SelfReferentialPointerRingInit | initializes self-referential pointer ring within object |

**Guard conditions:** If a3 == 0, takes conditional init path: NullCheckWithVirtualDispatch on facet at 0x4C, acquires ref count, and clears field at 0x44 to 0. If a3 != 0, skips this path. The flag at 0x48 is set to (a3 == 1).
