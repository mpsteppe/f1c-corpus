## NullSafePointerDereference_00415c30 — NullSafePointerDereference

**Summary:** Returns the dereferenced string pointer from a char** argument, falling back to the default application directory path if null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NameListBuilderFromVehicleArray (004159b0), DirectoryFileEnumerator (00431db0), SettingsCopySetupFileCopy (00432220), AISettingsFileLoader (004333e0), sub_457000 (00457000), F_2DTransformStructCopy (00457b60), sub_459330 (00459330), SessionConfigBuilder (00461610), VehicleDataLoader (004c4240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | String pointer to dereference; if null, returns fallback path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if *this (string pointer) is null. PASSES: non-null — returns the string. BLOCKED: null pointer — returns &byte_5EA438 (default path).
