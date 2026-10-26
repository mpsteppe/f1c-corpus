## TripleFieldQuery_0054b420 — Triple field query

**Summary:** Reads three adjacent fields (offsets 0x20, 0x24, 0x28) and writes them to caller-provided output pointers if non-null. Returns `a4`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioPhysicsMixWithLerp (0040e2b0), sub_40ED10 (0040ed10), VehicleSceneLoadAndPositionTires (004681b0), ParticleCollisionSpawn (004c9fb0), F_3DDistanceCheckAccumulate (004d0b20), BoundingBoxUpdate (004dd6a0), VehicleGraphicsSceneLoader (004dfce0), UITimerTweenUpdate (004e0c90), PhysicsAudioVectorUpdate (004e2ad0), SuspensionAndWheelPhysics (004e5f60), sub_4FBA10 (004fba10), DualMatrixTransformMultiply (0054b530), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | First value (written to `*a2` if a2 non-null) |
| this | 0x24 | R | — | Second value (written to `*a3` if a3 non-null) |
| this | 0x28 | R | — | Third value (written to `*a4` if a4 non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) is null-checked independently — if null, that field write is skipped. No early return.
