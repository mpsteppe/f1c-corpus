## CameraModeViewportUpdate_00409a00 — CameraModeViewportUpdate

**Summary:** Switches between camera modes (0-8: chase, cockpit, replay, etc.), applies 3D coordinate transforms, Euler rotation adjustments, mirror/flip logic, and renders the viewport per frame. Central camera/viewport system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x18 | R | — | vtable method at slot 6 (offset 24) — called to process camera transform |
| *(*(this+0x1C)+0x0) | 0x1C | R | — | vtable method at slot 7 (offset 28) — called to update/commit sub-object after clamp |
| *(this+0x1C) | 0x0 | R | — | sub-object vtable pointer (case 3 camera object) |
| *(this+0x1C) | 0xC | R | — | post-transform position X (read from camera object) |
| *(this+0x1C) | 0x10 | R | — | post-transform position Y |
| *(this+0x1C) | 0x14 | R | — | post-transform position Z |
| *(this+0x1C) | 0x18 | R | — | post-transform view direction X / orientation X |
| *(this+0x1C) | 0x1C | R | — | post-transform view direction Y / orientation Y |
| *(this+0x1C) | 0x20 | R | — | post-transform view direction Z / orientation Z |
| *(this+0x1C) | 0x48 | R | — | return value field — passed to ConditionalFloatSetter |
| *(this+0x1C) | 0xA0 | RW | — | clamped camera angle/offset (clamped between -2.95 and -0.05 in case 3) |
| *(this+0x1C) | 0xA4 | RW | — | copied component 2 (from intermediate register after clamp) |
| *(this+0x1C) | 0xA8 | RW | — | copied component 3 (from intermediate register after clamp) |
| *(this+0x2C) | 0xBC | R | — | camera offset field at v3+188 — read in case 7 state machine |
| *(this+0x2C) | 0xC0 | R | — | camera offset field at v3+192 — Y component modified by ±flt_5BE8FC |
| *(this+0x30) | 0xBC | RW | — | camera offset field at v3+188 — written in case 8 state machine |
| *(this+0x30) | 0xC0 | RW | — | camera offset field at v3+192 — Y component modified by ±flt_5BE8FC |
| *(this+0x30) | 0xC4 | RW | — | camera offset field at v3+196 — copied alongside BC/C0 |
| *(this+0x4) | 0x1B0 | R | — | chassis world transform flag (432 decimal) — if set, applies negated chassis transform |
| obj | 0x14 | R | — | unknown — accessed via indirection in DualFieldGetter/ShortComputation_6080 path |
| this | 0x0 | R | — | vtable pointer — used for virtual method dispatch at vtable+20 |
| this | 0x4 | R | — | primary context/object pointer — early null guard (aborts if zero) |
| this | 0x10 | R | — | camera sub-object for mode 0 (chase/normal) |
| this | 0x14 | R | — | camera sub-object for mode 1 (cockpit/recon) |
| this | 0x18 | R | — | camera sub-object for mode 2 |
| this | 0x1C | R | — | camera sub-object for mode 3 (clamped angle) |
| this | 0x20 | R | — | camera sub-object for mode 4 (offset by 200*selector) |
| this | 0x24 | R | — | camera sub-object for mode 5 |
| this | 0x28 | R | — | camera sub-object for mode 6 |
| this | 0x2C | R | — | camera sub-object for mode 7 (state-machine driven, +flt_5BE8FC) |
| this | 0x30 | R | — | camera sub-object for mode 8 (state-machine driven, -flt_5BE8FC) |
| this | 0x34 | R | — | camera mode selector (switch index 0-8, default zeroes all) |
| this | 0x3C | R | — | multiplier offset for mode 4 (200 * this value added to sub-object ptr) |
| this | 0x40 | R | — | mirror/negate flag — if set, negates view X, adds π to Y rotation, negates Z |
| this | 0x44 | R | — | Euler rotation angle X — applied to camera matrix if non-zero |
| this | 0x48 | R | — | Euler rotation angle Y — applied to camera matrix via RotationMatrixY |
| this | 0x4C | R | — | Euler rotation angle Z — applied to camera matrix via RotateMatrixAndExtractAngles |

**Written-by note (persistence):**
- *(this+0x1C) 0xA0: written conditionally in case 3 (clamped between -2.95 and -0.05) — external poke does NOT persist if case 3 runs
- *(this+0x1C) 0xA4: written unconditionally in case 3 — external poke does NOT persist
- *(this+0x1C) 0xA8: written unconditionally in case 3 — external poke does NOT persist
- *(this+0x30) 0xBC: written conditionally in case 8 state machine — external poke may persist if state != 1
- *(this+0x30) 0xC0: written conditionally in case 8 state machine — external poke may persist if state != 1
- *(this+0x30) 0xC4: written conditionally in case 8 state machine — external poke may persist if state != 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00409f1c | jpt_409A3C | R | switch jump table for camera mode dispatch (9 cases + default) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e664 | flt_59E664 | R | RenderTransformScale [DERIVED] |
| 0059e668 | flt_59E668 | R | FloatRead_59E668 [DERIVED] |
| 005be8fc | flt_5BE8FC | R | Unknown_Float_5BE8FC [DERIVED] — camera Y-offset adjustment value for modes 7/8 |
| 005be900 | dword_5BE900 | RW | Int_GameStateSubmode [DERIVED] — state machine counter (0→1→2) for camera offset sequencing |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) — source of 3D position data for viewport |
| 007cfe70 | byte_7CFE70 | R | ReconScreenFlag [DERIVED] — triggers ConditionalBranchByFlag in mode 1 if non-zero |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004084a0 | ShortComputation_84a0 | computes a float scaling value used as camera parameter |
| 0040c780 | ScoringGateConditionCheck | checks scoring/gate condition — returns float used as camera parameter |
| 00456060 | DualFieldGetter | retrieves two field values (likely camera shake/offset parameters) |
| 00456080 | ShortComputation_6080 | computes two additional values for camera adjustment |
| 004d8860 | ConditionalBranchByFlag | conditionally executes branch based on flag (called with flag=1) |
| 004e1fd0 | F_3DTransformPointByMatrixAndTranslation | transforms a 3D point by matrix with translation — extracts viewport position/orientation |
| 004e2070 | LocalToWorldCoordinateTransform | converts local to world coordinates (mode 1 cockpit view) |
| 004e2130 | ChassisWorldTransform | retrieves vehicle chassis world transform matrix — used for mirror/negation path |
| 00541cd0 | UtilityFunction_1cd0 | 6-parameter utility — processes camera position and orientation data |
| 00542050 | sub_542050 | applies rotation/angle processing with two computed values |
| 005423c0 | TwoFieldSetterCall | sets two field values from computed camera parameters |
| 00542680 | ConditionalFloatSetter | conditionally sets a float value as camera return parameter |
| 0054a160 | FlagBitSetter_a160 | sets flag bit 4096 (likely camera update dirty flag) |
| 00566e40 | EulerToRotationMatrix | converts Euler angles to rotation matrix for camera orientation |
| 00567340 | RotationMatrixYAxisRotationEulerExtraction | extracts Y-axis rotation from Euler angle and applies to camera matrix |
| 00567400 | RotationMatrixY | applies Y-axis rotation to camera orientation matrix |
| 005674c0 | RotateMatrixAndExtractAngles | rotates camera matrix and extracts resulting angles |

**Guard conditions:** 
1. this+0x4 (primary context) == 0: BLOCKED — immediate return, no camera update.
2. this+0x34 (camera mode) switch: 0-8 PASSES with mode-specific sub-object and transform; default zeroes all outputs.
3. byte_7CFE70 (recon screen flag): if set in mode 1, calls ConditionalBranchByFlag(1) — enables recon-specific branch.
4. this+0x40 (mirror flag): if non-zero, negates X, adds π to Y, negates Z — mirror/spectator mode.
5. this+0x44/0x48/0x4C (Euler angles): any non-zero triggers rotation matrix chain on camera.
6. dword_5BE900 (state machine): cases 7/8 use 0→1→2 sequencing for camera offset positioning.
