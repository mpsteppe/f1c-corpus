## CollisionAntiRollInit_0044e240 — init anti-roll bar state type 73

**Summary:** Initializes anti-roll bar collision data with type 73, zeroes three fields, and sets wheel caster limit to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd1d8 | dword_7CD1D8 | W | StateTracker_Index [DERIVED] (also: block type 0x49) |
| 007cd1dc | dword_7CD1DC | W | unknown — zeroed anti-roll field |
| 007cd1e0 | dword_7CD1E0 | W | unknown — zeroed anti-roll field |
| 007cd1e4 | dword_7CD1E4 | W | unknown — zeroed anti-roll field |
| 007cd1e8 | dword_7CD1E8 | W | Unknown_Float_AudioCh [DERIVED] |
| 007cd1ec | dword_7CD1EC | W | Flt_WheelCaster_C1EC [DERIVED] (also: limit value 27000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — function always executes all writes unconditionally
