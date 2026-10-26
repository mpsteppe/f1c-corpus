## LinkedListNodeRemovalWithMemoryFree_0057b050 — NetworkAddressListRemoveAndFree

**Summary:** Searches embedded linked list for node whose data matches a2. Unlinks node, decrements counter at offset 0x14. If node flag at offset 8 set, frees data. Frees node. Returns 1 on success, 0 on failure. Inverse of NetworkAddressListAppend.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x0 | R | — | node data field; compared against a2 for search |
| *(this+0xC) | 0x4 | R | — | node next pointer; read during traversal and unlinking |
| *(this+0xC) | 0x8 | R | — | node flag byte; checked to decide whether to free data |
| this | 0x8 | RW | — | linked list head (this[2]); updated if removing first node |
| this | 0xC | RW | — | linked list tail (this[3]); updated if removing last node |
| this | 0x10 | RW | — | secondary tail pointer (this[4]); updated if removing tail2 node |
| this | 0x14 | R | — | counter (this[5]); decremented on successful removal |

**Written-by note (persistence):**
- this 0x8: written on removal of first node; survives
- this 0xC: written on removal of last node; survives
- this 0x10: written on removal of tail2; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees node data (if flag set) and node itself |

**Guard conditions:** a2 null → return 0. Head (this[2]) null → return 0. Linear scan fails to find match → return 0. Found and unlinked → return 1 (PASSES).

