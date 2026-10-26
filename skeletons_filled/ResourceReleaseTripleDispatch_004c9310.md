## ResourceReleaseTripleDispatch_004c9310 — ResourceReleaseTripleDispatch

**Summary:** Dispatches vtable+8 method on up to three sub-objects stored at offsets 0x20, 0x24, 0x28. Does NOT null or free pointers. Returns result from last successful dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x8 | R | — | VTable offset 8 method of first sub-object |
| *(this+0x24) | 0x8 | R | — | VTable offset 8 method of second sub-object |
| *(this+0x28) | 0x8 | R | — | VTable offset 8 method of third sub-object |
| this | 0x20 | R | — | Pointer to first sub-object |
| this | 0x24 | R | — | Pointer to second sub-object |
| this | 0x28 | R | — | Pointer to third sub-object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each pointer (this+0x20, +0x24, +0x28) checked for non-null before dispatching vtable+8. Null pointers are silently skipped.
