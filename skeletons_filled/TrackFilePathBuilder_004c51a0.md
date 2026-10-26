## TrackFilePathBuilder_004c51a0 — Register scene file and build scene file path

**Summary:** Strips extension and path from a scene file path, extracts the base filename, searches/creates an entry in the scene file registry array, stores the full path, calls section writer, and computes a formatted scene file path result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileLoader (004c52c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 008ac488 | dword_8AC488 | RW | SceneFileCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c5ae0 | SeasonRacesSectionWriter | Write season races section data for the scene file |
| 004c5bb0 | SceneFilePathFormatter | Format scene file path with parameters (115, 211); returns formatted result |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string format: copy base filename to local buffer |
| 00588410 | sub_588410 | Compare base filename against scene entry names at offset 0x104; returns 0 on match |

**Guard conditions:** Strips file extension (after last '.') and path prefix (after last backslash); if neither found, uses full filename. Searches scene file registry (`dword_8AC488` entries, stride 0x18C) for matching name at offset 0x104 — if name not found (loop exhausts without match), allocates new empty entry and copies base filename there, incrementing count.
