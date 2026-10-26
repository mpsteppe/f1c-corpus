## sub_4BC2D0_004bc2d0 — PitTrackerStateInit

**Summary:** Initializes three state fields for pit timer/tracker: zeroes counter at offset 0xC, sets state/mode to 2 at offset 0x60, stores driver/vehicle index at offset 0x64. Called by PitTimerStateInit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimerStateInit (004d23d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | counter field (zeroed, likely lap/sector count) |
| this | 0x60 | RW | 2 | state/mode field (initialized to 2) |
| this | 0x64 | RW | — | driver or vehicle index (copied from parameter) |

**Written-by note (persistence):**
- this 0xC: written once (0) on init; external poke survives and will be read by state machine
- this 0x60: written once (2) on init; external poke survives
- this 0x64: written once on init; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional initialization of all three fields
