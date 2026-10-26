## MilesSoundSystemSampleAllocator_004072e0 — MilesSoundSystemSampleAllocator

**Summary:** Manages Miles Sound System sample allocation: frees existing sample array and AIL sample handles, allocates new array of 20-byte entries with allocated AIL sample handles, and initializes each sample via AIL_init_sample.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GenericObjectConstructorWithVTable (00406ab0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | RW | 0 | pointer to allocated array of 20-byte sample entries |
| this | 0x4C | RW | 0 | count of sample entries in the array |
| this | 0x90 | R | — | driver handle (passed to AIL_allocate_sample_handle) |

**Written-by note (persistence):**
- this 0x48: written on reallocation — set to new array pointer or 0
- this 0x4C: written on reallocation — set to new count or 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3dc | _AIL_init_sample@4 | R | Miles API to initialize an allocated sample handle |
| 0059e3ec | _AIL_allocate_sample_handle@4 | R | Miles API to allocate a sample handle from driver |
| 0059e3f0 | _AIL_release_sample_handle@4 | R | Miles API to release/free a sample handle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees the allocated array header memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory for new sample array with header |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | > | 0 | sample count determines whether to iterate and process entries |

**Guard interpretation:** When this[19] (offset 0x4C) > 0, iterates over all entries to release old handles. When input parameter a2 > 0, allocates new array. If driver handle (this[36], offset 0x90) is non-zero, allocates AIL sample handles for each entry; otherwise leaves entry sample handle at 0.
