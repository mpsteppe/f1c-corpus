## DriverInputController_00451720 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x4E8)+0x80)+0x0) | 0x58 | R | — | [LLM] |
| *(*(*(this+0x4EC)+0x80)+0x0) | 0x58 | R | — | [LLM] |
| *(*(*(this+0x4F0)+0x80)+0x0) | 0x58 | R | — | [LLM] |
| *(*(*(this+0x4F4)+0x80)+0x0) | 0x58 | R | — | [LLM] |
| *(*(this+0x4E8)+0x80) | 0x0 | R | — | [LLM] |
| *(*(this+0x4EC)+0x80) | 0x0 | R | — | [LLM] |
| *(*(this+0x4F0)+0x80) | 0x0 | R | — | [LLM] |
| *(*(this+0x4F4)+0x80) | 0x0 | R | — | [LLM] |
| *(this+0x4E8) | 0x80 | R | — | [LLM] |
| *(this+0x4EC) | 0x80 | R | — | [LLM] |
| *(this+0x4F0) | 0x80 | R | — | [LLM] |
| *(this+0x4F4) | 0x80 | R | — | [LLM] |
| this | 0x2D4 | R | — | [LLM] |
| this | 0x418 | RW | 0 | [LLM] |
| this | 0x41C | RW | 0 | [LLM] |
| this | 0x420 | RW | 0 | [LLM] |
| this | 0x428 | RW | 1 | [LLM] |
| this | 0x48C | RW | — | [LLM] |
| this | 0x490 | RW | — | [LLM] |
| this | 0x498 | RW | — | [LLM] |
| this | 0x49C | RW | — | [LLM] |
| this | 0x4A8 | RW | — | [LLM] |
| this | 0x4AC | RW | 18446744073709541616 | [LLM] |
| this | 0x4B0 | RW | 0 | [LLM] |
| this | 0x4B4 | RW | 0 | [LLM] |
| this | 0x4BC | RW | 1000000 | [LLM] |
| this | 0x4C0 | R | — | [LLM] |
| this | 0x4C4 | R | — | [LLM] |
| this | 0x4C8 | R | — | [LLM] |
| this | 0x4CC | R | — | [LLM] |
| this | 0x4D0 | RW | 0 | [LLM] |
| this | 0x4D4 | RW | 0 | [LLM] |
| this | 0x4D8 | RW | 0 | [LLM] |
| this | 0x4DC | RW | 0 | [LLM] |
| this | 0x4E0 | RW | 0 | [LLM] |
| this | 0x4E4 | RW | — | [LLM] |
| this | 0x4E8 | R | — | [LLM] |
| this | 0x4EC | R | — | [LLM] |
| this | 0x4F0 | R | — | [LLM] |
| this | 0x4F4 | R | — | [LLM] |
| this | 0x510 | R | — | [LLM] |
| this | 0x514 | R | — | [LLM] |
| this | 0x560 | RW | 0 | [LLM] |
| this | 0x564 | RW | 0 | [LLM] |
| this | 0x568 | RW | 0 | [LLM] |
| this | 0x56C | RW | 0 | [LLM] |
| this | 0x570 | RW | 0 | [LLM] |
| this | 0x574 | RW | 0 | [LLM] |

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
| 00452668 | jpt_451960 | R | [LLM] |
| 00452680 | jpt_451982 | R | [LLM] |
| 00452690 | jpt_451A5A | R | [LLM] |
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
| 00587bdc | CRTFtol | [LLM] |
| 005881f0 | sub_5881F0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
