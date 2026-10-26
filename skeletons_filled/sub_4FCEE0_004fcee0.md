## sub_4FCEE0_004fcee0 — HUD Scoring Progress Bar Animation Update

**Summary:** Updates a HUD scoring/progress bar element each frame: decrements a timer, encodes ring-buffer events when expired, interpolates alpha/color/position based on time-of-day and value thresholds, and updates audio panning and UI properties. Part of the HUD/scoring display system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x5C)+0x0) | 0x0 | R | — | event linked-list node timestamp (compared against SessionTime to trigger processing) |
| *(*(this+0x5C)+0x0) | 0x4 | R | — | event type selector (1 = encode type 2, otherwise type 3) |
| *(*(this+0x5C)+0x0) | 0x8 | R | — | event normalized value (0-1 range, used to compute alpha byte) |
| *(this+0x5C) | 0x0 | R | — | head pointer of event linked list (node with timestamp) |
| *(this+0x5C) | 0x4 | R | — | next pointer in linked list (used to advance head after processing) |
| this | 0x0 | R | — | base animation rate multiplier (multiplied by SessionTime for timing) |
| this | 0x4 | RW | 1065353216 → 1.0f | countdown timer (decrements by dbl_8AFE98 each frame; resets to 1.0 on expire) |
| this | 0x8 | RW | — | blended alpha/interpolation value (lerp between this+0x20 and current, based on timer) |
| this | 0xC | RW | — | current displayed alpha (smoothed toward computed alpha, threshold-gated update) |
| this | 0x10 | RW | — | day/night toggle flag (0 = night, 1 = day; triggers UI updates on change) |
| this | 0x14 | RW | 1 | active engagement flag (set to 1 when progress value this+0x2C > 0) |
| this | 0x18 | RW | — | cached progress baseline value (updated when delta from this+0x28 > 0.01, for scoring state switching) |
| this | 0x1C | RW | 0 | one-shot override accumulator (read to blend with alpha, then zeroed each frame) |
| this | 0x20 | R | — | target alpha/blend value (source for blending into this+0x8) |
| this | 0x24 | R | — | blend interpolation factor (controls lerp between this+0x8 and this+0x20) |
| this | 0x28 | R | — | current progress/fullness value (lower bound for bar fill calculation) |
| this | 0x2C | R | — | target progress/fullness value (upper bound for bar fill calculation) |
| this | 0x40 | RW | 0 | timer-expired flag byte (set to 0 when timer expires and string is copied) |
| this | 0x44 | RW | 18446744073701163007 | last event timestamp (session time when position was encoded; checked for 2.5s staleness) |
| this | 0x48 | RW | — | last encoded position X coordinate (from sub_4FC870, stored in ring buffer) |
| this | 0x4C | RW | — | last encoded position Y coordinate |
| this | 0x50 | RW | — | last encoded position Z coordinate |
| this | 0x5C | RW | — | pointer to event linked-list head (consumed from queue, advanced per processed node) |
| this | 0xA4 | RW | — | smoothed fullness display value (threshold-gated update toward computed fullness) |
| this | 0xA8 | R | — | color interpolation threshold (crossfade split point for progress) |
| this | 0xAC | R | — | color interpolation slope below threshold (inverse slope) |
| this | 0xB0 | R | — | color interpolation slope above threshold |
| this | 0xB4 | R | — | color set 1 R channel at progress=0 (low) |
| this | 0xB8 | R | — | color set 1 G channel at progress=0 |
| this | 0xBC | R | — | color set 1 B channel at progress=0 |
| this | 0xC0 | R | — | color set 1 R channel at progress=1 (high) |
| this | 0xC4 | R | — | color set 1 G channel at progress=1 |
| this | 0xC8 | R | — | color set 1 B channel at progress=1 |
| this | 0xCC | R | — | color set 2 R channel at progress=1 (high) |
| this | 0xD0 | R | — | color set 2 G channel at progress=1 |
| this | 0xD4 | R | — | color set 2 B channel at progress=1 |
| this | 0xD8 | R | — | color set 2 R channel at progress=0 (low) |
| this | 0xDC | R | — | color set 2 G channel at progress=0 |
| this | 0xE0 | R | — | color set 2 B channel at progress=0 |
| this | 0xE4 | R | — | computed output color 1 R channel |
| this | 0xE8 | R | — | computed output color 1 G channel |
| this | 0xEC | R | — | computed output color 1 B channel |
| this | 0xF0 | R | — | computed output color 2 R channel |
| this | 0xF4 | R | — | computed output color 2 G channel |
| this | 0xF8 | R | — | computed output color 2 B channel |
| this | 0xFC | R | — | alpha modulation lower bound offset |
| this | 0x100 | R | — | alpha modulation upper bound offset |

**Written-by note (persistence):**
- this 0x4: written every frame (decremented); conditional reset to 1.0 on expire — external poke does NOT persist
- this 0x8: written every frame — external poke does NOT persist
- this 0xC: written conditionally (when delta from target > 0.018) — external poke may persist briefly
- this 0x10: written only on day/night mode toggle — external poke persists until next day/night boundary
- this 0x14: written conditionally (when this+0x2C > 0) — external poke may persist until progress changes
- this 0x18: written conditionally (when delta > 0.01 from this+0x28) — external poke may persist briefly
- this 0x1C: written to 0 every frame — external poke does NOT persist
- this 0x40: written conditionally (when timer expires) — external poke may persist until next expire
- this 0x44: written conditionally (when position delta > 2.5s) — external poke may persist
- this 0x48: written conditionally (with 0x44) — external poke may persist
- this 0x4C: written conditionally (with 0x44) — external poke may persist
- this 0x50: written conditionally (with 0x44) — external poke may persist
- this 0x5C: pointer updated conditionally (when event consumed from queue) — external poke may persist if no events
- this 0xA4: written conditionally (when delta > 0.003) — external poke may persist briefly

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 0059e97c | flt_59E97C | R | LapTimeDeltaScale [DERIVED] |
| 0059ef78 | flt_59EF78 | R | ContactNormalizationFactor [DERIVED] (also: ` — second threshold/reference value) |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005ad294 | flt_5AD294 | R | ViewportTransformConstant [DERIVED] |
| 005ad298 | flt_5AD298 | R | ParticleEmitRate [DERIVED] |
| 005ad29c | flt_5AD29C | R | Float5AD29C [DERIVED] |
| 005ad2a0 | flt_5AD2A0 | R | FloatConst_5AD2A0 [DERIVED] |
| 005ad2a4 | flt_5AD2A4 | R | Unknown_Float_5AD2A4 [DERIVED] |
| 005ad2a8 | flt_5AD2A8 | R | ParticleLifeScale [DERIVED] |
| 005ad2ac | flt_5AD2AC | R | TireSpinThreshold [DERIVED] |
| 005ad2b0 | flt_5AD2B0 | R | PhysicsEffectFloat [DERIVED] |
| 005ad2b4 | flt_5AD2B4 | R | UnknownPhysicsConst [DERIVED] |
| 005ad2b8 | dbl_5AD2B8 | R | SteeringNoise_dbl_5AD2B8 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d6f78 | aNightlight | R | NightLightString [DERIVED] |
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 007cf8a8 | dword_7CF8A8 | R | RenderThrottleFrames [DERIVED] |
| 007cfec4 | flt_7CFEC4 | R | Flt_7CFEC4_Render [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acea8 | dword_8ACEA8 | R | Unknown_Scene_Value [DERIVED] |
| 008aceac | dword_8ACEAC | R | Session_RaceConfig_CEAC [DERIVED] |
| 008acfb0 | flt_8ACFB0 | R | RaceTimingConstant [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | encodes a progress-bar event into ring buffer (type, subtype, size, flags, timestamp) |
| 004cefe0 | StridedArraySearchAndCall | iterates over array with stride 10, calls handler with float value |
| 004fc170 | RenderColorUpdate | updates render color/alpha state for this HUD element |
| 004fc650 | StringCopyWithRingBuffer | copies string into ring buffer with wrapping logic |
| 004fc870 | sub_4FC870 | retrieves 3D position vector (3 floats) into output array |
| 004fdeb0 | AudioADSREnvelope | computes audio ADSR envelope with vehicle-count parameter |
| 00543870 | UIElementPositionSetter | sets UI element screen position from RGB color components (byte range) |
| 005438b0 | AudioPanUpdate | updates audio panning position from XY coordinates |
| 00543920 | BoundedFloatSetterWithFlag | sets bounded float value with associated flag toggle |
| 00545670 | CameraPositionGetter | retrieves counts of camera-position entities for day/night iteration |
| 005457c0 | LinkedListTraversal | traverses linked list from given node (used with index 0 for full reset) |
| 005457f0 | LinkedListNthElement | retrieves Nth element from linked structure |
| 00545820 | LinkedIndexedAccess | indexed access into linked/circular structure |
| 0055d2f0 | BitFlagSetterWithDXUpdate | sets bit flag on entity and triggers DirectX render update |
| 0055d410 | UIPropertyValueSetter | sets a UI property value by ID (here ID=2, alpha property) |
| 00587bdc | CRTFtol | C runtime float-to-integer conversion (used for 0-255 byte range mapping) |
| 00588640 | sub_588640 | string comparison (checks entity name against "Nightlight") |
| 0058957a | InterruptDispatch | dispatches interrupt event with timing value for day/night cycle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x5C)+0x0) | 0x4 | == | 1 | event type in linked-list node (1 = standard event, encode type 2; else = encode type 3) |

**Guard interpretation:** Entire update body requires `(dword_7C56A0 & 1) != 0` (multiplayer flag bit 0 set) AND `dword_8AB6E4 != 2` (scoring gate not in disabled state 2). Timer-expire sub-block (event encode) executes when this+0x4 decrements below 0.0 AND byte at this+0x40 is nonzero. Event-linked-list processing (lines 92-117) requires: valid pointer at this+0x5C, non-null first node, AND SessionTime has passed the node's timestamp. Within that block: node offset 0x4 == 1 selects ProgressBarEventEncode type 2 vs type 3. Day/night cycle overlay (lines 133-189) applies only when flt_7CFEC4 < 1.0. Alpha update (lines 197-211) triggers when delta > 0.018. Fullness update (lines 223-228) triggers when delta > 0.003. Scoring state toggling (lines 270-307) triggers when delta between this+0x40 and cached this+0x24 > 0.01; if value <= 0.03, toggles state 7→6 and 22→21; if > 0.03, toggles 6→7 and 21→22.
