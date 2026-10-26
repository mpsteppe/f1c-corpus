## ParticleSpawnFunction_004cce90 — ParticleGroupSpawner

**Summary:** Spawn multiple particles in a burst. Reads particle count from parameter (shifted by emitter detail level), allocates slots, applies random noise to position and velocity from weather noise table, computes collision normal, sets up billboard quad for each particle.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectWorldTransform (004e16f0), sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | emitter detail level (right-shift divisor for particle count) |
| this | 0x58 | R | — | buffer capacity / max slot count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] (also: ` — position scale factor) |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | virtual dispatch on session manager |
| 0044c550 | CollisionNormalFromFeature | compute collision normal from feature data |
| 004b9ce0 | Delegation | delegate scoring query |
| 004b9cf0 | FloatDifference | compute float difference for scoring |
| 004b9e30 | VehicleDataAccessor | access vehicle data for scoring |
| 004cb540 | CircularBufferSlotAlloc | allocate particle slot from circular buffer |
| 004cc500 | ParticleEffectBillboardQuadSetup | set up billboard quad for each spawned particle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x58 | > | 0 | slot capacity (must have available slots) |

**Guard interpretation:** Passes (spawns particles) when slot capacity > 0. Blocked when no slots available.
