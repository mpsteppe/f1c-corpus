## DestructorWithFreeCondition_00477ee0 — Destructor with conditional buffer free

**Summary:** Destructor that frees an inner allocated buffer (if non-null), runs dual-cleanup on two sub-objects, calls base cleanup, then conditionally frees the instance itself based on flag parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x158 | R | — | pointer to heap-allocated buffer to free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | clean up base/release internal resources |
| 00499b50 | ConditionalDualCleanup | free a paired-allocation sub-object |
| 00587bcf | FreeWrapper_7bcf | free heap memory block |

**Guard conditions:** this+0x158 (dw344) non-zero → free inner buffer; a2 & 1 set → free this instance. If null or flag clear, respective free skipped.
