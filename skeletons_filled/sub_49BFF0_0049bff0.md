## sub_49BFF0_0049bff0 — Next lap time format

**Summary:** Reads time value for next lap index (current+1, wraps at 2→0), formats as " MM:SS.mmm" string in output buffer. Part of lap timing HUD display with ghost/replay comparison support.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_d8b0 (0049d8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005cce18 | asc_5CCE18 | R | empty string prefix — copied to output buffer before time format |
| 005cce24 | a2d063f_1 | R | Unknown_String5CCE24 [DERIVED] |
| 005f0780 | flt_5F0780 | R | ghost car lap time array (indexed by car×4656 stride) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] — race state struct with lap timing fields |
| 007cfff0 | byte_7CFFF0 | R | TextRenderFlag [DERIVED] — bit 1 enables ghost time comparison |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b630 | SpatialGridCell | converts float seconds to minutes:seconds components for display format |
| 004d1b50 | sub_4D1B50 | gets ghost/replay car index (0-254, 255=invalid) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe formatted string assembly with buffer overflow protection |

**Guard conditions:** `(byte_7CFFF0 & 1) != 0` → PASSES branch uses flt_5F0780 ghost time; else reads from dword_7C54E0 directly. `sub_4D1B50(0) == 255` → BLOCKED (return 0, ghost car unavailable). `v5 <= 0.0` → skips formatting (time not available/zero).