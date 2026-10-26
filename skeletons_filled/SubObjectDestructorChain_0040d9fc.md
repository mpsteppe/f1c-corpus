## SubObjectDestructorChain_0040d9fc — SubObjectDestructorChain

**Summary:** Destructor-like function: frees this[34] if non-null, calls LinkedListDestructorWithInnerFree on this+19, then reinitializes this+5 via ConstraintSolverParamInit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x88 | R | — | pointer field checked for non-null before freeing |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567a30 | LinkedListDestructorWithInnerFree | destruct linked list at this+19, freeing inner elements |
| 00587bcf | FreeWrapper_7bcf | free memory block at this[34] |

**Guard conditions:** this[34] non-null → free it; null → skip free
