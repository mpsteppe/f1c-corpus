## NameCompareAndFormat_004b1410 — NameCompareAndFormat

**Summary:** Compares input name against stored name at this[2023]. If matching, builds season directory path + name, performs object ID lookup, loads audio file for the name, then initializes settings file and runs 5-step initialization. Returns 1 on success, 0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigWriteback (00461900), CopyProfileIconBMP (0046cd20), TrackConfigurationNameBuilder (004b16b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F9C | R | — | stored name string pointer for comparison |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0720 | F_5StepInit | runs 5-step initialization sequence for the session |
| 004b0930 | SettingsFileInit | initializes settings file, reads career section |
| 00566650 | StringCopyWithBufferRealloc | copies string with reallocation |
| 00567f40 | AudioFileLoadDecode | loads and decodes audio file for the name |
| 005684a0 | ObjectIDLookupAcross9Arrays | performs object ID lookup across 9 arrays |
| 00588410 | sub_588410 | string comparison (name match check) |
| 0058969d | StringFormatProcessingWithNullTerm | safe sprintf with null termination, builds path strings |

**Guard conditions:** First guard: if sub_588410(a2, this[2023]) returns 0 (name mismatch), return 0 immediately. Blocked: input name doesn't match stored name. Second guard: if path formatting fails (< 0), return 0. Third guard: if audio file loading fails (not == 1), return 0.
