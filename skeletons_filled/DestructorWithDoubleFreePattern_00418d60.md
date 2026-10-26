## DestructorWithDoubleFreePattern_00418d60 — SimplePointerListCleanup

**Summary:** Destructor for simple pointer container. If flag at this+0x8 is set and data block is non-null, frees first internal pointer then the block itself. Optionally frees container if a2 bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NameListBuilderFromVehicleArray (004159b0), sub_45D730 (0045d730), HTMLOutputSectionProcessor (00467f90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First internal pointer inside data block (freed first) |
| this | 0x0 | R | — | Pointer to data block (v3); freed after internal cleanup |
| this | 0x8 | R | — | Cleanup enable flag (byte); must be non-zero to proceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** this+0x8 (cleanup flag) must be non-zero to enter cleanup path. *this (data block) must be non-null to proceed. *v3 (first internal pointer) checked for null before FreeWrapper_7bcf call. After cleanup, if a2 bit 0 is set, `this` container is also freed.
