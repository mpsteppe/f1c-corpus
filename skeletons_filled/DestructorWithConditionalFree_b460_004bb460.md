## DestructorWithConditionalFree_b460_004bb460 — Secondary data destructor with self-free

**Summary:** Frees secondary allocation at this+0x4 if non-null. Optionally frees this itself if a2 bit 0 is set. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ModelSceneFileLoader (004b6c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Secondary data pointer (freed if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** this[1] freed only if non-null. Self freed only if a2 bit 0 set.
