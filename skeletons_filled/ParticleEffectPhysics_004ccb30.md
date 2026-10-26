## ParticleEffectPhysics_004ccb30 — ParticleEffectPhysicsUpdate

**Summary:** Updates particle physics each frame — removes particles outside lifetime window, applies acceleration to velocity, runs AABB collision detection with sliding response against player vehicle or nearby drivers, and renders bounding boxes for remaining particles.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParticlePositionAdd (004ccdc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | particle count / array size |
| this | 0x68 | R | — | particle array pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cfa04 | dword_7CFA04 | R | ParticleFlags [DERIVED] |
| 007cfa4c | dword_7CFA4C | R | PitchVolumeLFE [DERIVED] (also: ` — render debug flags (bit 0: player proximity, bit 1: all vehicle proximity) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegate to scoring system method |
| 004b9cf0 | FloatDifference | compute float difference from scoring data |
| 004b9e30 | VehicleDataAccessor | access vehicle data from scoring pointer |
| 004c9c70 | FindDriversInRange | find nearby driver vehicles within collision range |
| 004cb5a0 | ArrayElementRemoval | remove expired particle from array |
| 004cbf50 | F_3DAABBOverlapTestWithSlidingResponse | AABB collision detection with sliding response |
| 004cc700 | F_3DBoundingBoxRender | render bounding box for debug visualization |
| 004cc840 | sub_4CC840 | update particle rotation matrices |

**Guard conditions:** None at function entry. Inner loop checks particle lifetime against v18/v34 (session time or delegated value). If outside [birth, death] window → particle removed via ArrayElementRemoval. If inside → velocity updated and collision checked.
