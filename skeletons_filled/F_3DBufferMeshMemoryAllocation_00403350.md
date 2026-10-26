## F_3DBufferMeshMemoryAllocation_00403350 — MeshBufferAllocFromDimensions

**Summary:** Allocates and initializes mesh buffer memory for a 3D object based on dimension fields. Frees any existing allocations at this+336/340/344, computes new buffer sizes from this+348/352/356/360 (vertex/index/batch counts), allocates three buffers (stream, index, batch) via OperatorNewNhMallocWrapper, zero-fills each, and returns. Sets stride-based layout offsets at this+8/12/16/20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 1 | set to 1 — allocation flag / initialized marker |
| this | 0xC | RW | — | stream buffer offset (v2 based on this+348) |
| this | 0x10 | RW | — | stream buffer end offset |
| this | 0x14 | RW | — | stream buffer total size (v4+v3) |
| this | 0x150 | RW | — | pointer to vertex stream buffer (allocated) |
| this | 0x154 | RW | — | pointer to index buffer (allocated) |
| this | 0x158 | RW | — | pointer to batch buffer (allocated) |
| this | 0x15C | R | — | vertex count (input dimension) |
| this | 0x160 | R | — | index count (input dimension) |
| this | 0x164 | R | — | batch group count (input dimension) |
| this | 0x168 | R | — | sub-batch multiplier (input dimension) |

**Written-by note (persistence):**
- this 0x8: written once per allocation — persists across frames until reallocation
- this 0xC: written once per allocation — persists across frames until reallocation
- this 0x10: written once per allocation — persists across frames until reallocation
- this 0x14: written once per allocation — persists across frames until reallocation
- this 0x150: written once per allocation — persists across frames until reallocation
- this 0x154: written once per allocation — persists across frames until reallocation
- this 0x158: written once per allocation — persists across frames until reallocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees existing buffer allocations before reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory (28-byte stride) for mesh buffers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | vertex count > 0 — guards zero-fill loop for stream buffer |
| this | 0x164 | > | 0 | index count > 0 — guards zero-fill loop for index buffer |

**Guard interpretation:** If vertex count (this+0x160) > 0, zero-fills all vertex stream entries (28 bytes each). If index count (this+0x164) > 0, zero-fills all index entries. If batch count (this+0x15C) > 0, zero-fills all batch buffer entries (batch_count * sub_batch_count). If dimension <= 0, allocation still happens but zero-fill loops are skipped.
