## sub_4FC2C0_004fc2c0 — StewardRestart

**Summary:** Initializes/resets the race steward controller — reads race configuration (laps, duration, pit speeds, formation speed, day) from config sections, sets up timing and scoring based on race type/game mode. Source: steward.cpp.

**Called by:** sub_42FFB0 (0042ffb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | RW | 2147483647 | max laps (INT_MAX default, overridden from config) |
| this | 0x94 | RW | 2139095039 | race duration / time limit seconds (FLT_MAX default) |
| this | 0x98 | RW | 2139095039 | race duration display / countdown |
| this | 0x9C | RW | 1065353216 → 1.0f | race progress fraction (laps completed / total) |
| this | 0xA0 | RW | 0 | race active flag |
| this | 0xA1 | RW | 0 | race restart flag |
| this | 0xA2 | RW | 0 | unknown boolean flag |
| this | 0xAF | RW | 0 | unknown flag |
| this | 0xB0 | RW | 1190993920 → 32400.0f | race duration in seconds (9 hours default) |
| this | 0xB4 | RW | 1102169884 → 22.2222f | formation speed in m/s (50 mph default, converted) |
| this | 0xB8 | RW | 1102169884 → 22.2222f | pit road speed in m/s (50 mph default) |
| this | 0xBC | RW | 0 | unknown byte flag |
| this | 0xBD | RW | 0 | unknown byte flag |
| this | 0xC0 | RW | — | random track/day index (set for race type 5) |
| this | 0xC4 | RW | 2139095039 | countdown timer / time-remaining display (FLT_MAX default) |
| this | 0x100 | RW | 0 | restart counter / flag reset |
| this | 0x108 | R | — | unknown |
| this | 0x10C | R | — | unknown |
| this | 0x118 | RW | 0 | unknown counter |
| this | 0x11C | RW | 5 | unknown max/count |
| this | 0x120 | RW | 0 | unknown |
| this | 0x124 | RW | 0 | unknown |
| this | 0x128 | RW | 0 | unknown |
| this | 0x4A8 | RW | 0 | pit window open flag |
| this | 0x4AC | RW | 0 | pit window close flag |

**Written-by note (persistence):**
- this 0x90: written once per restart — survives until next restart
- this 0x94: written once per restart — survives until next restart
- this 0x98: written once per restart — survives until next restart
- this 0x9C: written once per restart — survives until next restart
- this 0xA0: written once per restart — survives until next restart
- this 0xA1: written once per restart — survives until next restart
- this 0xA2: written once per restart — survives until next restart
- this 0xAF: written once per restart — survives until next restart
- this 0xB0: written once per restart — survives until next restart
- this 0xB4: written once per restart — survives until next restart
- this 0xB8: written once per restart — survives until next restart
- this 0xBC: written once per restart — survives until next restart
- this 0xBD: written once per restart — survives until next restart
- this 0xC0: conditional (only race type 5) — survives until next restart
- this 0xC4: written once per restart — survives until next restart
- this 0x100: written once per restart — survives until next restart
- this 0x118: written once per restart — survives until next restart
- this 0x11C: written once per restart — survives until next restart
- this 0x120: written once per restart — survives until next restart
- this 0x124: written once per restart — survives until next restart
- this 0x128: written once per restart — survives until next restart
- this 0x4A8: written once per restart — survives until next restart
- this 0x4AC: written once per restart — survives until next restart

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004fcb1c | jpt_4FC70A | R | jump table for race-type switch (dword_75CBB0) |
| 004fcb28 | byte_4FCB28 | R | unknown |
| 004fcb34 | jpt_4FC799 | R | jump table for race-type sub-switch (cases 1-6) |
| 005d5710 | dbl_5D5710 | R | double constant (session timing) |
| 005d5c78 | flt_5D5C78 | R | float constant |
| 005d5db8 | dbl_5D5DB8 | R | double constant |
| 005ea86c | flt_5EA86C | R | float constant |
| 005ea870 | dbl_5EA870 | R | double constant |
| 005fbe14 | aSeasonraces | R | config section name "SeasonRaces" |
| 005fd340 | NumOfElements | R | number of active drivers |
| 005fd3a4 | aLaps_1 | R | config key "Laps" |
| 005fd3a8 | byte_5FD3A8 | R | "Laps" string fragment |
| 00611a24 | aDDevNascar2004_21 | R | source file path "D:\dev\NASCAR_2004\Source\steward.cpp" |
| 00611d34 | aPreracepresent | R | config section "PreRacePresentation" |
| 00611d48 | dword_611D48 | R | config key prefix bytes for "Duration" |
| 00611d4c | dword_611D4C | R | config key "Duration" bytes |
| 00611d50 | byte_611D50 | R | "Duration" null terminator |
| 00611d54 | aDDF | R | scanf format "%d:%d:%f" |
| 00611d60 | aFormationspeed | R | config key "FormationSpeedMPH" |
| 00611d74 | aDefaultscoring | R | config section "DefaultScoring" |
| 00611d84 | aWednesday | R | default race-day string "Wednesday" |
| 00611d90 | byte_611D90 | R | config key "RacePitMPH" |
| 00611d9c | byte_611D9C | R | config key "NormalPitMPH" |
| 00611dac | dword_611DAC | R | config key prefix for "Start" |
| 00611db0 | word_611DB0 | R | config key suffix "Day" |
| 00611db4 | off_611DB4 | R | "Day" string |
| 00611db8 | aEnteredSteward_1 | R | debug log string "Entered Steward::Restart()" |
| 00629120 | byte_629120 | R | empty string sentinel |
| 0075aad0 | dword_75AAD0 | R | driver/player table |
| 0075cba8 | dword_75CBA8 | R | current game state |
| 0075cbb0 | dword_75CBB0 | R | current race type (0-8) |
| 00764d70 | dword_764D70 | R | unknown |
| 00766124 | byte_766124 | RW | flag cleared on restart |
| 00766128 | dword_766128 | W | counter reset on restart |
| 00766594 | dword_766594 | R | season-race-specific driver name string |
| 00766e00 | dword_766E00 | R | flag: championship mode active |
| 00766f44 | dword_766F44 | R | flag: practice session |
| 00767088 | dword_767088 | R | flag: qualifying session |
| 00768a2c | dword_768A2C | R | race lap count from championship |
| 00768b70 | dword_768B70 | R | total races in championship |
| 0076bb28 | dword_76BB28 | R | unknown (passed to nullsub_6) |
| 007d7920 | dword_7D7920 | R | debug log channel |
| 007d7a10 | byte_7D7A10 | R | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414bb0 | sub_414BB0 | pre-race presentation setup |
| 00414d80 | StringPathExtensionManipulation [structural] | manipulate file path extension |
| 00414e50 | sub_414E50 | load presentation config |
| 0042f570 | sub_42F570 | get race-type-specific directory path |
| 0042f950 | sub_42F950 | set game state (dword_75CBA8) |
| 00463490 | sub_463490 | unknown check |
| 004ba410 | sub_4BA410 | unknown (final call) |
| 004cf510 | nullsub_6 | no-op cleanup |
| 004f7ed0 | sub_4F7ED0 | reset pit-stop state |
| 004f80d0 | sub_4F80D0 | initialize pit window logic |
| 004f8d30 | ArithmeticComparison_0ec0 [exact] | set comparison/mode for timing element |
| 004f8d70 | sub_4F8D70 | reset timing element |
| 004f9f50 | sub_4F9F50 | initialize scoring/timing |
| 004fa8e0 | sub_4FA8E0 | clear/reset race state |
| 00500f90 | sub_500F90 | debug log level check |
| 00500fe0 | sub_500FE0 | debug log output |
| 0057a6d0 | sub_57A6D0 | get config value string from key |
| 0057a720 | StringKeyedLinkedListSearch [structural] | find config key in section |
| 0057ae50 | sub_57AE50 | find config section by name |
| 005beab0 | _strncpy | standard strncpy |
| 005bebfe | _atol | standard atol |
| 005bf239 | _atof | standard atof |
| 005bf36d | _rand | standard rand |
| 005bf71b | _sscanf | standard sscanf |

**Guard conditions:** No early-return guards — function always runs through. Branching only via switch on dword_75CBB0 (race type 0-8) to configure different timing/scoring modes.

**String literals referenced (deterministic):**

- `SeasonRaces`
- `Laps`
- `Laps`
- `D:\dev\NASCAR_2004\Source\steward.cpp`
- `PreRacePresentation`
- `Duration`
- `%d:%d:%f`
- `%d:%d:%f`
- `FormationSpeedMPH`
- `FormationSpeedMPH`
- `DefaultScoring`
- `Wednesday`
- `RacePitMPH`
- `NormalPitMPH`
- `Start`
- `Day`
- `Entered Steward::Restart()`
