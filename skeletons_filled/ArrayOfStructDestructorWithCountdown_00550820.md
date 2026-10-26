## ArrayOfStructDestructorWithCountdown_00550820 — CountedArrayDestructorBackward

**Summary:** Frees a counted array of 8-byte elements by iterating backward, destroying each element via sub_550810, then freeing the entire block including the count prefix.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_550F70 (00550f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Pointer to allocated counted array (count at offset -4, 8-byte elements) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00550810 | sub_550810 | Destructor for a single 8-byte array element |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation for the entire array block |

**Guard conditions:** 
- this[2] (this+0x8) == 0: skip array destruction entirely. PASS when non-null.
