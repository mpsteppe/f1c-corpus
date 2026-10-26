## GameFilterDataLoader_004c0db0 — Game filter data and career state loader

**Summary:** Loads game filter configuration, initializes career standings structure for player and up to 103 opponents, and populates per-driver data from the vehicle file pool. Sets default session vehicle counts and active flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NodeAllocListInsert (004c2780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A4 | RW | — | per-entry driver index / position (set from loop counter) |
| this | 0x1A8 | RW | — | per-entry driver position copy (same as index) |
| this | 0x1AC | RW | 1 | per-entry padding/flag field (always set to 1) |
| this | 0x1B0 | RW | 1 | per-entry active flag byte (always set to 1) |
| this | 0xB110 | RW | — | session vehicle count for first slot |
| this | 0xB114 | RW | — | session vehicle count for second slot |
| this | 0xB118 | RW | 0 | zero-initialized field |
| this | 0xB11C | RW | 1 | active/init flag byte (set to 1) |
| this | 0xB144 | RW | 2 | season status (set to 2) |
| this | 0xB148 | RW | 0 | current race index (set to 0) |

**Written-by note (persistence):**
- this 0x1A4: overwritten each time function runs; external poke changes driver index
- this 0x1A8: overwritten each time; external poke changes position value
- this 0x1AC: always set to 1; external poke changes padding/flag
- this 0x1B0: always set to 1; external poke changes active flag
- this 0xB110: set from SessionVehicleCount; external poke changes session count
- this 0xB114: set from SessionVehicleCount; external poke changes session count
- this 0xB118: always set to 0; external poke persists
- this 0xB11C: always set to 1; external poke changes init flag
- this 0xB144: always set to 2; external poke changes season status
- this 0xB148: always set to 0; external poke changes current race index

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | ".HOT" file extension for filter resource |
| 005c7130 | aGameFilter | R | "Game Filter" string constant for resource dispatch |
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007ce498 | byte_7CE498 | R | auto-load config file name |
| 007ce64c | dword_7CE64C | R | game filter data path string |
| 007d0a20 | dword_7D0A20 | R | session vehicle count (number of opponents) |
| 007d0dcc | dword_7D0DCC | R | alternate filter path string |
| 008ad3b4 | dword_8AD3B4 | R | game data directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0b20 | sub_4B0B20 | read auto-load config file name |
| 004bf630 | ZeroInit4Ints | zero-initialize temporary list structure |
| 004bf640 | LinkedListDestruction_f640 | destroy temporary linked list after use |
| 004bf790 | AIOpponentSelection | build sorted opponent candidate list |
| 004bfcd0 | VehicleArrayIndexAccessor | get vehicle file entry pointer by list index |
| 004c07f0 | LapSessionDataArrayInitializer | initialize lap/session data for driver entry |
| 005665b0 | sub_5665B0 | copy path string with reallocation |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 005681f0 | ConditionalDispatch_81f0 | dispatch game filter resource load |
| 00587bcf | FreeWrapper_7bcf | free allocated memory |

**Guard conditions:** No explicit early return guards. Opponent loop runs up to SessionVehicleCount (dword_7D0A20); if count <= 0, entire loop is skipped and per-driver fields are not written.
