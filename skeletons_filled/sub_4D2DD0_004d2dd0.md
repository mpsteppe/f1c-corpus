## sub_4D2DD0_004d2dd0 — Lazy allocation of 8-byte sub-structure

**Summary:** Lazily allocates an 8-byte zero-initialized structure on first call, stores pointer at this+0xA4, and passes it to sub_4D0110 init. Returns existing pointer on subsequent calls (singleton pattern).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA4 | RW | 0 | Pointer to lazily-allocated sub-structure (8 bytes, zero-initialized) |

**Written-by note (persistence):**
- this 0xA4: Written once on first allocation (lazy init). Subsequent calls return existing pointer without overwriting. External poke would survive but may be overwritten if allocation runs again after clearing.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0060 | ZeroInitSubCall | Zero-initializes an allocated block |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 8 bytes of heap memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA4 | != | 0 | Allocation guard — non-zero means already allocated |
| v3 (malloc) | — | == | NULL | Heap allocation failure |

**Guard interpretation:** If this+0xA4 is non-zero (already allocated), return it directly (skip allocation). If allocation returns NULL, store 0 and call sub_4D0110(0). Otherwise allocate, init, store, and call sub_4D0110 with new pointer.
