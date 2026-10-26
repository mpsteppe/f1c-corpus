## SetupFileLoadAndFinalize_00469630 — SetupFileLoadAndFinalize

**Summary:** Loads a setup file by retrieving a filename from a linked list, stripping its extension, copying season directory path, dispatching file copy check, loading an audio file, and processing sub-objects via vtable methods. Belongs to setup/configuration file loading system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | vtable method offset 28 (0x1C) on sub-object this[16]; called with args 29 and 2 |
| this | 0x40 | R | — | pointer to sub-object with vtable (this[16]); used to retrieve objects by ID |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004693e0 | FilenameFromLinkedList | retrieves setup filename from linked list by index |
| 00470190 | sub_470190 | processes an object obtained via vtable call |
| 0048d360 | GuardedAccessor | obtains index/token for filename retrieval |
| 004b04e0 | StringCopyFileCheckDispatch | copies or dispatches file for setup loading |
| 00566650 | StringCopyWithBufferRealloc | copies filename string with potential reallocation |
| 00567f40 | AudioFileLoadDecode | loads and decodes an audio file from constructed path |
| 005684a0 | ObjectIDLookupAcross9Arrays | looks up object ID across multiple arrays for path construction |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (not directly called in decompiled code) |
| 0058969d | StringFormatProcessingWithNullTerm | constructs path string with format and null termination |

**Guard conditions:** Checks FilenameFromLinkedList result for null or empty (return 0 early, BLOCKED). Checks dword_7D0434 (SeasonPath) and dword_5EC3D8 (SeasonDir) for null (default to byte_5EA438). Compares season path against default via strcmp to decide whether to load audio. Checks StringFormatProcessingWithNullTerm return value >= 0 before calling ObjectIDLookupAcross9Arrays and AudioFileLoadDecode. Checks vtable method results (v10, v11) for null before processing objects.
