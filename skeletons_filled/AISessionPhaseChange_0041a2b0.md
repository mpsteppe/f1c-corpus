## AISessionPhaseChange_0041a2b0 — SessionPhaseChangeEventHandler

**Summary:** Processes session phase changes (race phase counter transitions) for AI commentary. For non-player vehicles during race sessions, inserts phase change event (21 or 22) or qualifying/practice event (178/179). Always calls AIPositionChangeEvent for race sessions regardless of player match.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A5EA0 (004a5ea0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to check driver identity |
| 007c56a4 | dword_7C56A4 | R | Session type (5=Race, 6-7=Qualifying/Practice) |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct for new event entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event type, phase counter, and computed time |
| 00418560 | InsertDriverTableEntry | Inserts phase change event into session event table |
| 004198b0 | AIPositionChangeEvent | Delegates to position change handler when session type is 5 (Race) |

**Guard conditions:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, dword_7C56A8 (race phase) != 8. Player vehicle (match a2+18580 vs player vehicle) skips event insertion but still processes position changes. Non-player in race: skip if byte at a2+16444 is 0xFF; else event 21 (counter < 12) or 22 (counter >= 12). Qualifying/Practice (session type 6-7): event 178 or 179 (if a2+16480 == 1, position 1). Other session types: skip event insertion entirely.
