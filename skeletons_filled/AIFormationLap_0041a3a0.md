## AIFormationLap_0041a3a0 — FormationLapEventHandler

**Summary:** Handles formation lap commentary events for non-player vehicles. In race/practice sessions, uses generic event 6. In championship weekend (session type 7) with non-World-Championship mode, checks lap proximity and formation lap position status to emit specific events (180-182). Part of AI session event pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A5F20 (004a5f20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x342C | R | — | Formation lap position status (1, 2, or 3 → events 180/181/182) |
| this | 0x3430 | R | — | Formation lap position counter (compared against lap number) |
| this | 0x403C | R | — | lapNumber — current lap counter |
| this | 0x4894 | R | — | Driver ID — matched against player vehicle to skip player events |
| this | 0x489C | R | — | Related driver index (teammate/tracked driver ID for event context) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to check driver match |
| 007c56a4 | dword_7C56A4 | R | Session type (0-6 = race/practice, 7 = championship weekend) |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |
| 007d0410 | dword_7D0410 | R | Championship mode — 5 = World Championship (uses generic event 6) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct for new event entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event type and computed time |
| 00418560 | InsertDriverTableEntry | Inserts formation lap event into session event table |

**Guard conditions:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0, dword_7C56A8 (race phase) != 8. Must not be player vehicle (a1[4645] != player driver ID). Session type >= 0. Session type 7 path only: championship mode != 5 OR if == 5 use generic event 6; formation position counter (this+0x3430) must be within ±1 of lap number (this+0x403C); position status (this+0x342C) must be 1, 2, or 3.
