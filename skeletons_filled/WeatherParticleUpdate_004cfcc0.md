## WeatherParticleUpdate_004cfcc0 — WeatherParticleUpdate

**Summary:** Main weather particle system update — sorts drivers by distance, spawns weather particles with wind noise, updates all particle subsystems via type dispatch, and updates emitter children with rotation/scaling based on camera direction and visibility distance.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | emitter child count (a1[0]) |
| this | 0x4 | R | — | particle subsystem array count (a1[4]) |
| this | 0x10 | R | — | particle subsystem array count (a1[4]) |
| this | 0x14 | R | — | base pointer for strided particle subsystem array (a1[5]) |
| this | 0x1C | R | — | particle spawner pointer (a1[7]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 005aced4 | flt_5ACED4 | R | VisibilityHorizonConstant [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afee4 | flt_8AFEE4 | R | RainFadeCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | resolve session manager for wind/camera direction data |
| 004b9a00 | PackedFlagRead_9a00 | read packed flag from scoring data |
| 004b9cf0 | FloatDifference | compute float difference from scoring data |
| 004b9e30 | VehicleDataAccessor | access vehicle data from scoring pointer |
| 004c9c00 | SortDriversByDistance | sort driver array by distance from camera |
| 004ca2d0 | ParticleEmitterChildUpdateWithRotationAndScaling | update particle emitter child with rotation and scaling |
| 004cc970 | sub_4CC970 | spawn weather particles with wind noise |
| 004cdb20 | sub_4CDB20 | dispatch to type-specific particle subsystem update |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | emitter child count |
| this | 0x10 | > | 0 | particle subsystem array count |

**Guard interpretation:** Outer gate: byte_7C56AC == 0 OR PackedFlagRead returns true. PASSES: spawn wind-affected particles, update ALL particle subsystems via dispatch. BLOCKED (enabled flag on, packed flag off): only update subsystems with type <= 5. Inner guards: this[4] > 0 → iterate subsystems; *this (this[0]) > 0 → iterate emitter children.
