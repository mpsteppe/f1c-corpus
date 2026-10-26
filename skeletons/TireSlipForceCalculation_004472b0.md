## TireSlipForceCalculation_004472b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x16E0)+0x54) | 0x28 | R | — | [LLM] |
| *(this+0x15F0) | 0x4 | R | — | [LLM] |
| *(this+0x15F0) | 0xC | R | — | [LLM] |
| *(this+0x15F0) | 0x14 | R | — | [LLM] |
| *(this+0x15F0) | 0x64 | R | — | [LLM] |
| *(this+0x15F0) | 0x6C | R | — | [LLM] |
| *(this+0x15F0) | 0x74 | R | — | [LLM] |
| *(this+0x15F0) | 0x7C | R | — | [LLM] |
| *(this+0x15F0) | 0x84 | R | — | [LLM] |
| *(this+0x15F0) | 0x8C | R | — | [LLM] |
| *(this+0x16E0) | 0x54 | R | — | [LLM] |
| *(this+0x1F00) | 0x4894 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x690 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x16E0 | R | — | [LLM] |
| this | 0x16F0 | R | — | [LLM] |
| this | 0x1C5C | R | — | [LLM] |
| this | 0x1CDC | R | — | [LLM] |
| this | 0x1DE4 | R | — | [LLM] |
| this | 0x1DEC | R | — | [LLM] |
| this | 0x1DF4 | R | — | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e974 | flt_59E974 | R | AI_TrackPosThreshold [DERIVED] |
| 0059eca8 | dbl_59ECA8 | R | PhysicsTireDamping [DERIVED] |
| 0059eec0 | dbl_59EEC0 | R | NormalizationScale [DERIVED] |
| 0059eec8 | dbl_59EEC8 | R | NormalizationBias [DERIVED] |
| 0059eed0 | flt_59EED0 | R | BrightnessMultiplierRB [DERIVED] (also: ` — brightness multiplier for R/B channels) |
| 0059eed8 | dbl_59EED8 | R | SlipForceGainFactor [DERIVED] |
| 0059eee0 | flt_59EEE0 | R | SteeringDeadzoneThreshold [DERIVED] |
| 0059eee8 | dbl_59EEE8 | R | Unknown_Double_Tire_Tread [DERIVED] |
| 007c7810 | unk_7C7810 | R | ContactSurfaceArray [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043aee0 | TransformApply3D | [LLM] |
| 004ce3e0 | CollisionEffectDispatch | [LLM] |
| 004ce930 | ParticleCollisionEffect | [LLM] |
| 004ef560 | SetWheelContactFlags | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
