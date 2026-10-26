## ToggleFileReadOnlyAttributeViaWin32API_0058ba36 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409770 (00409770), MultiLineTextDraw (0040bd10), FilePathExtensionCheck (00414900), sub_422BE0 (00422be0), ConfigFileParser (004330d0), sub_499690 (00499690), sub_4B0770 (004b0770), SettingsFileInit (004b0930), FileSettingExistenceCheck (004b8010), FileAttributeCheckSequence (005668f0), FileAttributesExistenceCheck (00568540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d8 | GetFileAttributesA | R | [LLM] |
| 0059e17c | SetFileAttributesA | R | [LLM] |
| 0059e188 | GetLastError | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
