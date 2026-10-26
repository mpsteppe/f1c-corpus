## ArrayCleanupWithDualFree_00546370 — Cleanup array with per-element dual free

**Summary:** Frees array of 148-byte stride structures at this+0xA8. For each element, frees allocation at +76 and at +144 (calling EmptyStub_7470 before second free). Then frees the entire array block (allocated with count prefix at -4). Resource manager cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TwoListCleanup (00547420), sub_547710 (00547710), DirectXMeshVertexBufferParsingAndLoading (00547b40), D3DTextureResourceCreation (00548190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA4 | R | — | element count (number of array entries) |
| this | 0xA8 | RW | 0 | pointer to allocated array block (count prefix at -4) |

**Written-by note (persistence):**
- this 0xA8: zeroed unconditionally at end of cleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | stub called before freeing per-element resources |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA4 | > | 0 | element count check: proceed with per-element cleanup loop |

**Guard interpretation:** If this+0xA4 (element count) > 0, iterates through array freeing per-element allocations. If <= 0, skips per-element loop but still frees the array block itself (if this+0xA8 non-null).
