## IndexedLinkedListNodeGetter_0057b0d0 — NetworkAddressListGetByIndex

**Summary:** Returns data pointer (node+0) from linked list at index a2. Bounds-checked against counter at offset 0x14. Walks list from head (offset 0x8) via next pointers (node+4). Returns 0 on bounds failure or node not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendWithQueryMatching (0057d8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | linked list head pointer (this[2]); start of traversal |
| this | 0xC | R | — | part of linked list struct; not directly read in C |
| this | 0x10 | R | — | part of linked list struct; not directly read in C |
| this | 0x14 | R | — | counter (this[5]); upper bound for index validation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 < 0 OR a2 >= counter(this[5]) → return 0. If a2 > 0 and traversal exhausts nodes → return 0. If target node is null → return 0. Node found → return node->data (PASSES).

