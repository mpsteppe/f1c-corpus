## VehicleListBuilderFromGlobalArray_00415780 — VehicleListBuilderFromGlobalArray

**Summary:** Clears existing vehicle list, then builds a new linked list of 176-byte vehicle entries from the global vehicle array (stride 0x424). Each entry is initialized with sub-structs, text format reset, and driver file path setup via sub_414600.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5090 (00415090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Next pointer in list node for traversal during cleanup |
| obj | 0x0 | R | — | Pointer to the resource struct stored in the list node |
| obj | 0x8 | R | — | Flag byte at offset +8: 0 = skip, non-zero = active entry |
| this | 0x0 | RW | 0 | List head pointer — zeroed after cleanup, updated during rebuild |
| this | 0x4 | RW | 0 | List tail pointer — zeroed after cleanup, updated during rebuild |
| this | 0x8 | RW | 0 | Secondary list pointer — zeroed after cleanup, updated during rebuild |
| this | 0xC | RW | 0 | Entry count — zeroed after cleanup, incremented during rebuild |

**Written-by note (persistence):**
- this 0x0: set to 0 after cleanup; set to first list node during rebuild
- this 0x4: set to 0 after cleanup; updated as tail during rebuild
- this 0x8: set to 0 after cleanup; set to first node on initial insert
- this 0xC: set to 0 after cleanup; incremented for each entry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00415520 | SmallEntryStructInit | R | Function pointer used as array initializer for sub-struct arrays in new entries |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] — number of vehicle entries to process |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] — source vehicle data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | Array initializer — fills array elements with SmallEntryStructInit callback |
| 00414600 | sub_414600 | Driver file path builder for each vehicle entry |
| 004149a0 | TextFormatStructInitializer | Resets/initializes text format struct in each new entry |
| 00415520 | SmallEntryStructInit | Initializes small entry sub-structs within the 176-byte allocation |
| 00415900 | StructDestructor | Destructor called on existing active entries during cleanup |
| 00566650 | StringCopyWithBufferRealloc | Copies and reallocates string data from vehicle array |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing old list nodes during cleanup |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocator for new list nodes and 176-byte entries |

**Guard conditions:** During cleanup, each list node's flag byte (offset +8) is checked: if non-zero AND inner resource pointer (offset +0) is non-null, StructDestructor(1) is called. If dword_8AC390 (vehicle count) <= 0, returns 1 immediately (no entries to build).
