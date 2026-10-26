## TireSlipForceCalculation_004472b0 — Per-wheel tire slip force computation and collision effect dispatch

**Summary:** Computes per-wheel tire slip ratios, contact patch forces, and dispatches collision/particle effects for a 4-wheel vehicle each frame. Part of the vehicle physics simulation tick.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x16E0)+0x54) | 0x28 | R | — | wheel contact surface material/type flag (deep pointer chain: wheel-contact-ptr → surface-data-ptr+0x54 → flag at +0x28) |
| *(this+0x15F0) | 0x4 | R | — | vehicle transform position X (double) |
| *(this+0x15F0) | 0xC | R | — | vehicle transform position Y (double) |
| *(this+0x15F0) | 0x14 | R | — | vehicle transform position Z (double) |
| *(this+0x15F0) | 0x64 | R | — | vehicle transform orientation matrix element (column vector X component, double) |
| *(this+0x15F0) | 0x6C | R | — | vehicle transform orientation matrix element (column vector Y component, double) |
| *(this+0x15F0) | 0x74 | R | — | vehicle transform orientation matrix element (column vector Z component, double) |
| *(this+0x15F0) | 0x7C | R | — | vehicle transform cross-axis orientation element (rotation row1 col3, double) |
| *(this+0x15F0) | 0x84 | R | — | vehicle transform cross-axis orientation element (rotation row2 col3, double) |
| *(this+0x15F0) | 0x8C | R | — | vehicle transform cross-axis orientation element (rotation row3 col2, double) |
| *(this+0x16E0) | 0x54 | R | — | wheel contact surface data pointer (dereferenced to get material flag) |
| *(this+0x1F00) | 0x4894 | R | — | scoring/grid track position index (passed as collision effect parameter) |
| this | 0x8 | R | — | vehicle longitudinal scale factor (used to compute force ratio) |
| this | 0x60 | R | — | vehicle reference dimension (passed as float to collision/particle dispatch) |
| this | 0x690 | R | — | wheel temperature base reference value (1023.16, used for normalization) |
| this | 0x15F0 | R | — | pointer to vehicle transform matrix structure (3x3 rotation + position) |
| this | 0x16E0 | R | — | pointer to wheel contact state array (4 entries, indexed per wheel) |
| this | 0x16F0 | R | — | per-wheel vertical offset array (4 doubles, tested for negative=contact) |
| this | 0x1C5C | R | — | force scaling factor (numerator for slip force ratio) |
| this | 0x1CDC | R | — | force scaling factor (denominator for slip force ratio, 1/x) |
| this | 0x1DE4 | R | — | longitudinal slip force component (X-axis, double) |
| this | 0x1DEC | R | — | lateral slip force component (Y-axis, double) |
| this | 0x1DF4 | R | — | vertical slip force component (Z-axis, double) |
| this | 0x1F00 | R | — | pointer to vehicle scoring/grid state structure |

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
| 0043aee0 | TransformApply3D | applies 3D homogeneous transform (matrix × vector) to convert local wheel position to world space |
| 004ce3e0 | CollisionEffectDispatch | dispatches collision spark/debris effects at wheel contact point |
| 004ce930 | ParticleCollisionEffect | spawns particle effects (smoke/sparks) when wheel contact flags indicate collision |
| 004ef560 | SetWheelContactFlags | sets per-wheel terrain contact type and severity flags for physics response |
| 00587bdc | CRTFtol | converts float to truncated long integer (used for discretizing normalized slip ratio to N steps) |

**Guard conditions:** Three nested guards in the wheel-contact loop (lines 176-181):
1. `*(this+0x16F0)[wheel] < 0.0` — wheel vertical offset negative → wheel has ground contact. If >= 0.0, skip wheel (no contact).
2. `*(this+0x16E0)[wheel] != NULL` — wheel contact state pointer valid. If NULL, skip.
3. `*(*(*(this+0x16E0)[wheel] + 84) + 40) != 0` — deep flag: surface contact material data present. If zero, skip (no surface interaction to process).

Additional guard: per-wheel contact surface area `<= 0.0` (line 65/89) → zero slip; if > 0.0, compute slip from contact properties.

Force clamp guard: slip acceleration ratio clamped to [-1.0, 0.0] range (lines 143-151), then per-axis force components are conditionally scaled (lines 152-166): if force component <= 0.0, multiply by clamped ratio; if > 0.0, use as-is.
