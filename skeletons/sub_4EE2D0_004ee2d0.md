## sub_4EE2D0_004ee2d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690), sub_4B9B80 (004b9b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x738 | R | — | [LLM] |
| this | 0x73C | R | — | [LLM] |
| this | 0x740 | R | — | [LLM] |
| this | 0x77C | RW | — | [LLM] |
| this | 0x790 | RW | — | [LLM] |
| this | 0x7A4 | RW | — | [LLM] |
| this | 0x7D4 | RW | — | [LLM] |
| this | 0x7D8 | RW | — | [LLM] |
| this | 0x7DC | RW | 0 | [LLM] |
| this | 0x7E0 | RW | 0 | [LLM] |
| this | 0x7E4 | RW | 0 | [LLM] |
| this | 0x7E8 | RW | 0 | [LLM] |
| this | 0x7EC | RW | 20 | [LLM] |
| this | 0x8CC | RW | — | [LLM] |
| this | 0x9F4 | RW | — | [LLM] |
| this | 0xB1C | RW | — | [LLM] |
| this | 0xC44 | RW | — | [LLM] |
| this | 0xC74 | RW | 0 | [LLM] |
| this | 0xC78 | RW | 0 | [LLM] |
| this | 0xC7C | RW | 0 | [LLM] |
| this | 0xC80 | RW | 0 | [LLM] |
| this | 0xC84 | RW | 0 | [LLM] |
| this | 0xC88 | RW | — | [LLM] |
| this | 0x101C | R | — | [LLM] |
| this | 0x1020 | R | — | [LLM] |
| this | 0x1024 | R | — | [LLM] |
| this | 0x1028 | R | — | [LLM] |
| this | 0x102C | R | — | [LLM] |
| this | 0x1070 | R | — | [LLM] |
| this | 0x1078 | R | — | [LLM] |
| this | 0x107C | R | — | [LLM] |
| this | 0x1080 | R | — | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34AC | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x34EC | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x34FC | R | — | [LLM] |
| this | 0x3500 | R | — | [LLM] |
| this | 0x3590 | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x35CC | R | — | [LLM] |
| this | 0x35D0 | R | — | [LLM] |
| this | 0x3610 | R | — | [LLM] |
| this | 0x3668 | R | — | [LLM] |
| this | 0x36C4 | R | — | [LLM] |
| this | 0x3760 | R | — | [LLM] |
| this | 0x3BE8 | R | — | [LLM] |
| this | 0x3BEC | R | — | [LLM] |
| this | 0x3BF0 | R | — | [LLM] |
| this | 0x3D54 | R | — | [LLM] |
| this | 0x3D58 | R | — | [LLM] |
| this | 0x3D5C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x77C: recalc every frame — external poke does NOT persist
- this 0x790: recalc every frame — external poke does NOT persist
- this 0x7A4: recalc every frame — external poke does NOT persist
- this 0x7D4: recalc every frame — external poke does NOT persist
- this 0x7D8: recalc every frame — external poke does NOT persist
- this 0x7DC: recalc every frame — external poke does NOT persist
- this 0x7E0: recalc every frame — external poke does NOT persist
- this 0x7E4: recalc every frame — external poke does NOT persist
- this 0x7E8: recalc every frame — external poke does NOT persist
- this 0x7EC: recalc every frame — external poke does NOT persist
- this 0x8CC: recalc every frame — external poke does NOT persist
- this 0x9F4: recalc every frame — external poke does NOT persist
- this 0xB1C: recalc every frame — external poke does NOT persist
- this 0xC44: recalc every frame — external poke does NOT persist
- this 0xC74: recalc every frame — external poke does NOT persist
- this 0xC78: recalc every frame — external poke does NOT persist
- this 0xC7C: recalc every frame — external poke does NOT persist
- this 0xC80: recalc every frame — external poke does NOT persist
- this 0xC84: recalc every frame — external poke does NOT persist
- this 0xC88: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ef168 | jpt_4EE3A8 | R | [LLM] |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |
| 005ac108 | flt_5AC108 | R | TexDecompress_1_15th [DERIVED] (also: ` — 4-bit color scale factor (1/15 ≈ 0.0667) |
| 005ad210 | flt_5AD210 | R | ThreeBitChannelScale [DERIVED] (also: ` — float multiplier for 3-bit channels) |
| 005ad214 | flt_5AD214 | R | BrakeForceRampThresholds [DERIVED] |
| 005ad218 | flt_5AD218 | R | BrakeForceRampThreshold2 [DERIVED] |
| 005ad21c | flt_5AD21C | R | BrakeRampThreshold1 [DERIVED] |
| 005ad220 | flt_5AD220 | R | BrakeForceThreshold [DERIVED] |
| 005ad224 | flt_5AD224 | R | BrakePressureThreshold [DERIVED] |
| 005ad228 | flt_5AD228 | R | BrakeForceThreshold1 [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008aceb8 | dword_8ACEB8 | R | PhysicsFlagCounter [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004472b0 | TireSlipForceCalculation | [LLM] |
| 0044c4c0 | SpatialGridQuery | [LLM] |
| 004b9ce0 | Delegation | [LLM] |
| 004cce90 | ParticleSpawnFunction | [LLM] |
| 004ce380 | FloatComparisonWithConstantsTable | [LLM] |
| 004ce3e0 | CollisionEffectDispatch | [LLM] |
| 004ce8f0 | sub_4CE8F0 | [LLM] |
| 004ce930 | ParticleCollisionEffect | [LLM] |
| 004e16f0 | ParticleEffectWorldTransform | [LLM] |
| 004e9630 | PositionChangeMonitor | [LLM] |
| 004ed750 | F_3DCrossProduct | [LLM] |
| 004ee230 | ThrottleBrakeOverride | [LLM] |
| 004fd7e0 | F_1DTableLookupWithLerp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
