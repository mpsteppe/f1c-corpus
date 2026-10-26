## BufferLockAllocate_00540f00 — Buffer allocation with lock flags

**Summary:** Allocates a buffer through an allocator vtable, storing result pointer in `*this`. Returns 0 on success, or buffer ID on failure (incrementing failure counter).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_53EB70 (0053eb70), ConditionalFieldSetter_0d40 (00540d40), AudioBufferClear (00541470), VertexBufferSurfaceInit (005527c0), sub_553070 (00553070), sub_553370 (00553370), sub_553700 (00553700), TextureAllocationWithFormatSizeFlags (00558d10), sub_55C070 (0055c070), sub_55C860 (0055c860), sub_55D720 (0055d720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Buffer result pointer (written with allocation return value) |
| this | 0x13E0 | R | — | Allocation type hint (0, 1, or 2) controlling flag OR-ing |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `a2` (request struct) is NULL → return 0. If `a2[8]` (allocator object pointer) is 0 → return 0. Both block allocation early. Passing through: valid a2, non-null allocator vtable, flags decoded from a2[0] and this[0x13E0].
