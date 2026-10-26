## ShortComputation_d4d0_004dd4d0 — Element destructor (free single resource)

**Summary:** Frees the resource pointer stored at offset +0x14 (this[5]) via FreeWrapper_7bcf if non-null; returns the pointer value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A2220 (004a2220), sub_4A22D0 (004a22d0), ArrayCleanupWithDestructorLoop (004dd470), DualArrayDestructor (004ded20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Resource pointer to free (this[5]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free memory wrapper |

**Guard conditions:** Checks `this[5]` (offset +0x14) for non-null. PASSES (frees) when non-null. BLOCKED (no-op) when null.
