## ObjectInitializationWithBufferBoundsSetup_005994bc — StreambufConstructorWithBufferBounds

**Summary:** Constructs MSVC streambuf object. Sets up buffer boundary pointers (eback/gptr/egptr/pptr/epptr), acquires locale refcount if a3==0, initializes self-referential pointer ring, sets capacity from dword_8D5A68. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSEHVTableInitChain (00598bbc), FileCloseWrapperWithStatus (00599495)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | gptr — get pointer (initial position in buffer) |
| this | 0x10 | RW | — | egptr — get end pointer |
| this | 0x1C | RW | — | eback — buffer start / putback position |
| this | 0x20 | RW | — | pptr — put pointer |
| this | 0x2C | RW | — | epptr — put end pointer (current put limit) |
| this | 0x30 | RW | — | pbase — put base (start of put area) |
| this | 0x38 | RW | 0 | codecvt facet pointer — initialized to 0 |
| this | 0x3C | RW | — | encoding state tracking from dword_8D5A68 |
| this | 0x40 | RW | — | buffer capacity/limit from dword_8D5A68 |
| this | 0x44 | RW | 0 | external buffer pointer — zeroed if a3==0 |
| this | 0x48 | RW | — | byte flag — set to (a3 == 1) — indicates no internal buffer |
| this | 0x50 | RW | — | buffer base pointer assigned from a2 |

**Written-by note (persistence):**
- offsets 0xC, 0x10, 0x1C, 0x20, 0x2C, 0x30, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x50: all written during construction; streambuf operations (seek, underflow, overflow) will modify them later — external poke would corrupt stream state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d5a68 | dword_8D5A68 | R | BufferCapacityLimit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598c1c | LocaleRefcountAcquireUnderLock | acquire locale reference count under lock (when a3==0) |
| 00598c70 | NullCheckWithVirtualDispatch | null-check pointer at this+0x4C then dispatch virtual call |
| 0059a4c9 | SelfReferentialPointerRingInit | initialize self-referential pointer ring for streambuf chaining |

**Guard conditions:** if a3==0, acquire locale refcount and zero this+0x44. If a2 (buffer) is non-null AND flag at this+0x48 is not set (internal buffer mode), initialize buffer boundary pointers; otherwise leave them unset.
