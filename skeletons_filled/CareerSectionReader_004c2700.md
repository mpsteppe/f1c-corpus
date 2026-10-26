## CareerSectionReader_004c2700 — CareerSectionFileReader

**Summary:** Opens a file handle, reads the "Career" section from it using a structured reader, and writes career stats via CareerStatsWriter. Returns success/failure flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsFileInit (004b0930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2e88 | aCareer | R | StringCareer [DERIVED] — "Career" section key string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c2420 | CareerStatsWriter | write parsed career stats from file data into this object |
| 005668b0 | ZeroInitSmallStruct | zero-initialize a stack structure |
| 005668d0 | SubCallWithConditionalFieldFree | cleanup/conditional free of structure fields |
| 00566940 | sub_566940 | open/read data section from file handle with flags (0, 1, 1) |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | close file handle if needed |

**Guard conditions:** a2 (file handle) must be non-null. sub_566940 must return non-zero (read success) for CareerStatsWriter to be called.
