## RaceCommentaryDirectorSystem_0040d4c0 — CommentaryDirectorStateInit

**Summary:** Initializes a broadcast/commentary director state machine from a configuration data block, parsing action types (camera, commentary, gridwalk, flyover, etc.), target entities, timing, and probability fields. Part of the race broadcast/cinematic commentary system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDelegation (0040dd30), CinematicEventStateMachine (0040ddf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | configDataPtr — pointer to the commentary config data block |
| this | 0xC | RW | 1065353216 → 1.0f | probability — event trigger probability (0.0–1.0) |
| this | 0x10 | RW | 0 | timeValue — duration or delay time in seconds |
| this | 0x14 | RW | 2 | timeMode — 1=relative (starts with '+'), 2=absolute time |
| this | 0x18 | RW | 0 | iterations — number of times to repeat the event (minimum 1) |
| this | 0x20 | RW | — | waitFlag — if set, event waits (does not auto-advance) |
| this | 0x24 | RW | 0 | actionType — director action type (0–12: camera, commentary, flyover, etc.) |
| this | 0x28 | RW | 18446744073709551615 | targetEntityId — target camera/vehicle entity ID (-1 = none) |
| this | 0x2C | RW | 0 | resultCode — init result: -1 = failed, 0 = unset, 2/4 = success |

**Written-by note (persistence):**
- this 0x4: written once on init — external poke may persist until re-init
- this 0xC: written once on init — external poke may persist until re-init
- this 0x10: written once on init — external poke may persist until re-init
- this 0x14: written once on init — external poke may persist until re-init
- this 0x18: written once on init — external poke may persist until re-init
- this 0x20: written once on init — external poke may persist until re-init
- this 0x24: written once on init — external poke may persist until re-init
- this 0x28: written once on init — external poke may persist until re-init
- this 0x2C: written once on init — external poke may persist until re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d950 | jpt_40D72B | R | jump table for switch dispatch on actionType |
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
| 0040d490 | StructFieldInit | resets all director state fields to default/zero values |
| 0040db00 | CameraTargetNameResolver | resolves a camera target name string to an internal camera entity ID |
| 00567970 | DataEntryAccessor | dereferences a linked-list config node to return its data payload |
| 005679c0 | StringKeyedLinkedListSearch | searches the config linked list for a node by string key |
| 00587ece | sub_587ECE | parses an integer value from a config data string |
| 00587f59 | SingleFunctionCallWrapper_7f59 | parses a single integer/float value from config data |
| 00588410 | sub_588410 | string-contains / field-exists check — tests if a key is present in config data |
| 0058850f | sub_58850F | parses a float value from config data string |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2C | == | 0 | resultCode — if 0 after type parsing, short-circuits to skip parsing sub-fields |
| this | 0x2C | >= | 0 | resultCode — if >= 0 after all parsing, sets iterations=0 when targetEntityId==4 |

**Guard interpretation:** Two guards on resultCode: (1) If actionType parses to 0 (ScriptEnd), resultCode stays 0 → skips Probability/Time/Iterations/Wait parsing entirely and jumps to the switch. (2) At the end, if resultCode >= 0 and targetEntityId equals 4 (error/unresolved), iterations is forced to 0 to prevent the action from executing. The function returns 1 (success) if resultCode != -1, otherwise returns 0 after resetting state.

(End of file - total 91 lines)
