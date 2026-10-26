## SeasonSceneMatchByIndex_004c4ff0 — Find vehicle in list matching a name string

**Summary:** Searches the linked list of vehicle indices for a vehicle whose name (from global vehicle array) matches the search string `a2`. Returns pointer to vehicle entry if found, storing match index in field 0x18; returns 0 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackSceneConfigLoader (00477680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | R | — | Data pointer from iterator's current node (vehicle index int) |
| *(this+0x8) | 0x0 | R | — | Data pointer from head node (first vehicle index to check) |
| this | 0x8 | R | — | Head pointer of linked list |
| this | 0x10 | RW | — | Current iteration pointer; advanced per node during search |
| this | 0x14 | R | — | Count of items (unused in search logic) |
| this | 0x18 | RW | 0 | Stores index of matching node if found, or 0 if not found |

**Written-by note (persistence):**
- this 0x10: rewritten as traversal advances; final value is last node visited or null
- this 0x18: set to match index (0-based position in list) on success, 0 on failure

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | Compare search string against vehicle name; returns 0 on match, non-zero on mismatch |

**Guard conditions:** Returns 0 (null) immediately if `this[2]` (head) is null or `*head`'s data pointer is null. For each node: if vehicle entry exists, compare search string `a2` against vehicle name via `sub_588410` — if match (returns 0), break and store position. If vehicle name pointer is null, uses default path `byte_5EA438` as name. If list exhausted without match, stores 0 in this[6] and returns null.
