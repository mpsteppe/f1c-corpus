# Global Ownership Map

Generated from IDA data xrefs (17037 total references across 7990 globals).


## Summary Statistics

- Total globals with xrefs: 7990
- Globals with write xrefs: 1081
- Read/offset-only globals (no static writer): 6909
- Written by exactly one subsystem: 1001
- **Shared mutable state (2+ subsystems write): 80** — COUPLING POINTS

## Shared Mutable State (written by 2+ subsystems)

These globals are the coupling interfaces between subsystems.

| Global | Writers | Readers |
|--------|---------|---------|
| DAT_008D423C (DynamicsSolverCounter) | engine architecture, math utilities | — |
| DAT_008D446C (DynamicsSolverFlag) | engine architecture, math utilities | — |
| DAT_007C5690 (InitStateFlag) | engine architecture, file formats, session race logic, track system | ai system, engine architecture, session race logic |
| DAT_005CC9E8 (SessionInitState) | session race logic, unknown | renderer, track system, unknown |
| DAT_007c54dc (CurrentPlayerIndex) | engine architecture, session race logic, track system | engine architecture, file formats, math utilities, pit system, renderer, session race logic, track system, unknown, vehicle physics |
| DAT_007c54e0 (unknown (near PlayerVehiclePtr +0x8)) | engine architecture, session race logic, track system | ai system, engine architecture, file formats, math utilities, renderer, session race logic, track system, unknown, vehicle physics |
| DAT_007C56A0 (MultiplayerFlags) | engine architecture, session race logic, track system, unknown | session race logic, track system, unknown |
| DAT_008D3EC8 (FileOpenCount) | file formats, math utilities | — |
| DAT_008D3FB0 (LocaleValidationFlags) | file formats, math utilities | math utilities, session race logic |
| DAT_005c329c (VehicleCount) | file formats, session race logic, track system | ai system, engine architecture, file formats, math utilities, physics collision, pit system, renderer, session race logic, track system, unknown, vehicle physics |
| DAT_007CDDF8 (CollisionListTail) | engine architecture, physics collision | — |
| DAT_007CDDFC (CollisionContactCounter) | engine architecture, physics collision | engine architecture |
| DAT_007CE258 (InitZeroFieldSet) | math utilities, pit system, session race logic | session race logic |
| DAT_008AC48C (CurrentSceneIndex) | track system, unknown | engine architecture, file formats, math utilities, renderer, session race logic, track system, unknown |
| DAT_005DD804 (ImageBlitTransparentColor) | file formats, math utilities, renderer | — |
| DAT_007CDDF4 (CollisionListTailPointer) | engine architecture, physics collision | physics collision |
| DAT_007CE250 (CollisionConfigVersion) | engine architecture, math utilities | engine architecture, physics collision, session race logic |
| DAT_007d0410 (RaceMode (4=?)) | engine architecture, session race logic, track system | ai system, engine architecture, file formats, math utilities, pit system, renderer, session race logic, track system, unknown |
| DAT_008AB704 (FreeListTailPtr) | audio network internals, physics collision, session race logic | — |
| DAT_008AB708 (GlobalAllocPoolNode) | audio network internals, physics collision, session race logic | math utilities |
| DAT_008ac38c (CurrentFontHandle) | file formats, track system | ai system, file formats, math utilities, session race logic |
| DAT_008B8F3C (GlobalDataBufferPtr) | math utilities, unknown | math utilities |
| DAT_005cc9e4 (GameMenuState) | session race logic, unknown | unknown |
| DAT_005d76c0 (PTR_FUN_SteerTable) | math utilities, renderer | math utilities |
| DAT_005D76C4 (CollisionDispatchFn) | math utilities, renderer | math utilities |
| DAT_005DD814 (ImageIO_ScanlineWidth) | file formats, math utilities | — |
| DAT_005e77f0 (DST_StartYear) | file formats, session race logic | session race logic |
| DAT_005E7800 (TimeZoneBiasEnd) | file formats, session race logic | session race logic |
| DAT_007C5694 (TimerOutputInt) | engine architecture, session race logic | engine architecture |
| DAT_007CA3CC (HUDTelemetry_Param4) | physics collision, tire system | — |
| DAT_007CA3EC (FrontBrakeBalance) | physics collision, tire system | — |
| DAT_007CA474 (ZeroFloat) | physics collision, tire system | — |
| DAT_007CA494 (AudioEngine_MinVolume) | physics collision, tire system | — |
| DAT_007CCA48 (RenderFloat_A) | physics collision, tire system | — |
| DAT_007CCA70 (VehicleSetup_BrakeBalance) | physics collision, tire system | — |
| DAT_007CCA80 (RenderState_7CCA80) | physics collision, tire system | — |
| DAT_007ccbb4 (VehicleRideHeightRear) | physics collision, tire system | — |
| DAT_007CCF64 (Flt_Threshold_CF64) | physics collision, tire system | — |
| DAT_007CCF74 (RenderState_7CCF74) | physics collision, tire system | — |
| DAT_007CCF84 (VehicleSetupFloat_7CCF84) | physics collision, tire system | — |
| DAT_007ccf94 (UIStatThreshold) | physics collision, tire system | — |
| DAT_007CCFA4 (RenderFloat_CFA4) | physics collision, tire system | — |
| DAT_007CCFB4 (Flt_WheelCamber_CFB4) | physics collision, tire system | — |
| DAT_007cd19c (VehicleHeatDisplayTread) | physics collision, tire system | — |
| DAT_007CDE08 (DestSurface) | math utilities, physics collision | physics collision |
| DAT_007CDE14 (CollisionSoundSurface2) | math utilities, physics collision | math utilities |
| DAT_007CDE20 (SurfaceObjectRef) | math utilities, physics collision | math utilities |
| DAT_007CE25E (SessionRequestFlag) | engine architecture, math utilities | session race logic |
| DAT_007CE25F (SessionPauseFlag) | engine architecture, math utilities | engine architecture, session race logic |
| DAT_007d00ec (GameState (1-7)) | session race logic, unknown | file formats |
| DAT_007d0990 (RaceSessionVehicleCount) | file formats, session race logic | session race logic |
| DAT_008AB70C (FreeNodeCount) | audio network internals, session race logic | physics collision |
| DAT_008AFE74 (Net_PacketBufferIndex) | math utilities, unknown | engine architecture |
| DAT_008AFE90 (EngineCoolingRate) | math utilities, unknown | ai system, audio network internals, engine architecture, math utilities, physics collision, physics dynamics, session race logic, track system, unknown |
| DAT_008AFE98 (ScoringDefaultReturn) | math utilities, unknown | ai system, engine architecture, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, track system, unknown |
| DAT_008afe9c (TimeAccumulator_A) | math utilities, unknown | — |
| DAT_008AFEA8 (InputAxisDeadZone) | engine architecture, math utilities | ai system, math utilities, physics collision, session race logic, unknown |
| DAT_008b6ab8 (AudioBufferLoopBoundary) | math utilities, renderer | math utilities |
| DAT_008B6AC0 (PhysicsObjectCount) | renderer, unknown | math utilities, session race logic, unknown |
| DAT_008B6AC4 (TextureEffectGate) | audio network internals, renderer | engine architecture |
| DAT_008b6ac8 (StringBuffer) | math utilities, renderer | math utilities |
| DAT_008B8E24 (AudioInitFlag) | math utilities, renderer | unknown |
| DAT_008b8e2c (RendererMipmapFlag) | math utilities, renderer | renderer |
| DAT_008B8F18 (NetConfigData) | math utilities, renderer | renderer |
| DAT_008B8F30 (TempFileReadBuffer) | math utilities, unknown | renderer |
| DAT_008B8F34 (FileReadBuffer2) | math utilities, unknown | — |
| DAT_008d3c04 (TaskListTail) | math utilities, session race logic | math utilities |
| DAT_008D3F9C (LocaleMatchFlag) | math utilities, session race logic | math utilities |
| DAT_008D3FA0 (Locale_CharsetMode) | math utilities, session race logic | math utilities |
| DAT_008d3fa4 (LocaleIsThreeLetterFlag) | math utilities, session race logic | math utilities |
| DAT_008D463C (RefCountArray) | math utilities, physics dynamics | — |
| DAT_008D4680 (NetworkEncodeBuffer) | physics collision, unknown | — |
| DAT_008D4684 (XORPadData) | physics collision, unknown | — |
| DAT_008d4688 (NetworkSaltBuffer) | physics collision, unknown | — |
| DAT_008d468c (XORKey_NetworkAuth) | physics collision, unknown | — |
| DAT_008D46CC (CodePageInitFlag) | audio network internals, session race logic | session race logic |
| DAT_008D47E1 (CharClassTable_byte) | audio network internals, session race logic | file formats, session race logic |
| DAT_008D48E4 (LocaleCRT) | audio network internals, session race logic | math utilities, session race logic |
| DAT_008D48F0 (HeapAllocCursor) | math utilities, session race logic | math utilities |
| DAT_008D5A5C (HeapLockCounter) | math utilities, session race logic | audio network internals, math utilities, unknown |

## Per-Subsystem Ownership

### ai system

**Owns — sole writer (10 globals):**
- `DAT_005C3160 (TrackConfigByte_5C3160)` ← read by: ai system
- `DAT_007D2E50 (SessionMsgCount)` ← read by: audio network internals, math utilities, session race logic, track system, unknown
- `DAT_0083ee54 (SessionDataOffset (stride 0x1b0))` ← read by: track system
- `DAT_0083ee58 (ScoringDataPtr)`
- `DAT_0083ee5c (SeasonScoringQueuePtr)`
- `DAT_0083EE60 (RingBufferCount)` ← read by: audio network internals, engine architecture, math utilities, pit system, session race logic, track system, unknown, vehicle physics, weather system
- `DAT_008AAE64 (RingBufferWritePtr)` ← read by: audio network internals, engine architecture, math utilities, pit system, session race logic, track system, unknown, vehicle physics, weather system
- `DAT_008aae68 (ScoringListHeadPtr)`
- `DAT_008aae6c (ScoringDataQueuePtr)`
- `DAT_008ACFA0 (HalfDistanceFlag)` ← read by: session race logic

**Reads from other subsystems (6 globals):**
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007CEC30 (ReconPitOpen)` (owned by session race logic)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)

### audio network internals

**Owns — sole writer (78 globals):**
- `DAT_005dd8cc (SoundMixClipTable)`
- `DAT_005ddccc (AlphaBlendSumTable)`
- `DAT_005deccc (MultiplyLUT_8x32)`
- `DAT_005e0ccc (MulLookupTable)`
- `DAT_005E6BD8 (DecimalSeparatorChar)` ← read by: file formats, math utilities, unknown
- `DAT_005e6bdc (LocaleInitFlag)`
- `DAT_007ca488 (CollisionScaleInit)`
- `DAT_007CA48C (RendererFloatState_7CA48C)` ← read by: tire system
- `DAT_007cc9c4 (SteeringFFBInitVal)`
- `DAT_007cc9c8 (BrakePedalDeadzone)` ← read by: tire system
- `DAT_007cd07c (Dword_Unknown_Render)`
- `DAT_008b5924 (FilterCoeff_8B5924)`
- `DAT_008b5928 (DCT_Coeff)`
- `DAT_008b592c (ColorTransformChromaB)`
- `DAT_008b5930 (DCTScaleFactor0)`
- `DAT_008b5934 (DCTDifferenceCoeff)`
- `DAT_008b5938 (Flt_DCT_Coeff)`
- `DAT_008b593c (DCTTransformCoeff0)`
- `DAT_008b5940 (DCT_Output_00)`
- `DAT_008b5944 (DCTOutputCoeff1)`
- `DAT_008b5948 (Render_Bicubic_8B5948)`
- `DAT_008B594C (Unknown_Float_DCT_Write)`
- `DAT_008b5950 (DCTOutputBuffer1)`
- `DAT_008b5954 (DCT_OutputBuffer)`
- `DAT_008b5958 (DCT_OutputBuffer0)`
- `DAT_008b595c (DCT_Output_8B595C)`
- `DAT_008b5960 (DCTOutputCoeff)`
- `DAT_008b5964 (Render_Bicubic_8B5964)`
- `DAT_008b5968 (DCTOutputCoeff2)`
- `DAT_008b596c (DCT_Output_01)`
- `DAT_008b5970 (DCTTransformCoeff1)`
- `DAT_008b5974 (Flt_DCT_Coeff2)`
- `DAT_008b5978 (DCTDiffCoeff2)`
- `DAT_008b597c (DCTScaleFactor1)`
- `DAT_008b5980 (ColorTransformChromaR)`
- `DAT_008b5984 (DCT_Coeff2)`
- `DAT_008b5988 (FilterCoeff_8B5988)`
- `DAT_008b598c (WaveletDSPFloat)`
- `DAT_008b5990 (DCTOutputBlock)`
- `DAT_008B5994 (AudioMixBuffer)`
- `DAT_008b5998 (IDCTOutputBuffer)`
- `DAT_008b599c (DCTWorkspaceFloat)`
- `DAT_008b59a0 (DCT_Coefficient_8B59A0)`
- `DAT_008b59a4 (Render_Bicubic_8B59A4)`
- `DAT_008B59A8 (Unknown_Float_DCT_Write2)`
- `DAT_008b59ac (DCTOutputBuffer2)`
- `DAT_008b59b0 (DCT_OutputBuffer2)`
- `DAT_008b59b4 (DCT_OutputBuffer1)`
- `DAT_008b59b8 (DCT_Output_8B59B8)`
- `DAT_008b59bc (DCTOutputScaler)`
- `DAT_008b59c0 (IDCTWorkspace)`
- `DAT_008B59C4 (Unknown_Float_DCT_Write3)`
- `DAT_008b59c8 (Render_Bicubic_8B59C8)`
- `DAT_008b59cc (DCTOutputCoeff3)`
- `DAT_008b59d0 (DCT_Output_02)`
- `DAT_008b59d4 (DCTTransformCoeff2)`
- `DAT_008b59d8 (Flt_DCT_Coeff3)`
- `DAT_008b59dc (DCTDiffCoeff3)`
- `DAT_008b59e0 (DCTScaleFactor2)`
- `DAT_008B59E4 (AudioMixOutput_59E4)`
- `DAT_008B59E8 (Unknown_Float_DCT_Write4)`
- `DAT_008b59ec (DCTOutputBuffer3)`
- `DAT_008b59f0 (Flt_DCT_Coeff4)`
- `DAT_008b59f4 (WaveletOutFloat)`
- `DAT_008b59f8 (DCT_OutputBuffer2)`
- `DAT_008b59fc (DCTDiffCoeff5)`
- `DAT_008B5A00 (AudioMixOutput_5A00)`
- `DAT_008b5a04 (DCT_Output_8B5A04)`
- `DAT_008b5a08 (DCT_Output_03)`
- `DAT_008b5a0c (FilterResult_8B5A0C)`
- `DAT_008b5a10 (DCTTransformCoeff3)`
- `DAT_008b5a14 (DCT_OutputBuffer3)`
- `DAT_008b5a18 (DCTWorkspace)`
- `DAT_008b5a1c (DCTDiffCoeff4)`
- `DAT_008b5a20 (DCTOutputBuffer4)`
- `DAT_008B8E48 (AudioChannelCount)` ← read by: audio network internals, math utilities
- `DAT_008d3e24 (SerialObjHeader)`
- `DAT_008D3E28 (SocketAsyncWindowHandle)` ← read by: audio network internals, unknown

**Reads from other subsystems (28 globals):**
- `DAT_005e69c8 (CharTypeTable)` (owned by math utilities)
- `DAT_005E6BD4 (CharTypeTableVersion)` (owned by math utilities)
- `DAT_007CA3C8 (CollisionRegionType)` (owned by physics collision)
- `DAT_007CA3E8 (AudioEngineDefaultType)` (owned by physics collision)
- `DAT_007ca470 (CollisionGridSize (4))` (owned by physics collision)
- `DAT_007CA490 (CollisionCellInitCount)` (owned by physics collision)
- `DAT_007CCA44 (NodeElementCount)` (owned by physics collision)
- `DAT_007CCA6C (RenderStateInt_9)` (owned by physics collision)
- `DAT_007cca7c (UIElementTypeID)` (owned by physics collision)
- `DAT_007CCBB0 (CollisionMaterialDefault)` (owned by physics collision)
- `DAT_007CCF80 (MaxContactCount)` (owned by physics collision)
- `DAT_007ccfb0 (RenderStateID_S)` (owned by physics collision)
- `DAT_007CD198 (DefaultCollisionState)` (owned by physics collision)
- `DAT_007D0E98 (Unknown_Flag_7D0E98)` (owned by session race logic)
- `DAT_007D2E50 (SessionMsgCount)` (owned by ai system)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008AB700 (FreeListHead)` (owned by session race logic)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B00A0 (FPUControlStore)` (owned by math utilities)
- `DAT_008B0108 (AudioCodecInitFlag)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008d41d4 (CodePageAutoFlag)` (owned by session race logic)
- `DAT_008D46BC (CRT_Locale)` (owned by session race logic)
- `DAT_008D4904 (PrivateHeapHandle)` (owned by math utilities)
- `DAT_008D4908 (OSVersionCode)` (owned by math utilities)
- `DAT_008d5a58 (LocaleThreadRefCount)` (owned by unknown)

### engine architecture

**Owns — sole writer (53 globals):**
- `DAT_005E6D40 (TlsIndex)` ← read by: math utilities
- `DAT_005E9EF4 (RefCount)` ← read by: engine architecture, math utilities
- `DAT_005ea04c (ReferenceCounter)` ← read by: engine architecture, math utilities
- `DAT_005EA500 (GameStateFlag_5EA500)` ← read by: file formats
- `DAT_005ea504 (UIMenuState)` ← read by: file formats
- `DAT_005EA508 (UIDispatchTable)` ← read by: file formats
- `DAT_005ea535 (byte_5EA535)`
- `DAT_005ea538 (FileInitCounter)`
- `DAT_005ea53e (InitFlagByte)`
- `DAT_005EA550 (Unknown_GameState_5EA550)` ← read by: file formats
- `DAT_005EA554 (Unknown_Flag_5EA554)` ← read by: file formats
- `DAT_005EA558 (Unknown_SetupFlag)` ← read by: file formats
- `DAT_007c5698 (SessionTickCounter)` ← read by: engine architecture, physics collision, pit system, renderer
- `DAT_007C56AD (SessionFlagByte)`
- `DAT_007C56B0 (SessionState_56B0)` ← read by: session race logic
- `DAT_007c932c (RaceScoring_ClearFlags_0)`
- `DAT_007C9330 (UpdateLoopZeroState)`
- `DAT_007c9334 (SessionClearStateArray)`
- `DAT_007c9338 (StewardCounterBlock8)`
- `DAT_007c933c (CollisionAccumulator)`
- `DAT_007c9340 (ScoringAudioAccum0)`
- `DAT_007c9344 (PhysicsWorkspace_Zeroed_Block)`
- `DAT_007C9348 (PhysicsAccum_07)`
- `DAT_007c934c (ZeroedBlock7C934C)`
- `DAT_007C9350 (Unknown_FlagBlock_Clear)`
- `DAT_007C9354 (LapScoringFlagsBatch)`
- `DAT_007c9358 (SimulationAccumBlock)`
- `DAT_007CA3C0 (ExtendedMaterialTable)` ← read by: physics collision, tire system
- `DAT_007CA3C4 (CollisionInitOne)`
- `DAT_007CA440 (CollisionRadiusSentinel)`
- `DAT_007CA444 (HUDTelemetry_Param5)` ← read by: tire system
- `DAT_007CCCB8 (UIBrightness_CCCB8)` ← read by: tire system
- `DAT_007cccbc (CollisionConfigFloat (1.0f))`
- `DAT_007ccfe4 (MinusOneSentinel)`
- `DAT_007CCFE8 (RenderFloat_CFE8)` ← read by: tire system
- `DAT_007cd110 (UIElementFloat_7CD110)` ← read by: tire system
- `DAT_007cd114 (D3D_InitValue_1)`
- `DAT_007CD190 (InvalidContactSentinel)`
- `DAT_007CD194 (RearRPMGovernor)` ← read by: tire system
- `DAT_007CE2A0 (HInstance)` ← read by: engine architecture, session race logic, unknown
- `DAT_007ce2d8 (FileHandle_7CE2D8)` ← read by: engine architecture
- `DAT_007cff30 (ExperienceLapsResetFlag)`
- `DAT_007CFF84 (ScreenModeSetting)`
- `DAT_007D0798 (RaceSetupScaling)` ← read by: session race logic, unknown
- `DAT_007D2E44 (ScoringGateEnableFlag)` ← read by: engine architecture, session race logic
- `DAT_008AC4C4 (InitStatus)` ← read by: audio network internals, file formats, math utilities, renderer, session race logic, track system, unknown
- `DAT_008AFE68 (ParticleLifeValue)` ← read by: math utilities, unknown
- `DAT_008AFE6C (ParticleArrayCurrentIndex)` ← read by: engine architecture, unknown
- `DAT_008AFE70 (RaceByteFlag)` ← read by: unknown
- `DAT_008AFE84 (Unknown_Race_DynamicsValue)` ← read by: unknown
- `DAT_008afeac (Unknown_8AFEAC)`
- `DAT_008D3E44 (CRTCallResult)`
- `DAT_008D46B4 (NetworkContextPtr)` ← read by: physics dynamics

**Reads from other subsystems (38 globals):**
- `DAT_005D6D60 (ScreenWidth)` (owned by math utilities)
- `DAT_005D6D64 (ScreenWidth)` (owned by math utilities)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007CCCD8 (CollisionGridSize)` (owned by physics collision)
- `DAT_007CCCF0 (RainBrakeBiasGlobal)` (owned by physics collision)
- `DAT_007CCD08 (CollisionRegionType)` (owned by physics collision)
- `DAT_007CCD20 (CollisionStateBlock11)` (owned by physics collision)
- `DAT_007CCD38 (GridNodeElementCount)` (owned by physics collision)
- `DAT_007CCD50 (CollisionShape_13)` (owned by physics collision)
- `dword_7CD2AC (0x007cd2ac)` (owned by physics dynamics)
- `DAT_007CD9CC (PoolDescriptorPtr)` (owned by renderer)
- `DAT_007CD9D0 (AllocatorHandle)` (owned by renderer)
- `DAT_007CDDF0 (CollisionStateCounters)` (owned by physics collision)
- `DAT_007CDE1C (SubsystemInstancePtr)` (owned by math utilities)
- `DAT_007CE25C (GlobalSessionFlag)` (owned by math utilities)
- `DAT_007CE260 (InitGuard_45d500)` (owned by math utilities)
- `DAT_007CE264 (SessionStateFlag)` (owned by unknown)
- `DAT_007CE2DC (HWnd)` (owned by session race logic)
- `DAT_007CE2E4 (SleepSuppressFlag)` (owned by session race logic)
- `DAT_007CE2E8 (SessionCatchupFlag)` (owned by math utilities)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B8DC8 (RenderDevicePtr)` (owned by renderer)
- `DAT_008B8DD4 (ScreenWidthRatio)` (owned by renderer)
- `DAT_008B8DD8 (ScreenHeight)` (owned by renderer)
- `DAT_008B8E34 (RenderVisibilityMask)` (owned by renderer)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008B8F2C (RenderResourceHandle2)` (owned by renderer)
- `DAT_008d4920 (CriticalSectionArray (stride 0x24))` (owned by math utilities)

### engine wear damage

**Owns:** none

**Reads from other subsystems (5 globals):**
- `DAT_005C7530 (GlobalDataStructBase)` (owned by unknown)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007ce97c (TireModelFlag)` (owned by session race logic)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)

### file formats

**Owns — sole writer (25 globals):**
- `DAT_005BE900 (Int_GameStateSubmode)` ← read by: renderer
- `DAT_005c6658 (sProfileIconBmp)` ← read by: file formats
- `DAT_005C66F8 (DefaultProfileIconPath)` ← read by: file formats
- `DAT_005dd844 (Blit_CopyAllFlag)`
- `DAT_005E7758 (TimeBias_MinutesBias)` ← read by: math utilities
- `DAT_005e775c (DSTActiveFlag)` ← read by: math utilities, session race logic
- `DAT_005E7760 (DSTOffsetSeconds)` ← read by: math utilities, session race logic
- `DAT_007cd717 (FileCopied_Flag)`
- `DAT_007cd817 (FilePathNullTerminator)`
- `DAT_007CEC90 (VehicleLoadState)` ← read by: session race logic, unknown
- `DAT_007ced8c (UIRacePhaseFlag)` ← read by: pit system, session race logic, unknown
- `DAT_007CEE88 (SessionInitFlags)` ← read by: pit system, session race logic, unknown
- `DAT_008d3e50 (LocaleConvResult)`
- `DAT_008d3e74 (VersionInfo_BuildNum)`
- `DAT_008d3e78 (OSVersionPacked)`
- `DAT_008d3e7c (OSVersion_Major)`
- `DAT_008d3e80 (WinVersionMinor)`
- `DAT_008D3E90 (StringTablePtr)` ← read by: file formats, math utilities, session race logic
- `DAT_008d3eb4 (CmdLineEnvironmentStr)` ← read by: file formats
- `DAT_008d3fa8 (LocaleLanguageStr)` ← read by: math utilities, session race logic
- `DAT_008D3FAC (LocaleLanguageRegionPtr)` ← read by: math utilities, session race logic
- `DAT_008d3fc0 (TimeZoneInitFlag)` ← read by: session race logic
- `DAT_008D464C (GlobalObjManagerPtr)`
- `DAT_008d5a44 (CmdLinePtr)` ← read by: math utilities, session race logic
- `DAT_008D5A48 (ArgvParsedFlag)` ← read by: session race logic

**Reads from other subsystems (36 globals):**
- `DAT_005e69c8 (CharTypeTable)` (owned by math utilities)
- `DAT_005E6BD4 (CharTypeTableVersion)` (owned by math utilities)
- `DAT_005E6BD8 (DecimalSeparatorChar)` (owned by audio network internals)
- `DAT_005EA500 (GameStateFlag_5EA500)` (owned by engine architecture)
- `DAT_005ea504 (UIMenuState)` (owned by engine architecture)
- `DAT_005EA508 (UIDispatchTable)` (owned by engine architecture)
- `DAT_005EA550 (Unknown_GameState_5EA550)` (owned by engine architecture)
- `DAT_005EA554 (Unknown_Flag_5EA554)` (owned by engine architecture)
- `DAT_005EA558 (Unknown_SetupFlag)` (owned by engine architecture)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008AC398 (TrackNameBuffer)` (owned by unknown)
- `DAT_008AC3E8 (SCNFilePathBuffer)` (owned by unknown)
- `DAT_008AC438 (AIWFilePathBuffer)` (owned by unknown)
- `DAT_008ac488 (SceneFileCount)` (owned by unknown)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008B8CF0 (RendererBrightness)` (owned by renderer)
- `DAT_008B8CF4 (AudioMusicVolume)` (owned by renderer)
- `DAT_008B8DD4 (ScreenWidthRatio)` (owned by renderer)
- `DAT_008B8E30 (RegisteredEntryCount)` (owned by renderer)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008D3F98 (CurrentLocaleID)` (owned by math utilities)
- `DAT_008D3FB4 (LocaleLanguageID)` (owned by math utilities)
- `DAT_008D48E8 (Int_HeapReAllocCapacity)` (owned by math utilities)
- `DAT_008d48f8 (HeapBlockCounter)` (owned by math utilities)
- `DAT_008D48FC (LocaleConvBuffer)` (owned by math utilities)
- `DAT_008D4904 (PrivateHeapHandle)` (owned by math utilities)
- `DAT_008d4920 (CriticalSectionArray (stride 0x24))` (owned by math utilities)
- `DAT_008D4A20 (OpenFileCount)` (owned by math utilities)

### globals reference

**Owns — sole writer (2 globals):**
- `DAT_007ca3b0 (VehicleCamberFront)` ← read by: tire system
- `DAT_007ca3b4 (AudioVolumeFloat)`


### math utilities

**Owns — sole writer (69 globals):**
- `DAT_005D6D60 (ScreenWidth)` ← read by: engine architecture, math utilities, renderer, session race logic, unknown
- `DAT_005D6D64 (ScreenWidth)` ← read by: engine architecture, math utilities, physics collision, renderer, session race logic, unknown
- `DAT_005D6D68 (FrameTimeLast)` ← read by: unknown
- `DAT_005dc470 (VertexTransformCount)`
- `DAT_005E6730 (CRTFunctionTable)` ← read by: unknown
- `DAT_005e6744 (CRTFunctionPtr)`
- `DAT_005e69c8 (CharTypeTable)` ← read by: audio network internals, file formats, math utilities, renderer, session race logic, unknown
- `DAT_005e69cc (CRTCodePageBuffer)`
- `DAT_005E6BD4 (CharTypeTableVersion)` ← read by: audio network internals, file formats, math utilities, renderer, session race logic, unknown
- `DAT_005E7978 (HeapMarker)` ← read by: unknown
- `DAT_005EBB18 (ResetStateCounter0)`
- `DAT_005EBB1C (ZeroedGlobal)`
- `DAT_005EBB20 (ZeroedInitState)`
- `DAT_005EBB24 (ZeroedFloat4)`
- `DAT_007c8310 (SessionStartPaused)`
- `DAT_007c8314 (Renderer_TextureFlag_7C8314)`
- `DAT_007CA450 (HUDThreshold1)` ← read by: tire system
- `DAT_007ca454 (FloatInitOne)`
- `DAT_007CCBFC (InvalidIndexSentinel)`
- `DAT_007CCC00 (CollisionZeroField)` ← read by: tire system
- `DAT_007CDE04 (Surface1ResourceHandle)` ← read by: physics collision
- `DAT_007CDE10 (RendererSurfaceHandle)` ← read by: math utilities, physics collision
- `DAT_007CDE1C (SubsystemInstancePtr)` ← read by: engine architecture, physics collision
- `DAT_007CE25C (GlobalSessionFlag)` ← read by: engine architecture
- `DAT_007CE25D (GlobalFlagA0DA0)` ← read by: session race logic
- `DAT_007CE260 (InitGuard_45d500)` ← read by: engine architecture, math utilities, session race logic
- `DAT_007CE269 (SessionInitGate)` ← read by: math utilities, session race logic
- `DAT_007CE26C (RaceTimerValue)` ← read by: session race logic
- `DAT_007CE2E8 (SessionCatchupFlag)` ← read by: engine architecture
- `DAT_008ac4d8 (RandomCycleCounter)`
- `DAT_008AD254 (StateFlagPair)` ← read by: engine architecture, engine wear damage, file formats, physics dynamics, pit system, session race logic, unknown, vehicle physics
- `DAT_008AD258 (SessionStateFlag)`
- `DAT_008ad384 (SessionInitCompleteFlag)`
- `DAT_008AFE72 (AudioInitSuccessFlag)` ← read by: unknown
- `DAT_008afe78 (NetworkPacketParam)` ← read by: unknown
- `DAT_008AFEA0 (SessionTime)` ← read by: ai system, audio network internals, engine architecture, engine wear damage, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics, weather system
- `DAT_008b0098 (SineLookupWorkspace)`
- `DAT_008B009C (ConversionState)` ← read by: renderer, session race logic
- `DAT_008B00A0 (FPUControlStore)` ← read by: audio network internals, math utilities, renderer, unknown
- `DAT_008B0108 (AudioCodecInitFlag)` ← read by: audio network internals, math utilities, renderer
- `DAT_008B6C20 (RendererStateFlag)` ← read by: math utilities, renderer, session race logic
- `DAT_008B8DBC (AudioStreamHandleA)` ← read by: session race logic, unknown
- `DAT_008B8DC0 (StreamHandleB)` ← read by: session race logic, unknown
- `DAT_008B8E40 (AudioMixFixedPointConst)` ← read by: math utilities
- `DAT_008B8E4C (MipLODBiasCount)` ← read by: renderer
- `DAT_008b8ed8 (AudioPlaybackRate)`
- `DAT_008B8EFC (SetterParamStore2)`
- `DAT_008B8F00 (AudioSystemCallback)` ← read by: session race logic
- `DAT_008B8F08 (Unknown_Triple_Store)`
- `DAT_008b8f0c (AudioStreamHandle_2)` ← read by: math utilities, renderer
- `DAT_008B8F10 (ObjMgrParam)`
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` ← read by: engine architecture, file formats, math utilities, physics collision, physics dynamics, renderer, session race logic, unknown, vehicle physics
- `DAT_008B8F28 (UIRootContextPtr)` ← read by: audio network internals, engine architecture, file formats, math utilities, physics dynamics, renderer, session race logic, unknown
- `DAT_008d3e84 (CRTArgc)`
- `DAT_008d3e88 (CmdLineArgv)`
- `DAT_008d3ea0 (CmdLineArgvPtr)`
- `DAT_008D3F98 (CurrentLocaleID)` ← read by: file formats
- `DAT_008D3FB1 (Unknown_Byte_Config)`
- `DAT_008D3FB4 (LocaleLanguageID)` ← read by: file formats
- `DAT_008d41b8 (LivePageCounter)`
- `DAT_008D48E8 (Int_HeapReAllocCapacity)` ← read by: file formats
- `DAT_008d48f4 (HeapFreeListCount)` ← read by: math utilities, session race logic
- `DAT_008d48f8 (HeapBlockCounter)` ← read by: file formats, math utilities, session race logic
- `DAT_008D48FC (LocaleConvBuffer)` ← read by: file formats, math utilities, session race logic
- `DAT_008D4900 (HeapMaxAllocSize)` ← read by: math utilities, session race logic
- `DAT_008D4904 (PrivateHeapHandle)` ← read by: audio network internals, file formats, math utilities, session race logic, unknown
- `DAT_008D4908 (OSVersionCode)` ← read by: audio network internals, math utilities, session race logic
- `DAT_008d4920 (CriticalSectionArray (stride 0x24))` ← read by: engine architecture, file formats, math utilities, session race logic
- `DAT_008D4A20 (OpenFileCount)` ← read by: file formats, math utilities, session race logic

**Reads from other subsystems (54 globals):**
- `DAT_005C753C (Unknown_5C753C)` (owned by unknown)
- `DAT_005D3488 (Collision_RestitutionCoeff)` (owned by unknown)
- `DAT_005d348c (CollisionPenetrationThreshold)` (owned by unknown)
- `DAT_005E5238 (TireTractionConstantSq)` (owned by tire system)
- `DAT_005E5240 (TireTractionConstant)` (owned by tire system)
- `DAT_005E6BD8 (DecimalSeparatorChar)` (owned by audio network internals)
- `DAT_005E6D40 (TlsIndex)` (owned by engine architecture)
- `DAT_005E7758 (TimeBias_MinutesBias)` (owned by file formats)
- `DAT_005e775c (DSTActiveFlag)` (owned by file formats)
- `DAT_005E7760 (DSTOffsetSeconds)` (owned by file formats)
- `DAT_005E9EF4 (RefCount)` (owned by engine architecture)
- `DAT_005ea04c (ReferenceCounter)` (owned by engine architecture)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007CE23C (UIRenderFlags)` (owned by unknown)
- `DAT_007CE2DC (HWnd)` (owned by session race logic)
- `DAT_007D0F94 (GlobalBooleanFlag)` (owned by session race logic)
- `DAT_007D2E50 (SessionMsgCount)` (owned by ai system)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008ab6f0 (AudioBucketListHead)` (owned by session race logic)
- `DAT_008AB700 (FreeListHead)` (owned by session race logic)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008AD3AC (TrackDB_DataPtr)` (owned by unknown)
- `DAT_008ADAF8 (SlotCounter)` (owned by renderer)
- `DAT_008AFC78 (LoadedModuleHandle)` (owned by unknown)
- `DAT_008AFC80 (ModuleFuncPtr)` (owned by unknown)
- `DAT_008AFC84 (CallbackPtr_8AFC84)` (owned by unknown)
- `DAT_008AFC88 (Renderer_CallbackPtr)` (owned by unknown)
- `DAT_008afc8c (FunctionPointer (callback))` (owned by unknown)
- `DAT_008AFE68 (ParticleLifeValue)` (owned by engine architecture)
- `DAT_008AFE7C (RaceFlag_7C)` (owned by unknown)
- `DAT_008B8CEC (Int_AudioQuality)` (owned by renderer)
- `DAT_008B8CF0 (RendererBrightness)` (owned by renderer)
- `DAT_008B8CF4 (AudioMusicVolume)` (owned by renderer)
- `DAT_008B8DC8 (RenderDevicePtr)` (owned by renderer)
- `DAT_008B8E30 (RegisteredEntryCount)` (owned by renderer)
- `DAT_008B8E34 (RenderVisibilityMask)` (owned by renderer)
- `DAT_008B8E48 (AudioChannelCount)` (owned by audio network internals)
- `DAT_008B8EE0 (AudioSystemFlags)` (owned by renderer)
- `DAT_008B8EEC (AudioHalfBufferSize)` (owned by session race logic)
- `DAT_008B8F04 (NetConfigData)` (owned by renderer)
- `DAT_008B8F14 (ObjLinkedListHead)` (owned by renderer)
- `DAT_008D3BFC (ModuleInitListHead)` (owned by session race logic)
- `DAT_008D3C00 (GenericList_Tail)` (owned by session race logic)
- `DAT_008D3C08 (PoolAllocCounter)` (owned by session race logic)
- `DAT_008D3E90 (StringTablePtr)` (owned by file formats)
- `DAT_008d3fa8 (LocaleLanguageStr)` (owned by file formats)
- `DAT_008D3FAC (LocaleLanguageRegionPtr)` (owned by file formats)
- `DAT_008D46BC (CRT_Locale)` (owned by session race logic)
- `DAT_008d5a44 (CmdLinePtr)` (owned by file formats)
- `DAT_008d5a58 (LocaleThreadRefCount)` (owned by unknown)

### physics collision

**Owns — sole writer (110 globals):**
- `DAT_007ca384 (SinLookupTable)`
- `DAT_007CA388 (MaterialPropertyTable)` ← read by: physics collision
- `DAT_007CA3C8 (CollisionRegionType)` ← read by: audio network internals, renderer
- `DAT_007CA3D0 (FloatNegOneSentinel)`
- `DAT_007CA3D4 (HUDThreshold2)` ← read by: tire system
- `DAT_007CA3E8 (AudioEngineDefaultType)` ← read by: audio network internals, renderer
- `DAT_007ca3f0 (SteeringWheelRange)` ← read by: tire system
- `DAT_007ca3f4 (CollisionScaleZ)`
- `DAT_007ca470 (CollisionGridSize (4))` ← read by: audio network internals, renderer
- `DAT_007CA478 (MinusOneSentinel)`
- `DAT_007CA47C (VecInitZero)` ← read by: tire system
- `DAT_007CA490 (CollisionCellInitCount)` ← read by: audio network internals, renderer
- `DAT_007ca498 (RenderStateMinThreshold_498)` ← read by: tire system
- `DAT_007CA49C (CollisionCellScale)`
- `DAT_007CA4D0 (CollisionWorldObjType)` ← read by: renderer
- `DAT_007ca4d4 (CameraInitFloat1)`
- `DAT_007CA4D8 (Sentinel_MinusOne)`
- `DAT_007ca4dc (FloatInit)`
- `DAT_007CA4F8 (SteeringRackTravel)` ← read by: renderer
- `DAT_007CA4FC (Unknown_Float_4FC_Zeroed)`
- `DAT_007CA500 (RenderStateColorValue)`
- `DAT_007ca504 (AudioMixerInitFloat)`
- `DAT_007CA508 (KeyboardLayoutHandle)`
- `DAT_007ca57c (ForceFeedbackGain)` ← read by: renderer
- `DAT_007ca580 (InitState2)`
- `DAT_007ca584 (CollisionBoundMax)`
- `DAT_007ca588 (Flt_Unknown_Render)`
- `DAT_007CCA44 (NodeElementCount)` ← read by: audio network internals, renderer
- `DAT_007CCA4C (CollisionRadiusSentinel)`
- `DAT_007cca50 (UISliderMinThreshold)` ← read by: tire system
- `DAT_007CCA6C (RenderStateInt_9)` ← read by: audio network internals, renderer
- `DAT_007cca74 (DriverStatThreshold)` ← read by: tire system
- `DAT_007cca78 (FloatInit)`
- `DAT_007cca7c (UIElementTypeID)` ← read by: audio network internals, renderer
- `DAT_007cca84 (CameraInitFloat)`
- `DAT_007CCA88 (AudioEngine_MinVol_Type5)` ← read by: tire system
- `DAT_007CCBB0 (CollisionMaterialDefault)` ← read by: audio network internals, renderer
- `DAT_007CCBB8 (RendererClampThreshold)` ← read by: tire system
- `DAT_007CCBBC (MaterialRestCoeff)`
- `DAT_007ccbc0 (KeyboardCharBuffer)`
- `DAT_007CCCD8 (CollisionGridSize)` ← read by: engine architecture, tire system
- `DAT_007CCCDC (SpatialGridState)`
- `DAT_007CCCE0 (CollisionGridParam)`
- `DAT_007ccce4 (AudioState2Block)`
- `DAT_007ccce8 (CollisionGridZeroBlock)`
- `DAT_007CCCEC (CollisionGridState1)`
- `DAT_007CCCF0 (RainBrakeBiasGlobal)` ← read by: engine architecture, tire system
- `DAT_007cccf4 (CollisionStateCounter)`
- `DAT_007cccf8 (CollisionState_7CCCF8)`
- `DAT_007CCCFC (RenderState_Zero_05)`
- `DAT_007ccd00 (ZeroedCollisionState)`
- `DAT_007CCD04 (Unknown_Zeroed_CCD04)`
- `DAT_007CCD08 (CollisionRegionType)` ← read by: engine architecture, tire system
- `DAT_007CCD0C (CollisionRegionParams)`
- `DAT_007ccd10 (CollisionGridField)`
- `DAT_007ccd14 (CollisionConfigField3)`
- `DAT_007ccd18 (VideoMode_Index_2)`
- `DAT_007CCD1C (CollisionRegionParams)`
- `DAT_007CCD20 (CollisionStateBlock11)` ← read by: engine architecture, tire system
- `DAT_007ccd24 (CollisionCellOffsetY)`
- `DAT_007ccd28 (Dword_Unknown_Render)`
- `DAT_007ccd2c (CollisionGridInitZero)`
- `DAT_007ccd30 (CollisionInitBlock)`
- `DAT_007ccd34 (CollisionGridInitZero2)`
- `DAT_007CCD38 (GridNodeElementCount)` ← read by: engine architecture, tire system
- `DAT_007ccd3c (VideoMode_Index)`
- `DAT_007CCD40 (CollisionZeroState)`
- `DAT_007ccd44 (UnknownZeroedState)`
- `DAT_007ccd48 (CollisionInitZeroed)`
- `DAT_007ccd4c (CollisionInit6)`
- `DAT_007CCD50 (CollisionShape_13)` ← read by: engine architecture, tire system
- `DAT_007CCD54 (CollisionBucketState)`
- `DAT_007ccd58 (CollisionGridInitZero)`
- `DAT_007ccd5c (CollisionGridZeroField)`
- `DAT_007ccd60 (CollisionConfigField5)`
- `DAT_007CCD64 (CollisionBucketState)`
- `DAT_007CCF60 (CollisionGlobalCount107)` ← read by: renderer
- `DAT_007CCF68 (CollisionNegOne)`
- `DAT_007CCF6C (UIColorBias_CCF6C)` ← read by: tire system
- `DAT_007CCF70 (CollisionConfigBlock)` ← read by: renderer
- `DAT_007CCF78 (AudioEngine_MinVol_Type10)` ← read by: tire system
- `DAT_007CCF7C (CollisionConfigVars)`
- `DAT_007CCF80 (MaxContactCount)` ← read by: audio network internals, renderer
- `DAT_007CCF88 (CollisionContactSentinel)`
- `DAT_007CCF8C (Flt_CopilotThreshold)` ← read by: tire system
- `DAT_007CCF90 (VehicleSetup_Target_7CCF90)` ← read by: renderer
- `DAT_007CCF98 (VehicleSetupFloat_7CCF98)` ← read by: tire system
- `DAT_007CCF9C (RenderState_OneFloat)`
- `DAT_007ccfa0 (RenderStateID_CFA0)` ← read by: renderer
- `DAT_007ccfa8 (FloatBF800000)`
- `DAT_007ccfac (UIElementFloat_7CCFAC)` ← read by: tire system
- `DAT_007ccfb0 (RenderStateID_S)` ← read by: audio network internals, renderer
- `DAT_007ccfb8 (CollisionInitFloat1)`
- `DAT_007CCFBC (CubemapParam)` ← read by: tire system
- `DAT_007ccfc0 (KeyboardCharBuffer)`
- `DAT_007CD100 (AudioPanInitialValue)` ← read by: tire system
- `DAT_007CD104 (CollisionScale1)`
- `DAT_007CD198 (DefaultCollisionState)` ← read by: audio network internals, renderer
- `DAT_007CD1A0 (AudioMixThreshold)` ← read by: tire system
- `DAT_007cd1a4 (Flt_Unknown_Render)`
- `DAT_007cd208 (Network_ResetFlag_7CD208)`
- `DAT_007CD20C (Sentinel_NegOne)`
- `DAT_007CD264 (GlobalMutexHandle)`
- `DAT_007CD268 (MutexLockState)`
- `DAT_007CD26C (MutexInitFlag)`
- `DAT_007CD460 (CollisionDistanceState)`
- `DAT_007CD464 (CollisionSentinel)`
- `DAT_007CDDF0 (CollisionStateCounters)` ← read by: engine architecture, physics collision
- `DAT_007CDE2C (CollisionSoundHandle)`
- `DAT_007D1490 (ContactForceStateArray)`

**Reads from other subsystems (14 globals):**
- `DAT_005D6D64 (ScreenWidth)` (owned by math utilities)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c5698 (SessionTickCounter)` (owned by engine architecture)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007CA3C0 (ExtendedMaterialTable)` (owned by engine architecture)
- `DAT_007CDE04 (Surface1ResourceHandle)` (owned by math utilities)
- `DAT_007CDE10 (RendererSurfaceHandle)` (owned by math utilities)
- `DAT_007CDE1C (SubsystemInstancePtr)` (owned by math utilities)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008AB700 (FreeListHead)` (owned by session race logic)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B8DC8 (RenderDevicePtr)` (owned by renderer)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008C5F40 (AudioOutputHandle)` (owned by session race logic)

### physics dynamics

**Owns — sole writer (416 globals):**
- `DAT_005e99d0 (IOFunctionPtr)`
- `DAT_005e99d8 (D3DDeviceCallbackPtr)`
- `DAT_005e9a90 (LinkedList_Sentinel)`
- `DAT_005e9a94 (AllocLinkedListPtr)`
- `DAT_005e9a98 (CRT_AllocChainPtr)`
- `DAT_005ec3bc (Dword_Unknown_Setup)`
- `DAT_007C73E8 (DeviceIdentityHandle1)` ← read by: engine architecture, file formats, math utilities, physics dynamics, session race logic, track system, unknown, vehicle physics
- `DAT_007C73EC (InitSentinel_1)`
- `DAT_007C73F0 (GraphicsStateResetBlock)` ← read by: physics dynamics
- `DAT_007C73F4 (InitSentinelValue_Neg1)`
- `DAT_007C73F8 (InitFlagsBlock)` ← read by: physics dynamics
- `DAT_007C73FC (MutexGroupInitNegOne)`
- `DAT_007C7404 (CollisionInitZeroBlock)` ← read by: physics dynamics
- `DAT_007C7408 (PhysicsStateInitBlock)`
- `DAT_007C740C (Unknown_Camera_7C740C)`
- `DAT_007C7410 (Int_RenderListHead)`
- `DAT_007C7418 (InputDeviceListHead)` ← read by: physics dynamics
- `DAT_007C741C (LinkedListTail_7C741C)`
- `DAT_007C7420 (Unknown_List_7C7420)`
- `DAT_007C7424 (InitFlagField_7424)`
- `DAT_007c8884 (VehicleDamageFlag)`
- `DAT_007CA514 (ContactSepNormal)`
- `DAT_007ca518 (VehicleHeatDisplayRear)` ← read by: tire system
- `dword_7CD2AC (0x007cd2ac)` ← read by: engine architecture
- `DAT_008cfbf8 (LDLTWorkspaceA)`
- `DAT_008cfc00 (LDLTWorkspaceBlock)`
- `DAT_008cfc20 (DynSolver_WS_8CFC20)`
- `DAT_008cfc28 (SolverMatrixBlock)`
- `DAT_008cfcc8 (LDLTWorkspaceBlock2)`
- `DAT_008cfce8 (Dbl_DynamicsSolverWk)`
- `DAT_008cfcf0 (DynSolver_WS_8CFCF0)`
- `DAT_008cfdb0 (SolverFactorOutput1)`
- `DAT_008cfdb8 (LDLTWorkspaceC)`
- `DAT_008cfe50 (Dbl_DynamicsSolverWk2)`
- `DAT_008cfe58 (SolverWorkspaceDbl2)`
- `DAT_008cfe70 (LDLT_MatrixElement_B)`
- `DAT_008cfe78 (LDLT_Work_2)`
- `DAT_008cff30 (SolverMatrixTemp)`
- `DAT_008cff48 (LDLT_MatrixElement_C)`
- `DAT_008cff50 (LDLTWorkspace)`
- `DAT_008d0020 (LDLTWorkspaceDouble5)`
- `DAT_008d0028 (LDLTWorkspaceResult)`
- `DAT_008d0108 (DynamicsSolverWorkspace_8D0108)`
- `DAT_008d0290 (DynSolver_WorkDouble)`
- `DAT_008d0418 (SolverWorkspaceDbl6)`
- `DAT_008d0420 (LDLT_MatrixElement_F)`
- `DAT_008d0440 (LDLT_Work_5)`
- `DAT_008d0448 (DynSolver_WorkDouble2)`
- `DAT_008d04e8 (LDLTWorkspace2)`
- `DAT_008d0508 (LDLT_Work_6)`
- `DAT_008d0510 (LDLT_Workspace_8D0510)`
- `DAT_008d05d0 (Dbl_DynamicsSolverWk8)`
- `DAT_008d05d8 (DynSolver_WS_8D05D8)`
- `DAT_008d0670 (LDLT_Work_7)`
- `DAT_008d0678 (DynSolver_WorkDouble3)`
- `DAT_008d0690 (DynSolverOutput_0690)`
- `DAT_008d0698 (Dynamics_Matrix_D0698)`
- `DAT_008d0750 (DynamicsSolverWorkspace_8D0750)`
- `DAT_008d0768 (DynSolverOutput_0768)`
- `DAT_008d0770 (DynamicsWorkTemp)`
- `DAT_008d0840 (LDLT_MatrixElement_J)`
- `DAT_008d0848 (LDLTWorkspace3)`
- `DAT_008D0928 (Unknown_Double_Solver10)`
- `DAT_008d0ab0 (LDLTWorkspaceM)`
- `DAT_008d1f60 (LDLT_Workspace_8D1F60)`
- `DAT_008d1f68 (DynSolver_WriteDouble)`
- `DAT_008d2040 (SolverFactorOutput2)`
- `DAT_008d2120 (ConstraintMatrix00)` ← read by: physics dynamics, unknown
- `DAT_008d21c8 (Cholesky_WorkspaceBase)`
- `DAT_008D21D0 (DynSolver_Matrix_8D21D0)` ← read by: physics dynamics
- `DAT_008D21D8 (DynamicsSolver_DiagBlock1)` ← read by: physics dynamics
- `DAT_008d2278 (DynSolver_WriteDouble_CH)`
- `DAT_008D2280 (DynamicsBlockElement_8D2280)` ← read by: physics dynamics
- `DAT_008D2288 (DynSolverElem_1_2)` ← read by: physics dynamics
- `DAT_008d2290 (DynamicsMatrix_2_2)` ← read by: physics dynamics
- `DAT_008d2328 (CholeskyFactorOut1)`
- `DAT_008D2330 (DynSolver_MatrixBlock3)` ← read by: physics dynamics
- `DAT_008D2338 (DynamicsSolverBlock_8D2338)` ← read by: physics dynamics
- `DAT_008D2340 (SolverBlock_8D2340)` ← read by: physics dynamics
- `DAT_008D2348 (DynamicsBlockElement_8D2348)` ← read by: physics dynamics
- `DAT_008d23d8 (LDLTFactorWorkspaceA)`
- `DAT_008d23e0 (DynamicsMatrix_Block4)` ← read by: physics dynamics
- `DAT_008d23e8 (DynMatrix_8D23E8)` ← read by: physics dynamics
- `DAT_008D23F0 (Dynamics_Block23E0_Elem)` ← read by: physics dynamics
- `DAT_008D23F8 (DynSolver_MatrixBlock4b)` ← read by: physics dynamics
- `DAT_008D2400 (DynamicsSolverElement4_0)` ← read by: physics dynamics
- `DAT_008d2488 (DynSolver_WS_8D2488)`
- `DAT_008D2490 (DynamicsBlock_4)` ← read by: physics dynamics
- `DAT_008D2498 (ConstraintMatrix_8D2498)` ← read by: physics dynamics
- `DAT_008D24A0 (DynamicsBlock_8D24A0)` ← read by: physics dynamics
- `DAT_008d24a8 (DynamicsMatrix_Block8)` ← read by: physics dynamics
- `DAT_008D24B0 (Dyn_SolverBlock_24B0)` ← read by: physics dynamics
- `DAT_008D24B8 (DynamicsBlock_24B8)` ← read by: physics dynamics
- `DAT_008d2538 (LDLTWorkspaceB)`
- `DAT_008d2540 (ConstraintMatrix_Body0_DOF5)` ← read by: physics dynamics
- `DAT_008D2548 (DynSolver_Matrix_8D2548)` ← read by: physics dynamics
- `DAT_008d2550 (SolverBlock_8D2550)` ← read by: physics dynamics
- `DAT_008D2558 (DynamicsBlock_2558)` ← read by: physics dynamics
- `DAT_008D2560 (DynSolverElem_5_2)` ← read by: physics dynamics
- `DAT_008d2568 (DynSolverMatrixElem_8D2568)` ← read by: physics dynamics
- `DAT_008D2570 (Dyn_SolverBlock_2570)` ← read by: physics dynamics
- `DAT_008d25e8 (DynamicsFactorWorkspace_8D25E8)`
- `DAT_008D25F0 (DynamicsMatrixBlock4)` ← read by: physics dynamics
- `DAT_008D25F8 (DynamicsSolver_DiagBlock5)` ← read by: physics dynamics
- `DAT_008D2600 (DynamicsSolverElement2_2)` ← read by: physics dynamics
- `DAT_008d2608 (DynSolverMatrixElem_8D2608)` ← read by: physics dynamics
- `DAT_008D2610 (DynamicsSolverBlock_8D2610)` ← read by: physics dynamics
- `DAT_008D2618 (DynamicsMatrixBlock8)` ← read by: physics dynamics
- `DAT_008D2620 (DynSolverElem_6_0)` ← read by: physics dynamics
- `DAT_008d2628 (DynamicsMatrix_Block10)` ← read by: physics dynamics
- `DAT_008d2630 (SolverMatrixDiag)`
- `DAT_008d2638 (Dynamics_Factor_D2638)`
- `DAT_008d2698 (CholeskyFactorOut2)`
- `DAT_008d26a0 (DynSolver_Block5_Element00)` ← read by: physics dynamics
- `DAT_008D26A8 (DynamicsBlockElement_8D26A8)` ← read by: physics dynamics
- `DAT_008D26B0 (Dyn_SolverBlock_26B0)` ← read by: physics dynamics
- `DAT_008D26B8 (DynamicsMatrixBlock7)` ← read by: physics dynamics
- `DAT_008d26c0 (DynMatrix_8D26C0)` ← read by: physics dynamics
- `DAT_008d26c8 (DynSolver_Block5_Element6)` ← read by: physics dynamics
- `DAT_008D26D0 (DynamicsSolverBlock_8D26D0)` ← read by: physics dynamics
- `DAT_008D26D8 (DynamicsBlock_26D8)` ← read by: physics dynamics
- `DAT_008D26E0 (DynamicsBlock_8D26E0)` ← read by: physics dynamics
- `DAT_008D26E8 (DynamicsSolver_D26E8)`
- `DAT_008d2748 (LDLTFactorWorkspaceB)`
- `DAT_008d2750 (DynamicsMatrix_0_9)` ← read by: physics dynamics
- `DAT_008D2758 (DynSolver_MatrixBlock8b)` ← read by: physics dynamics
- `DAT_008D2760 (DynSolverElem_7_0)` ← read by: physics dynamics
- `DAT_008d2768 (DynSolver_Block6_Element13)` ← read by: physics dynamics
- `DAT_008D2770 (ConstraintMatrix_8D2770)` ← read by: physics dynamics
- `DAT_008d2778 (DynamicsMatrix_2_3)` ← read by: physics dynamics
- `DAT_008d2780 (DynMatrix_8D2780)` ← read by: physics dynamics
- `DAT_008d2788 (DynSolverMatrixElem_8D2788)` ← read by: physics dynamics
- `DAT_008d2790 (SolverBlock_8D2790)` ← read by: physics dynamics
- `DAT_008D2798 (ConstraintMatrix_8D2798)` ← read by: physics dynamics
- `DAT_008d27f8 (Dbl_DynamicsSolverWk25)`
- `DAT_008d2800 (SolverBlock_8D2800)` ← read by: physics dynamics
- `DAT_008D2898 (DynamicsSolverBias1)` ← read by: physics dynamics
- `DAT_008D28A0 (Dyn_SolverBlock_28A0)` ← read by: physics dynamics
- `DAT_008D2930 (DynSolverBlock_3_0)` ← read by: physics dynamics
- `DAT_008d2938 (DynSolverMatrixElem_8D2938)` ← read by: physics dynamics
- `DAT_008D2940 (Dyn_SolverBlock_2940)` ← read by: physics dynamics
- `DAT_008d2948 (DynSolverFactorOut)`
- `DAT_008d2950 (SolverRHSVector)`
- `DAT_008D29C8 (DynamicsSolverBlock_8D29C8)` ← read by: physics dynamics
- `DAT_008D29D0 (DynamicsMatrixBlock10)` ← read by: physics dynamics
- `DAT_008D29D8 (DynSolverElem_3_3)` ← read by: physics dynamics
- `DAT_008d29e0 (DynamicsMatrix_Block11)` ← read by: physics dynamics
- `DAT_008d29e8 (CholeskyWorkspaceC)`
- `DAT_008d2a60 (DynMatrix_8D2A60)` ← read by: physics dynamics
- `DAT_008d2a68 (DynSolver_Block9_Element?)` ← read by: physics dynamics
- `DAT_008D2A70 (DynamicsSolverBlock_8D2A70)` ← read by: physics dynamics
- `DAT_008D2A78 (DynamicsBlock_2A78)` ← read by: physics dynamics
- `DAT_008D2A80 (DynamicsBlock_8D2A80)` ← read by: physics dynamics
- `DAT_008D2AF8 (SolverBlock_8D2AF8)` ← read by: physics dynamics
- `DAT_008d2b00 (DynamicsMatrix_Block12)` ← read by: physics dynamics
- `DAT_008D2B08 (DynamicsSolverBlock_8D2B08)` ← read by: physics dynamics
- `DAT_008d2b10 (DynamicsMatrix_2_7)` ← read by: physics dynamics
- `DAT_008D2B18 (DynSolver_Matrix_8D2B18)` ← read by: physics dynamics
- `DAT_008D2B20 (SolverBlock_8D2B20)` ← read by: physics dynamics
- `DAT_008D2B28 (ConstraintMatrix_8D2B28)` ← read by: physics dynamics
- `DAT_008D2B30 (DynamicsMatrixBlock9)` ← read by: physics dynamics
- `DAT_008D2B38 (DynamicsSolverElement_3_X)` ← read by: physics dynamics
- `DAT_008D2B40 (DynSolver_Matrix_8D2B40)` ← read by: physics dynamics
- `DAT_008d2b70 (DynamicsMatrix_Block13)` ← read by: physics dynamics
- `DAT_008d2b78 (LDLTSolverWorkspaceDouble)`
- `DAT_008d2b80 (LDLTSolverResultBlock)`
- `DAT_008d2ba0 (Dbl_DynamicsSolverWk26)`
- `DAT_008D2C08 (DynamicsMatrix_DiagBlock)` ← read by: physics dynamics
- `DAT_008D2C10 (DynamicsBlock_2C10)` ← read by: physics dynamics
- `DAT_008d2c18 (DynMatrix_8D2C18)` ← read by: physics dynamics
- `DAT_008D2C20 (SolverBlock_8D2C20)` ← read by: physics dynamics
- `DAT_008D2C28 (DynamicsSolver_BlockCol4)` ← read by: physics dynamics
- `DAT_008D2C30 (Dynamics_Block2C08_Elem2)` ← read by: physics dynamics
- `DAT_008D2C38 (DynSolver_Matrix_8D2C38)` ← read by: physics dynamics
- `DAT_008d2c40 (DynSolver_Block11_Element8)` ← read by: physics dynamics
- `DAT_008D2C48 (Dyn_SolverBlock_2C48)` ← read by: physics dynamics
- `DAT_008D2C50 (DynamicsSolver_BlockCol6)` ← read by: physics dynamics
- `DAT_008D2C80 (DynamicsBlock_8_80)` ← read by: physics dynamics
- `DAT_008d2c88 (DynSolver_Block11_Element13)` ← read by: physics dynamics
- `DAT_008d2c90 (FactorWorkspaceDbl1)`
- `DAT_008d2cb0 (CholeskyMatrixTemp)`
- `DAT_008D2D18 (DynamicsBlock_8D2D18)` ← read by: physics dynamics
- `DAT_008d2d20 (DynSolverMatrixElem_8D2D20)` ← read by: physics dynamics
- `DAT_008D2D28 (ConstraintMatrix_8D2D28)` ← read by: physics dynamics
- `DAT_008D2D30 (Dynamics_Block2D18_Elem)` ← read by: physics dynamics
- `DAT_008D2D38 (DynamicsBlockElement_8D2D38)` ← read by: physics dynamics
- `DAT_008D2D40 (DynamicsBlock_8D2D40)` ← read by: physics dynamics
- `DAT_008D2D48 (DynamicsSolver_BlockCol5)` ← read by: physics dynamics
- `DAT_008d2d50 (DynamicsMatrix_3_1)` ← read by: physics dynamics
- `DAT_008D2D58 (DynSolverElem_8_3)` ← read by: physics dynamics
- `DAT_008D2D60 (DynamicsBlockElement_8D2D60)` ← read by: physics dynamics
- `DAT_008d2d90 (ConstraintMatrix_Body3_Row6)` ← read by: physics dynamics
- `DAT_008D2D98 (DynamicsSolver_BlockCol7)` ← read by: physics dynamics
- `DAT_008D2DA0 (ConstraintMatrix_8D2DA0)` ← read by: physics dynamics
- `DAT_008d2dc0 (LDLT_Work_23)`
- `DAT_008D2E28 (DynamicsSolverBias2)` ← read by: physics dynamics
- `DAT_008d2e30 (DynSolver_WriteDouble2_CH)`
- `DAT_008d2e38 (DynamicsFactorWorkspace_8D2E38)`
- `DAT_008d2e48 (DynSolverFactorOut2)`
- `DAT_008d2e50 (SolverSolutionVec)`
- `DAT_008D2EA8 (Dyn_SolverBlock_2EA8)` ← read by: physics dynamics
- `DAT_008D2EB0 (ConstraintMatrix_8D2EB0)` ← read by: physics dynamics
- `DAT_008d2eb8 (CholeskyFactorOut3)`
- `DAT_008d2ec8 (CholeskyWorkspaceD)`
- `DAT_008D2ED0 (Unknown_Double_Cholesky)`
- `DAT_008D2F28 (DynSolverBlock_4_5)` ← read by: physics dynamics
- `DAT_008d2f30 (SolverBlock_8D2F30)` ← read by: physics dynamics
- `DAT_008D2F38 (DynamicsMatrixBlock14)` ← read by: physics dynamics
- `DAT_008d2f48 (LDLTSolverWorkspaceDouble2)`
- `DAT_008d2f50 (LDLTSolverWorkBlock)`
- `DAT_008D2FA8 (ConstraintMatrix_8D2FA8)` ← read by: physics dynamics
- `DAT_008D2FB0 (DynamicsMatrixBlock6)` ← read by: physics dynamics
- `DAT_008D2FB8 (DynSolver_Matrix_8D2FB8)` ← read by: physics dynamics
- `DAT_008D2FC0 (DynamicsBlock_8D2FC0)` ← read by: physics dynamics
- `DAT_008D2FC8 (DynSolver_MatrixBlock11b)` ← read by: physics dynamics
- `DAT_008d2fd0 (SolverBlock_8D2FD0)` ← read by: physics dynamics
- `DAT_008D2FD8 (DynamicsBlockElement_8D2FD8)` ← read by: physics dynamics
- `DAT_008D2FE0 (SolverBlock_8D2FE0)` ← read by: physics dynamics
- `DAT_008D2FE8 (DynamicsSolverBlock_8D2FE8)` ← read by: physics dynamics
- `DAT_008D2FF0 (DynSolver_MatrixBlock11c)` ← read by: physics dynamics
- `DAT_008D3020 (DynamicsMatrixBlock5)` ← read by: physics dynamics
- `DAT_008D3028 (DynamicsBlockElement_8D3028)` ← read by: physics dynamics
- `DAT_008D3030 (DynSolver_Matrix_8D3030)` ← read by: physics dynamics
- `DAT_008D3050 (DynSolver_Workspace_3050)` ← read by: physics dynamics
- `DAT_008D30B8 (DynamicsSolverBlock_8D30B8)` ← read by: physics dynamics
- `DAT_008D30C0 (DynamicsSolverElement_X5)` ← read by: physics dynamics
- `DAT_008d30c8 (DynSolver_Block13_Element?)` ← read by: physics dynamics
- `DAT_008d30d8 (ConstraintMatrix_Body5_6)` ← read by: physics dynamics
- `DAT_008d30e0 (CholeskyMatrixTemp2)`
- `DAT_008d3138 (DynMatrix_8D3138)` ← read by: physics dynamics
- `DAT_008D3140 (Dyn_SolverBlock_3140)` ← read by: physics dynamics
- `DAT_008d3148 (DynamicsMatrix_3_4_col1)` ← read by: physics dynamics
- `DAT_008D3158 (DynamicsMatrixScalar)` ← read by: physics dynamics
- `DAT_008d3160 (DynSolver_Block13_Element24)` ← read by: physics dynamics
- `DAT_008D31B8 (ConstraintMatrix_8D31B8)` ← read by: physics dynamics
- `DAT_008d31c0 (DynamicsMatrix_3_4_col0)` ← read by: physics dynamics
- `DAT_008d31c8 (DynMatrix_8D31C8)` ← read by: physics dynamics
- `DAT_008d31d0 (DynSolverMatrixElem_8D31D0)` ← read by: physics dynamics
- `DAT_008d31d8 (SolverBlock_8D31D8)` ← read by: physics dynamics
- `DAT_008D31E0 (DynSolver_MatrixBlock12b)` ← read by: physics dynamics
- `DAT_008d31e8 (DynamicsMatrix_Block25)` ← read by: physics dynamics
- `DAT_008D31F0 (DynamicsSolver_BlockBody2)` ← read by: physics dynamics
- `DAT_008D3210 (DynamicsSolver_Block64kC)` ← read by: physics dynamics
- `DAT_008d3228 (DynamicsMatrix_3_3)` ← read by: physics dynamics
- `DAT_008D3278 (DynSolver_Workspace_3278)` ← read by: physics dynamics
- `DAT_008D3280 (SolverBlock_8D3280)` ← read by: physics dynamics
- `DAT_008D3288 (ConstraintMatrix_8D3288)` ← read by: physics dynamics
- `DAT_008D3290 (DynamicsMatrixBlock11)` ← read by: physics dynamics
- `DAT_008D3298 (DynamicsSolverElement_X3)` ← read by: physics dynamics
- `DAT_008D32A0 (DynamicsBlock_32A0)` ← read by: physics dynamics
- `DAT_008d32a8 (DynSolverMatrixElem_8D32A8)` ← read by: physics dynamics
- `DAT_008D32B0 (DynamicsBlockElement_8D32B0)` ← read by: physics dynamics
- `DAT_008D32D0 (DynamicsBlockElement_8D32D0)` ← read by: physics dynamics
- `DAT_008D32E8 (SolverBlock_8D32E8)` ← read by: physics dynamics
- `DAT_008D32F0 (DynamicsSolverBias3)` ← read by: physics dynamics
- `DAT_008D3338 (DynamicsSolver_Block64kB)` ← read by: physics dynamics
- `DAT_008D3340 (Dynamics_Block33A8_ElemPre)` ← read by: physics dynamics
- `DAT_008D3348 (DynSolver_Matrix_8D3348)` ← read by: physics dynamics
- `DAT_008d3350 (DynSolver_Block14_Element?)` ← read by: physics dynamics
- `DAT_008D3358 (Dyn_SolverBlock_3358)` ← read by: physics dynamics
- `DAT_008D3360 (DynamicsMatrixBlock12)` ← read by: physics dynamics
- `DAT_008d3368 (DynSolver_Block14_Element?)` ← read by: physics dynamics
- `DAT_008D3370 (DynSolver_MatrixBlock13)` ← read by: physics dynamics
- `DAT_008D3390 (DynSolver_MatrixBlock12)` ← read by: physics dynamics
- `DAT_008D33A8 (DynamicsMatrix_Block24)` ← read by: physics dynamics
- `DAT_008D33B0 (DynSolver_Matrix_8D33B0)` ← read by: physics dynamics
- `DAT_008d33b8 (DynamicsMatrix_3_5)` ← read by: physics dynamics
- `DAT_008D33F8 (DynamicsBlockElement_8D33F8)` ← read by: physics dynamics
- `DAT_008D3400 (DynamicsBlock_8D3400)` ← read by: physics dynamics
- `DAT_008D3408 (DynamicsSolver_BodyBlock1)` ← read by: physics dynamics
- `DAT_008d3410 (DynamicsMatrix_4_0)` ← read by: physics dynamics
- `DAT_008D3418 (DynSolverElem_12_0)` ← read by: physics dynamics
- `DAT_008d3420 (DynamicsMatrix_4_1)` ← read by: physics dynamics
- `DAT_008D3428 (SolverBlock_8D3428)` ← read by: physics dynamics
- `DAT_008d3430 (DynamicsMatrix_Block28)` ← read by: physics dynamics
- `DAT_008d3450 (DynamicsMatrix_Block29)` ← read by: physics dynamics
- `DAT_008D3468 (DynamicsBlock_8D3468)` ← read by: physics dynamics
- `DAT_008D3470 (DynamicsSolver_BodyBlock2)` ← read by: physics dynamics
- `DAT_008D3478 (SolverBlock_8D3478)` ← read by: physics dynamics
- `DAT_008d3480 (DynMatrix_8D3480)` ← read by: physics dynamics
- `DAT_008D34B8 (DynSolver_MatrixBlock13b)` ← read by: physics dynamics
- `DAT_008d34c0 (SolverBlock_8D34C0)` ← read by: physics dynamics
- `DAT_008D34C8 (DynamicsBlockElement_8D34C8)` ← read by: physics dynamics
- `DAT_008D34D0 (SolverBlock_8D34D0)` ← read by: physics dynamics
- `DAT_008D34D8 (DynamicsSolverBlock_8D34D8)` ← read by: physics dynamics
- `DAT_008D34E0 (Dynamics_Block34B8_Elem)` ← read by: physics dynamics
- `DAT_008D34E8 (DynamicsBlock_8D34E8)` ← read by: physics dynamics
- `DAT_008D34F0 (DynamicsBlock_34F0)` ← read by: physics dynamics
- `DAT_008D3510 (DynamicsBlock_11)` ← read by: physics dynamics
- `DAT_008d3528 (SolverBlock_8D3528)` ← read by: physics dynamics
- `DAT_008D3530 (DynamicsBlockElement_8D3530)` ← read by: physics dynamics
- `DAT_008D3538 (Dynamics_Block3528_Elem)` ← read by: physics dynamics
- `DAT_008D3540 (ConstraintMatrix_8D3540)` ← read by: physics dynamics
- `DAT_008d3548 (DynSolverMatrixElem_8D3548)` ← read by: physics dynamics
- `DAT_008d3578 (DynamicsMatrix_3_6)` ← read by: physics dynamics
- `DAT_008d3580 (SolverBlock_8D3580)` ← read by: physics dynamics
- `DAT_008d3588 (DynSolverMatrixElem_8D3588)` ← read by: physics dynamics
- `DAT_008D3590 (DynSolverElem_13_0)` ← read by: physics dynamics
- `DAT_008D3598 (DynamicsSolverBlock_8D3598)` ← read by: physics dynamics
- `DAT_008D35A0 (SolverBlock_8D35A0)` ← read by: physics dynamics
- `DAT_008D35A8 (DynSolverElem_13_2)` ← read by: physics dynamics
- `DAT_008D35B0 (DynamicsBlockElement_8D35B0)` ← read by: physics dynamics
- `DAT_008D35B8 (SolverBlock_8D35B8)` ← read by: physics dynamics
- `DAT_008D35C0 (Dyn_SolverBlock_35C0)` ← read by: physics dynamics
- `DAT_008D35C8 (DynSolver_MatrixBlock13d)` ← read by: physics dynamics
- `DAT_008D35D0 (DynamicsBlock_8D35D0)` ← read by: physics dynamics
- `DAT_008D35D8 (DynSolver_Matrix_8D35D8)` ← read by: physics dynamics
- `DAT_008D35E0 (DynamicsMatrixBlock17)` ← read by: physics dynamics
- `DAT_008d35e8 (SolverBlock_8D35E8)` ← read by: physics dynamics
- `DAT_008D3610 (SolverBlock_8D3610)` ← read by: physics dynamics
- `DAT_008D3618 (DynamicsSolverElement_X4)` ← read by: physics dynamics
- `DAT_008D3620 (DynamicsMatrixBlock13)` ← read by: physics dynamics
- `DAT_008d3628 (DynMatrix_8D3628)` ← read by: physics dynamics
- `DAT_008D3630 (ConstraintMatrix_8D3630)` ← read by: physics dynamics
- `DAT_008D3638 (Dynamics_Block3610_Elem)` ← read by: physics dynamics
- `DAT_008D3640 (DynamicsSolverBlock_8D3640)` ← read by: physics dynamics
- `DAT_008D3648 (DynSolver_MatrixBlock14)` ← read by: physics dynamics
- `DAT_008d3650 (DynamicsMatrix_4_3)` ← read by: physics dynamics
- `DAT_008D3658 (DynamicsSolverElement_X7)` ← read by: physics dynamics
- `DAT_008d3660 (DynamicsMatrix_Block30)` ← read by: physics dynamics
- `DAT_008d3668 (SolverBlock_8D3668)` ← read by: physics dynamics
- `DAT_008D3670 (DynamicsSolver_BodyBlock4)` ← read by: physics dynamics
- `DAT_008d3678 (DynSolver_Block15_Element?)` ← read by: physics dynamics
- `DAT_008D3680 (DynamicsSolverElement_X9)` ← read by: physics dynamics
- `DAT_008D3688 (ConstraintMatrix_8D3688)` ← read by: physics dynamics
- `DAT_008D36A8 (DynamicsMatrix_Block136)` ← read by: physics dynamics
- `DAT_008D36B0 (Dyn_SolverBlock_36B0)` ← read by: physics dynamics
- `DAT_008d36b8 (DynSolver_Block15_Element?)` ← read by: physics dynamics
- `DAT_008D36C0 (DynSolver_Matrix_8D36C0)` ← read by: physics dynamics
- `DAT_008D36C8 (DynamicsSolver_BlockBody3)` ← read by: physics dynamics
- `DAT_008D36D0 (DynamicsBlock_8D36D0)` ← read by: physics dynamics
- `DAT_008d36d8 (DynMatrix_8D36D8)` ← read by: physics dynamics
- `DAT_008d36e0 (DynamicsMatrix_Block31)` ← read by: physics dynamics
- `DAT_008d36e8 (DynSolver_Block15_Element?)` ← read by: physics dynamics
- `DAT_008D36F0 (DynSolverElem_14_1)` ← read by: physics dynamics
- `DAT_008D36F8 (DynamicsBlock_36F8)` ← read by: physics dynamics
- `DAT_008D3700 (DynamicsSolverElement_X8)` ← read by: physics dynamics
- `DAT_008D3708 (DynamicsBlockElement_8D3708)` ← read by: physics dynamics
- `DAT_008d3710 (DynamicsMatrix_4_4_col0)` ← read by: physics dynamics
- `DAT_008D3718 (Dyn_SolverBlock_3718)` ← read by: physics dynamics
- `DAT_008D3720 (DynSolver_Matrix_8D3720)` ← read by: physics dynamics
- `DAT_008d3728 (DynamicsMatrix_Block32b)` ← read by: physics dynamics
- `DAT_008d3730 (FactorWorkspaceDbl2)`
- `DAT_008d3738 (CholeskyMatrixTemp3)`
- `DAT_008D3740 (DynamicsBlock_8D3740)` ← read by: physics dynamics
- `DAT_008D3748 (DynSolverElem_14_0)` ← read by: physics dynamics
- `DAT_008d3750 (DynamicsMatrix_4_5)` ← read by: physics dynamics
- `DAT_008D3758 (DynamicsBlockElement_8D3758)` ← read by: physics dynamics
- `DAT_008D3760 (DynSolver_MatrixBlock14b)` ← read by: physics dynamics
- `DAT_008d3768 (SolverBlock_8D3768)` ← read by: physics dynamics
- `DAT_008D3770 (ConstraintMatrix_8D3770)` ← read by: physics dynamics
- `DAT_008D3778 (DynamicsBlock_3778)` ← read by: physics dynamics
- `DAT_008D3780 (Dynamics_Block3740_Elem)` ← read by: physics dynamics
- `DAT_008D3788 (DynamicsSolverBlock_8D3788)` ← read by: physics dynamics
- `DAT_008d3790 (DynSolverMatrixElem_8D3790)` ← read by: physics dynamics
- `DAT_008D3798 (Dyn_SolverBlock_3798)` ← read by: physics dynamics
- `DAT_008D37A0 (DynSolver_MatrixBlock14c)` ← read by: physics dynamics
- `DAT_008D37A8 (SolverBlock_8D37A8)` ← read by: physics dynamics
- `DAT_008D37B0 (DynSolverElem_14_2)` ← read by: physics dynamics
- `DAT_008D37B8 (DynamicsSolver_BodyBlock5)` ← read by: physics dynamics
- `DAT_008D37C0 (DynamicsBlock_37C0)` ← read by: physics dynamics
- `DAT_008d37c8 (DynSolver_Block16_Element?)` ← read by: physics dynamics
- `DAT_008d37d0 (LDLTWorkspaceC)`
- `DAT_008d37d8 (SolverBlock_8D37D8)` ← read by: physics dynamics
- `DAT_008D37E0 (DynamicsSolverBlock_8D37E0)` ← read by: physics dynamics
- `DAT_008D37E8 (SolverBlock_8D37E8)` ← read by: physics dynamics
- `DAT_008d37f0 (DynamicsMatrix_Block33)` ← read by: physics dynamics
- `DAT_008D37F8 (DynamicsBlock_37F8)` ← read by: physics dynamics
- `DAT_008D3800 (DynamicsSolverElement_X6)` ← read by: physics dynamics
- `DAT_008D3808 (DynSolver_Matrix_8D3808)` ← read by: physics dynamics
- `DAT_008d3810 (DynSolverMatrixElem_8D3810)` ← read by: physics dynamics
- `DAT_008D3818 (DynamicsBlock_8D3818)` ← read by: physics dynamics
- `DAT_008d3820 (DynMatrix_8D3820)` ← read by: physics dynamics
- `DAT_008D3828 (DynamicsMatrixBlock16)` ← read by: physics dynamics
- `DAT_008D3830 (DynSolverElem_14_3)` ← read by: physics dynamics
- `DAT_008d3838 (DynamicsMatrix_Block32)` ← read by: physics dynamics
- `DAT_008D3840 (Dynamics_Block3870_Elem4)` ← read by: physics dynamics
- `DAT_008D3848 (DynamicsSolverBlock_8D3848)` ← read by: physics dynamics
- `DAT_008D3850 (DynamicsBlockElement_8D3850)` ← read by: physics dynamics
- `DAT_008d3858 (DynSolverMatrixElem_8D3858)` ← read by: physics dynamics
- `DAT_008d3860 (DynamicsMatrix_4_5_col0)` ← read by: physics dynamics
- `DAT_008D3868 (Dynamics_Block3870_Elem5)` ← read by: physics dynamics
- `DAT_008D3870 (DynamicsBlock_14)` ← read by: physics dynamics, unknown
- `DAT_008d3878 (DynSolver_Block16_Element?)` ← read by: physics dynamics
- `DAT_008D3880 (DynamicsSolver_DiagBlock6)` ← read by: physics dynamics
- `DAT_008d3888 (SolverBlock_8D3888)` ← read by: physics dynamics
- `DAT_008d3890 (DynamicsMatrix_Block34)` ← read by: physics dynamics
- `DAT_008D3898 (DynamicsSolverElement_X1)` ← read by: physics dynamics
- `DAT_008D38A0 (DynSolver_MatrixBlock14e)` ← read by: physics dynamics
- `DAT_008D38A8 (Dynamics_Block3870_Elem)` ← read by: physics dynamics
- `DAT_008d38b0 (DynMatrix_8D38B0)` ← read by: physics dynamics
- `DAT_008d38b8 (DynamicsMatrix_Block35)` ← read by: physics dynamics
- `DAT_008D38C0 (DynamicsBlock_38C0)` ← read by: physics dynamics
- `DAT_008D38C8 (DynamicsSolverElement_X2)` ← read by: physics dynamics
- `DAT_008D38D0 (DynSolver_MatrixBlock14f)` ← read by: physics dynamics
- `DAT_008D38D8 (Dynamics_Block3870_Elem2)` ← read by: physics dynamics
- `DAT_008d38e0 (DynMatrix_8D38E0)` ← read by: physics dynamics
- `DAT_008D38E8 (DynSolver_Matrix_8D38E8)` ← read by: physics dynamics
- `DAT_008d38f0 (DynMatrix_8D38F0)` ← read by: physics dynamics
- `DAT_008D38F8 (Dynamics_Block3870_Elem3)` ← read by: physics dynamics
- `DAT_008D3900 (DynamicsBlock_8D3900)` ← read by: physics dynamics
- `DAT_008d3908 (DynSolverMatrixElem_8D3908)` ← read by: physics dynamics
- `DAT_008D3910 (Dyn_SolverBlock_3910)` ← read by: physics dynamics
- `DAT_008D3918 (DynamicsSolver_BodyBlock7)` ← read by: physics dynamics
- `DAT_008D3920 (DynamicsMatrixBlock15)` ← read by: physics dynamics
- `DAT_008d3928 (SolverBlock_8D3928)` ← read by: physics dynamics
- `DAT_008D3930 (ConstraintMatrix_8D3930)` ← read by: physics dynamics
- `DAT_008d3938 (DynSolver_Block16_Element?)` ← read by: physics dynamics
- `DAT_008D3940 (DynamicsSolverBlock_8D3940)` ← read by: physics dynamics
- `DAT_008D3948 (DynamicsBlock_3948)` ← read by: physics dynamics
- `DAT_008D3950 (DynamicsBlock_8D3950)` ← read by: physics dynamics
- `DAT_008d3958 (DynMatrix_8D3958)` ← read by: physics dynamics
- `DAT_008D3960 (DynSolver_MatrixBlock14g)` ← read by: physics dynamics
- `DAT_008D3968 (DynamicsMatrixBlock18)` ← read by: physics dynamics
- `DAT_008D3970 (SolverBlock_8D3970)` ← read by: physics dynamics
- `DAT_008D3978 (DynamicsBlock_8D3978)` ← read by: physics dynamics

**Reads from other subsystems (11 globals):**
- `DAT_005E5238 (TireTractionConstantSq)` (owned by tire system)
- `DAT_005E5240 (TireTractionConstant)` (owned by tire system)
- `DAT_007c75c4 (GlobalSpeedTime (double))` (owned by session race logic)
- `DAT_007CE874 (InputModeFlag)` (owned by session race logic)
- `DAT_007CE88C (VehicleModeFlag)` (owned by session race logic)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008D46B4 (NetworkContextPtr)` (owned by engine architecture)

### pit system

**Owns:** none

**Reads from other subsystems (11 globals):**
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c5698 (SessionTickCounter)` (owned by engine architecture)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007CEC30 (ReconPitOpen)` (owned by session race logic)
- `DAT_007ced8c (UIRacePhaseFlag)` (owned by file formats)
- `DAT_007CEE88 (SessionInitFlags)` (owned by file formats)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)

### renderer

**Owns — sole writer (36 globals):**
- `DAT_005D6D70 (EngineBrakeTorqueFactor)` ← read by: unknown
- `DAT_005d6d74 (UnknownFloatSelector)`
- `DAT_005ea5d4 (FileLoadSentinel)`
- `DAT_005ea5d8 (FileEnumSentinel)`
- `DAT_005ea5dc (FileEnumSentinel)`
- `DAT_007ca3e0 (Physics_AntiRoll_NegOne)`
- `DAT_007CA3E4 (RenderParam_7CA3E4)` ← read by: tire system
- `DAT_007CA418 (CollisionRestitution)`
- `DAT_007CA41C (CollisionParamsDefault)`
- `DAT_007CB310 (DeviceCreateResult)`
- `DAT_007cd150 (RenderStateThreshold_150)` ← read by: tire system
- `DAT_007cd154 (FloatOneInit)`
- `DAT_007CD9CC (PoolDescriptorPtr)` ← read by: engine architecture
- `DAT_007CD9D0 (AllocatorHandle)` ← read by: engine architecture
- `DAT_008ADAF8 (SlotCounter)` ← read by: math utilities
- `DAT_008B8CEC (Int_AudioQuality)` ← read by: math utilities
- `DAT_008B8CF0 (RendererBrightness)` ← read by: file formats, math utilities, unknown
- `DAT_008B8CF4 (AudioMusicVolume)` ← read by: file formats, math utilities, unknown
- `DAT_008b8dc4 (AudioMixer_InitFlag)`
- `DAT_008B8DC8 (RenderDevicePtr)` ← read by: engine architecture, math utilities, physics collision, renderer, session race logic, unknown
- `DAT_008b8dcc (RendererStateFlag)`
- `DAT_008b8dd0 (RendererInitZero)`
- `DAT_008B8DD4 (ScreenWidthRatio)` ← read by: engine architecture, file formats, renderer, unknown
- `DAT_008B8DD8 (ScreenHeight)` ← read by: engine architecture, renderer, unknown
- `DAT_008b8de4 (AudioStream_Param4)` ← read by: unknown
- `DAT_008b8dec (AudioStreamLoopFlag)`
- `DAT_008B8E28 (AudioInitialized)` ← read by: renderer, unknown
- `DAT_008B8E30 (RegisteredEntryCount)` ← read by: file formats, math utilities, unknown
- `DAT_008B8E34 (RenderVisibilityMask)` ← read by: engine architecture, math utilities
- `DAT_008B8EE0 (AudioSystemFlags)` ← read by: math utilities, track system
- `DAT_008B8F04 (NetConfigData)` ← read by: math utilities, renderer
- `DAT_008B8F14 (ObjLinkedListHead)` ← read by: math utilities, session race logic, unknown
- `DAT_008B8F1C (NetConfigData)` ← read by: renderer
- `DAT_008b8f20 (ResourceHandle)` ← read by: renderer
- `DAT_008B8F2C (RenderResourceHandle2)` ← read by: engine architecture, renderer, unknown
- `DAT_008cef70 (RenderFrameEndFlag)`

**Reads from other subsystems (46 globals):**
- `DAT_005BE900 (Int_GameStateSubmode)` (owned by file formats)
- `DAT_005d3490 (CockpitUIFloat)` (owned by unknown)
- `DAT_005D3494 (PhysicsStepAccumulator)` (owned by unknown)
- `DAT_005D6D60 (ScreenWidth)` (owned by math utilities)
- `DAT_005D6D64 (ScreenWidth)` (owned by math utilities)
- `DAT_005e69c8 (CharTypeTable)` (owned by math utilities)
- `DAT_005E6BD4 (CharTypeTableVersion)` (owned by math utilities)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c5698 (SessionTickCounter)` (owned by engine architecture)
- `DAT_007CA3C8 (CollisionRegionType)` (owned by physics collision)
- `DAT_007CA3E8 (AudioEngineDefaultType)` (owned by physics collision)
- `DAT_007ca470 (CollisionGridSize (4))` (owned by physics collision)
- `DAT_007CA490 (CollisionCellInitCount)` (owned by physics collision)
- `DAT_007CA4D0 (CollisionWorldObjType)` (owned by physics collision)
- `DAT_007CA4F8 (SteeringRackTravel)` (owned by physics collision)
- `DAT_007ca57c (ForceFeedbackGain)` (owned by physics collision)
- `DAT_007CCA44 (NodeElementCount)` (owned by physics collision)
- `DAT_007CCA6C (RenderStateInt_9)` (owned by physics collision)
- `DAT_007cca7c (UIElementTypeID)` (owned by physics collision)
- `DAT_007CCBB0 (CollisionMaterialDefault)` (owned by physics collision)
- `DAT_007CCF60 (CollisionGlobalCount107)` (owned by physics collision)
- `DAT_007CCF70 (CollisionConfigBlock)` (owned by physics collision)
- `DAT_007CCF80 (MaxContactCount)` (owned by physics collision)
- `DAT_007CCF90 (VehicleSetup_Target_7CCF90)` (owned by physics collision)
- `DAT_007ccfa0 (RenderStateID_CFA0)` (owned by physics collision)
- `DAT_007ccfb0 (RenderStateID_S)` (owned by physics collision)
- `DAT_007CD198 (DefaultCollisionState)` (owned by physics collision)
- `DAT_007CE23C (UIRenderFlags)` (owned by unknown)
- `DAT_007d084c (UIPercentageSlider)` (owned by session race logic)
- `DAT_007D0FC4 (RaceSetupByte_0FC4)` (owned by session race logic)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008ACEDC (ParticleIndexCounter)` (owned by unknown)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B009C (ConversionState)` (owned by math utilities)
- `DAT_008B00A0 (FPUControlStore)` (owned by math utilities)
- `DAT_008B0108 (AudioCodecInitFlag)` (owned by math utilities)
- `DAT_008B6C20 (RendererStateFlag)` (owned by math utilities)
- `DAT_008B8E4C (MipLODBiasCount)` (owned by math utilities)
- `DAT_008B8EEC (AudioHalfBufferSize)` (owned by session race logic)
- `DAT_008b8f0c (AudioStreamHandle_2)` (owned by math utilities)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)

### session race logic

**Owns — sole writer (83 globals):**
- `DAT_005E77F4 (DateSerialDay)` ← read by: session race logic
- `DAT_005e77f8 (DateTimeThresholdStart)` ← read by: session race logic
- `DAT_005E7804 (SeasonEndDate)` ← read by: session race logic
- `DAT_005E7808 (DateTimeBoundaryValue)` ← read by: session race logic
- `DAT_005f073c (VehiclePitFlags[0x48c0])` ← read by: session race logic
- `DAT_007C54E4 (CurrentVehicleIndex)` ← read by: ai system, engine architecture, file formats, renderer, session race logic, track system, unknown, vehicle physics
- `DAT_007C54E8 (PlayerVehiclePtr)` ← read by: ai system, engine architecture, file formats, math utilities, pit system, renderer, session race logic, track system, unknown, vehicle physics, weather system
- `DAT_007C54F0 (VehiclePtrArray)` ← read by: ai system, engine architecture, file formats, physics collision, pit system, renderer, session race logic, track system, unknown, vehicle physics
- `DAT_007c569c (SessionType5 (5=server))` ← read by: engine architecture, engine wear damage, file formats, physics collision, pit system, session race logic, track system, unknown, vehicle physics
- `DAT_007C74F8 (CameraViewMode)`
- `DAT_007c75c4 (GlobalSpeedTime (double))` ← read by: physics dynamics
- `DAT_007c8b44 (VehicleDynamicsState)`
- `DAT_007c8b48 (VehiclePhysicsInt)`
- `DAT_007cd84d (FilmModeFlag)`
- `DAT_007cd87f (Byte_ReplayFlag)`
- `DAT_007ce270 (RaceStateStruct)`
- `DAT_007ce274 (RaceStateFlag_7CE274)`
- `DAT_007ce27c (SessionResetFlag)`
- `DAT_007ce280 (RaceSessionStateFlag)`
- `DAT_007ce284 (SessionStateWrite42)`
- `DAT_007ce288 (UnknownFlag_7CE288)`
- `DAT_007ce28c (UnknownWriteFlag)`
- `DAT_007ce290 (Setup_Option_7CE290)`
- `DAT_007ce294 (SessionStateByte)`
- `DAT_007CE29C (SessionInitState)`
- `DAT_007ce2a8 (SessionInitStruct)`
- `DAT_007ce2ac (SessionInitGate2)`
- `DAT_007ce2b4 (SessionCatchupGate2)`
- `DAT_007ce2b8 (SessionStateTimer)`
- `DAT_007CE2BC (Unknown_Flag_7CE2BC)`
- `DAT_007ce2c0 (SessionInitFlag)`
- `DAT_007ce2c4 (RaceStateValue_7CE2C4)`
- `DAT_007ce2c8 (RaceStateFlag_7CE2C8)`
- `DAT_007ce2cc (SessionStateWrite43)`
- `DAT_007ce2d4 (Dword_PitState)`
- `DAT_007CE2DC (HWnd)` ← read by: engine architecture, math utilities, unknown
- `DAT_007CE2E0 (Int_WindowState_E2E0)` ← read by: unknown
- `DAT_007CE2E4 (SleepSuppressFlag)` ← read by: engine architecture
- `DAT_007CE874 (InputModeFlag)` ← read by: physics dynamics, session race logic
- `DAT_007CE88C (VehicleModeFlag)` ← read by: physics dynamics, session race logic
- `DAT_007ce97c (TireModelFlag)` ← read by: engine wear damage, session race logic
- `DAT_007CEC30 (ReconPitOpen)` ← read by: ai system, pit system, session race logic, unknown
- `DAT_007cec54 (ReconPitClosed)` ← read by: session race logic, unknown
- `DAT_007ced44 (Flag_DamageDisplay)` ← read by: session race logic
- `DAT_007cf134 (WeatherModeUI (0-5))` ← read by: session race logic
- `DAT_007D0014 (Setup_AIDriverSkill)` ← read by: session race logic, vehicle physics
- `DAT_007d084c (UIPercentageSlider)` ← read by: renderer, session race logic
- `DAT_007d0a44 (GameModePlayerCount)` ← read by: session race logic
- `DAT_007D0D14 (Flag_Unknown_d14)` ← read by: session race logic
- `DAT_007D0E98 (Unknown_Flag_7D0E98)` ← read by: audio network internals, session race logic
- `DAT_007D0EBC (Int_RaceSetupFuelStrat)`
- `DAT_007D0EC0 (Unknown_Flag_7D0EC0)`
- `DAT_007D0EC4 (SessionConfigValue_7D0EC4)` ← read by: session race logic
- `DAT_007D0EC8 (OptionFlagBuffer)` ← read by: session race logic
- `DAT_007D0F4C (Setup_OptionFlag_0F4C)` ← read by: session race logic
- `DAT_007D0F94 (GlobalBooleanFlag)` ← read by: math utilities
- `DAT_007D0FC4 (RaceSetupByte_0FC4)` ← read by: renderer, session race logic
- `DAT_007D2DC8 (RaceResultLinkedList)`
- `DAT_008ab6e4 (ScoringGate (skip if 2))` ← read by: ai system, engine architecture, file formats, math utilities, physics collision, physics dynamics, renderer, session race logic, track system, unknown
- `DAT_008ab6f0 (AudioBucketListHead)` ← read by: math utilities
- `DAT_008ab6f4 (ScoringListTailPtr)`
- `DAT_008ab6f8 (FreeListTailPtr)`
- `DAT_008ab6fc (PhysicsMemoryBlockCount)`
- `DAT_008AB700 (FreeListHead)` ← read by: audio network internals, math utilities, physics collision
- `DAT_008acfe4 (Byte_GameStateFlag)`
- `DAT_008ad008 (NetworkPacketFlag)`
- `DAT_008afedc (NetSessionPacketData)`
- `DAT_008B8EE8 (AudioBufferSize)` ← read by: session race logic, track system
- `DAT_008B8EEC (AudioHalfBufferSize)` ← read by: math utilities, renderer, session race logic
- `DAT_008B8EF0 (AudioBufferDataPtr)` ← read by: session race logic
- `DAT_008B8EF4 (TotalAudioSampleDataSize)` ← read by: session race logic
- `DAT_008B8EF8 (AudioBufferReadyCounter)` ← read by: session race logic
- `DAT_008C5F40 (AudioOutputHandle)` ← read by: physics collision
- `DAT_008C5F44 (UIFocusFlag)`
- `DAT_008D3BFC (ModuleInitListHead)` ← read by: math utilities
- `DAT_008D3C00 (GenericList_Tail)` ← read by: math utilities
- `DAT_008D3C08 (PoolAllocCounter)` ← read by: math utilities
- `DAT_008d3ea8 (FatalErrorGate)`
- `DAT_008d3eac (AppExitFlag)`
- `DAT_008D3F4C (CodePageConversionBuf)`
- `DAT_008d41d4 (CodePageAutoFlag)` ← read by: audio network internals
- `DAT_008D46BC (CRT_Locale)` ← read by: audio network internals, math utilities, session race logic
- `DAT_008d46e0 (CharUpperTable)` ← read by: session race logic

**Reads from other subsystems (54 globals):**
- `DAT_005D6D60 (ScreenWidth)` (owned by math utilities)
- `DAT_005D6D64 (ScreenWidth)` (owned by math utilities)
- `DAT_005e69c8 (CharTypeTable)` (owned by math utilities)
- `DAT_005E6BD4 (CharTypeTableVersion)` (owned by math utilities)
- `DAT_005e775c (DSTActiveFlag)` (owned by file formats)
- `DAT_005E7760 (DSTOffsetSeconds)` (owned by file formats)
- `DAT_005F0730 (DriverTeamIndexTable)` (owned by unknown)
- `DAT_007C56B0 (SessionState_56B0)` (owned by engine architecture)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007CE25D (GlobalFlagA0DA0)` (owned by math utilities)
- `DAT_007CE260 (InitGuard_45d500)` (owned by math utilities)
- `DAT_007CE264 (SessionStateFlag)` (owned by unknown)
- `DAT_007CE269 (SessionInitGate)` (owned by math utilities)
- `DAT_007CE26C (RaceTimerValue)` (owned by math utilities)
- `DAT_007CE2A0 (HInstance)` (owned by engine architecture)
- `DAT_007CEC90 (VehicleLoadState)` (owned by file formats)
- `DAT_007ced8c (UIRacePhaseFlag)` (owned by file formats)
- `DAT_007CEE88 (SessionInitFlags)` (owned by file formats)
- `DAT_007D0798 (RaceSetupScaling)` (owned by engine architecture)
- `DAT_007D2E44 (ScoringGateEnableFlag)` (owned by engine architecture)
- `DAT_007D2E50 (SessionMsgCount)` (owned by ai system)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ac488 (SceneFileCount)` (owned by unknown)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008ACFA0 (HalfDistanceFlag)` (owned by ai system)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AD3EC (SoundEffectArray)` (owned by vehicle physics)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B009C (ConversionState)` (owned by math utilities)
- `DAT_008B6C20 (RendererStateFlag)` (owned by math utilities)
- `DAT_008B8DBC (AudioStreamHandleA)` (owned by math utilities)
- `DAT_008B8DC0 (StreamHandleB)` (owned by math utilities)
- `DAT_008B8DC8 (RenderDevicePtr)` (owned by renderer)
- `DAT_008B8F00 (AudioSystemCallback)` (owned by math utilities)
- `DAT_008B8F14 (ObjLinkedListHead)` (owned by renderer)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008D3E90 (StringTablePtr)` (owned by file formats)
- `DAT_008d3fa8 (LocaleLanguageStr)` (owned by file formats)
- `DAT_008D3FAC (LocaleLanguageRegionPtr)` (owned by file formats)
- `DAT_008d3fc0 (TimeZoneInitFlag)` (owned by file formats)
- `DAT_008d48f4 (HeapFreeListCount)` (owned by math utilities)
- `DAT_008d48f8 (HeapBlockCounter)` (owned by math utilities)
- `DAT_008D48FC (LocaleConvBuffer)` (owned by math utilities)
- `DAT_008D4900 (HeapMaxAllocSize)` (owned by math utilities)
- `DAT_008D4904 (PrivateHeapHandle)` (owned by math utilities)
- `DAT_008D4908 (OSVersionCode)` (owned by math utilities)
- `DAT_008d4920 (CriticalSectionArray (stride 0x24))` (owned by math utilities)
- `DAT_008D4A20 (OpenFileCount)` (owned by math utilities)
- `DAT_008d5a44 (CmdLinePtr)` (owned by file formats)
- `DAT_008D5A48 (ArgvParsedFlag)` (owned by file formats)
- `DAT_008d5a58 (LocaleThreadRefCount)` (owned by unknown)

### tire system

**Owns — sole writer (51 globals):**
- `DAT_005E5238 (TireTractionConstantSq)` ← read by: math utilities, physics dynamics
- `DAT_005E5240 (TireTractionConstant)` ← read by: math utilities, physics dynamics
- `DAT_007CA3AC (VehicleState_Float_03)`
- `DAT_007CA3BC (CollisionAngularVelY)`
- `DAT_007CA3DC (SuspensionBumpTravel)`
- `DAT_007ca408 (RenderStateIntPair)`
- `DAT_007CA430 (CollisionStateField)`
- `DAT_007ca43c (CameraFovScale)`
- `DAT_007ca44c (Renderer_OvershootState_7CA44C)`
- `dword_7CA468 (0x007ca468)`
- `DAT_007ca484 (CollisionStateFloat)`
- `DAT_007ca4b0 (RenderStateDwordPair)`
- `DAT_007ca4c8 (ControlThresholdStore)`
- `DAT_007ca4f0 (WheelSettingCopy_7CA4F0)`
- `DAT_007ca510 (RenderStateFloatPair)`
- `DAT_007CA52C (CollisionGridStateField)`
- `DAT_007ca544 (Dword_Unknown_Render4)`
- `DAT_007ca55c (SoundBank_VolumeFL_Alt)`
- `DAT_007ca574 (VehicleSetupFloat_7CA574)`
- `DAT_007cc9c0 (RenderStateFloatPair)`
- `DAT_007CC9F0 (Unknown_Float_AudioBalance)`
- `DAT_007cca0c (AudioMixThreshold)`
- `DAT_007cca24 (CollisionMiscFloat)`
- `DAT_007cca3c (ControlStateStore)`
- `DAT_007cca64 (AudioMixFloat)`
- `DAT_007CCBF8 (CollisionShape_37_Zero)`
- `DAT_007CCCB4 (CollisionAngularVelX)`
- `DAT_007ccf58 (CollisionStateInitBlock)`
- `DAT_007ccfd4 (CollisionMaterialPairB)`
- `DAT_007ccfe0 (RenderStateFloat_7CCFE0)`
- `DAT_007ccffc (CameraEffectOffset2)`
- `DAT_007cd014 (DamperBoundA)`
- `DAT_007CD02C (CollisionDataBlock)`
- `DAT_007cd044 (Dword_Unknown_Render3)`
- `DAT_007cd05c (WheelSettingCopy_7CD05C)`
- `DAT_007cd074 (SoundBank_VolumeFL)`
- `dword_7CD090 (0x007cd090)`
- `DAT_007CD0A8 (CollisionZeroFlag)`
- `DAT_007cd0c0 (CollisionMaterialConfig)`
- `DAT_007cd0d8 (VehicleSetupFloat_7CD0D8)`
- `DAT_007cd0f0 (CollisionCellCount)`
- `DAT_007cd0fc (AudioMixVolume2)`
- `DAT_007cd10c (AudioMixTargetVolume)`
- `DAT_007cd128 (CameraEffectOffset)`
- `DAT_007CD140 (CollisionGridState)`
- `DAT_007cd14c (RenderStateFloat)`
- `DAT_007CD15C (CollisionInitZero)`
- `DAT_007cd18c (CameraMinClipDist)`
- `DAT_007cd1b8 (Renderer_OvershootState)`
- `DAT_007CD1D0 (VehicleState_DoubleBuffer_08)`
- `DAT_007CD1E8 (Unknown_Float_AudioCh)`

**Reads from other subsystems (38 globals):**
- `DAT_007ca3b0 (VehicleCamberFront)` (owned by globals reference)
- `DAT_007CA3C0 (ExtendedMaterialTable)` (owned by engine architecture)
- `DAT_007CA3D4 (HUDThreshold2)` (owned by physics collision)
- `DAT_007CA3E4 (RenderParam_7CA3E4)` (owned by renderer)
- `DAT_007ca3f0 (SteeringWheelRange)` (owned by physics collision)
- `DAT_007CA444 (HUDTelemetry_Param5)` (owned by engine architecture)
- `DAT_007CA450 (HUDThreshold1)` (owned by math utilities)
- `DAT_007CA47C (VecInitZero)` (owned by physics collision)
- `DAT_007CA48C (RendererFloatState_7CA48C)` (owned by audio network internals)
- `DAT_007ca498 (RenderStateMinThreshold_498)` (owned by physics collision)
- `DAT_007ca518 (VehicleHeatDisplayRear)` (owned by physics dynamics)
- `DAT_007cc9c8 (BrakePedalDeadzone)` (owned by audio network internals)
- `DAT_007CC9F4 (Flt_SuspensionSpring_C9F4)` (owned by vehicle physics)
- `DAT_007cca50 (UISliderMinThreshold)` (owned by physics collision)
- `DAT_007cca74 (DriverStatThreshold)` (owned by physics collision)
- `DAT_007CCA88 (AudioEngine_MinVol_Type5)` (owned by physics collision)
- `DAT_007CCBB8 (RendererClampThreshold)` (owned by physics collision)
- `DAT_007CCC00 (CollisionZeroField)` (owned by math utilities)
- `DAT_007CCCB8 (UIBrightness_CCCB8)` (owned by engine architecture)
- `DAT_007CCCD8 (CollisionGridSize)` (owned by physics collision)
- `DAT_007CCCF0 (RainBrakeBiasGlobal)` (owned by physics collision)
- `DAT_007CCD08 (CollisionRegionType)` (owned by physics collision)
- `DAT_007CCD20 (CollisionStateBlock11)` (owned by physics collision)
- `DAT_007CCD38 (GridNodeElementCount)` (owned by physics collision)
- `DAT_007CCD50 (CollisionShape_13)` (owned by physics collision)
- `DAT_007CCF6C (UIColorBias_CCF6C)` (owned by physics collision)
- `DAT_007CCF78 (AudioEngine_MinVol_Type10)` (owned by physics collision)
- `DAT_007CCF8C (Flt_CopilotThreshold)` (owned by physics collision)
- `DAT_007CCF98 (VehicleSetupFloat_7CCF98)` (owned by physics collision)
- `DAT_007ccfac (UIElementFloat_7CCFAC)` (owned by physics collision)
- `DAT_007CCFBC (CubemapParam)` (owned by physics collision)
- `DAT_007CCFE8 (RenderFloat_CFE8)` (owned by engine architecture)
- `DAT_007CD100 (AudioPanInitialValue)` (owned by physics collision)
- `DAT_007cd110 (UIElementFloat_7CD110)` (owned by engine architecture)
- `DAT_007cd150 (RenderStateThreshold_150)` (owned by renderer)
- `DAT_007CD160 (ZeroedCollisionState)` (owned by unknown)
- `DAT_007CD194 (RearRPMGovernor)` (owned by engine architecture)
- `DAT_007CD1A0 (AudioMixThreshold)` (owned by physics collision)

### track system

**Owns — sole writer (2 globals):**
- `DAT_007CD2A0 (TrackSceneRefreshFlag)`
- `DAT_008AFF00 (SessionReadyFlag)`

**Reads from other subsystems (17 globals):**
- `DAT_005C7530 (GlobalDataStructBase)` (owned by unknown)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007D2E50 (SessionMsgCount)` (owned by ai system)
- `DAT_0083ee54 (SessionDataOffset (stride 0x1b0))` (owned by ai system)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008ac488 (SceneFileCount)` (owned by unknown)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B8EE0 (AudioSystemFlags)` (owned by renderer)
- `DAT_008B8EE8 (AudioBufferSize)` (owned by session race logic)

### unknown

**Owns — sole writer (60 globals):**
- `DAT_005c7520 (HModule_Instance)`
- `DAT_005c7524 (NullPtrSentinel)`
- `DAT_005c7528 (UninitializedData)`
- `DAT_005c752c (Dword_5C752C_Session)`
- `DAT_005C7530 (GlobalDataStructBase)` ← read by: engine wear damage, track system, vehicle physics
- `DAT_005c7534 (CRT_UnknownDword)`
- `DAT_005c7538 (CRTDwordWrite)`
- `DAT_005C753C (Unknown_5C753C)` ← read by: math utilities
- `DAT_005CC9E0 (Flt_UIColorIntensity)`
- `DAT_005d325c (Off5D325C)`
- `DAT_005D3488 (Collision_RestitutionCoeff)` ← read by: math utilities
- `DAT_005d348c (CollisionPenetrationThreshold)` ← read by: math utilities
- `DAT_005d3490 (CockpitUIFloat)` ← read by: renderer
- `DAT_005D3494 (PhysicsStepAccumulator)` ← read by: renderer
- `DAT_005D6798 (BrakeForceConst_5D6798)` ← read by: unknown
- `DAT_005d679c (PedalForceCoeff)` ← read by: unknown
- `DAT_005D67A0 (SteeringForceCoeff)` ← read by: unknown
- `DAT_005D67A4 (AeroDownforceConstant)` ← read by: unknown
- `DAT_005D67A8 (Flt_AiBrakeBiasGain_67A8)` ← read by: unknown
- `DAT_005D67AC (FFBParam_5D67AC)` ← read by: unknown
- `DAT_005d7994 (RendererStateInt)`
- `DAT_005d7998 (RenderStateValue_5D7998)`
- `DAT_005F0730 (DriverTeamIndexTable)` ← read by: session race logic
- `DAT_007CD160 (ZeroedCollisionState)` ← read by: tire system
- `DAT_007CD164 (FrictionRestitutionDefault)`
- `DAT_007CE23C (UIRenderFlags)` ← read by: math utilities, renderer
- `DAT_007CE264 (SessionStateFlag)` ← read by: engine architecture, session race logic, unknown
- `DAT_007CE268 (SessionInitByte)`
- `DAT_008AC398 (TrackNameBuffer)` ← read by: file formats
- `DAT_008AC3E8 (SCNFilePathBuffer)` ← read by: file formats
- `DAT_008AC438 (AIWFilePathBuffer)` ← read by: file formats
- `DAT_008ac488 (SceneFileCount)` ← read by: file formats, session race logic, track system, unknown, vehicle physics
- `DAT_008ac490 (SceneArray (stride 0x18c))` ← read by: engine architecture, file formats, math utilities, renderer, session race logic, track system, unknown, vehicle physics
- `DAT_008ACEDC (ParticleIndexCounter)` ← read by: renderer
- `DAT_008AD3AC (TrackDB_DataPtr)` ← read by: math utilities
- `DAT_008AFC78 (LoadedModuleHandle)` ← read by: math utilities
- `DAT_008AFC7C (CachedFrameCount)`
- `DAT_008AFC80 (ModuleFuncPtr)` ← read by: math utilities
- `DAT_008AFC84 (CallbackPtr_8AFC84)` ← read by: math utilities
- `DAT_008AFC88 (Renderer_CallbackPtr)` ← read by: math utilities
- `DAT_008afc8c (FunctionPointer (callback))` ← read by: math utilities
- `DAT_008AFE7C (RaceFlag_7C)` ← read by: math utilities
- `DAT_008afebc (PhysicsIntWrite)`
- `DAT_008aff80 (WaypointDistArray)`
- `DAT_008AFF84 (Unknown_Float_AFF84)`
- `DAT_008AFF88 (UnknownFloat_8AFF88)`
- `DAT_008aff8c (FloatWritten_8AFF8C)`
- `DAT_008aff90 (Unknown_Float_8AFF90)`
- `DAT_008aff94 (Flt_Unknown_Physics)`
- `DAT_008affa4 (UnknownSessionFloat)`
- `DAT_008affa8 (Unknown_Setup_8AFFA8)`
- `DAT_008affac (PitEntryCheckFloat)`
- `DAT_008affb0 (UnknownPhysicsFloat)`
- `DAT_008affb4 (Unknown_Setup_Flag)`
- `DAT_008affb8 (UnknownSetupFloat)`
- `DAT_008cfae4 (StringParseCursor)`
- `DAT_008d3c14 (DynSolver_InitDword)`
- `DAT_008d41dc (CRTInitFlag)`
- `DAT_008d41e0 (LocaleModulePtr)`
- `DAT_008d5a58 (LocaleThreadRefCount)` ← read by: audio network internals, math utilities, session race logic

**Reads from other subsystems (56 globals):**
- `DAT_005D6D60 (ScreenWidth)` (owned by math utilities)
- `DAT_005D6D64 (ScreenWidth)` (owned by math utilities)
- `DAT_005D6D68 (FrameTimeLast)` (owned by math utilities)
- `DAT_005D6D70 (EngineBrakeTorqueFactor)` (owned by renderer)
- `DAT_005E6730 (CRTFunctionTable)` (owned by math utilities)
- `DAT_005e69c8 (CharTypeTable)` (owned by math utilities)
- `DAT_005E6BD4 (CharTypeTableVersion)` (owned by math utilities)
- `DAT_005E6BD8 (DecimalSeparatorChar)` (owned by audio network internals)
- `DAT_005E7978 (HeapMarker)` (owned by math utilities)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007CE2A0 (HInstance)` (owned by engine architecture)
- `DAT_007CE2DC (HWnd)` (owned by session race logic)
- `DAT_007CE2E0 (Int_WindowState_E2E0)` (owned by session race logic)
- `DAT_007CEC30 (ReconPitOpen)` (owned by session race logic)
- `DAT_007cec54 (ReconPitClosed)` (owned by session race logic)
- `DAT_007CEC90 (VehicleLoadState)` (owned by file formats)
- `DAT_007ced8c (UIRacePhaseFlag)` (owned by file formats)
- `DAT_007CEE88 (SessionInitFlags)` (owned by file formats)
- `DAT_007D0798 (RaceSetupScaling)` (owned by engine architecture)
- `DAT_007D2E50 (SessionMsgCount)` (owned by ai system)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ab6e4 (ScoringGate (skip if 2))` (owned by session race logic)
- `DAT_008AC4C4 (InitStatus)` (owned by engine architecture)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AD3EC (SoundEffectArray)` (owned by vehicle physics)
- `DAT_008AFE68 (ParticleLifeValue)` (owned by engine architecture)
- `DAT_008AFE6C (ParticleArrayCurrentIndex)` (owned by engine architecture)
- `DAT_008AFE70 (RaceByteFlag)` (owned by engine architecture)
- `DAT_008AFE72 (AudioInitSuccessFlag)` (owned by math utilities)
- `DAT_008afe78 (NetworkPacketParam)` (owned by math utilities)
- `DAT_008AFE84 (Unknown_Race_DynamicsValue)` (owned by engine architecture)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B00A0 (FPUControlStore)` (owned by math utilities)
- `DAT_008B8CF0 (RendererBrightness)` (owned by renderer)
- `DAT_008B8CF4 (AudioMusicVolume)` (owned by renderer)
- `DAT_008B8DBC (AudioStreamHandleA)` (owned by math utilities)
- `DAT_008B8DC0 (StreamHandleB)` (owned by math utilities)
- `DAT_008B8DC8 (RenderDevicePtr)` (owned by renderer)
- `DAT_008B8DD4 (ScreenWidthRatio)` (owned by renderer)
- `DAT_008B8DD8 (ScreenHeight)` (owned by renderer)
- `DAT_008b8de4 (AudioStream_Param4)` (owned by renderer)
- `DAT_008B8E28 (AudioInitialized)` (owned by renderer)
- `DAT_008B8E30 (RegisteredEntryCount)` (owned by renderer)
- `DAT_008B8F14 (ObjLinkedListHead)` (owned by renderer)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)
- `DAT_008B8F28 (UIRootContextPtr)` (owned by math utilities)
- `DAT_008B8F2C (RenderResourceHandle2)` (owned by renderer)
- `DAT_008d2120 (ConstraintMatrix00)` (owned by physics dynamics)
- `DAT_008D3870 (DynamicsBlock_14)` (owned by physics dynamics)
- `DAT_008D3E28 (SocketAsyncWindowHandle)` (owned by audio network internals)
- `DAT_008D4904 (PrivateHeapHandle)` (owned by math utilities)

### vehicle physics

**Owns — sole writer (6 globals):**
- `DAT_007c56c4 (CostDisplayModeBackup)`
- `DAT_007CC9F4 (Flt_SuspensionSpring_C9F4)` ← read by: tire system
- `DAT_007CC9F8 (CollisionMaterialCoeff)`
- `DAT_008AD3EC (SoundEffectArray)` ← read by: session race logic, unknown
- `DAT_008ad3f0 (Network_JoinFlag_8AD3F0)`
- `DAT_008ad3f4 (Dword_8AD3F4)`

**Reads from other subsystems (14 globals):**
- `DAT_005C7530 (GlobalDataStructBase)` (owned by unknown)
- `DAT_007C54E4 (CurrentVehicleIndex)` (owned by session race logic)
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_007C54F0 (VehiclePtrArray)` (owned by session race logic)
- `DAT_007c569c (SessionType5 (5=server))` (owned by session race logic)
- `DAT_007C73E8 (DeviceIdentityHandle1)` (owned by physics dynamics)
- `DAT_007D0014 (Setup_AIDriverSkill)` (owned by session race logic)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008ac488 (SceneFileCount)` (owned by unknown)
- `DAT_008ac490 (SceneArray (stride 0x18c))` (owned by unknown)
- `DAT_008AD254 (StateFlagPair)` (owned by math utilities)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)
- `DAT_008B8F24 (D3DDeviceWrapperPtr)` (owned by math utilities)

### weather system

**Owns:** none

**Reads from other subsystems (4 globals):**
- `DAT_007C54E8 (PlayerVehiclePtr)` (owned by session race logic)
- `DAT_0083EE60 (RingBufferCount)` (owned by ai system)
- `DAT_008AAE64 (RingBufferWritePtr)` (owned by ai system)
- `DAT_008AFEA0 (SessionTime)` (owned by math utilities)

## Orphan Globals (no static writer found)

These are written at runtime (config loading, OS callbacks, DLL init) or the writer is inlined/indirect.

| Global | Readers | Ref count |
|--------|---------|-----------|
| DAT_005ea438 (unknown directory/file path) | ai system, audio network internals, engine architecture, file formats, math utilities, physics dynamics, pit system, renderer, session race logic, struct offsets, tire system, track system, unknown, vehicle physics | 431 |
| DAT_0059e440 (ZeroThreshold (~0.0f, physics clamp)) | ai system, audio network internals, engine architecture, engine wear damage, file formats, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, tire system, track system, unknown, vehicle physics, weather system | 334 |
| DAT_0059e43c (physics constant) | ai system, audio network internals, engine wear damage, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, struct offsets, track system, unknown, vehicle physics, weather system | 208 |
| DAT_0059E450 (DegreesToRadians) | ai system, audio network internals, engine architecture, engine wear damage, file formats, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics, weather system | 146 |
| DAT_008AD25C (DebugMessageBuffer) | engine architecture, engine wear damage, file formats, math utilities, pit system, session race logic, struct offsets, track system, unknown, vehicle physics | 122 |
| DAT_0059E420 (BaseDoubleConstant) | audio network internals, engine architecture, engine wear damage, file formats, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, tire system, track system, unknown, vehicle physics | 99 |
| DAT_007c56a4 (SessionType (7=race)) | ai system, audio network internals, engine architecture, engine wear damage, file formats, math utilities, pit system, renderer, session race logic, track system, unknown, vehicle physics | 99 |
| DAT_0059E430 (ZeroSentinel) | ai system, audio network internals, engine wear damage, file formats, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics | 86 |
| DAT_005ec4c0 (EmptyStringBuffer) | ai system, audio network internals, engine architecture, engine wear damage, file formats, math utilities, pit system, renderer, session race logic, track system, unknown, vehicle physics | 74 |
| DAT_008afe64 (RaceTimeDelta) | audio network internals, engine architecture, file formats, math utilities, physics collision, pit system, renderer, session race logic, track system, unknown, vehicle physics | 73 |
| DAT_008B78A0 (SoundManager) | audio network internals, engine architecture, file formats, math utilities, physics dynamics, renderer, session race logic, unknown | 73 |
| DAT_005EC4CC (MessageDisplayBuffer) | ai system, audio network internals, engine architecture, engine wear damage, file formats, pit system, renderer, session race logic, track system, unknown, vehicle physics | 71 |
| DAT_005ea618 (PointerTableEntry) | ai system, engine architecture, physics dynamics, pit system, renderer, session race logic, track system, unknown | 63 |
| DAT_0059E880 (HalfStep) | audio network internals, engine wear damage, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics | 52 |
| DAT_008AC368 (VehicleSetupBase) | ai system, engine architecture, file formats, math utilities, pit system, renderer, session race logic, struct offsets, track system, unknown, vehicle physics | 49 |
| DAT_007CD25C (GameModuleManager) | audio network internals, engine architecture, file formats, math utilities, physics collision, pit system, renderer, session race logic, track system, unknown | 48 |
| DAT_008ACEE0 (ForceFeedbackBase) | ai system, engine architecture, engine wear damage, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics | 48 |
| DAT_005BE860 (PathFormatString) | audio network internals, engine architecture, file formats, renderer, session race logic, track system, unknown, vehicle physics | 47 |
| DAT_008aae70 (RingBufferCounter (QA/weather noise)) | ai system, audio network internals, engine wear damage, math utilities, physics collision, pit system, renderer, session race logic, track system, unknown, vehicle physics | 47 |
| DAT_007C56A8 (RacePhase) | ai system, pit system, renderer, session race logic, track system, unknown, vehicle physics | 43 |
| DAT_007ce498 (AutoLoadConfigFile) | ai system, engine architecture, file formats, math utilities, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 42 |
| DAT_007cf3c8 (TrackConditionState) | ai system, physics dynamics, pit system, renderer, session race logic, track system, unknown | 42 |
| DAT_007D0308 (RaceActiveFlag) | ai system, physics dynamics, pit system, session race logic, track system, unknown | 42 |
| DAT_0059e7f8 (AntiRollMixingFactor) | ai system, audio network internals, engine architecture, math utilities, physics collision, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics, weather system | 39 |
| DAT_007d2db0 (RaceStandingsSortBuffer) | ai system, file formats, math utilities, session race logic, track system, unknown | 39 |
| DAT_008AFE88 (CollisionGeometryHandle) | audio network internals, engine architecture, math utilities, physics collision, pit system, renderer, session race logic, track system, unknown, vehicle physics | 38 |
| DAT_0059E670 (SentinelFlagConstant) | ai system, audio network internals, math utilities, physics collision, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 36 |
| DAT_005EA510 (SessionManager) | engine architecture, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown, weather system | 35 |
| DAT_007CDE00 (Unknown_Render_CDE00) | audio network internals, engine architecture, file formats, math utilities, physics collision, renderer, session race logic, unknown | 35 |
| DAT_005EC6D0 (DataTable_5EC6D0) | ai system, engine architecture, file formats, physics collision, session race logic, track system, unknown, vehicle physics | 34 |
| DAT_0059E478 (SteeringCenterBoost) | ai system, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, struct offsets, track system, unknown, weather system | 32 |
| DAT_0059E800 (AmplitudeLimit) | ai system, audio network internals, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, unknown, vehicle physics | 32 |
| DAT_005EB978 (GameStatePtrArray3) | ai system, engine architecture, engine wear damage, math utilities, physics dynamics, pit system, session race logic, unknown, vehicle physics, weather system | 32 |
| DAT_005ea2c0 (SetupScenePtr) | ai system, engine architecture, math utilities, physics dynamics, renderer, session race logic, track system, unknown | 31 |
| DAT_007CD204 (ResourceDispatch_007CD204) | ai system, engine architecture, math utilities, pit system, session race logic, track system, unknown, vehicle physics | 31 |
| DAT_008ac394 (VehicleArray (stride 0x424)) | ai system, engine architecture, file formats, math utilities, renderer, session race logic, tire system, track system, unknown, vehicle physics | 31 |
| DAT_008AFE18 (GameRacePhaseTimer) | engine architecture, math utilities, physics collision, renderer, session race logic, track system, unknown | 31 |
| DAT_0059E444 (FrameDelta) | ai system, math utilities, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics, weather system | 30 |
| DAT_007C7428 (RaceTimeElapsed) | ai system, engine architecture, math utilities, physics collision, physics dynamics, session race logic, unknown, vehicle physics | 30 |
| DAT_0059E46C (TireSlipOffset) | ai system, audio network internals, math utilities, physics collision, physics dynamics, pit system, renderer, session race logic, unknown | 29 |
| DAT_005ec3d8 (SeasonDir) | engine architecture, file formats, pit system, renderer, session race logic, track system, unknown | 29 |
| DAT_008AC494 (SceneArrayFirstSceneName) | engine architecture, math utilities, session race logic, track system, unknown | 29 |
| DAT_005c3280 (ConfigParseTokenList) | audio network internals, engine architecture, file formats, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown | 28 |
| DAT_0059E84C (VelocityRateLimit) | ai system, audio network internals, engine architecture, engine wear damage, physics collision, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 27 |
| DAT_007CD8C0 (GameCommandDispatchInterface) | engine architecture, file formats, math utilities, session race logic, track system, unknown, vehicle physics | 27 |
| DAT_008AAE74 (TrigLookup256) | ai system, audio network internals, engine wear damage, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown, vehicle physics | 27 |
| DAT_0059e7e8 (TimeScalingConstant) | ai system, audio network internals, engine architecture, engine wear damage, math utilities, physics collision, pit system, renderer, session race logic, unknown, vehicle physics | 26 |
| DAT_007CE24D (SessionTransitionFlag) | engine architecture, math utilities, physics collision, session race logic, track system, unknown | 26 |
| DAT_0059E7EC (ZeroConstant) | ai system, audio network internals, math utilities, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 25 |
| DAT_0059E448 (TileSteppingMultiplier) | ai system, audio network internals, engine architecture, engine wear damage, math utilities, physics collision, physics dynamics, renderer, session race logic, struct offsets, track system, unknown, vehicle physics | 24 |
| DAT_005ec6d8 (PlayerDataPath) | ai system, file formats, math utilities, physics collision, physics dynamics, renderer, session race logic, track system, unknown, weather system | 24 |
| DAT_007ce234 (DriverAppearanceFlag) | ai system, engine architecture, math utilities, physics collision, renderer, session race logic, unknown, vehicle physics | 24 |
| DAT_007CE254 (DisableHUDFlag) | engine architecture, engine wear damage, math utilities, renderer, session race logic, track system, unknown | 24 |
| DAT_008AB274 (WeatherNoiseTable) | audio network internals, engine wear damage, physics collision, renderer, session race logic, track system, unknown, vehicle physics | 24 |
| DAT_008AD3B4 (GameDataDir) | engine architecture, file formats, pit system, session race logic, unknown | 24 |
| DAT_00800000 (MMXFlag) | math utilities, physics collision, renderer, unknown | 23 |
| DAT_0059FEC8 (AlphaChannelMultiplier) | audio network internals, math utilities, renderer, session race logic, unknown | 22 |
| DAT_005BE828 (FileModeRb) | audio network internals, engine architecture, file formats, math utilities, unknown | 22 |
| DAT_007CA590 (ModulePtrArray) | engine architecture, file formats, math utilities, physics collision, renderer, session race logic, track system, unknown | 22 |
| DAT_008ACEA0 (ScoringGridBase) | engine architecture, math utilities, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 22 |
| DAT_007CE048 (RaceSessionState) | engine architecture, engine wear damage, math utilities, pit system, renderer, session race logic, unknown, vehicle physics | 21 |
| DAT_008ac388 (VehicleFilePathBuffer) | ai system, file formats, math utilities, renderer, session race logic, track system, unknown | 21 |
| DAT_005e6768 (NullSubDispatcher) | engine architecture, file formats, math utilities, session race logic | 20 |
| DAT_005EA560 (GlobalInstance_5EA560) | engine architecture, file formats, math utilities, session race logic, vehicle physics | 20 |
| DAT_008AB6EC (ScoringDataPtr) | physics dynamics, renderer, session race logic, track system, unknown | 20 |
| DAT_008AD298 (SessionModeIdentifier) | engine architecture, math utilities, physics dynamics, pit system, renderer, session race logic, track system | 20 |
| DAT_0059E5FC (FrameRateCorrectionFactor) | ai system, audio network internals, math utilities, physics collision, physics dynamics, renderer, session race logic, track system, unknown | 19 |
| DAT_0059E8A4 (ReverseGearThrottleMult) | ai system, engine architecture, math utilities, pit system, renderer, session race logic, unknown | 19 |
| DAT_005ADB14 (DegreeWrap360) | audio network internals, math utilities, renderer, session race logic, unknown | 19 |
| DAT_005E6788 (AssetBankVTable) | engine architecture, math utilities, session race logic | 19 |
| DAT_005EA5E8 (MemoryCleanupList3) | ai system, file formats, math utilities, renderer, session race logic, track system, unknown | 19 |
| DAT_008ACF8C (TotalRaceLaps) | ai system, file formats, math utilities, renderer, session race logic, unknown, vehicle physics | 19 |
| DAT_0059e460 (AlphaScaleFactor) | audio network internals, math utilities, physics dynamics, renderer, session race logic, unknown | 18 |
| DAT_0059E7FC (BumpDampingConstant) | ai system, engine wear damage, math utilities, physics dynamics, session race logic, track system, vehicle physics, weather system | 18 |
| DAT_0059EB50 (InputScaleFactor) | physics dynamics, session race logic, track system, unknown, vehicle physics | 18 |
| DAT_005E6748 (DynamicsVTable) | engine architecture, math utilities | 18 |
| DAT_007CE2A4 (Unknown_Session_7CE2A4) | engine architecture, math utilities, session race logic, track system, unknown | 17 |
| DAT_005C2C18 (FmtStr_PercentS) | file formats, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown | 16 |
| DAT_005c30b4 (ConfigSubstringToken) | engine architecture, file formats, renderer, session race logic, unknown, vehicle physics | 16 |
| DAT_005C5CE4 (SourceDevPathStr) | track system, unknown | 16 |
| DAT_007C9360 (Unknown_Struct_7C9360) | physics collision, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 16 |
| DAT_008ac390 (VehicleFileCount) | ai system, file formats, session race logic, unknown | 16 |
| DAT_0059E6F8 (SignedShortScale) | ai system, engine architecture, engine wear damage, math utilities, physics collision, physics dynamics, renderer, unknown | 15 |
| DAT_0059e824 (AIDynamicsThreshold) | ai system, audio network internals, engine wear damage, file formats, math utilities, pit system, session race logic, unknown | 15 |
| DAT_0059E8B4 (ClampUpperThreshold) | ai system, audio network internals, engine wear damage, renderer, session race logic, track system, vehicle physics, weather system | 15 |
| DAT_0059E8CC (WheelSpeedThreshold) | ai system, engine wear damage, file formats, math utilities, physics dynamics, pit system, renderer, session race logic, track system, unknown | 15 |
| DAT_005EA4E8 (RandomOffsetFlag) | engine architecture, math utilities, session race logic, unknown | 15 |
| DAT_007CE64C (GameFilterDataPath) | ai system, file formats, renderer, session race logic, track system, unknown | 15 |
| DAT_008AFEE8 (TrackGripBase) | ai system, engine wear damage, math utilities, physics dynamics, pit system, session race logic, track system, unknown | 15 |
| DAT_0059E868 (SteeringResponseGain) | ai system, audio network internals, math utilities, physics collision, renderer, session race logic, track system, vehicle physics | 14 |
| DAT_0059E8C8 (Physics_ConvergenceThreshold) | ai system, engine wear damage, math utilities, physics collision, physics dynamics, renderer, session race logic, unknown, vehicle physics | 14 |
| DAT_0059E8EC (SpeedDeadzone) | ai system, math utilities, physics collision, physics dynamics, session race logic, unknown | 14 |
| DAT_005c6784 (sFormatPath) | audio network internals, renderer, session race logic, track system, unknown | 14 |
| DAT_007ce5d0 (CurrentTrackPath) | engine architecture, file formats, renderer, session race logic, track system, unknown | 14 |
| DAT_008B5A3C (AudioEntryArray) | file formats, math utilities, renderer, unknown | 14 |
| DAT_0059E600 (SteeringForceThreshold) | ai system, physics collision, session race logic, unknown | 13 |
| DAT_0059E8D8 (BrakingSpeedThreshold3) | ai system, math utilities, physics dynamics, pit system, renderer, session race logic | 13 |
| DAT_005B9C38 (SetupConstantValue) | engine architecture, file formats, math utilities, session race logic | 13 |
| DAT_005EA43C (SetupDirSuffix) | engine architecture, physics collision, session race logic, track system, unknown | 13 |
| DAT_005ec428 (SeasonName) | engine architecture, file formats, renderer, session race logic, track system, unknown | 13 |
| DAT_007ce24c (CriticalSection) | audio network internals, engine architecture, file formats, math utilities, session race logic, track system, unknown | 13 |
| DAT_007CE5EC (SettingsFilePath) | ai system, engine architecture, session race logic, track system, vehicle physics | 13 |
| DAT_008ACF90 (RaceTimeOffset) | ai system, engine wear damage, renderer, session race logic, unknown | 13 |
| DAT_008D3F48 (DefaultCodePage) | file formats, math utilities, renderer, session race logic | 13 |
| DAT_0059E4E8 (PhysicsScale_E4E8) | ai system, audio network internals, engine wear damage, math utilities, renderer, session race logic, weather system | 12 |
| DAT_0059EA60 (DampingFactorB) | engine wear damage, physics collision, physics dynamics, session race logic, unknown, vehicle physics | 12 |
| DAT_005C2AAC (BackslashChar) | ai system, file formats, math utilities, session race logic, unknown, vehicle physics | 12 |
| DAT_005C2D64 (SessionConfigFile) | track system, unknown | 12 |
| DAT_005c32d8 (HotExtension (.HOT)) | ai system, file formats, math utilities, renderer, session race logic, track system, unknown | 12 |
| DAT_005EA3FC (TrackRefSpeed) | ai system, math utilities, pit system, session race logic, unknown | 12 |
| DAT_008AB710 (UIWidgetList) | engine architecture, math utilities, physics dynamics, renderer, session race logic, track system, unknown | 12 |
| DAT_0059E7D8 (ThermalInflectionThreshold) | engine architecture, engine wear damage, physics collision, physics dynamics, pit system, session race logic, track system, unknown | 11 |
| DAT_0059E98C (AccelerationTuningFactor) | math utilities, physics collision, physics dynamics, renderer, session race logic, unknown, vehicle physics | 11 |
| DAT_0059EAC8 (ThermalTempOffset) | engine wear damage, physics dynamics, unknown, vehicle physics | 11 |
| DAT_0059F118 (RaceTimeThreshold) | engine wear damage, math utilities, physics collision, pit system, session race logic, unknown | 11 |
| DAT_005EC440 (SettingsDirectory) | ai system, file formats, renderer, session race logic, unknown, vehicle physics | 11 |
| DAT_007ce958 (TireModelMode) | engine architecture, physics dynamics, session race logic, tire system, unknown | 11 |
| DAT_008D3F38 (DefaultLocale) | audio network internals, math utilities, renderer, session race logic | 11 |
| DAT_008D4210 (ExceptionTypeDesc) | engine architecture, math utilities | 11 |
| DAT_008D42A0 (ExceptionTypeDescriptor) | engine architecture, math utilities | 11 |
| DAT_008D43C8 (LocaleManagementStruct) | engine architecture, math utilities | 11 |
| DAT_008d4400 (DynamicsSolverBase_8D4400) | engine architecture, math utilities | 11 |
| DAT_008D4440 (DynamicsConstraintData) | engine architecture, math utilities | 11 |
| DAT_008D4568 (ExceptionTypeDescriptor) | engine architecture, math utilities | 11 |
| DAT_0059E890 (YawErrorToleranceRad) | ai system, engine wear damage, file formats, physics collision, physics dynamics, session race logic, track system, unknown, vehicle physics | 10 |
| DAT_0059E908 (CollisionEventThreshold) | ai system, audio network internals, math utilities, session race logic, unknown, weather system | 10 |
| DAT_005BEB48 (PathSepWord) | audio network internals, file formats, math utilities, track system, unknown | 10 |
| DAT_005D3624 (SourcePath_25) | track system, unknown | 10 |
| DAT_005EB10C (SoundSystemPtr) | physics dynamics, session race logic, unknown | 10 |
| DAT_005EF9A0 (VehicleGridArray) | audio network internals, engine architecture, file formats, physics collision, physics dynamics, renderer, session race logic, track system | 10 |
| DAT_007CE814 (QualifyingDSQEnabled) | file formats, pit system, session race logic, vehicle physics | 10 |
| DAT_007cea5c (EngineWearMode (0/2/3)) | ai system, engine wear damage, session race logic, unknown, vehicle physics | 10 |
| DAT_007CF2CC (DSPTransformParam) | math utilities, physics dynamics, renderer, unknown | 10 |
| DAT_007CF884 (DetailLevel) | math utilities, pit system, renderer, tire system, unknown | 10 |
| DAT_007D0398 (PhotoFreeCameraFlag) | ai system, engine architecture, file formats, math utilities, session race logic, track system, unknown | 10 |
| DAT_007d0434 (SeasonPath) | file formats, renderer, session race logic, track system, unknown | 10 |
| DAT_008AC4C8 (AudioMixerPtr) | audio network internals, math utilities, renderer, session race logic | 10 |
| DAT_008AFEC0 (Unknown_Setup_FEC0) | engine architecture, math utilities, physics dynamics, pit system, session race logic, unknown | 10 |
| DAT_008AFEEC (TrackGripComparison) | math utilities, physics dynamics, pit system, session race logic, track system, unknown | 10 |
| DAT_008D4248 (DynamicsBlock_8D4248) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008D42D8 (ExceptionTypeInfo) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008D4330 (ExceptionTypeDescriptor) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008d4370 (DynamicsWorkBuffer) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008D4478 (LocaleDataReference) | engine architecture, math utilities | 10 |
| DAT_008D44B8 (DynamicsSolver_BasePtr) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008D4510 (DynamicsSolverWorkspace_4510) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_008D45A0 (CleanupContextData) | engine architecture, math utilities, physics dynamics | 10 |
| DAT_0059E65C (CameraShakeMultiplier) | engine architecture, math utilities, pit system, renderer, track system, unknown | 9 |
| DAT_0059E6E8 (TireDampingBlendFactor) | ai system, math utilities, physics collision, physics dynamics, session race logic | 9 |
| DAT_0059e7e0 (LookupThreshold_14) | ai system, engine architecture, engine wear damage, math utilities, physics collision, physics dynamics, track system, unknown, vehicle physics | 9 |
| DAT_0059E864 (ColorQuantScale) | ai system, audio network internals, physics dynamics, renderer, session race logic | 9 |
| DAT_0059E87C (TimeStepMultiplier) | ai system, engine architecture, physics collision, pit system, track system, unknown | 9 |
| DAT_0059e9c0 (TimeConversionFactor) | math utilities, physics collision, session race logic, unknown | 9 |
| DAT_0059ED18 (ForceReductionFactor) | engine wear damage, physics dynamics, renderer, session race logic, unknown, vehicle physics | 9 |
| DAT_005AF900 (AngleConstantPair1) | math utilities, physics dynamics, renderer | 9 |
| DAT_005C3590 (DevicePath_99_02) | engine architecture, unknown | 9 |
| DAT_005CC79C (HashTableHead) | engine architecture, math utilities, session race logic, track system, unknown | 9 |
| DAT_005CCEF0 (FormatString) | math utilities, renderer, session race logic, unknown | 9 |
| DAT_007C56AC (EnableFlag) | math utilities, renderer, session race logic, track system, unknown, vehicle physics | 9 |
| DAT_007ca594 (WheelBrakeBiasThreshold) | math utilities, physics collision, session race logic, unknown | 9 |
| DAT_007CB218 (InputDeviceCount) | engine architecture, file formats, math utilities, renderer, session race logic, unknown | 9 |
| DAT_007cd9d8 (Unknown_Race_7CD9D8) | math utilities, unknown | 9 |
| DAT_008AC4B0 (SceneCameraParam) | engine architecture, math utilities, renderer, session race logic, weather system | 9 |
| DAT_008B89A0 (GameDeviceObject) | engine architecture, file formats, math utilities, session race logic | 9 |
| DAT_0059E428 (NaNInvalidSentinel) | math utilities, physics dynamics, track system, vehicle physics | 8 |
| DAT_0059E468 (BrakingZoneSpeedThreshold2) | ai system, physics collision, pit system, session race logic, unknown | 8 |
| DAT_0059E4DC (FullResponseThreshold) | math utilities, physics collision, pit system, renderer, unknown, vehicle physics | 8 |
| DAT_0059E4E0 (ForceIncrementClamp) | ai system, audio network internals, math utilities, physics dynamics, renderer, session race logic, unknown | 8 |
| DAT_0059EA08 (CollisionSkinThickness) | physics collision, physics dynamics, pit system, renderer, session race logic, track system, vehicle physics | 8 |
| DAT_0059F120 (IntensityMultiplier) | math utilities, session race logic | 8 |
| DAT_005ACCD0 (RGBChannelScaleR) | math utilities, renderer, session race logic | 8 |
| DAT_005ACCD4 (ChannelDecodeScale) | math utilities, renderer, session race logic | 8 |
| DAT_005af8f0 (SSEZeroThreshold) | math utilities, physics dynamics | 8 |
| DAT_005AF988 (PackedMathOne) | audio network internals, math utilities, physics dynamics | 8 |
| DAT_005C36F0 (Token_R) | ai system, file formats, renderer, unknown, vehicle physics | 8 |
| DAT_005c596c (sTrue) | tire system, track system, unknown | 8 |
| DAT_005CC4F4 (Str_UI_CompareToken_CC4F4) | math utilities, tire system, unknown | 8 |
| DAT_005e7898 (DefaultBufferDescriptor) | math utilities, session race logic | 8 |
| DAT_005EC3D0 (SeasonParentPath) | engine architecture, math utilities, session race logic, track system | 8 |
| DAT_007CDB70 (StringCompareBuffer_007CDB70) | math utilities, unknown | 8 |
| DAT_007D0B64 (FuelMult) | engine wear damage, file formats, session race logic, unknown, vehicle physics | 8 |
| DAT_008ACF94 (RaceTimeThreshold) | ai system, renderer, session race logic, unknown | 8 |
| DAT_008AD3B0 (FileSearchData) | file formats, session race logic, unknown | 8 |
| DAT_008AFEF0 (GlobalForceReference) | engine wear damage, physics dynamics, pit system, session race logic, vehicle physics | 8 |
| DAT_0059E6FC (RGBChannelMultiplier) | math utilities, renderer, session race logic, track system | 7 |
| DAT_0059E708 (SoundVolumeLowThreshold) | math utilities, physics dynamics, renderer, session race logic, track system | 7 |
| DAT_0059E774 (ShortToFloatScale) | math utilities, session race logic, unknown, vehicle physics | 7 |
| DAT_0059E77C (ShortVertexScale) | audio network internals, math utilities, session race logic, vehicle physics | 7 |
| DAT_0059e86c (FloatToInt64Scale) | ai system, renderer, session race logic, track system, unknown | 7 |
| DAT_0059E874 (AITurnInSpeedThreshold) | ai system, audio network internals, engine wear damage, renderer, session race logic, track system | 7 |
| DAT_0059E920 (SuspensionAntirollFactor) | ai system, physics dynamics, renderer, session race logic, track system, unknown, vehicle physics | 7 |
| DAT_0059E9E0 (ColorChannelScaleFactor) | ai system, audio network internals, math utilities, renderer, session race logic | 7 |
| DAT_0059EB28 (Damper2MaxAdd) | engine wear damage, physics collision, physics dynamics, track system | 7 |
| DAT_0059EED0 (BrightnessMultiplierRB) | math utilities, physics collision, physics dynamics, renderer, session race logic, unknown | 7 |
| DAT_005AC108 (TexDecompress_1_15th) | math utilities, physics collision, physics dynamics, session race logic | 7 |
| DAT_005AC988 (UVCoordScaleFactor) | audio network internals, math utilities, physics collision, renderer, session race logic, vehicle physics | 7 |
| DAT_005ACCD8 (DXT_GreenChannelScale) | math utilities, renderer, session race logic | 7 |
| DAT_005ACCDC (AlphaChannelScale) | math utilities, renderer, session race logic | 7 |
| DAT_005ADE40 (NearZeroEpsilonPtr) | math utilities, physics dynamics, renderer, unknown | 7 |
| DAT_005C25B4 (Str_Team_Toyota) | file formats, unknown | 7 |

*(showing top 200 of 6909 orphan globals by reference count)*
