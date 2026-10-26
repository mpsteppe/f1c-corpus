## CameraProjectionMatrixInitWithFloatConstants_0040eb30 — PhysicsShapeInitType3

**Summary:** Initializes a physics collision shape structure with subtype=3, stores precomputed float constants via CollisionInvMassStore and F_6FieldBulkSetter. Physics collision system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | type/index discriminator word |
| this | 0x1C | RW | 3 | subtype/kind constant (physics shape type 3) |
| this | 0x20 | RW | — | pointer to external data passed through to sub-calls |

**Written-by note (persistence):**
- this 0x8: written once unconditionally, external poke survives
- this 0x1C: written once unconditionally, external poke survives
- this 0x20: written once unconditionally, external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|


**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | conditional continuation computation on this if a4 != 0 |
| 00459950 | CollisionInvMassStore | store inverse mass scalar (15.0f) and local float array into collision data |
| 00459990 | F_6FieldBulkSetter | bulk-set 6 float fields in collision data structure |

**Guard conditions:** if a4 != 0, calls ShortComputation_e770; else returns 0 — guards continuation path
