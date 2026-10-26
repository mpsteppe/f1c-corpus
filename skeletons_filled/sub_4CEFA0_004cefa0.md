## sub_4CEFA0_004cefa0 — ArraySearchAndWheelContactParticle

**Summary:** Searches a strided array (108 bytes per entry) for an element whose slot at +4 matches a3. On match, calls WheelContactParticle to spawn a contact particle effect at that entry's position. Returns the entry index or array count if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIWaypointPathCheckerRenderer (004024f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | entry type/ID field at offset 4 of each array element |
| this | 0x10 | R | — | array element count |
| this | 0x14 | R | — | pointer to first array element |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd6c0 | WheelContactParticle | spawn wheel contact particle effect at matched entry |

**Guard conditions:** Array count (this+0x10) > 0. PASSES: linear search through 108-byte-stride entries matching *(entry+4) == a3. BLOCKED (<= 0): return 0 immediately.
