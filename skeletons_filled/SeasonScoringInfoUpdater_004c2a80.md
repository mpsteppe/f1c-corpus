## SeasonScoringInfoUpdater_004c2a80 — SeasonScoringProcessor

**Summary:** Updates season scoring statistics during a race session. Accumulates player vehicle laps/minimum speed into track scene nodes, applies running average filters, and evaluates race completion scoring criteria (90% race distance, vehicle state, championship mode). Integrates with file-based season scoring data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0760 (004a0760), Steward_Post (004d4600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 005d2804 | aSeasonscoringi | R | sSeasonScoringInfo [DERIVED] — "SeasonScoringInfo" file/section key |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] — player vehicle data base |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — checked for 7 (Race) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — checked for 3 or 4 |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] — must not equal 2 |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — scene array index |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — scene data array base |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] — total race laps for 90% threshold |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] — game data directory for file access |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | validate scoring gate conditions |
| 004c28d0 | TrackSceneNodeAdd | add/find track scene node for scoring data |
| 004c2be0 | Accumulator | accumulate player vehicle value into total |
| 004c2c00 | ArithmeticComparison_2c00 | compare and evaluate scoring result |
| 004c2c20 | SimpleCounterIncrement | increment session counter when vehicle state == 1 |
| 004c2cb0 | MovingAverageFilterWithClamp | apply moving average filter to vehicle data |
| 00567970 | DataEntryAccessor | access data entry value from linked list node |
| 005679a0 | NullCheckWrapper | null-check and wrap argument pointer |
| 00568210 | AudioChannelStop | validate file/section access for season scoring |
| 00587bdc | CRTFtol | convert float to long (for 90% race distance) |
| 00587ece | sub_587ECE | parse/convert data entry to integer |

**Guard conditions:** ScoringGateCheck must pass AND dword_8AB6E4 != 2. Scene pointer must be non-null for TrackSceneNodeAdd. Node from TrackSceneNodeAdd must be non-null for lap/time accumulation. SessionType == 7 gates the race-specific block. ChampionshipMode == 3 or 4 gates final scoring evaluation. Inner guard for scoring file read: vehicle state at dword_7C54E8+0x4064 != 3, accumulated laps >= 90% of TotalRaceLaps, and AudioChannelStop must return non-zero.
