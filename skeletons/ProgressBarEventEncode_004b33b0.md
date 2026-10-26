## ProgressBarEventEncode_004b33b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraShakeRingBufferWrite (0040f600), NetCommSessionMessageDispatcher (0045d890), MouseInputHandler (0045f030), SessionUIElementRenderer (0045f2b0), SessionSynchronizer (0045f950), SendServerOKRequest (00460470), ParticleSoundEffectSpawner (004607a0), ServerOpenTrackSignal (00460e90), ServerCloseTrackSignal (00461020), WeatherSurfaceUpdate (004628a0), CollisionEventNetworkBroadcast (00462940), EntityVisibilityGridManager (00465460), SessionMessageUICommandHandler (00470490), StateChangeNotify (004a5c80), PitStopOperationTimer (004a6340), StopGoPenaltyHandler (004bbd60), ProgressBarIncrement (004bbf20), sub_4BC060 (004bc060), DisqualificationHandler (004bc0e0), LapSplitTimeEvent (004bc390), EngineFailureCheck (004bec55), SetupCarLightingAndRender (004c71c0), sub_4D1730 (004d1730), sub_4D1D80 (004d1d80), ProgressBarDataStore (004d2260), TrackTemperatureDisplay (004d37b0), sub_4D4580 (004d4580), VehicleRespawnReset (004e0800), CollisionSparkParticleEffects (004ec1a0), sub_4EF2E0 (004ef2e0), PositionUpdateWithTelemetryRecording (004ef4f0), StringCopyWithRingBuffer (004fc650), sub_4FCEE0 (004fcee0), AudioSampleCrossFadeInterpolation (004ff8f0), AudioSamplePlaybackWithPitchModulationAndStereoP (00500210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x1AC | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
