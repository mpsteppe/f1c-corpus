## sub_59A9CA_0059a9ca — String buffer subrange assignment

**Summary:** Assigns a subrange of source string buffer `a2` to destination `this`. If self-assignment, truncates via BufferTruncationShrink. Otherwise attempts reference-counted sharing when copying the full string; falls back to allocation + memcpy for partial ranges or large strings.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionInitHandler (0059a69a), ExceptionObjectConstructor (0059a781), CExceptionInitHandler_ada3 (0059ada3), CObjectConstructorWithVtable (0059ae7d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Buffer data pointer (string content) |
| this | 0x8 | RW | — | Buffer length (used length) |
| this | 0xC | RW | — | Buffer capacity (allocated size) |

**Written-by note (persistence):**
- this 0x4: Written on share/alloc — external poke would corrupt pointer.
- this 0x8: Written with new length — external poke corrupts length tracking.
- this 0xC: Written on alloc — external poke corrupts capacity tracking.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d34 | unk_5B9D34 | R | Buf_NullStringSentinel [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058cc00 | MemoryCopy_cc00 | Raw memory copy (memcpy) |
| 00599348 | BufferTruncationShrink | Shrink/reallocate buffer to fit subrange |
| 005993af | ReferenceCountDecrementWithConditionalFree | Decrement ref count on existing buffer |
| 00599560 | sub_599560 | Allocate/resize buffer for requested capacity |
| 0059af68 | sub_59AF68 | Throw std::out_of_range on invalid access |

**Guard conditions:** `if (a2[2] < a3) sub_59AF68()` — throws out_of_range when source length < offset. `if (!v5 || v5 != a2[2]) goto copy_path` — ref-count sharing only when copying entire string (v5 == full source length).
