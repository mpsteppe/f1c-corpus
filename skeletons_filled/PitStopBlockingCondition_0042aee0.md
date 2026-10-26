> **UPDATE 2026-07-24 (prose only, fact table untouched) — THIS IS THE AI
> WING-RETIREMENT DECIDER.** The 4th term of the race-session return,
> `*(_DWORD *)(*this + 3352) && !*(_BYTE *)(*this + 3416)`, is the REAR-WING
> damage record: `veh+0xD18` (ptr) and `veh+0xD58` (intact flag, 1=intact).
> When it is true at the pit box, `PitStopDecisionTireCompound_0042a3d0` writes
> `RetiredFlag(0x4410)=1` + `ActiveFlag(0x45F4)=0` and the car RETIRES.
> The FRONT-wing record (`veh+0xCD4`/`0xD14`) is deliberately NOT in this
> condition — which is the entire reason a front wing is repaired and a rear
> wing retires. Verified live on 4 cars. Full evidence:
> `investigations/part_detach_commentary/README.md`. Offsets CONFIRMED in
> `name_index.json`. Arming `0xD58=0` + `callToBox=1` retires a healthy car via
> the game's own path (`tools/force_wing_retire.py`).

## PitStopBlockingCondition_0042aee0 — PitStopBlockedCheck

**Summary:** Checks whether pit stop is blocked. Two code paths based on session type: for non-race sessions checks pit data bitmask; for race sessions (type 7) checks lap completion, race phase, and vehicle state flags.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopDecisionTireCompound (0042a3d0), PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xD18 | R | — | postProcessPitFlags |
| obj | 0xD58 | R | — | postProcessPitByteFlag |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x39FA | R | — | pitStopBlockedFlag |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x45E0 | R | — | pitArrayIndex |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** SessionType determines path. If != 7: return bit 3 of pit data array entry `pitArray[pitArrayIndex]`. If == 7 (race): blocked (returns true) when ANY of: lapNumber >= TotalRaceLaps (race done), RacePhase == 8, pitStopBlockedFlag at 0x39FA is set, or postProcess has pit stop flags active (0xD18 set and 0xD58 clear).
