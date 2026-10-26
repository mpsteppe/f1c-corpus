## DriverInputController_00451720 — DriverInputController_UpdateTick

**Summary:** Per-frame tick that processes driver input state and vehicle physics data to update audio/visual effects across 10 channels (headlights, engine RPM, tire sounds, 3D positional audio). Reads wheel contact types and dispatches enable/disable to 4 audio sub-controllers.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x4E8)+0x80)+0x0) | 0x58 | R | — | vtable function at index 22 on sub-controller 0 (enable/disable dispatch) |
| *(*(*(this+0x4EC)+0x80)+0x0) | 0x58 | R | — | vtable function at index 22 on sub-controller 1 (enable/disable dispatch) |
| *(*(*(this+0x4F0)+0x80)+0x0) | 0x58 | R | — | vtable function at index 22 on sub-controller 2 (enable/disable dispatch) |
| *(*(*(this+0x4F4)+0x80)+0x0) | 0x58 | R | — | vtable function at index 22 on sub-controller 3 (enable/disable dispatch) |
| *(*(this+0x4E8)+0x80) | 0x0 | R | — | inner object vtable pointer for sub-controller 0 |
| *(*(this+0x4EC)+0x80) | 0x0 | R | — | inner object vtable pointer for sub-controller 1 |
| *(*(this+0x4F0)+0x80) | 0x0 | R | — | inner object vtable pointer for sub-controller 2 |
| *(*(this+0x4F4)+0x80) | 0x0 | R | — | inner object vtable pointer for sub-controller 3 |
| *(this+0x4E8) | 0x80 | R | — | pointer to sub-controller 0 object |
| *(this+0x4EC) | 0x80 | R | — | pointer to sub-controller 1 object |
| *(this+0x4F0) | 0x80 | R | — | pointer to sub-controller 2 object |
| *(this+0x4F4) | 0x80 | R | — | pointer to sub-controller 3 object |
| this | 0x2D4 | R | — | driver input flags (steering/pedal/button state bits) |
| this | 0x418 | RW | 0 | controller initialization byte flag (0=uninitialized, 1=initialized) |
| this | 0x41C | RW | 0 | previous effect intensity for channel 0 (headlights) |
| this | 0x420 | RW | 0 | previous smoothing target for channel 0 (headlights) |
| this | 0x428 | RW | 1 | previous sample-rate divisor for channel 0 (headlights) |
| this | 0x48C | RW | — | effect intensity value for channel 5 (RPM-based audio) |
| this | 0x490 | RW | — | smoothing target value for channel 5 (RPM-based audio) |
| this | 0x498 | RW | — | previous sample-rate divisor for channel 5 |
| this | 0x49C | RW | — | effect intensity value for channel 6 (speed-based audio) |
| this | 0x4A8 | RW | — | previous sample-rate divisor for channel 6 |
| this | 0x4AC | RW | 18446744073709541616 | target value for channel 7 (3D positional audio), init to large negative offset |
| this | 0x4B0 | RW | 0 | effect intensity for channel 8 (engine/tire audio) |
| this | 0x4B4 | RW | 0 | target value for channel 8 (engine/tire audio) |
| this | 0x4BC | RW | 1000000 | previous sample-rate divisor for channel 8 |
| this | 0x4C0 | R | — | headlight brightness input (float from vehicle state) |
| this | 0x4C4 | R | — | RPM/speed input value for channel 5 |
| this | 0x4C8 | R | — | speed input value for channel 6 |
| this | 0x4CC | R | — | engine speed input for channel 8 |
| this | 0x4D0 | RW | 0 | tire-slip flag (set when case 0xB wheel contact detected) |
| this | 0x4D4 | RW | 0 | previous tire-slip flag |
| this | 0x4D8 | RW | 0 | tire-lock flag (set when case 9/0xA wheel contact detected) |
| this | 0x4DC | RW | 0 | previous tire-lock flag |
| this | 0x4E0 | RW | 0 | total wheel contact count (sum across 4 wheels) |
| this | 0x4E4 | RW | — | previous wheel contact count |
| this | 0x4E8 | R | — | audio sub-controller 0 handle |
| this | 0x4EC | R | — | audio sub-controller 1 handle |
| this | 0x4F0 | R | — | audio sub-controller 2 handle |
| this | 0x4F4 | R | — | audio sub-controller 3 handle |
| this | 0x510 | R | — | sub-controller identity check (compared to sub-controller handle) |
| this | 0x514 | R | — | sub-controller identity check (compared to sub-controller handle) |
| this | 0x560 | RW | 0 | 3D positional audio accumulator X (double) |
| this | 0x564 | RW | 0 | 3D positional audio accumulator X high word |
| this | 0x568 | RW | 0 | 3D positional audio accumulator Y (double) |
| this | 0x56C | RW | 0 | 3D positional audio accumulator Y high word |
| this | 0x570 | RW | 0 | 3D positional audio accumulator Z (double) |
| this | 0x574 | RW | 0 | 3D positional audio accumulator Z high word |

**Written-by note (persistence):**
- this 0x418: recalc every frame — external poke does NOT persist
- this 0x41C: recalc every frame — external poke does NOT persist
- this 0x420: recalc every frame — external poke does NOT persist
- this 0x428: recalc every frame — external poke does NOT persist
- this 0x48C: recalc every frame — external poke does NOT persist
- this 0x490: recalc every frame — external poke does NOT persist
- this 0x498: recalc every frame — external poke does NOT persist
- this 0x49C: recalc every frame — external poke does NOT persist
- this 0x4A8: recalc every frame — external poke does NOT persist
- this 0x4AC: recalc every frame — external poke does NOT persist
- this 0x4B0: recalc every frame — external poke does NOT persist
- this 0x4B4: recalc every frame — external poke does NOT persist
- this 0x4BC: recalc every frame — external poke does NOT persist
- this 0x4D0: recalc every frame — external poke does NOT persist
- this 0x4D4: recalc every frame — external poke does NOT persist
- this 0x4D8: recalc every frame — external poke does NOT persist
- this 0x4DC: recalc every frame — external poke does NOT persist
- this 0x4E0: recalc every frame — external poke does NOT persist
- this 0x4E4: recalc every frame — external poke does NOT persist
- this 0x560: recalc every frame — external poke does NOT persist
- this 0x564: recalc every frame — external poke does NOT persist
- this 0x568: recalc every frame — external poke does NOT persist
- this 0x56C: recalc every frame — external poke does NOT persist
- this 0x570: recalc every frame — external poke does NOT persist
- this 0x574: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00452668 | jpt_451960 | R | jump table target for switch dispatch |
| 00452680 | jpt_451982 | R | jump table target for switch dispatch |
| 00452690 | jpt_451A5A | R | jump table target for switch dispatch |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 0059e958 | flt_59E958 | R | WheelbaseMult [DERIVED] |
| 0059ee68 | flt_59EE68 | R | PhysicsConstant_59EE68 [DERIVED] |
| 0059ef5c | flt_59EF5C | R | RenderEffectFloat [DERIVED] |
| 0059ef60 | flt_59EF60 | R | HeadlightRangeScale [DERIVED] |
| 0059ef64 | flt_59EF64 | R | HeadlightRangeFactor [DERIVED] |
| 0059ef68 | flt_59EF68 | R | RenderStateFloat [DERIVED] |
| 0059ef6c | flt_59EF6C | R | VehiclePhysicsFloat [DERIVED] |
| 0059ef70 | flt_59EF70 | R | VehicleEffectFloatConst [DERIVED] |
| 0059ef74 | flt_59EF74 | R | PitCrew_FlagState [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007c77f8 | dbl_7C77F8 | R | VehicleEffectDouble [DERIVED] |
| 007c7c5c | dbl_7C7C5C | R | DoublePhysicsConst [DERIVED] |
| 007c8a18 | dword_7C8A18 | R | Ptr_VehicleTransformBase [DERIVED] |
| 007c8a80 | dbl_7C8A80 | R | VehicleBodyAngularVel [DERIVED] |
| 007cc130 | flt_7CC130 | R | RendererTintParam [DERIVED] |
| 007cc15c | flt_7CC15C | R | Unknown_Float_7CC15C [DERIVED] |
| 007cd1f8 | flt_7CD1F8 | RW | AudioSourceHandle [DERIVED] |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] (also: ` — BrakeDiffSettings byte (docs/12) |
| 007d1358 | byte_7D1358 | R | EnableFlag [DERIVED] |
| 007d1fd8 | dword_7D1FD8 | R | AudioRaceModeFlag [DERIVED] (also: ` â€” flag for race-mode audio (higher gain heads) |
| 007d1ffc | dword_7D1FFC | R | AudioQualityLevel [DERIVED] |
| 007d2068 | dword_7D2068 | R | AudioMuteFlags [DERIVED] (also: ` â€” independent left/right channel mute flags) |
| 007d208c | flt_7D208C | R | AudioSampleRateDiv [DERIVED] |
| 007d20b0 | flt_7D20B0 | R | VehicleEffectParam [DERIVED] |
| 007d20d4 | flt_7D20D4 | R | CameraShakeMagnitude [DERIVED] |
| 007d211c | flt_7D211C | R | HeadlightBrightness [DERIVED] |
| 007d2140 | flt_7D2140 | R | HUDRefValue [DERIVED] |
| 007d2164 | flt_7D2164 | R | SessionTimeThreshold [DERIVED] |
| 007d2188 | flt_7D2188 | R | Anim_FadeSpeed [DERIVED] |
| 007d21ac | flt_7D21AC | R | ParticleEffectScale [DERIVED] |
| 007d21d0 | flt_7D21D0 | R | Unknown_Float_Visibility [DERIVED] |
| 007d22a8 | flt_7D22A8 | R | RenderBloomIntensity [DERIVED] |
| 007d22cc | flt_7D22CC | R | RendererFloatParam_7D22CC [DERIVED] |
| 007d2314 | flt_7D2314 | R | VehicleEffectRadius [DERIVED] |
| 007d235c | flt_7D235C | R | Flt_RenderDist_235C [DERIVED] |
| 007d2380 | flt_7D2380 | R | RenderLODParam [DERIVED] |
| 007d23c8 | flt_7D23C8 | R | Flt_Unknown_Render [DERIVED] |
| 007d23ec | flt_7D23EC | R | UIRenderFloat [DERIVED] |
| 007d2458 | flt_7D2458 | R | RenderStateFloat [DERIVED] |
| 007d247c | flt_7D247C | R | CameraDistanceParam [DERIVED] |
| 007d24a0 | flt_7D24A0 | R | VehiclePhysics_Param_7D24A0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | float-to-int conversion (used for all audio/effect parameter quantization) |
| 005881f0 | sub_5881F0 | power/exponentiation function (called for non-standard HUDRefValue exponent) |

**Guard conditions:** byte_7C56AC (enable flag) gates sub-controller init state. When byte_7C56AC==1 and this+0x418==0: enables all 4 sub-controllers (vtable call with param 32), sets this+0x418=1. When byte_7C56AC==0 and this+0x418==1: disables all 4 sub-controllers (vtable call with param 16), sets this+0x418=0. Also: this+0x418 (controller init byte) blocks overwriting channel state values when set (forces reset to defaults via LABEL_130/LABEL_244 paths). Player vehicle identity check (dword_7C54E8 != dword_7C54E0) combined with AI-controlled flag or brake-diff flag overrides wheel-contact detection and forces zero effect values.</content>
