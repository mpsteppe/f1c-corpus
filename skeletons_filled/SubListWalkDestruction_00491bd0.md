## SubListWalkDestruction_00491bd0 — EmbeddedListWalkDestroy

**Summary:** Destroys an embedded linked list at `*this + 12`: prepends each node's value to another list (reparent), then frees all node memory (with conditional value free). Zeros the 4-DWORD list sentinel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0xC)+0x4) | 0x4 | R | — | Next pointer of first node in sub-list (read for iteration) |
| *(obj+0x14) | 0x0 | R | — | Value of node at current iteration position (reparent target) |
| *(obj+0x14) | 0x4 | R | — | Next pointer of node at current iteration position |
| *(obj+0xC) | 0x0 | R | — | Value pointer of first node in sub-list |
| *(obj+0xC) | 0x8 | R | — | Flags byte (+8) of first node in sub-list |
| obj | 0xC | RW | 0 | Sub-list head pointer (zeroed after destruction) |
| obj | 0x10 | RW | 0 | Sub-list tail pointer (zeroed after destruction) |
| obj | 0x14 | RW | 0 | Sub-list current/iteration pointer (zeroed after destruction) |
| obj | 0x18 | RW | 0 | Sub-list node count (zeroed after destruction) |
| this | 0x0 | R | — | Pointer to struct containing embedded sub-list at offset 12 |

**Written-by note (persistence):**
- obj 0xC: zeroed after destruction; destroyed
- obj 0x10: zeroed after destruction; destroyed
- obj 0x14: zeroed after destruction; destroyed
- obj 0x18: zeroed after destruction; destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | Prepend each node's value to another list (reparent before free) |
| 00587bcf | FreeWrapper_7bcf | Free node memory (and match value if flags byte is non-zero) |

**Guard conditions:** Phase 1 (reparent): if head `*(*this + 12)` is null → skip. If first value `**(void***)(*this+12)` is null → skip. Iteration stops when current pointer `*(*this + 20)` is null, or next current is null, or next value is null. Phase 2 (free): walks from head pointer; stops when null. After both phases, zeros all 4 sentinel fields.
