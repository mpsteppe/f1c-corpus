## NameListBuilderFromVehicleArray_004159b0 — NameListBuilderFromVehicleArray

**Summary:** Builds a deduplicated name list from the global vehicle array, then creates a secondary linked list of 172-byte commentary entries with TV/PWS path setup via sub_414A90, appending each to a doubly-linked list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5090 (00415090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | Next pointer in existing list for cleanup traversal |
| this | 0x10 | RW | 0 | Existing list head — zeroed after cleanup |
| this | 0x14 | RW | 0 | Existing list tail — zeroed after cleanup |
| this | 0x18 | RW | 0 | Existing list counter — zeroed after cleanup |
| this | 0x1C | RW | 0 | Existing list tracking field — zeroed after cleanup |

**Written-by note (persistence):**
- this 0x10: zeroed after cleanup
- this 0x14: zeroed after cleanup
- this 0x18: zeroed after cleanup
- this 0x1C: zeroed after cleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00415520 | SmallEntryStructInit | R | Function pointer used as array initializer for sub-struct arrays in commentary entries |
| 005ea438 | byte_5EA438 | R | Default path string fallback when a name pointer is null |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] — number of vehicles to iterate for name collection |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] — source vehicle data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | Array initializer — fills sub-struct arrays with SmallEntryStructInit callback |
| 00414a90 | sub_414A90 | Commentary PWS/TV path builder for each new entry |
| 00414d70 | TextFormatStructInitializer_4d70 | Resets/initializes text format struct in each commentary entry |
| 00415c30 | NullSafePointerDereference | Returns string pointer or default path fallback |
| 00418c10 | MemoryAllocation_8c10 | Allocates memory for list cleanup iteration |
| 00418d60 | DestructorWithDoubleFreePattern | Destructor called on name list entries after rebuild |
| 00434030 | DoublyLinkedListAppend | Appends entry to global doubly-linked list |
| 00566650 | StringCopyWithBufferRealloc | Copies and reallocates string data from vehicle array |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocator for name list nodes and commentary entries |
| 00588410 | sub_588410 | String comparison function used for deduplication (returns 0 on match) |

**Guard conditions:** If dword_8AC390 <= 0, skips name collection phase. Each vehicle name at offset +124 is checked for non-null before processing. Existing list at this[4] is iterated and entries freed via MemoryAllocation_8c10(1) before rebuild. PASSES: at least one vehicle with valid name; BLOCKED: no vehicles.
