## MultiFieldFree_f8eb_0058f8eb — MultiFieldFreeGuard

**Summary:** Frees 7 pointer fields (indices 3-9, offsets 0xC-0x24) from a structure via sub_58AA6F, but only if the structure's third field (index 3, offset 0xC) does not point to the static sentinel word_8D41CC. This protects static/read-only locale data from being freed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsAllocatorNodeInit_f6fe (0058f6fe)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Field index 3 — sentinel check pointer (compared against word_8D41CC to detect static data) |
| this | 0x10 | R | — | Field index 4 — locale buffer pointer (freed if sentinel check passes) |
| this | 0x14 | R | — | Field index 5 — locale buffer pointer (freed) |
| this | 0x18 | R | — | Field index 6 — locale buffer pointer (freed) |
| this | 0x1C | R | — | Field index 7 — locale buffer pointer (freed) |
| this | 0x20 | R | — | Field index 8 — locale buffer pointer (freed) |
| this | 0x24 | R | — | Field index 9 — locale buffer pointer (freed) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d41cc | word_8D41CC | R | ConfigParseBuffer [DERIVED] — static sentinel address; if a1[3] points here, skip freeing (static data) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058aa6f | sub_58AA6F | Free a single memory allocation |

**Guard conditions:**
- `a1 == NULL` → return immediately (no-op)
- `a1[3] == &word_8D41CC` → skip all freeing (pointers reference static/read-only data)
- Otherwise → free a1[3] through a1[9] (7 pointers at offsets 0xC-0x24)
