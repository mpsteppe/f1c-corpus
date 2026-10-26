## sub_4BACD0_004bacd0 — Race/game state machine controller

**Summary:** Central game state dispatcher: monitors input event sequences (word_762A08 array), manages state transitions (racing, trackside, menu), checks replay/session flags, and triggers appropriate sub-system updates. Returns current game state code (4, 6, or value from dword_75CBA8).

**Called by:** sub_4300E0 (004300e0)

**Struct fields accessed:**

(None — this is a static function referencing only globals.)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | screen width fraction constant |
| 005d5bd4 | flt_5D5BD4 | R | threshold constant |
| 005fb990 | aTrackside | R | "Trackside" string (compare against current camera name) |
| 005fd340 | NumOfElements | R | number of active players/entities |
| 00608f60 | dword_608F60 | R | menu/game mode flag (checked for value 3) |
| 00629124 | dword_629124 | R | input state structure (passed to sub_4057C0/sub_405BE0) |
| 006291cc | dword_6291CC | R | render context handle |
| 0062bf64 | unk_62BF64 | R | unknown data reference |
| 0075aacc | dword_75AACC | R | base pointer for race session data |
| 0075aad0 | dword_75AAD0 | R | player data array (indexed for sub_4DD150 calls) |
| 0075cba8 | dword_75CBA8 | RW | current game state code (written and returned) |
| 0075cbb0 | dword_75CBB0 | R | game mode ID (checked for value 7 = replay mode) |
| 00761ff8 | dword_761FF8 | R | input event flags (lower 2 bits checked) |
| 00762a04 | dword_762A04 | R | input event count (when flags & 3 != 0) |
| 00762a08 | word_762A08 | R | input event sequence array |
| 00763b84 | dword_763B84 | R | global flag (enables early state transition) |
| 00764d70 | dword_764D70 | R | data reference for sub_463490 |
| 00766124 | byte_766124 | R | global state byte |
| 00766178 | dword_766178 | RW | frame/cycle counter (incremented each call) |
| 0076617c | byte_76617C | R | state flag |
| 00766180 | dword_766180 | RW | race phase state (0=racing, 1=transition, 2=trackside) |
| 00766185 | byte_766185 | RW | transition flag (set to 0 after processing) |
| 00766186 | byte_766186 | RW | event-triggered flag |
| 00766187 | byte_766187 | R | mode parameter for sub_49C1D0 |
| 00766188 | byte_766188 | R | event flag |
| 0076618c | dword_76618C | R | mode toggle flag |
| 00766191 | byte_766191 | RW | countdown/timer active flag |
| 00766194 | dword_766194 | RW | countdown timer value (decremented by dbl_7DA9C8) |
| 007689cc | dword_7689CC | R | pointer to race structure (offset 0 = state) |
| 007d5dac | dword_7D5DAC | R | timer/countdown data (passed to sub_4D9AE0) |
| 007d6b78 | byte_7D6B78 | R | state flag for sub_4F0190/sub_4F01B0 |
| 007d79f4 | flt_7D79F4 | R | threshold float (checked against <= 0.0) |
| 007da9c8 | dbl_7DA9C8 | R | countdown decrement value (subtracted each cycle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004057c0 | sub_4057C0 | check input event state |
| 00405be0 | ByteFieldExtractorWithShift [exact] | extract byte field from input state |
| 00405c10 | sub_405C10 | reset/clear input state |
| 0040c460 | sub_40C460 | get render device/context |
| 0042dba0 | sub_42DBA0 | check race session active |
| 0042fa50 | sub_42FA50 | set game state code (dword_75CBA8) |
| 00459ba0 | sub_459BA0 | get camera name string |
| 00463490 | sub_463490 | compute replay-related boolean |
| 0049c1d0 | sub_49C1D0 | dispatch/transition to next game phase |
| 004ba250 | sub_4BA250 | update per-frame race state |
| 004ba580 | sub_4BA580 | trigger trackside/reset transition |
| 004d9ae0 | sub_4D9AE0 | check countdown/timer active |
| 004dd150 | sub_4DD150 | update per-player state |
| 004f0190 | sub_4F0190 | enable state flag |
| 004f01b0 | sub_4F01B0 | disable state flag |
| 005074a0 | ReciprocalWithSignCheck [exact] | compute reciprocal with sign |
| 005074d0 | SafeDivisionWithZeroGuard [structural] | safe division (0.0 call returns 4) |
| 0051bc20 | sub_51BC20 | trigger event/reset |
| 005bf290 | __strcmpi | case-insensitive string comparison |

**Guard conditions:** Multiple nested checks on input event types (21 = cross finish line, 49 = transition, 1 = default), game mode (dword_75CBB0 == 7 for replay), countdown timer value, and track position flag (byte_766185). The state machine has three main phases: racing (dword_766180=0), transitioning (1), and trackside (2).

**String literals referenced (deterministic):**

- `Trackside`
