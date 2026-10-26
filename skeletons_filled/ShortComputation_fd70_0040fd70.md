## ShortComputation_fd70_0040fd70 — FileStreamSubobjectDestructor

**Summary:** Destructor for an object with FileStream vtable. Replaces vtable pointer at this+0 with VTable_FileStream, then calls MultiFieldCleanupDestructor on a nested subobject at this+0xD4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GraphicsResourceDestructor (0040fb30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, overwritten with VTable_FileStream during destruction |

**Written-by note (persistence):**
- this 0x0: set once per destructor call to VTable_FileStream; permanent (object being destroyed)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e720 | off_59E720 | R | VTable_FileStream [DERIVED] — assigned to this+0 as part of destructor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e6a0 | MultiFieldCleanupDestructor | cleans up nested subobject at this+0xD4 |

**Guard conditions:** none — unconditional, no early return
