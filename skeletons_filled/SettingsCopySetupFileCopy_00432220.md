## SettingsCopySetupFileCopy_00432220 — SetupFileSceneIteratorAndCopier

**Summary:** Iterates scene entries, creates directory trees and copies settings/config files for each scene. When directory creation fails or config mismatch detected, builds a linked list of vehicle configuration entries (with .svm extension paths) and adds them via AddVehicleConfigEntryToLinkedList.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerNameSetup (004326e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | vtable/object base pointer — dereferenced to get array of path strings |
| this | 0x0 | R | — | root `this` pointer — dereferenced to read first pointer (directory path or null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c3fa8 | off_5C3FA8 | R | VTable_Base [DERIVED] |
| 005c403c | aSvm | R | FileExtSvm [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d03f8 | byte_7D03F8 | R | SessionConfigGate [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | safely indexes pointer array — checks bounds before accessing element |
| 00423a00 | BinarySearchInStringTable | searches string in hash/lookup table — returns non-zero if key found |
| 00432650 | StringCapitalizer | converts string to uppercase in place |
| 004326a0 | SettingsFolderResolver | extracts settings folder path from scene data at given offset |
| 00433b60 | AddVehicleConfigEntryToLinkedList | inserts a new vehicle configuration entry (path + data) into linked list |
| 0049adb0 | ShortComputation_adb0 | traverses to next linked-list entry — returns next node pointer |
| 004c5840 | SeasonRacesSectionFinder | locates season/races section within scene structure — returns non-zero if found |
| 005665b0 | sub_5665B0 | string copy/concat helper — copies source string into destination buffer |
| 00566650 | StringCopyWithBufferRealloc | copies string with dynamic buffer allocation/reallocation |
| 00566810 | sub_566810 | finds file extension (.svm) in path string and truncates at that point |
| 00567970 | DataEntryAccessor | retrieves data field value from linked-list entry (accesses payload) |
| 005679c0 | StringKeyedLinkedListSearch | finds linked-list entry by matching string key |
| 00568620 | sub_568620 | constructs path string with 255-char limit — likely snprintf-style |
| 00568b00 | sub_568B00 | error handler or empty no-op — called on AddVehicleConfigEntryToLinkedList failure |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (operator delete wrapper) |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory via nothrow operator new |
| 00588410 | sub_588410 | checks if scene-specific config file matches/is loadable — returns bool |
| 00589671 | CreateDirectoryAWrapper | creates directory via Win32 CreateDirectoryA — returns 0 on success |

**Guard conditions:** Loop guard: `dword_8AC488 > 0` — BLOCKED (no-op) when scene count is zero. Per-scene: `v26` (CreateDirectoryAWrapper failed → true) OR `v24` (sub_588410 returned 0 → config mismatch → set to 1) — if NEITHER fails, SKIP the vehicle-config linked-list build (no entries needed). Within inner loop: `v4` (SeasonRacesSectionFinder result) — if zero (no season section), skip linked-list traversal entirely. `byte_7D03F8` (SessionConfigGate): if zero, skip config-file matching sub_588410 call, v24 stays 0. `v24 && v27` at line 148: only on first iteration (v27=1) AND config mismatch, calls AddVehicleConfigEntryToLinkedList then may break out if directory creation succeeded (v26=0).