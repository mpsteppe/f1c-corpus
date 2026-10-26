## SettingsFileInit_004b0930 — SettingsFileInit

**Summary:** Updates vehicle data fields, builds a ".bch" settings file path from object's name field via NamePathFormatterWithLengthCheck, toggles read-only attribute, then reads career section data from the file via CareerSectionReader.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B0770 (004b0770), NameCompareAndFormat (004b1410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b02b0 | NamePathFormatterWithLengthCheck | formats path string with ".bch" extension from object name |
| 004b0e30 | VehicleDataFieldCopy | copies vehicle data fields to settings structure |
| 004c2700 | CareerSectionReader | reads career section data from .bch file |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | toggles file read-only attribute (128 = set normal/none) |

**Guard conditions:** None — straight-line execution.
