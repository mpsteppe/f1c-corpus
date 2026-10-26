## LinkedListNodeRemovalWithCleanup_004c1820 — LinkedListNodeRemoveWithCleanup

**Summary:** Removes a node from a singly-linked list by matching its data pointer against LinkedListDereference result. Updates head/tail/count metadata, optionally frees the node's data payload if ownership flag is set, then deallocates the node. Returns 1 on success, 0 if target not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NodeAllocListInsert (004c2780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | node data pointer, matched against target value |
| *(obj+0x4) | 0x4 | R | — | node next pointer, used for traversal |
| *(obj+0x4) | 0x8 | R | — | node ownership flag byte, checked before data cleanup |
| obj | 0x4 | RW | — | node next pointer, relinked during removal |
| this | 0x0 | RW | — | list head pointer, updated if removing first node |
| this | 0x4 | RW | — | list head/tail pointer, updated if removing tracked node |
| this | 0x8 | RW | — | list tail/special pointer, updated if removing tracked node |
| this | 0xC | R | — | list node count, decremented on removal |

**Written-by note (persistence):**
- obj 0x4: node is freed — pointer invalidated
- this 0x0: updated if head node removed — external poke survives
- this 0x4: updated if tracked node removed — external poke survives
- this 0x8: updated if tracked node removed — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0b10 | PitStopMemoryCleanup | cleanup/release pit stop memory from removed node's data |
| 004c2850 | LinkedListDereference | dereference/search helper returning target data pointer |
| 00587bcf | FreeWrapper_7bcf | deallocate memory block |

**Guard conditions:** LinkedListDereference must return non-null target. List head must be non-null. Target node must exist in list (full walk; if next becomes null before match, return 0). Node ownership flag (byte at offset 8) must be non-zero AND data pointer at offset 0 must be non-null before data cleanup is performed.
