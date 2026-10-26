## DestructorWithVTableReset_00479e50 — Destructor with vtable reset and conditional free

**Summary:** Object destructor that resets vtable to off_5A5E40, calls ObjectInitWithVTableCleanup for cleanup, and frees memory if parameter a2 bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; reset to off_5A5E40 during destruction |

**Written-by note (persistence):**
- this 0x0: written during destruction; memory is freed afterward if a2 bit 0 is set

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5e40 | off_5A5E40 | R | vtable pointer written during destruction before cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3e0 | ObjectInitWithVTableCleanup | performs object cleanup/teardown |
| 00587bcf | FreeWrapper_7bcf | frees the object's memory block |

**Guard conditions:** if a2 & 1 == 0 — BLOCKS FreeWrapper_7bcf call (object destructed but not freed). if a2 & 1 != 0 — PASSES through to free.
