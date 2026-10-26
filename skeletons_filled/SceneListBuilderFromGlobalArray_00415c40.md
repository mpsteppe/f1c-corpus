## SceneListBuilderFromGlobalArray_00415c40 — SceneListBuilderFromGlobalArray

**Summary:** Clears existing scene list, then builds a new linked list of 92-byte scene entries from the global scene array (stride 0x18c). Each entry is initialized with sub-structs, text format reset, and track TV/PWS path setup via CommentaryTVPWSPathBuilder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5090 (00415090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x24) | 0x4 | R | — | Next pointer in list node for traversal during cleanup |
| this | 0x20 | RW | 0 | List head — zeroed after cleanup, updated during rebuild |
| this | 0x24 | RW | 0 | List tail — zeroed after cleanup, updated during rebuild |
| this | 0x28 | RW | 0 | Secondary list pointer — zeroed after cleanup, updated during rebuild |
| this | 0x2C | RW | 0 | Entry count — zeroed after cleanup, incremented during rebuild |

**Written-by note (persistence):**
- this 0x20: set to 0 after cleanup; set to first list node during rebuild
- this 0x24: set to 0 after cleanup; updated as tail during rebuild
- this 0x28: set to 0 after cleanup; set to first node on initial insert
- this 0x2C: set to 0 after cleanup; incremented for each entry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] — number of scene entries to process |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — source scene data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414e60 | CommentaryTVPWSPathBuilder | Builds track TV/PWS commentary paths for each scene entry |
| 00414fe0 | TextFormatStructInitializer_4fe0 | Resets/initializes text format struct variant in each new entry |
| 00415520 | SmallEntryStructInit | Initializes small entry sub-structs within the 92-byte allocation |
| 00418cf0 | ShortComputation_8cf0 | Destructor called on existing active entries during cleanup |
| 00566650 | StringCopyWithBufferRealloc | Copies and reallocates string data from scene array |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing old list nodes during cleanup |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocator for new list nodes and 92-byte entries |

**Guard conditions:** During cleanup, each list node's flag byte (offset +8) is checked: if non-zero AND inner resource pointer (offset +0) is non-null, ShortComputation_8cf0(1) is called. If dword_8AC488 (scene count) <= 0, returns 1 immediately (no entries to build).
