## SessionSynchronizer_0045f950 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionResponseStatus (00463cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | 1073741824 → 2.0f | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x374 | RW | 1 | [LLM] |
| this | 0x38C | RW | 0 | [LLM] |
| this | 0x410 | R | — | [LLM] |
| this | 0x3C74 | R | — | [LLM] |
| this | 0x3E14 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x374: [LLM: once/conditional? does external poke survive?]
- this 0x38C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 0059f094 | flt_59F094 | R | PhysicsConstant_59F094 [DERIVED] |
| 0059f11c | flt_59F11C | R | ContactNormalDotThreshold [DERIVED] |
| 005c5e74 | aSDMs | R | SDMsFormat [DERIVED] |
| 005c5e80 | aSynchronizingG | R | SynchronizingGameString [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042bda0 | TimerConversionWithSin | [LLM] |
| 0042cf10 | MultiplayerVehiclePlacement | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | [LLM] |
| 0045e570 | UtilityFunction_e570 | [LLM] |
| 00461530 | FlagBitTest | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 004a0250 | sub_4A0250 | [LLM] |
| 004a0da0 | GlobalFlagSetter | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004f9f60 | TimeOffsetGetter | [LLM] |
| 004f9fc0 | sub_4F9FC0 | [LLM] |
| 0057a610 | AnimationValueFetchWithTiming | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
