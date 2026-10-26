## CollisionContactBufferAllocator_004492d0 — Collision contact buffer allocator and AABB body array initializer

**Summary:** Allocates a heap buffer for `a2` AABB collision bodies (each 32 bytes). Stores count at offset 0x4, allocates memory via wrapper, initializes each body with AABBCollisionBodyInitializer, and stores the buffer pointer at offset 0x8. Precedes allocation with PhysicsBufferFree.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BezierPatchTessellation (0044b370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Count of AABB bodies requested |
| this | 0x8 | RW | 0 | Pointer to allocated AABB body array (null on alloc failure) |

**Written-by note (persistence):**
- this 0x4: Set to requested count when a2 > 0
- this 0x8: Set to allocated buffer pointer (or null if alloc fails)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448e90 | AABBCollisionBodyInitializer | Initializes each 32-byte AABB body slot to default values |
| 00449340 | PhysicsBufferFree | Frees/resets existing physics buffer before allocation |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation for 32*count+4 bytes (header + bodies) |

**Guard conditions:** a2 <= 0 → skip allocation (no bodies requested). OperatorNewNhMallocWrapper returns null → set buffer pointer to null, return.
