## AISessionEventAudio_0041a8c0 — TeammateLapEventAudio

**Summary:** Fires audio event (message ID 55) when an AI entrant with the same team/constructor ID as the player completes a lap, confirmed by matching field at offset 0x4894; restricted to non-phase-8 race states.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | R | — | Team/constructor ID field; compared between player vehicle and AI entrant to detect teammate |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID 55, timing info, and driver indices |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. Field at offset 0x4894 in player vehicle (`dword_7C54E8 + 0x4894`) must equal same field in passed AI entrant (`a1 + 0x4894`) → PASSES: AI entrant is same team as player. BLOCKED: different team/constructor.
4. `dword_7C56A8` (RacePhase) must not equal 8 → PASSES: race is in an active phase. BLOCKED: race phase is 8.
