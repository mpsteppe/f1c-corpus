## VehicleFileLoader_004c3d80 — VehicleFileLoader

**Summary:** Bulk-loads .veh vehicle files from the season directory. Scans directory for matching files, allocates/reallocates a vehicle data array (1060 bytes per entry), parses each file via VehFileParser, and updates the global vehicle count. Cleans up existing array before reload.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] — "%s%s" format for path construction |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] — "%s%s%s" format for full file path |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] — version/format identifier for error check |
| 005d307c | aFailedReadingD | R | FailedReadingField [DERIVED] — "Failed reading %s" error log format |
| 005d3098 | aVeh | R | VehExtension [DERIVED] — ".veh" file filter extension |
| 005ea438 | byte_5EA438 | R | default application directory, fallback for null paths |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] — season directory path |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] — season name string |
| 008ac390 | dword_8AC390 | RW | VehicleFileCount [DERIVED] — count of successfully loaded vehicles |
| 008ac394 | dword_8AC394 | RW | VehicleArray (stride 0x424) [DERIVED] — pointer to 1060-byte vehicle entries |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] — buffer for error logging |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] — directory scan state structure |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3050 | sub_4C3050 | initialize a single vehicle entry (1060 bytes) |
| 004c3130 | MultiFieldCleanup | cleanup/release a vehicle entry's allocated fields |
| 004c3200 | VehFileParser | parse a .veh file into a vehicle entry |
| 004c4240 | VehicleDataLoader | finalize vehicle data loading for this object |
| 004d7a50 | StringSplitLoop | check/fix file format version compatibility |
| 004d7aa0 | DebugLogWrite | write error message to debug log |
| 00565eb0 | sub_565EB0 | initialize directory scan |
| 00565f20 | LinkedListNodePeek | check if more directory entries remain |
| 00565f50 | LinkedListPopFront_5f50 | pop front node from scan list |
| 00565f70 | ShortComputation_5f70 | count .veh files matching filter |
| 00565f80 | sub_565F80 | set file filter pattern (".veh") |
| 005662d0 | DirectoryEntryIterator | iterate to next directory entry |
| 00566650 | StringCopyWithBufferRealloc | realloc-copy file path string |
| 00587bcf | FreeWrapper_7bcf | deallocate old vehicle array |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for vehicle array |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string format with bounds check |
| 00589901 | sub_589901 | check/validate file path before parsing |

**Guard conditions:** Null checks on dword_5EC428 and dword_5EC3D8 fall back to default directory. Existing vehicle array at dword_8AC394 is cleaned up if non-null. Directory iteration loop continues while DirectoryEntryIterator returns non-null; LinkedListNodePeek check breaks early if no more entries. VehFileParser success (returns 0) increments vehicle count; failure logs error.
