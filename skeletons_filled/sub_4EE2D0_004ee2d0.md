## sub_4EE2D0_004ee2d0 — Vehicle Physics Collision & Tire Contact Update

**Summary:** Per-frame vehicle physics update handling tire-ground contact, collision detection via spatial grid, and particle/spark effects. Dispatches to tire slip force solver, throttle/brake overrides, and collision effect systems based on physics mode (0-3).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690), sub_4B9B80 (004b9b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | vehicle object ID or physics context pointer |
| this | 0x4C | R | — | normal vector component for collision response (at this+76) |
| this | 0x50 | R | — | normal vector component for collision response (at this+80) |
| this | 0x54 | R | — | normal vector component for collision response (at this+84) |
| this | 0x738 | R | — | vehicle speed (float, read for position change tracking) |
| this | 0x73C | R | — | vehicle speed component (float, read for position change tracking) |
| this | 0x740 | R | — | vehicle speed component (float, read for position change tracking) |
| this | 0x77C | RW | — | tire contact depth / suspension travel (per-wheel, case 1) |
| this | 0x790 | RW | — | tire contact slip ratio (per-wheel) |
| this | 0x7A4 | RW | — | tire contact lateral force (per-wheel) |
| this | 0x7D4 | RW | — | tire contact longitudinal force (per-wheel) |
| this | 0x7D8 | RW | — | tire contact load (per-wheel) |
| this | 0x7DC | RW | 0 | tire contact friction coefficient (per-wheel, zeroed when inactive) |
| this | 0x7E0 | RW | 0 | tire contact temperature (per-wheel, zeroed) |
| this | 0x7E4 | RW | 0 | tire contact wear rate (per-wheel, zeroed) |
| this | 0x7E8 | RW | 0 | tire contact surface type (per-wheel, zeroed) |
| this | 0x7EC | RW | 20 | tire contact lifespan counter (per-wheel, init to 20) |
| this | 0x8CC | RW | — | tire contact point X world coordinate (per-contact) |
| this | 0x9F4 | RW | — | tire contact point Y world coordinate (per-contact) |
| this | 0xB1C | RW | — | tire contact point Z world coordinate (per-contact) |
| this | 0xC44 | RW | — | collision response force magnitude |
| this | 0xC74 | RW | 0 | collision effect timer (zeroed) |
| this | 0xC78 | RW | 0 | collision effect counter (zeroed) |
| this | 0xC7C | RW | 0 | collision effect accumulator X (zeroed) |
| this | 0xC80 | RW | 0 | collision effect accumulator Y (zeroed) |
| this | 0xC84 | RW | 0 | collision effect accumulator Z (zeroed) |
| this | 0xC88 | RW | — | collision response normal vector X |
| this | 0x101C | R | — | contact point array entry (per-contact struct, index by v8) |
| this | 0x1020 | R | — | contact point array entry +4 |
| this | 0x1024 | R | — | contact point array entry +8 |
| this | 0x1028 | R | — | contact point array entry +12 |
| this | 0x102C | R | — | contact point array entry +16 |
| this | 0x1070 | R | — | per-wheel suspension force / damping data (struct at this+4208 flag check) |
| this | 0x1078 | R | — | per-wheel suspension force +8 |
| this | 0x107C | R | — | per-wheel suspension force +12 |
| this | 0x1080 | R | — | per-wheel suspension force +16 |
| this | 0x32BC | R | — | physics update mode selector (0=slip, 1=suspension, 2/3=collision) |
| this | 0x34AC | R | — | orientation matrix: row 0, col 0 (read for transform) |
| this | 0x34B0 | R | — | orientation matrix: row 0, col 0 (vehicle world transform) |
| this | 0x34B4 | R | — | orientation matrix: row 0, col 1 (vehicle world transform) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | orientation matrix: row 1, col 1 |
| this | 0x34C0 | R | — | orientation matrix: row 1, col 2 |
| this | 0x34C4 | R | — | orientation matrix: row 2, col 0 |
| this | 0x34C8 | R | — | orientation matrix: row 2, col 1 |
| this | 0x34CC | R | — | orientation matrix: row 2, col 2 |
| this | 0x34D0 | R | — | vehicle world position X |
| this | 0x34D4 | R | — | vehicle world position Y |
| this | 0x34D8 | R | — | vehicle world position Z |
| this | 0x34DC | R | — | vehicle speed (float, duplicate of 0x738) |
| this | 0x34EC | R | — | vehicle angular velocity X |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x34FC | R | — | vehicle angular velocity Y |
| this | 0x3500 | R | — | vehicle angular velocity Z |
| this | 0x3590 | R | — | vehicle body force accumulator X |
| this | 0x3594 | R | — | vehicle body force accumulator Y |
| this | 0x35CC | R | — | vehicle wheel rotation speed (per-wheel) |
| this | 0x35D0 | R | — | vehicle wheel rotation speed (per-wheel) |
| this | 0x3610 | R | — | wheel contact normal (per-wheel, for cross product calc) |
| this | 0x3668 | R | — | per-wheel suspension attach point offset |
| this | 0x36C4 | R | — | wheel radius / travel limit (per-wheel) |
| this | 0x3760 | R | — | per-wheel damper/spring force parameter |
| this | 0x3BE8 | R | — | vehicle velocity X (world space) |
| this | 0x3BEC | R | — | vehicle velocity Y (world space) |
| this | 0x3BF0 | R | — | vehicle velocity Z (world space) |
| this | 0x3D54 | R | — | vehicle velocity component for collision (acceleration X) |
| this | 0x3D58 | R | — | vehicle velocity component for collision (acceleration Y) |
| this | 0x3D5C | R | — | vehicle velocity component for collision (acceleration Z) |

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
| 004ef168 | jpt_4EE3A8 | R | switch jump table for case dispatch on physics mode |
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
| 004472b0 | TireSlipForceCalculation | computes tire slip forces from lateral/longitudinal slip ratios |
| 0044c4c0 | SpatialGridQuery | queries the spatial grid for nearby objects (collision candidates) |
| 004b9ce0 | Delegation | delegates to scoring/grid system for race position data |
| 004cce90 | ParticleSpawnFunction | spawns particle effects at given world position |
| 004ce380 | FloatComparisonWithConstantsTable | compares float against a lookup table of constants |
| 004ce3e0 | CollisionEffectDispatch | dispatches collision response to visual/audio effect systems |
| 004ce8f0 | sub_4CE8F0 | checks if contact point is valid for particle effect spawning |
| 004ce930 | ParticleCollisionEffect | spawns collision particle effects at contact points |
| 004e16f0 | ParticleEffectWorldTransform | transforms particle effect coordinates to world space |
| 004e9630 | PositionChangeMonitor | monitors vehicle position change for track surface lookup |
| 004ed750 | F_3DCrossProduct | computes 3D vector cross product |
| 004ee230 | ThrottleBrakeOverride | applies AI/driver throttle and brake override values |
| 004fd7e0 | F_1DTableLookupWithLerp | 1D table lookup with linear interpolation |

**Guard conditions:** 
- `flt_8AFEEC == flt_8AFEE8`: Track grip values equal → use direct grip value. Otherwise compute position-change-based traction factor via PositionChangeMonitor and table lookup.
- Switch on `this[12988]` (offset 0x32BC): Case 0 = tire slip force mode, Case 1 = suspension/damper force mode, Case 2/3 = spatial-grid collision detection mode. Each branch computes different physics contributions.
- `v109 > 0.0 && v88` at LABEL_64: If a valid traction/depth value was computed and any wheel had active contact, run final SpatialGridQuery and CollisionEffectDispatch for the aggregate contact point.
- `*(_BYTE *)(this + 4208)` (offset 0x1070): If non-zero, apply ParticleEffectWorldTransform to convert contact points to world space.
- Case 1 wheel loop: `v90 <= 7500.0` / `v90 <= 15000.0`: Suspension travel limits gate damper force application.
- Case 2/3 bit extraction: Color-encoded tire contact data unpacked from byte fields into float ratios.
