## ShortComputation_00401130 — FreeContainedPointersAndRelease

**Summary:** Frees three optional pointer allocations at this+336, this+340, this+344 via FreeWrapper_7bcf if non-null, then calls ObjectReleaseArrayIterator to release the array at this. Used as a cleanup/destructor-like function for an object containing multiple sub-allocations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x150 | R | — | first optional pointer to free (if non-null) |
| this | 0x154 | R | — | second optional pointer to free (if non-null) |
| this | 0x158 | R | — | third optional pointer to free (if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees a heap allocation via wrapper |

**Guard conditions:** Checks each of three pointers (this+336/340/344) for non-null before calling FreeWrapper_7bcf. PASSES: all non-null pointers freed, then ObjectReleaseArrayIterator called.
