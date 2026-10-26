## DestructorWithConditionalFree_5900_00485900 — DualSubObjDtor

**Summary:** Destructor that frees buffer pointers at offsets 0x118 and 0x154 if non-null, calls ConditionalDualCleanup on sub-objects at offsets 224 and 288, then chains to base destructor sub_485EB0 and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x118 | R | — | buffer pointer freed if non-null |
| this | 0x154 | R | — | buffer pointer freed if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | chains to base class destructor |
| 00499b50 | ConditionalDualCleanup | cleans up a two-field sub-object (conditionally freeing embedded pointers) |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** Each buffer pointer at offsets 0x118 and 0x154 is only freed if non-null.
