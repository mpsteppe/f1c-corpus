## CleanupFunction_00557280 — VertexBufferSubResourceCleanup

**Summary:** Free vertex buffer sub-resource pointer at offset 0x20C if non-null, zero the field, then call stub.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanupDestructionForDirectXObjects (00543bf0), VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20C | RW | 0 | Pointer to sub-resource allocation, freed then zeroed |

**Written-by note (persistence):**
- this 0x20C: Written to 0 unconditionally; if non-null, freed first via FreeWrapper_7bcf

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Heap memory free wrapper |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20C | != | 0 | Sub-resource pointer |

**Guard interpretation:** PASS if pointer non-null (free the allocation), BLOCKED if null (nothing to free).
