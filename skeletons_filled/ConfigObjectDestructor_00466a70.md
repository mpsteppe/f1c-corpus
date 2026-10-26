## ConfigObjectDestructor_00466a70 — ConfigObjectDestructor

**Summary:** Destructor for a config/command-binding object. Frees linked list of allocations at this+0x44 (each node: data ptr, next ptr, flag byte). Resets list head/tail fields to 0. Calls StringCopyWithBufferRealloc, VehicleStatsEstimationDisplay (conditional on byte_7C7064), and LinkedListInsertWithNodeAllocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | data pointer in linked list node |
| *(this+0x48) | 0x4 | R | — | next pointer in linked list node |
| this | 0x44 | RW | 0 | linked list head pointer, cleared to 0 |
| this | 0x48 | RW | 0 | linked list tail pointer, cleared to 0 |
| this | 0x4C | RW | 0 | linked list count, cleared to 0 |
| this | 0x50 | RW | 0 | linked list field, cleared to 0 |
| this | 0x104 | RW | — | field 65 — set from dword_7C7368 indexed by this[66] |
| this | 0x108 | R | — | field 66 — index into dword_7C7368 |

**Written-by note (persistence):**
- this 0x44: cleared to 0 (destructor). External poke survives.
- this 0x48: cleared to 0 (destructor). External poke survives.
- this 0x4C: cleared to 0 (destructor). External poke survives.
- this 0x50: cleared to 0 (destructor). External poke survives.
- this 0x104: overwritten once (destructor). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c670c | aCustom_0 | R | StringCustom [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] |
| 007c7064 | byte_7C7064 | R | SceneDestroyedFlag [DERIVED] |
| 007c7368 | dword_7C7368 | R | CommandBindingsArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00430f00 | VehicleStatsEstimationDisplay | display vehicle stats estimation |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert custom config node into list |
| 00566650 | StringCopyWithBufferRealloc | copy/update string buffer |
| 00587bcf | FreeWrapper_7bcf | free allocated memory |

**Guard conditions:** If byte_7C7064 (SceneDestroyedFlag) is zero → call VehicleStatsEstimationDisplay (PASS). Otherwise skip (BLOCKED). Node iteration: checks flag byte at node+8; if set → free node's data pointer and node struct.
