## ArrayOfObjectsDestructor_0040fdd0 — MultiObjectArrayDestructor

**Summary:** Destructor for an array of 198-dword objects (or a single object) with FileStream vtable. If flag bit 2 set, iterates backward through an array (preceded by count dword at this-1), setting vtable and destructing each subobject. Always calls MultiFieldCleanupDestructor on subobject at +53 dwords. Optionally frees memory if flag bit 1 set.

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
| 0059e720 | off_59E720 | R | VTable_FileStream [DERIVED] — assigned to each object's vtable during destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568e60 | MultiFieldCleanupDestructor | destructs nested subobject at entry+53 dwords (0xD4) |
| 00587bcf | FreeWrapper_7bcf | frees memory block when flag bit 1 is set |

**Guard conditions:** if (a2 & 2) == 0 → single-object path (set vtable, destroy subobject, maybe free). If (a2 & 2) != 0 → array path: read count at this-1, iterate backward destroying each, then maybe free.
