## ParticleEffectUpdateDispatch_004eb430 — Vehicle Surface Effect & Particle Update Dispatch

**Summary:** Per-frame vehicle surface-effect dispatcher — clears/queues particle effect slots, computes slip velocity and wheel contact, runs collision detection, then iterates vehicle components dispatching surface-type-specific effects (sparks, dust, smoke) with force-dependent intensity, and accumulates telemetry positions for camera tracking.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3A9C) | 0x0 | R | — | reference position X (world-space tracking point) |
| *(this+0x3A9C) | 0x4 | R | — | reference position Y |
| *(this+0x3A9C) | 0x8 | R | — | reference position Z |
| obj | 0x48BC | R | — | byte flags on external object (bit 0 = post-process input enabled) |
| this | 0x0 | R | — | pointer to external object for postProcessInput check | postProcessInput [CONFIRMED] |
| this | 0xA4 | RW | 0 | accumulator / counter (zeroed each frame) |
| this | 0xA8 | RW | 1065353216 → 1.0f | multiplier / scale factor (reset to 1.0 each frame) |
| this | 0xAC | RW | 0 | accumulator (zeroed) |
| this | 0xB0 | RW | 0 | accumulator (zeroed) |
| this | 0xB4 | RW | 0 | accumulator (zeroed) |
| this | 0x6E8 | R | — | sprite grid render object pointer (passed to SpriteGridRender) |
| this | 0x1070 | RW | 1 | active-particle-effects flag (byte: non-zero = effects present) |
| this | 0x1074 | RW | 0 | particle-effect slot array start (17 slots × 28 bytes each) |
| this | 0x32BC | R | — | mode / state counter (only processes when ≤ 1) |
| this | 0x34AC | R | — | time delta or vehicle speed (passed to ModeDispatchWithSwitch) |
| this | 0x34B0 | R | — | 3×3 rotation matrix element [0][0] |
| this | 0x34B4 | R | — | 3×3 rotation matrix element [0][1] |
| this | 0x34B8 | R | — | 3×3 rotation matrix element [0][2] | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | 3×3 rotation matrix element [1][0] |
| this | 0x34C0 | R | — | 3×3 rotation matrix element [1][1] |
| this | 0x34C4 | R | — | 3×3 rotation matrix element [1][2] |
| this | 0x34C8 | R | — | 3×3 rotation matrix element [2][0] |
| this | 0x34CC | R | — | 3×3 rotation matrix element [2][1] |
| this | 0x34D0 | R | — | 3×3 rotation matrix element [2][2] |
| this | 0x34D4 | R | — | world position X |
| this | 0x34D8 | R | — | world position Y |
| this | 0x34DC | R | — | world position Z |
| this | 0x34EC | R | — | half-extent / bounding-box dimension X |
| this | 0x34F0 | R | — | half-extent / bounding-box dimension Y | RenderX [FACT] |
| this | 0x34F4 | R | — | half-extent / bounding-box dimension Z | RenderY [FACT] |
| this | 0x3514 | R | — | reference scale / normalization value |
| this | 0x3A9C | R | — | pointer to reference position vector |
| this | 0x3B75 | RW | 1 | byte state flag (set when certain surface condition detected) |
| this | 0x3B78 | RW | 0 | pending surface-effect queue start (4 slots × 28 bytes) |
| this | 0x3B79 | R | — | byte within pending effect slot (flag/type) |
| this | 0x3B88 | R | — | effect position X (within pending slot) |
| this | 0x3B8C | R | — | effect position Y (within pending slot) |
| this | 0x3B90 | R | — | effect position Z (within pending slot) |
| this | 0x3FF0 | RW | 1 | tire-slip flag (byte: set when slip direction exceeds threshold) |

**Written-by note (persistence):**
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0x1070: recalc every frame — external poke does NOT persist
- this 0x1074: recalc every frame — external poke does NOT persist
- this 0x3B75: recalc every frame — external poke does NOT persist
- this 0x3B78: recalc every frame — external poke does NOT persist
- this 0x3FF0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ebc20 | jpt_4EB6B1 | R | jump table for surface-type dispatch (cases 0-5) |
| 004ebc30 | byte_4EBC30 | R | condition byte for particle/surface effect branching |
| 004ebc3c | jpt_4EB96D | R | jump table for surface-type dispatch (case 6) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 005ad1e0 | flt_5AD1E0 | R | Unknown_Float_5AD1E0 [DERIVED] |
| 005ad1e4 | flt_5AD1E4 | R | CollisionResponseThreshold [DERIVED] |
| 005ad1e8 | flt_5AD1E8 | R | BrakeFluidMult [DERIVED] |
| 007cf728 | byte_7CF728 | R | condition byte checked during surface dispatch |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | random noise table for particle effect variation | WeatherNoiseTable [DERIVED] (also:  random noise table (docs/12) |
| 008ab710 | dword_8AB710 | R | UI widget list / sprite grid handle | UIWidgetList [DERIVED] |
| 008ad400 | unk_8AD400 | R | vehicle component force array (14-byte stride: force X, Y per component) | VehicleModel_OffsetTable_8AD400 [DERIVED] |
| 008ad404 | unk_8AD404 | R | vehicle setup block (surface-type + object pointer per component) | VehicleSetupBlock [DERIVED] |
| 008ad428 | unk_8AD428 | R | tire wear / tire-direction array (14-byte stride per component) | TireWearArray [DERIVED] |
| 008ad42c | unk_8AD42C | R | vehicle component array offset (pit crew / contact points) | VehicleArrayOffset_PitCrew [DERIVED] |
| 008adaf8 | dword_8ADAF8 | RW | active vehicle component slot counter | SlotCounter [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f4b0 | ModeDispatchWithSwitch | dispatches per-surface-type processing mode (tarmac, gravel, etc.) |
| 0040f550 | UICameraModeDispatchWithVehicleDataRead | dispatches UI/camera mode with vehicle telemetry data read |
| 004be340 | GridCellIterate | iterates spatial grid cells for collision/surface queries |
| 004be4e0 | SpriteGridRender | renders sprite grid (ground-level particle sprite placement) |
| 004e9630 | PositionChangeMonitor | monitors position delta and updates tracking state |
| 004e96c0 | sub_4E96C0 | condition check before wheel-contact distance computation |
| 004e9980 | ComputeSlipVelocityNorm | computes slip velocity magnitude (wheel slide detection) |
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | computes body-to-wheel contact distance for ride height |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | applies 3×3 rotation + translation to vehicle transform |
| 004ea970 | CollisionDetectionSystem | runs collision detection against track/world geometry |
| 004ebc60 | VehicleContactForceAccumulation | accumulates contact forces at wheel/body contact points |
| 004ec080 | VehicleTelemetryPositionAccumulator | accumulates telemetry position data for replay/camera |
| 004f8850 | PerIndexStructFieldSetter | sets struct fields at indexed position (particle effect injection) |
| 004f8ab0 | ConditionedFloatRead | reads float value with clamped/conditioned lookup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32BC | <= | 1 | mode counter: processes effects only when ≤ 1 (active gameplay mode) |

**Guard interpretation:** Execution BLOCKED entirely unless `this+0x32BC ≤ 1` AND the bit 0 of byte at `*(this+0)+0x48BC` (postProcessInput flag on external object) is set. When PASSES: clears/queues particle effects, runs surface-type dispatch (cases 0-5 regular surface, case 6 special, case 9 special), computes force-normalized effect intensity (5.0 threshold for regular, 1000.0 for special surfaces), spawns particle sprites at contact points via PerIndexStructFieldSetter, accumulates telemetry, and checks tire-slip directional threshold (-0.707) to set slip flag.
