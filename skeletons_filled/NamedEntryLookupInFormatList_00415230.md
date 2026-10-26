## NamedEntryLookupInFormatList_00415230 — NamedEntryLookupInFormatList

**Summary:** Searches a linked list of named format entries for a matching string and index, creating and appending a new 176-byte entry if not found. The new entry is initialized with sub-structs, a text format reset, and driver file path setup via sub_414600; on failure the entry is freed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5730 (00415730), SeasonDisplayIDResolver (0041daf0), PositionChangeDetector (00420490), VehicleSetupDriverNumber (004c7b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | Data pointer inside a list node |
| *(obj+0x4) | 0x8 | R | — | String pointer inside a list node's data |
| obj | 0x4 | R | — | Next pointer in linked list node (singley linked) |
| obj | 0x8 | R | — | Flag/active byte for list node |
| this | 0x0 | RW | — | Head pointer of the linked list |
| this | 0x4 | RW | — | Current/tail pointer for list append |
| this | 0x8 | RW | — | Previous node pointer for list insertion |
| this | 0xC | RW | — | Count of entries in the list |

**Written-by note (persistence):**
- this 0x0: updated when list is empty and first entry added
- this 0x4: updated on each new entry (tail pointer)
- this 0x8: updated when list is empty (also tracks last entry)
- this 0xC: incremented on each new entry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00414370 | ShortComputation_4370 | R | Function pointer used as array destructor callback for sub-array cleanup on failure |
| 00415520 | SmallEntryStructInit | R | Function pointer used as array initializer for sub-struct arrays in new entries |
| 005ea438 | byte_5EA438 | R | Default path string fallback when a string pointer is null |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | Array initializer — fills array elements with SmallEntryStructInit callback |
| 00401030 | ArrayDestructorIterator | Iterates and destroys array elements via callback; used on entry cleanup after failure |
| 00414370 | ShortComputation_4370 | Element-wise destructor callback for cleanup on allocation failure |
| 00414600 | sub_414600 | Driver file path builder; if returns 0 (success) the new entry is kept, if fails the entry is freed |
| 004149a0 | TextFormatStructInitializer | Resets/initializes text format struct in new entry |
| 00415520 | SmallEntryStructInit | Initializes small entry sub-structs within the new 176-byte allocation |
| 004b0b20 | sub_4B0B20 | String copy helper with max length (127 chars) |
| 004c3f80 | VehicleLookupByName | Looks up vehicle by name string |
| 004c4080 | CurrentVehicleAccessor | Gets current vehicle data from global buffer |
| 00566650 | StringCopyWithBufferRealloc | Copies and reallocates a string buffer |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing allocations on failure |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocator (malloc wrapper) for new list nodes and entries |
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions:** If a2 (input name) is null, returns -1. If this[3] (count) <= 0, returns -1. Iterates existing entries comparing strings; if match found returns entry index. If no match, allocates new 176-byte entry, initializes it, calls sub_414600 for path setup. If sub_414600 fails (returns non-zero), entry is freed and function returns -1. On success, appends to list and returns new index.
