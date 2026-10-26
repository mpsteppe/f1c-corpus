## TelemetryDataDump_004d4a80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 1 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 005c2ab0 | unk_5C2AB0 | R | ConfigDirectoryPath [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c55cc | aClutch | R | sClutch [DERIVED] |
| 005c565c | aBrake | R | ComponentNameBrake [DERIVED] |
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005c6f30 | aSteering | R | SteeringString [DERIVED] |
| 005c6f6c | aThrottle | R | String_Throttle [DERIVED] |
| 005d43dc | aOilTemperature | R | String_OilTemperature [DERIVED] |
| 005d43ec | aWaterTemperatu | R | WaterTemperature [DERIVED] |
| 005d4400 | aGear | R | Gear [DERIVED] |
| 005d4408 | aCornerWeight | R | CornerWeightField [DERIVED] |
| 005d4418 | aTyreWear | R | TyreWearString [DERIVED] |
| 005d4424 | aTyrePressureKp | R | TyrePressureKpString [DERIVED] |
| 005d4438 | aTyreRightTempK | R | TyreRightTempKString [DERIVED] |
| 005d444c | aTyreCenterTemp | R | Str_TyreCenterTemp [DERIVED] |
| 005d4464 | aTyreLeftTempK | R | StringTyreLeftTempK [DERIVED] |
| 005d4478 | aUndertrayRideH | R | UndertrayRideHeightString [DERIVED] |
| 005d4494 | aSuspensionDefl | R | SuspensionDeflString [DERIVED] |
| 005d44b0 | aWheelspinRadsS | R | WheelspinRadsString [DERIVED] |
| 005d44c4 | aRr | R | RrStr [DERIVED] |
| 005d44c8 | aRl | R | RLString [DERIVED] |
| 005d44cc | aFr | R | FrField [DERIVED] |
| 005d44d0 | aFl | R | aFl [DERIVED] |
| 005d44d4 | aUnfilteredClut | R | String_UnfilteredClut [DERIVED] |
| 005d44e8 | aUnfilteredStee | R | UnfilteredSteeString [DERIVED] |
| 005d44fc | aUnfilteredBrak | R | UnfilteredBrakeString [DERIVED] |
| 005d4510 | aUnfilteredThro | R | UnfilteredThrottle [DERIVED] |
| 005d4524 | aClutchRpm | R | ClutchRpm [DERIVED] |
| 005d4530 | aEngineRpm | R | EngineRpmField [DERIVED] |
| 005d453c | aLongAccelMS | R | LongAccelMSString [DERIVED] |
| 005d4550 | aVertAccelMS | R | VertAccelMSString [DERIVED] |
| 005d4564 | aLatAccelMS | R | LatAccelMSString [DERIVED] |
| 005d4574 | aYawRads | R | Str_YawRads [DERIVED] |
| 005d4580 | aPosZM | R | StringPosZM [DERIVED] |
| 005d458c | aPosYM | R | PosYMFormat [DERIVED] |
| 005d4598 | aPosXM | R | PosXMString [DERIVED] |
| 005d45a4 | aElapsedTimeS | R | ElapsedTimeString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56b8 | dword_7C56B8 | R | SessionHashSeed [DERIVED] |
| 007c935c | flt_7C935C | R | TelemetryBrakeFloat [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007ce9d0 | dword_7CE9D0 | R | Unknown_Int_7CE9D0 [DERIVED] (also: ` — telemetry enable flag) |
| 007ce9f4 | dword_7CE9F4 | R | PitCrewAnimState [DERIVED] (also: ` — telemetry gate flag) |
| 007cea34 | dword_7CEA34 | R | PitCrewLHSFlag [DERIVED] |
| 008aae70 | dword_8AAE70 | R | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008aced8 | dword_8ACED8 | R | TerrainINICRCOffset [DERIVED] (also: ` — CRC offset constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | [LLM] |
| 0042ddd0 | ScoreSlotDeallocator | [LLM] |
| 0042e320 | SessionStructInit | [LLM] |
| 004b3c60 | DeterministicHashPseudoRandomGenerator | [LLM] |
| 004ceef0 | sub_4CEEF0 | [LLM] |
| 004d5840 | ResourceDestroy | [LLM] |
| 004d5af0 | FileReadWithXORDecode | [LLM] |
| 004d5be0 | sub_4D5BE0 | [LLM] |
| 004f34e0 | TireModelDataInit | [LLM] |
| 004f4270 | TheSvmHdvVehicleFileParser | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568a60 | UtilityFunction_8a60 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 005881c0 | __alloca_probe | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |
| 00588678 | FileReadWrapperWithLock | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
