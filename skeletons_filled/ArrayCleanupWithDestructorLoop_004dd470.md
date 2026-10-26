## ArrayCleanupWithDestructorLoop_004dd470 — Cleanup array of objects with destructor loop

**Summary:** Frees a single resource pointer at offset +0x8, then processes an array at offset +0x10 by reading its element count from the preceding length header, iterating backward through 24-byte elements calling ShortComputation_d4d0 on each (destructor), and finally freeing the array allocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4E3360 (004e3360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Single resource pointer; freed directly if non-null |
| this | 0x10 | R | — | Array pointer (length header at offset -4); destructor loop + free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd4d0 | ShortComputation_d4d0 | Destructor called on each array element (24-byte objects) |
| 00587bcf | FreeWrapper_7bcf | Free memory allocation wrapper |

**Guard conditions:** Null-check on `this+0x8`: if null, skip single free. Null-check on `this+0x10`: if null, skip array destructor loop and array free. Both guards are independent.
