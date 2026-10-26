## ParticleSystemUpdateWithWindAndDamping_004cd220 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

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
| 0040c870 | VirtualDispatchHelper | [LLM] |
| 004b9ce0 | Delegation | [LLM] |
| 004b9cf0 | FloatDifference | [LLM] |
| 004b9e30 | VehicleDataAccessor | [LLM] |
| 004c9c70 | FindDriversInRange | [LLM] |
| 004cb5a0 | ArrayElementRemoval | [LLM] |
| 004cbf50 | F_3DAABBOverlapTestWithSlidingResponse | [LLM] |
| 004cc500 | ParticleEffectBillboardQuadSetup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
