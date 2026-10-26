## PathStringUtility_00404850 — PathStringValidationAndCopy

**Summary:** Copies/validates a path string from a struct field (offset 0x38) or a default global directory path if the field is null, but only if the string is non-empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceModeSetup (00404890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | pointer to path/directory string (nullable; falls back to default application directory) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b04e0 | StringCopyFileCheckDispatch | copies/validates a path string, returning success/failure |

**Guard conditions:** Checks if the resolved path string is non-empty via strlen(). PASSES (continues to copy): length > 0. BLOCKED (returns 0): length == 0 (empty string).
