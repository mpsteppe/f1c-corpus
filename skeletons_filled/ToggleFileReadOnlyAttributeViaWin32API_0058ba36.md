## ToggleFileReadOnlyAttributeViaWin32API_0058ba36 — ToggleFileReadOnlyAttribute

**Summary:** Toggles the read-only attribute (bit 0) on a file via Win32 API. Gets current attributes with GetFileAttributesA; if a2 >= 0 sets read-only flag (OR 1), if a2 < 0 clears it (AND 0xFE). Calls SetFileAttributesA and returns 0 on success, -1 on failure with error lookup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409770 (00409770), MultiLineTextDraw (0040bd10), FilePathExtensionCheck (00414900), sub_422BE0 (00422be0), ConfigFileParser (004330d0), sub_499690 (00499690), sub_4B0770 (004b0770), SettingsFileInit (004b0930), FileSettingExistenceCheck (004b8010), FileAttributeCheckSequence (005668f0), FileAttributesExistenceCheck (00568540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d8 | GetFileAttributesA | R | Win32 API import — retrieve current file attributes |
| 0059e17c | SetFileAttributesA | R | Win32 API import — set modified file attributes |
| 0059e188 | GetLastError | R | Win32 API import — get error code on failure |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | Map Win32 GetLastError code to internal error ID and log it |

**Guard conditions:**
- `GetFileAttributesA` returns -1 (INVALID_FILE_ATTRIBUTES) → skip toggle, fall through to error path
- `SetFileAttributesA` returns 0 (failure) → fall through to error path
- On success (SetFileAttributesA returns nonzero) → return 0
- On any failure → GetLastError + ErrorIDLookupTable + return -1
