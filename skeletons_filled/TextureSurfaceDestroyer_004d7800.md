## TextureSurfaceDestroyer_004d7800 — TextureSurfaceDestroyer

**Summary:** Destroys a texture surface container: iterates active entries calling ArrayBlockCleanup per entry, then walks the full allocated block freeing sub-pointers at offsets 0 and 0x18 via FreeWrapper_7bcf, frees the block header, zeros both fields. Called by SessionReset and TireBrandLoader during teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionReset (0042d350), TireBrandLoader (004d7660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | entry count (iterated and then cleared to 0) |
| this | 0x4 | RW | 0 | pointer to allocated entry block (freed and zeroed) |

**Written-by note (persistence):**
- this 0x0: cleared to 0 unconditionally after processing
- this 0x4: conditionally freed and zeroed (only if non-null pointer)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7050 | ArrayBlockCleanup | cleans up individual entry (36-byte struct within block) |
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation for block header and sub-pointers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | entry count |

**Guard interpretation:** PASSES (first loop runs) when this+0x0 > 0 — iterates ArrayBlockCleanup on active entries. Always continues to full block cleanup and free regardless. BLOCKED: nothing — the >0 guard only controls the active-entries loop; second block always runs.
