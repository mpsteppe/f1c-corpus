## UtilityFunction_004081e0 — ConditionalPointerCleanupAndFree

**Summary:** Checks a flag byte at offset 8; if set, performs multi-stage cleanup on the pointer at offset 0 then frees it. Conditional destructor helper for objects with resource management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ComplexDestructorWith4LinkedLists (00406ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to allocated object that needs cleanup and free |
| this | 0x8 | R | — | flag byte: non-zero means cleanup+free should occur |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405410 | MultiStageCleanupWithFree | performs multi-stage resource cleanup/release on the pointed-to object |
| 00587bcf | FreeWrapper_7bcf | frees the memory block after cleanup |

**Guard conditions:** If flag byte at offset 8 is zero, function returns immediately without cleanup. If pointer at offset 0 is null, cleanup+free is skipped. Returns the flag byte value unchanged.
