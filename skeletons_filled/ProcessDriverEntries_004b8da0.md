## ProcessDriverEntries_004b8da0 — ProcessDriverEntriesLoadConfig

**Summary:** Iterates through driver entry array (stride 4656), copies driver name strings from linked-list nodes matching a float key, resolves file paths, loads vehicle configurations, and adjusts vehicle count. Part of vehicle/driver loading system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiPathDispatcher (004ba180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x0 | R | — | float key of first linked list node (driver name match) |
| this | 0x40 | R | — | linked list head pointer within driver entry |
| this | 0x48 | RW | — | cursor pointer for list traversal within entry |
| this | 0x4C | R | — | element count or flag within entry |
| this | 0xF38 | R | — | float key value to match against list nodes |

**Written-by note (persistence):**
- this 0x48: updated during traversal; overwritten each entry iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | RW | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | driver entry array base |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc80 | BuildActiveVehiclePointerArray | rebuilds active vehicle pointer array |
| 004b50c0 | UtilityFunction_50c0 | compares float value against key for list traversal |
| 004c6980 | SetDriverName | updates driver name if changed |
| 004c69e0 | PathFilenameExtractor | extracts path/filename from driver entry |
| 004c6c40 | VehgenScnFileLoader | loads vehicle generation scene file |
| 004c6d90 | SceneRenderUpdate | updates scene rendering |
| 004c6e80 | sub_4C6E80 | handles driver entry removal/deactivation |
| 004c7b20 | TwoCallDelegation | two-call delegation for path processing |
| 004ef5a0 | SessionStateTransition | transitions session state |
| 00566650 | StringCopyWithBufferRealloc | copies driver name string with reallocation |
| 00588410 | sub_588410 | checks if file path already exists/loaded |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | == | 0 | driver entry's linked list head pointer |

**Guard interpretation:** If this+0x40 (linked list head) is NULL, the driver entry has no data to process — skips the name-copying inner block. If v24[445] (v17) is non-zero AND no matching path found, calls sub_4C6E80 to deactivate the entry and decrements vehicle count.
