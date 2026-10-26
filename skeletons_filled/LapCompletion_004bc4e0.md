## LapCompletion_004bc4e0 — LapCompletionHandler

**Summary:** Processes vehicle lap/sector completion events — records lap and sector times, detects fastest laps, manages race finish and retirement states, handles penalties (stop-go, disqualification), and triggers session transitions. Part of the race timing and session management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400), LapSplitTimeEvent (004bc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | session/race phase status (3 = session finished) |
| obj | 0x344C | R | — | vehicle-related state flag |
| obj | 0x4894 | R | — | vehicle entity index (for current-player checks) |
| this | 0x0 | R | — | pointer to vehicle session data object |
| this | 0x4 | R | — | vehicle pointer/ID |
| this | 0x8 | RW | — | checkpoint index / lap counter |
| this | 0xC | RW | 0 | sector number (0 = full lap, 1/2 = sector split) |
| this | 0x18 | RW | — | current sector/lap time (float seconds) |
| this | 0x1C | R | — | pointer to best sector 1 data |
| this | 0x20 | R | — | pointer to best sector 2 data |
| this | 0x30 | RW | — | finish/retirement status (0=racing, 1=finished, 2=retired, 3=DSQ) |
| this | 0x3C | R | — | number of pending stop-go penalties |
| this | 0x40 | RW | 0 | race-started flag (1 = first split recorded, race officially started) |
| this | 0x44 | R | — | vehicle index for current-player lookup |
| this | 0x60 | RW | — | lap-timing state (0=pre-start, 1=racing, 2=finished) |
| this | 0x64 | RW | — | last processed checkpoint time (float) |
| this | 0x68 | RW | — | fastest lap time (float seconds) |
| this | 0x74 | RW | — | best sector 1 time (float) |
| this | 0x78 | RW | — | best sector 2 time (float) |
| this | 0x7C | RW | — | best sector 3 time (float) |
| this | 0x80 | RW | — | pointer to per-lap timing data array |
| this | 0x84 | RW | — | accumulated penalty time (seconds added to race time) |
| this | 0x88 | R | — | max laps / max checkpoint count |
| this | 0x8C | R | — | per-lap time array (lap times history) |
| this | 0x90 | R | — | per-sector time array (sector times history) |
| this | 0x94 | R | — | pit-stop order / position array |

**Written-by note (persistence):**
- this 0x8: event-driven — external poke corrupts checkpoint counting
- this 0xC: event-driven — external poke corrupts sector tracking
- this 0x18: event-driven — external poke corrupts timing data
- this 0x30: event-driven — external poke corrupts finish/retirement state
- this 0x40: event-driven — external poke corrupts race-start detection
- this 0x60: event-driven — external poke corrupts lap-timing state machine
- this 0x64: event-driven — external poke corrupts checkpoint timing
- this 0x68: event-driven — external poke corrupts fastest lap
- this 0x74: event-driven — external poke corrupts best sector times
- this 0x78: event-driven — external poke corrupts best sector times
- this 0x7C: event-driven — external poke corrupts best sector times
- this 0x80: event-driven — external poke corrupts timing data pointer
- this 0x84: event-driven — external poke corrupts penalty time

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bc984 | jpt_4BC612 | R | switch jump table for session-type dispatch |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c2730 | aIgnoredStopGoP | R | "ignored stop-go penalty" disqualification message string |
| 005c32fc | aLaps_1 | R | "Laps" label string for disqualification message |
| 005c3778 | aDS | R | format string "%d %s" for disqualification display |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer — formatted disqualification text |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) — guards dev logging |
| 007c56a4 | dword_7C56A4 | R | SessionType — 0=retire, 1-6=race/weekend, 7=qualifying/practice |
| 007c56a8 | dword_7C56A8 | R | RacePhase — 8 = final phase (race end trigger in qualifying) |
| 007ce24c | unk_7CE24C | R | CriticalSection — session data object for RaceFinishHandler |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled — enables lap-over disqualification in qualifying |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps — configured race distance in laps |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset — qualifying time offset for finish calculation |
| 008acf94 | flt_8ACF94 | R | RaceTimeThreshold — time-based race limit |
| 008acfa0 | byte_8ACFA0 | RW | HalfDistanceFlag — set when current lap >= total/2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419500 | AICornerSpeedComparison | AI corner speed analysis on sector completion |
| 004199e0 | AIRetirementVehicleFailureEvent | trigger AI retirement / mechanical failure event |
| 0041a8c0 | AISessionEventAudio | play audio cue for penalty/session event |
| 00423a00 | BinarySearchInStringTable | lookup localized string in string table |
| 0042d140 | sub_42D140 | session metadata update (qualifying timer) |
| 004a0b20 | sub_4A0B20 | pre-finish vehicle processing |
| 004a0ba0 | RaceFinishHandler | process race finish — update standings, trigger results |
| 004a0c60 | SessionMenuModeSwitch | transition to session results / menu mode |
| 004a6d50 | sub_4A6D50 | post-lap vehicle state update |
| 004bc0e0 | DisqualificationHandler | apply disqualification with reason message |
| 004bc240 | sub_4BC240 | post-lap-completion state finalization |
| 004d1bc0 | PitStopOrderRank | update pit-stop position ranking |
| 004d1c40 | sub_4D1C40 | update sector timing display / HUD |
| 0058815f | StringFormatWithBufferOverflowCheck | format disqualification reason string |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | <= | 1 | session phase; if ≤1 (pre-race/formation) → block DSQ processing |
| obj | 0x32C8 | == | 3 | session phase; if 3 (finished) → early return, ignore all events |
| this | 0xC | == | 1 | sector number; if 1 → check for first-sector race-start flag |
| this | 0x30 | != | 3 | finish status; if not 3 (not DSQ) → normal finish processing |
| this | 0x30 | == | 1 | finish status; if 1 (already finished) → block re-finish |
| this | 0x3C | > | 0 | penalty count; if >0 → iterate and decrement pending stop-go penalties |
| this | 0x40 | != | 1 | race-started flag; if not 1 → set to 1 on first sector/lap |

**Guard interpretation:** Blocks processing if session already finished (obj+0x32C8==3). Full-lap path (a4==0): records lap time, checks fastest lap, updates pit-stop order. Switches on SessionType: 0 → retirement; 1-6 → race mode — checks total laps/time threshold for finish, DSQ for exceeding lap limit in qualifying; 7 → qualifying/practice — checks RacePhase==8 for session end, otherwise normal race finish via RaceFinishHandler. Processes pending stop-go penalties by decrementing counters. Sector path (a4!=0): records sector time, sets race-started flag on first split, triggers AI corner analysis and audio events.
