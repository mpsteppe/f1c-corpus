## ArrayCleanup_004e3050 — QuadArrayPointerCleanup

**Summary:** Iterates 4 array pointers at stride 296 bytes (starting from offset 0x1F4), zeroes each count field and frees non-null allocations, then zeroes pointers. Destructor/cleanup for cluster storage arrays.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleResetClear (004e09e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F4 | RW | 0 | per-cluster count field, zeroed during cleanup |

**Written-by note (persistence):**
- this 0x1F4: zeroed each call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory block |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F4 | == | 0 | clusterPtr |

**Guard interpretation:** If current cluster array pointer (iterating 4 slots) is NULL, skip FreeWrapper_7bcf for that slot; zero count field regardless.
