## StructEntryCleanup_004d6800 — StructEntryCleanup

**Summary:** Cleans up a struct entry: zeros three fields (offsets 0x8, 0xC, 0x10) and conditionally frees a heap-allocated buffer at offset 0x14 via FreeWrapper_7bcf. Also calls StringCopyWithBufferRealloc on a global string buffer. Called by ArrayBlockCleanup for per-entry teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArrayBlockCleanup (004d7050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | first data field (cleared to 0 on cleanup) |
| this | 0xC | RW | 0 | second data field (cleared to 0 on cleanup) |
| this | 0x10 | RW | 0 | third data field (cleared to 0 on cleanup) |
| this | 0x14 | RW | 0 | heap-allocated buffer pointer (freed if non-null) |

**Written-by note (persistence):**
- this 0x8: cleared unconditionally to 0 on cleanup
- this 0xC: cleared unconditionally to 0 on cleanup
- this 0x10: cleared unconditionally to 0 on cleanup
- this 0x14: conditionally freed and zeroed (only if non-null pointer)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | global path/string buffer passed to StringCopyWithBufferRealloc |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | string copy with reallocation of target buffer (operates on global string buffer) |
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation wrapper |

**Guard conditions:** only conditional is pointer check at this+0x14 (offset 0x14): if non-null, frees and zeros it. No early return — all other fields cleared unconditionally.
