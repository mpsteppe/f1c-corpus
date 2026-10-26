## sub_4DA9E0_004da9e0 — HUDLapTimePositionRender

**Summary:** Renders lap count or elapsed time text on HUD. If session has 1 lap total, shows "N LAPS" using string table lookup; otherwise computes formatted race time (MM:SS.mmm or SS.mmm) and renders with position suffix character.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Lap count or session lap number (used as integer in format string) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c3310 | aD063f | R | StrD063F [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005cce6c | aLaps_0 | R | sLaps [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae8 | byte_5D4AE8 | R | PositionNameSuffix [DERIVED] |
| 005d4b74 | a3f | R | Format3fString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Looks up string table entry; used here to find "LAPS"/"LAP" localized string |
| 0049b630 | SpatialGridCell | Converts float time to minutes:seconds components (int minutes, float remainder seconds) |
| 004d7e40 | UITextRenderWithScale | Renders text on screen with position, color, alignment, and scale parameters |
| 004dac30 | SizeOffsetTableByMode | Gets screen position/size offsets for HUD rendering based on display mode |
| 004dad30 | SingleFunctionCallWrapper_ad30 | Returns elapsed race session time (double) from a3 context |
| 004dad50 | ArithmeticComparison_ad50 | Returns computed difference/offset time value from this pointer |
| 00587dd0 | sub_587DD0 | Copies string to destination buffer with size limit (strncpy-like) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe snprintf-style string formatting |
| 00589901 | sub_589901 | Clears/resets string buffer for reuse |

**Guard conditions:** No guard — always renders. Branch on *(a3+16480) == 1 selects lap-vs-time display mode.

