## AIPositionChangeEvent_004198b0 — PositionChangeEventHandler

**Summary:** Detects and processes position changes for AI race commentary. Compares stored vs current position per driver. On change, determines gain/loss event type, builds driver data, and inserts into session event table. Handles player and AI vehicles differently.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISessionPhaseChange (0041a2b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table (passed to InsertDriverTableEntry) |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to identify player driver |
| 007c56a4 | dword_7C56A4 | R | Session type — must be 5 (Race) to process |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 (post-race) to proceed |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct for new event entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with event type, positions, and computed time |
| 00418560 | InsertDriverTableEntry | Inserts position change event into session event table |

**Guard conditions:** dword_7D0308 (race active) must be nonzero. flt_7CF3C8 (track condition) must be != 0.0 AND dword_7C56A8 (race phase) must be != 8. Stored position (this[driverID+108]) must differ from current position (a2[4120]). dword_7C56A4 (session type) must be 5. For player driver additional guards: a2[4111] != 1 and if gained, v4 != 1. For AI drivers: v4 != 1, a2[4111] != 1.
