## BoundingBoxComputation_004dd550 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioPhysicsMixWithLerp (0040e2b0), LightFrustumClosestPoint (0040e480), sub_40EA30 (0040ea30), sub_40ED10 (0040ed10), CameraViewSetupFromVehiclePosition (0045af50), Camera (004a3b50), SceneExtentComputation (004bdc10), ParticleCollisionSpawn (004c9fb0), sub_4D0110 (004d0110), BoundingBoxUpdate (004dd6a0), VehicleGraphicsSceneLoader (004dfce0), PhysicsAudioVectorUpdate (004e2ad0), sub_4FBA10 (004fba10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd4e0 | sub_4DD4E0 | [LLM] |
| 0054c210 | SceneGraphChildCount | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
