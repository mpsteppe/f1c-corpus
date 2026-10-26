## CollisionShapeInit_004492b0 — Collision shape structure initializer

**Summary:** Zeroes three collision shape fields (offsets 0x8, 0xC, 0x10) and calls PhysicsBufferFree to initialize or reset the internal physics buffer. Prepares a collision shape for use.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BezierPatchTessellation (0044b370), CollisionGeometryOperationSelector (0044bb60), SceneTrackFileLoader (0044c0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | Shape buffer pointer or handle (nulled) |
| this | 0xC | RW | 0 | Shape bounds or size (zeroed) |
| this | 0x10 | RW | 0 | Shape type or flags (zeroed) |

**Written-by note (persistence):**
- this 0x8: Set to 0 each call
- this 0xC: Set to 0 each call
- this 0x10: Set to 0 each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00449340 | PhysicsBufferFree | Deallocates or resets the physics buffer associated with this shape |

**Guard conditions:** No conditional branches — unconditional init.
