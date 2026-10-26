## CollisionGlobalZeroing_00494600 — Zero collision system globals

**Summary:** Zeros four collision system global counters/state variables at 0x7CDDF0-0x7CDDFC. Called during collision system reset or shutdown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cddf0 | dword_7CDDF0 | W | CollisionStateCounters [DERIVED] (also: ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed) |
| 007cddf4 | dword_7CDDF4 | W | CollisionListTailPointer [DERIVED] |
| 007cddf8 | dword_7CDDF8 | W | CollisionListTail [DERIVED] (also: ` — collision list iterator) |
| 007cddfc | dword_7CDDFC | W | CollisionContactCounter [DERIVED] (also: ` — collision state counters/flags (all zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions; always zeroes all four globals.
