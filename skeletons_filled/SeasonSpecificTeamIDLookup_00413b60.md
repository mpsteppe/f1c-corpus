## SeasonSpecificTeamIDLookup_00413b60 — SeasonDbTeamIdMapper

**Summary:** Maps team index a3 (1-17) to a team ID (333-400) based on which season database file matches the current season path (dword_7D0434). Four nested database filename checks (f11999 → f12000 → f12001 → f12002) select one of four team ID tables (base 334, 335, 336, or 333, each +4 per entry). Only active when a2==1 and a4==0. Writes team ID to a1+8 and sub_414180(1) to a1+12.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | mapped team ID (333-400), written on success |
| this | 0xC | RW | — | secondary value from sub_414180(1), written on success |

**Written-by note (persistence):**
- this 0x8: written on successful mapping; persists until overwritten
- this 0xC: written on success via sub_414180; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00413efc | jpt_413BB2 | R | jump table for table 1/2 (16 cases + default) |
| 00413f40 | jpt_413C97 | R | jump table for table 3 (16 cases + default) |
| 00413f84 | jpt_413D7C | R | jump table for table 4 (16 cases + default) |
| 00413fc8 | jpt_413E5F | R | jump table for f12002-matched path (table 4) |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] — database filename "F12002.GDB" |
| 005bf97c | aF12001Gdb | R | aF12001Gdb [DERIVED] — database filename "F12001.GDB" |
| 005bf988 | aF12000Gdb | R | TrackDatabaseFilename [DERIVED] — database filename "F12000.GDB" |
| 005bf994 | aF11999Gdb | R | aF11999Gdb [DERIVED] — database filename "F11999.GDB" |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default path used when season path is null |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] — current season directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414180 | sub_414180 | computes secondary value (called with 1) written to a1+12 |
| 00588410 | sub_588410 | compares season path against database filename string (returns bool) |

**Guard conditions:** a2 must be 1 AND a4 must be 0. Requires a3 in 1-17. Falls through to return -1 if season path matches F12002.GDB (no table for that combination), or if a3 not in valid range.
