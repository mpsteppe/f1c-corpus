## sub_4FCC70_004fcc70 — RaceResultsFileWriter

**Summary:** Writes the complete race results to a timestamped .txt file — includes game header (NASCAR Thunder 2004), driver aids configuration, track info, and per-driver results (position, laps, best lap time, sector times, DNF/DQ status, fines, laps led). Creates the output directory if needed.

**Called by:** sub_4FCB90 (004fcb90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | R | — | results-enabled flag (skip write if zero) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d56c4 | flt_5D56C4 | R | race timing constant |
| 005fb9d8 | asc_5FB9D8 | R | blank line separator string |
| 00600720 | aNascarThunderT | R | "NASCAR Thunder TM 2004" game title |
| 00610844 | aLapsleadD | R | "LapsLead=%d\n" format |
| 00610e38 | aTxt | R | ".txt" file extension |
| 00611dec | aResultD | R | "Result=%d\n" format |
| 00611df8 | aSCDD | R | "S-C=(%d,%d)\n" format |
| 00611e08 | aScs | R | "[SCS]\n" section header |
| 00611e10 | aQualificationD | R | "Qualification=%d\n" |
| 00611e24 | aTotalFinesF | R | "Total Fines=%f\n" |
| 00611e34 | aSectorDBest3f | R | "Sector %d Best=%.3f\n" |
| 00611e4c | aLapD3f3f | R | "Lap=(%d, %.3f, %.3f)\n" |
| 00611e64 | aTotalLapsD | R | "Total Laps=%d\n" |
| 00611e74 | aTotalEt3f | R | "Total ET=%.3f\n" |
| 00611e84 | aBestLapStart3f | R | "Best Lap Start=%.3f\n" |
| 00611e9c | aBestLapTime3f | R | "Best Lap Time=%.3f\n" |
| 00611eb0-11f84 | various | R | driver result format strings (DNF, DQ, pit/garage, vehicle, driver name, etc.) |
| 00611f40 | aSlot | R | "[Slot]\n" section header |
| 00611f48 | aDDD_1 | R | "%d,%d,%d" control format |
| 00611f54 | aControls_0 | R | "[Controls]\n" section header |
| 00612218 | aLocalSettings | R | "[Local Settings]\n" header |
| 0061222c | aTrackLength4f | R | "TrackLength=%4f\n" |
| 00612240 | aRaceLength3f | R | "RaceLength=%3f\n" |
| 00612254 | aRaceTimeD | R | "RaceTime=%d\n" |
| 00612264 | aRaceLapsD | R | "RaceLaps=%d\n" |
| 00612274 | aQualifyLapsD | R | "QualifyLaps=%d\n" |
| 006122d8 | aGameS | R | "Game=%s\n" |
| 006122e4 | aHeader | R | "[Header]\n" |
| 006122f0 | aD02d02d02d02d0 | R | timestamp format "%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d" |
| 00612314 | aResults | R | "\Results" subdirectory name |
| 006290d0 | flt_6290D0 | R | track length value |
| 00629120 | byte_629120 | R | default empty string |
| 0062a0c8 | dword_62A0C8 | R | results output path |
| 00631104 | dword_631104 | R | per-driver results data array base |
| 00759984 | dword_759984 | R | per-driver data array end |
| 0075cbb0 | dword_75CBB0 | R | replay mode check (7 = replay) |
| 00766578 | dword_766578 | R | scene/track name string |
| 007665b0 | Source | R | AI difficulty string |
| 007667b0-76693c | driver aid arrays | R | per-driver aid settings (steering, throttle, brake, anti-lock, spin recovery, etc.) |
| 00766960 | byte_766960 | R | driving aids allowed flag |
| 00766978-766b6c | more aid settings | R | auto clutch, shift, auto reverse, half rate, mech fail, damage |
| 007684bc | dword_7684BC | R | damage multiplier |
| 007689cc | dword_7689CC | R | race mode |
| 00768a2c-768cb4 | session config | R | qualify laps, race laps, race time |
| 00768df8 | flt_768DF8 | R | race length value |
| 0076926c-76963c | multipliers | R | tire, fuel, all cars equal, vehicles allowed |
| 007697c0 | byte_7697C0 | R | results write enabled flag |
| 0076986c | dword_76986C | R | multiplayer data rate |
| 0076a67c-76ad28 | control assignments | R | per-player control settings array |
| 0076bb84 | dword_76BB84 | R | no-player AI count |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd090 | sub_4DD090 | get lap time for driver |
| 004dd0c0 | sub_4DD0C0 | get sector time for driver |
| 004debd0 | sub_4DEBD0 | get laps led count |
| 00578560 | sub_578560 | append path component |
| 00578600 | StringCopyWithBufferRealloc [structural] | build output path |
| 0057a080 | ZeroInitSmallStruct [exact] | init write buffer |
| 0057a0a0 | sub_57A0A0 | close/finalize buffer |
| 0057a110 | sub_57A110 | open buffer for writing |
| 0057a240 | sub_57A240 | open file stream |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | close file handle |
| 0057a400 | BufferWriteWithStringLengthCheck [structural] | write formatted line to file |
| 0057b490 | UtilityFunction_8a60 [structural] | create file with random suffix |
| 005be8ae | sub_5BE8AE | memory free |
| 005be8e3 | ??2@YAPAXI@Z | operator new |
| 005beab0 | _strncpy | copy directory path |
| 005beec8 | _sprintf | format timestamp |
| 005bf36d | _rand | randomize filename suffix |
| 005c05a2 | __mkdir | create results directory |
| 005c069b | _time | get current time |
| 005c111c | _localtime | convert to local time struct |

**Guard conditions:** Primary guard: `dword_75CBB0 == 7` (replay mode check), `this[0xA0]` (results enabled flag), and `byte_7697C0` (global write flag). All three must be true for any output to occur.

**String literals referenced (deterministic):**

- `NASCAR Thunder TM 2004`, `.txt`, result format strings for all driver stats, driver aid settings labels, section headers
