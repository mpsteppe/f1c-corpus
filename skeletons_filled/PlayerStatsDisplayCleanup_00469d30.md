## PlayerStatsDisplayCleanup_00469d30 — PlayerStatsDisplayCleanup

**Summary:** Destroys the existing linked list of stat entries, repopulates it with 3 stat keys (Circuit, ExperienceLaps, BestLap), calls state cleanup, builds the stats display page via sub_469900, and resets a flag. Belongs to career mode player stats display system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | linked list node data pointer (string) |
| *(this+0x48) | 0x4 | R | — | linked list node next pointer |
| this | 0x44 | RW | 0 | linked list head pointer (this[17]); cleared after destruction |
| this | 0x48 | RW | 0 | linked list tail pointer (this[18]); cleared after destruction |
| this | 0x4C | RW | 0 | linked list node count (this[19]); cleared after destruction |
| this | 0x50 | RW | 0 | linked list capacity (this[20]); cleared after destruction |

**Written-by note (persistence):**
- this 0x44: set to 0 after list destruction; then rebuilt with stat insertions.
- this 0x48: set to 0 after list destruction; then rebuilt.
- this 0x4C: set to 0 after list destruction; then rebuilt.
- this 0x50: set to 0 after list destruction; then rebuilt.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6900 | aExperienceLaps | R | String_ExperienceLaps [DERIVED] |
| 005c6914 | aBestLap | R | sBestLap [DERIVED] |
| 005c6920 | aCircuit | R | StatKey_Circuit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00469900 | sub_469900 | builds player stats display page from race result data |
| 00486f30 | LinkedListInsertWithNodeAllocation | inserts a stat key string into the linked list |
| 00489cb0 | StateCleanupNotification | performs state cleanup notification |
| 0048a3b0 | ByteSetterAt0xe0 | sets a byte at offset 0xE0 in some global/context to 0 |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated node data and node structures |

**Guard conditions:** For each linked list node during destruction, checks byte at node+8 (free flag). If non-zero (PASSES), frees inner data and node struct. If zero (BLOCKED), frees only node struct. No early return — always destroys list, inserts 3 stat keys, calls sub_469900, and resets flag.
