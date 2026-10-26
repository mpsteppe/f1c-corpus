## AABBCollisionBodyInitializer_00448e90 — AABB collision body structure initializer

**Summary:** Initializes a collision body structure: zeroes the header (first 24 bytes), then sets individual fields to default values (active flag=1, type=0, handle=INVALID, next pointer=null). Used to reset AABB proxy entries in the collision broad-phase.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactBufferAllocator (004492d0), TriangleMeshAdjacencyBuilder (004493a0), IndexedVertexLookupFromStream (00449f60), CollisionCapsuleShapeCopyToPipeline (0044b040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | 1 | Active/in-use flag (1 = enabled) |
| this | 0x19 | RW | 0 | Body type or subtype (0 = default) |
| this | 0x1A | RW | 18446744073709551615 | Handle/index set to -1 (invalid sentinel) |
| this | 0x1C | RW | 0 | Next pointer in free list or linked chain (null) |

**Written-by note (persistence):**
- this 0x18: Written once (set to 1), survives until explicitly cleared
- this 0x19: Written once (set to 0), survives
- this 0x1A: Written once (set to -1/INVALID), survives
- this 0x1C: Written once (set to 0/null), survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — unconditional initialization.
