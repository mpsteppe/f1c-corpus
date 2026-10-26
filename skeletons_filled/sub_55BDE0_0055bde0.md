## sub_55BDE0_0055bde0 — LinkedListNodeGetByIndex

**Summary:** Walks the linked list (head at this[72]) and returns the node pointer at index a2. Each node uses offset 0x20 (field [8]) as next pointer. If index out of range or chain broken, returns current node or 0. Part of linked list accessor utilities.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalGuardedFieldReader (004f91b0), GuardedFieldAccessor (004f9200), sub_53F3F0 (0053f3f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x140) | 0x20 | R | — | Next pointer in linked list node (offset 0x20 = field [8]) |
| this | 0x11C | R | — | Count/upper bound (this[71]) — if a2 >= count, return 0 |
| this | 0x120 | R | — | Linked list head pointer (this[72]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 >= this[71] (count), returns 0. Iterates up to a2 steps following next pointers at node+0x20; breaks early if next pointer is null. Returns pointer to node at index a2 (or last reachable node).
