## ParticleSystemUpdateWithWindAndDamping_004cd220 — ParticleSystemFullUpdate

**Summary:** Full particle system update — removes expired particles, integrates velocity with damping and gravity, clamps position to ground with normal reflection/damping, detects AABB collisions with sliding response against player or nearby vehicles, and renders billboard quads for each active particle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | particle count (this[25]) |
| this | 0x68 | R | — | particle array pointer (this[26]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 005aceb8 | flt_5ACEB8 | R | SuspensionOffsetConstant [DERIVED] (also: ` — constant offset in brush model) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cfa4c | dword_7CFA4C | R | PitchVolumeLFE [DERIVED] (also: ` — render debug flags (bit 0: player proximity, bit 1: all vehicle proximity) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | resolve rotation/wind data from session manager |
| 004b9ce0 | Delegation | delegate to scoring system method |
| 004b9cf0 | FloatDifference | compute float difference from scoring data |
| 004b9e30 | VehicleDataAccessor | access vehicle data from scoring pointer |
| 004c9c70 | FindDriversInRange | find nearby driver vehicles within collision range |
| 004cb5a0 | ArrayElementRemoval | remove expired particle from array |
| 004cbf50 | F_3DAABBOverlapTestWithSlidingResponse | AABB collision detection with sliding response |
| 004cc500 | ParticleEffectBillboardQuadSetup | render particle as billboard quad |

**Guard conditions:** None at function entry. Inner loop checks particle lifetime (v9[2] birth, v9[3] death) against current time; if outside window → particle removed via ArrayElementRemoval. If inside → physics integration, collision check, and rendering proceed.
