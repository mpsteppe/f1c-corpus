## LinkedListNodeRemoval_00464740 — Linked list node removal with conditional free

**Summary:** Traverses singly-linked list from head, removes node matching a2, updates head/tail/prev pointers, decrements count, conditionally frees node's embedded data and node itself based on flag at node+8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | Next pointer of previous node (read to relink) |
| obj | 0x4 | RW | — | Node's next pointer |
| obj | 0x8 | R | — | Flag byte controlling whether to free node's embedded data |
| obj | 0xC | RW | 0 | Node value / identifier (not used after removal) |
| this | 0x0 | RW | — | Linked list head pointer |
| this | 0x4 | RW | — | Linked list tail pointer |
| this | 0x8 | RW | — | Newest/tail tracking pointer |
| this | 0xC | R | — | Node count (decremented on removal) |

**Written-by note (persistence):**
- obj 0x4: cleared when node is removed (next pointer lost)
- obj 0xC: written once during node creation (value)
- this 0x0: overwritten when head node removed
- this 0x4: overwritten when tail node removed
- this 0x8: overwritten when tail node removed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** If a2 is 0, return 0 (BLOCKED). If head (*this) is NULL, return 0 (BLOCKED). If node not found in list (traversal ends), return 0 (BLOCKED). Otherwise, node removed and freed (PASSES).
