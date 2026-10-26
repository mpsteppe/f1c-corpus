## FrontendScreenLoadingDisplayHandler_00476250 — FrontendLoadingAudioPlayHandler

**Summary:** Loads and plays frontend audio for a season scene path. Resolves scene name and season directory, builds path, loads audio, then dispatches display commands.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | vtable entry accessed via virtual call at offset 28 |
| this | 0x40 | R | — | internal container/accessor used to retrieve an object by ID |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007cd8bc | String1 | R | LocaleTestStringA [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00476f90 | SingleFunctionDispatch_6f90 | dispatches a single command function |
| 0048f590 | LinkedListIndexedAccessor_f590 | retrieves an indexed element from a linked list |
| 00566650 | StringCopyWithBufferRealloc | copies a string with automatic buffer reallocation |
| 00567a00 | StructZeroInit_7a00 | zero-initializes a stack structure |
| 00567a30 | LinkedListDestructorWithInnerFree | destroys a linked list and frees inner elements |
| 00567f40 | AudioFileLoadDecode | loads and decodes an audio file from path |
| 005681f0 | ConditionalDispatch_81f0 | conditionally dispatches based on game filter string |
| 0058969d | StringFormatProcessingWithNullTerm | formats a string with null termination and size limit |

**Guard conditions:** `LinkedListIndexedAccessor_f590()` returns 0 → skip all; virtual call on `this[16]` with arg 1 returns 0 → skip; `dword_7CD8C0` dispatch(21) returns 0 → skip; `StringFormatProcessingWithNullTerm()` returns < 0 → skip; `AudioFileLoadDecode()` returns != 1 → skip audio/display section
