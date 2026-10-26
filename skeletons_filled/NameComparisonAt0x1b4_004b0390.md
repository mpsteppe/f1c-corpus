## NameComparisonAt0x1b4_004b0390 — PathLastBackslashExtractor

**Summary:** Extracts the portion of a path string after the last backslash from object field at offset 0x1B4 (this[109]), or from default directory, and copies it to output buffer via sub_587DD0. Returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B4 | R | — | source path string pointer (or null to use default) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | copies substring from source to destination with length limit |

**Guard conditions:** If field at this[109] is null, falls back to global byte_5EA438. Always returns 1.
