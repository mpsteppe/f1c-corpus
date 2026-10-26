## VertexBufferOffsetSetup_00519375 — VertexBufferOffsetSetup

**Summary:** Allocates and populates vertex buffer offset arrays for each animation/render element. Computes per-element buffer start and end offsets based on element dimensions and stride. Part of rendering pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MediaBufferAlloc (005198b3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x180) | 0x38 | RW | — | buffer start offsets array pointer (allocated) |
| *(this+0x180) | 0x3C | RW | — | buffer end offsets array pointer (allocated) |
| *(this+0x4) | 0x0 | R | — | vtable allocation function |
| *(this+0xC4) | 0xC | R | — | element width (from element descriptor) |
| *(this+0xC4) | 0x24 | R | — | element height/stride (from element descriptor) |
| this | 0x4 | R | — | vtable pointer for allocation call |
| this | 0x20 | R | — | number of elements to process |
| this | 0xC4 | R | — | pointer to element descriptor array |
| this | 0x114 | R | — | animation frame count or stride divisor |
| this | 0x180 | R | — | pointer to output buffer descriptor struct |

**Written-by note (persistence):**
- *(this+0x180) 0x38: allocated array; external poke corrupts offsets
- *(this+0x180) 0x3C: allocated array; external poke corrupts offsets

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | element count |

**Guard interpretation:** If this->0x20 > 0 (PASSES), iterates through elements and computes per-element buffer offsets from dimensions and stride. If 0 (BLOCKED/empty), skips loop; only allocates the base buffer arrays.
