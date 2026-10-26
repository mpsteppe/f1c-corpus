## LookUpVehicleConfigEntry_004339e0 — LookUpVehicleConfigEntry

**Summary:** Searches auto-load entry linked list for vehicle config matching settings folder and session type. Returns 0 with matching path string, or 1 with default path if no match found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAIDriverNamesFromConfig (004336f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1C)+0x0)+0x8) | 0x0 | R | — | entry struct second string (car name) — checked for content |
| *(*(this+0x1C)+0x0) | 0x0 | R | — | entry struct path string (vehicle directory) |
| *(*(this+0x1C)+0x0) | 0x8 | R | — | entry struct second string (car model/filter name) |
| *(*(this+0x1C)+0x0) | 0x10 | R | — | entry struct session type value |
| *(*(this+0x1C)+0x0) | 0x14 | R | — | entry struct result path |
| *(*(this+0x24)+0x4) | 0x0 | R | — | current iterator node's next pointer (advance traversal) |
| *(this+0x1C) | 0x0 | R | — | first node's data pointer (entry start) |
| *(this+0x24) | 0x4 | R | — | current iterator node next pointer (for traversal) |
| this | 0x18 | R | — | bLoaded: flag set by AutoLoadEntryListLoader; if 0, loads list first |
| this | 0x1C | R | — | pHead: linked list head pointer |
| this | 0x24 | RW | — | pCurrent: iterator pointer advanced through list |
| this | 0x28 | R | — | nCount: entry count checked to guard against empty list |

**Written-by note (persistence):**
- this 0x24: overwritten during traversal. Last value is final node's next pointer (may be 0). Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007c56a4 | dword_7C56A4 | R | SessionType — used for IterationCountMap comparison |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath — for SettingsFolderResolver |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath — vehicle/game filter data path |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004326a0 | SettingsFolderResolver | resolve settings folder path from settings file |
| 00432e50 | IterationCountMap | map session type to iteration count value |
| 00432e70 | AutoLoadEntryListLoader | load auto-load entry list if not already loaded |
| 004c40b0 | ConditionalDispatch_40b0 | resolve game filter data from path |
| 00587dd0 | sub_587DD0 | copy string with length limit to output |
| 00588410 | sub_588410 | compare two path strings |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | <= | 0 | nCount: if count <= 0, skip search and return default path |

**Guard interpretation:** Entry guard at `this+0x18` (bLoaded): if 0, calls AutoLoadEntryListLoader then rechecks. Then `this+0x28` (nCount) must be > 0 to proceed with search; if <= 0, skips to default path. Within search, `this+0x24` (pCurrent) null-check terminates loop. Per node: `*v9` (head data) null-check skips to default. Node traversal stops when next pointer is null or next node's first DWORD is zero.
