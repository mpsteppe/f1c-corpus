## PITANIMSMASAnimationFileLoader_004a3220 — PITANIMSMASAnimationFileLoader

**Summary:** Loads pit crew animation data from the "PITANIMS.MAS" archive file. Cleans up existing resources, resolves the base directory path, opens the MAS file via sub_53CBC0, calls PitCrewAnimationLoader to parse animation data, then closes the file and cleans up string resources.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A4900 (004a4900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd480 | aPitanimsMas | R | StringPitAnimsMas [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a29a0 | ArrayResourceCleanup | cleans up existing pit crew animation array before reloading |
| 004a2a90 | PitCrewAnimationLoader | main loader that parses animation data from the opened file |
| 0053c800 | StringRegistry | registers directory path with string manager |
| 0053c900 | StringMatchWithFlagSet | registers directory path for string matching with flag tracking |
| 0053cbc0 | sub_53CBC0 | opens/initializes file handle for the PITANIMS.MAS archive |
| 0053ce40 | PhysicsObjectLinkedListRemoval | closes/releases the PITANIMS.MAS file handle |
| 00566650 | StringCopyWithBufferRealloc | copies source path string to allocated buffer |
| 00587bcf | FreeWrapper_7bcf | frees the allocated string buffer |

**Guard conditions:** No internal guard branches on struct fields. If the trailing-backslash find loop finds no backslash in byte_5EA438, the directory string is left unchanged. If v13 (allocated path copy) is null, uses byte_5EA438 directly.
