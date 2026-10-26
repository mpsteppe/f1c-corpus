## RaceCommentaryDirectorSystem_0040d4c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDelegation (0040dd30), CinematicEventStateMachine (0040ddf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0xC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 2 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | 18446744073709551615 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d950 | jpt_40D72B | R | [LLM] |
| 005be9b4 | aCrowd | R | CrowdString [DERIVED] |
| 005be9bc | aWeather_0 | R | WeatherString [DERIVED] |
| 005be9c4 | aTrackInfo | R | TrackInfoFormatString [DERIVED] |
| 005be9d0 | aWelcomeToCount | R | WelcomeToCountryString [DERIVED] |
| 005be9e4 | aGreeting | R | GreetingField [DERIVED] |
| 005be9f0 | aCommentary | R | Commentary_Commentary [DERIVED] |
| 005be9fc | aPlayer_0 | R | String_Player_0 [DERIVED] |
| 005bea08 | aDriver_0 | R | sDriver [DERIVED] |
| 005bea10 | aPosition_0 | R | PositionString [DERIVED] |
| 005bea1c | aCamera | R | CameraString [DERIVED] |
| 005bea24 | aNo | R | NoString [DERIVED] |
| 005bea28 | aWait_0 | R | String_Wait [DERIVED] |
| 005bea30 | aIterations | R | s_Iterations [DERIVED] |
| 005bea3c | aTime | R | Time [DERIVED] |
| 005bea44 | aProbability | R | ProbabilityField [DERIVED] |
| 005bea50 | aScriptEnd | R | ScriptEndString [DERIVED] |
| 005bea5c | aWait | R | WaitString [DERIVED] |
| 005bea64 | aGridwalk | R | GridwalkString [DERIVED] |
| 005bea70 | aFlyOver | R | Str_FlyOver [DERIVED] |
| 005bea7c | aCommentaryStop | R | StringCommentaryStop [DERIVED] |
| 005bea8c | aCommentaryStar | R | CommentaryStarString [DERIVED] |
| 005beaa0 | aCameraSetLast | R | CameraSetLastString [DERIVED] |
| 005beab0 | aCameraReleaseC | R | CameraReleaseCamString [DERIVED] |
| 005beac8 | aCameraAcquireC | R | CameraAcquireCFmt [DERIVED] |
| 005beae0 | aCameraTargetSe | R | CameraTargetSetString [DERIVED] |
| 005beaf8 | aCameraSelect | R | CameraSelectField [DERIVED] |
| 005beb08 | aType_0 | R | Commentary_Type [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d490 | StructFieldInit | [LLM] |
| 0040db00 | CameraTargetNameResolver | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00587ece | sub_587ECE | [LLM] |
| 00587f59 | SingleFunctionCallWrapper_7f59 | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 0058850f | sub_58850F | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2C | == | 0 | [LLM] |
| this | 0x2C | >= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
