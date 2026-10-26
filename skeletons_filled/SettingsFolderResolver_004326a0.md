## SettingsFolderResolver_004326a0 — SettingsSectionResolver

**Summary:** Resolves a settings section by checking if it matches a season/race section, then looking up the corresponding vehicle data entry in a linked list. Returns the data entry handle or the original section pointer if no match found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsCopySetupFileCopy (00432220), PlayerNameSetup (004326e0), AISettingsFileLoader (004333e0), LookUpVehicleConfigEntry (004339e0), AddVehicleConfigEntryToLinkedList (00433b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3fa4 | off_5C3FA4 | R | VehiclePartVTable [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c5840 | SeasonRacesSectionFinder | Checks if the section corresponds to a season/races category |
| 005679c0 | StringKeyedLinkedListSearch | Searches a string-keyed linked list for matching vehicle entry |

**Guard conditions:** SeasonRacesSectionFinder must return non-zero (section is a season/races type) for the lookup to proceed. If it returns 0, returns this pointer directly. Additionally, StringKeyedLinkedListSearch must return non-zero (entry found) to return the data entry handle; otherwise returns this pointer.
