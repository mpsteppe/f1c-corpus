## SessionConfigReader_004c11e0 — SessionConfigParser

**Summary:** Parses session configuration from a scene-order data file. Validates scene order via AudioChannelStop, opens the season races section, loads track scene, copies scene path strings into session object, and reads QualifyLaps/QualifyTime/RaceLaps/RaceTime values (defaulting to -1 if keys missing). Returns pointer to session string buffer at offset 0xB130.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C1050 (004c1050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB130 | RW | 18446744073709551615 | session string buffer 1 (path/name), returned pointer |
| this | 0xB134 | RW | 18446744073709551615 | session string buffer 2 (path/name) |
| this | 0xB138 | RW | 18446744073709551615 | QualifyLaps parsed integer value |
| this | 0xB13C | RW | 18446744073709551615 | QualifyTime parsed integer value |
| this | 0xB140 | RW | 18446744073709551615 | RaceLaps parsed integer value |
| this | 0xB148 | R | — | session count upper bound, compared against index a2 |

**Written-by note (persistence):**
- this 0xB130: set unconditionally via StringCopyWithBufferRealloc — external poke survives
- this 0xB134: set unconditionally via StringCopyWithBufferRealloc — external poke survives
- this 0xB138: set from data if QualifyLaps key found, else -1 — external poke survives
- this 0xB13C: set from data if QualifyTime key found, else -1 — external poke survives
- this 0xB140: set from data if RaceLaps key found, else -1 — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7444 | aRacelaps | R | String_RaceLaps [DERIVED] — "RaceLaps" key string |
| 005d2310 | aRacetime | R | aRacetime [DERIVED] — "RaceTime" key string |
| 005d231c | aQualifylaps | R | Str_QualifyLaps [DERIVED] — "QualifyLaps" key string |
| 005d28b4 | aSceneorder | R | SceneOrderStringConst [DERIVED] — "SceneOrder" string, passed to AudioChannelStop as validation |
| 005d28c0 | aQualifytime | R | QualifytimeString [DERIVED] — "QualifyTime" key string |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — scene array index |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — base of scene data array |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] — passed to AudioChannelStop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | dereference pointer-to-pointer to get string |
| 004c55b0 | TrackSceneLoader | load track scene file |
| 004c5840 | SeasonRacesSectionFinder | find season races section in data file |
| 00566650 | StringCopyWithBufferRealloc | realloc-copy string into managed buffer |
| 00567970 | DataEntryAccessor | access data entry value from linked list node |
| 005679a0 | NullCheckWrapper | null-check and wrap argument pointer |
| 005679c0 | StringKeyedLinkedListSearch | search linked list node by string key |
| 00568210 | AudioChannelStop | validate/initialize audio channel (acts as gate) |
| 00587ece | sub_587ECE | parse/convert data entry to integer |

**Guard conditions:** Three sequential guards: (1) AudioChannelStop must return non-zero, (2) NullCheckWrapper(a2) must return non-null, (3) SeasonRacesSectionFinder must return non-null. Any failure returns 0 immediately. Additionally, each key lookup (QualifyLaps/QualifyTime/RaceLaps/RaceTime) is individually guarded: if key not found, the corresponding field is set to -1 instead of the parsed value.
