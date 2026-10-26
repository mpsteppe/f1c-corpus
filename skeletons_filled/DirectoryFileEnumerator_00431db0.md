## DirectoryFileEnumerator_00431db0 — Directory File Enumerator

**Summary:** Enumerates files and subdirectories in a given path using Windows FindFirstFile/FindNextFile API. Builds two sorted linked lists — one for regular files and one for subdirectories — skipping "." and ".." entries, with automatic path separator normalization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSetupFileRead (00432180), Wrapper (004326d0), PathNormalizerFileEnumeration (00432980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x8 | R | — | linked list node next-pointer field within file list |
| *(this+0x30) | 0x8 | R | — | linked list node next-pointer field within directory list |
| this | 0x0 | R | — | base directory path string pointer (falls back to byte_5EA438 if null) |
| this | 0x8 | R | — | search pattern or extension filter string pointer (falls back to byte_5EA438 if null) |
| this | 0x1C | R | — | enumeration counter (incremented by 1 each call, v13[7]) |
| this | 0x20 | RW | 0 | file list head pointer (doubly-linked list of file entry nodes) |
| this | 0x24 | RW | 0 | file list tail pointer (last node in file list) |
| this | 0x28 | RW | 0 | file list end marker (duplicate tail reference for iteration) |
| this | 0x2C | RW | 0 | file list node count |
| this | 0x30 | RW | 0 | directory list head pointer (doubly-linked list of subdirectory entry nodes) |
| this | 0x34 | RW | 0 | directory list tail pointer |
| this | 0x38 | RW | 0 | directory list end marker |
| this | 0x3C | RW | 0 | directory list node count |

**Written-by note (persistence):**
- this 0x20: set once per enumeration call — external poke survives until next enumeration
- this 0x24: set once per enumeration call — external poke survives until next enumeration
- this 0x28: set once per enumeration call — external poke survives until next enumeration
- this 0x2C: set once per enumeration call — external poke survives until next enumeration
- this 0x30: set once per enumeration call — external poke survives until next enumeration
- this 0x34: set once per enumeration call — external poke survives until next enumeration
- this 0x38: set once per enumeration call — external poke survives until next enumeration
- this 0x3C: set once per enumeration call — external poke survives until next enumeration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0e0 | FindFirstFileA | R | Windows API: begins directory enumeration, returns search handle |
| 0059e0e4 | FindNextFileA | R | Windows API: continues directory enumeration for next entry |
| 0059e0e8 | FindClose | R | Windows API: closes the search handle after enumeration |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] — current directory sentinel "." string for filtering |
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c2ab4 | asc_5C2AB4 | R | FileExtGDBBytes [DERIVED] — file extension bytes appended to search path |
| 005c2ab8 | dword_5C2AB8 | R | SceneExtension [DERIVED] — scene file extension string appended to search |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| ff00000000005396 | byte_FF00000000005396 | R | unknown — likely 0xFF memory sentinel or guard page data |
| ff0000000000539e | byte_FF0000000000539E | R | unknown — likely 0xFF memory sentinel or guard page data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | safely dereferences a pointer with null check, returns pointer or safe default |
| 00434030 | DoublyLinkedListAppend | appends a new node to the end of the directory linked list |
| 00434090 | LinkedListMergeSort | sorts linked list by merging (called on single-element lists) |
| 00434290 | LinkedListMergeSort_4290 | primary merge sort routine for linked list sorting |
| 00434420 | DoublePointerFree | frees memory pointed to by a double pointer |
| 004bac20 | ShortComputation_ac20 | wraps a data node into a container struct for the linked list |
| 005665b0 | sub_5665B0 | appends string data to the path buffer (string concatenation helper) |
| 00566650 | StringCopyWithBufferRealloc | copies string into buffer, reallocating if needed |
| 00568910 | sub_568910 | formats/constructs string into a 256-byte stack buffer |
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation wrapper (nothrow) |

**Guard conditions:** from code — field, checked values, what PASSES vs what is BLOCKED
- **a2 (path parameter):** if non-null → copies a2 into path buffer (PASSES: custom path used). If null → uses this->0x0 and this->0x8 fields with default fallback to byte_5EA438 (PASSES: legacy/default path enumeration).
- **Last char check:** if path buffer is non-empty and last char before null is not backslash (0x5C = '\\') → appends backslash (PASSES: path separator normalized). Already ending with '\\' → BLOCKED: no append needed.
- **FindFirstFileA return:** if handle == INVALID_HANDLE_VALUE (-1) → sets return value to 0 (BLOCKED: no files found, enumeration fails). Otherwise → enters enumeration loop (PASSES: files processed).
- **dwFileAttributes & 0x10:** if file is a directory (bit 0x10 set) → directory list processing path (PASSES: added to subdirectory list after "."/".." filter). If regular file → file list path (PASSES: added to file list).
- **"." and ".." filter:** if cFileName equals "." or ".." → BLOCKED: skipped, not added to any list. Otherwise → PASSES: entry added to directory list.
