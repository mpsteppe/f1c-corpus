## LinkedListFloatSearch_00548a00 — LinkedListFloatValueSearch

**Summary:** Walks a linked list from this[0x2C] and returns the first node whose float field at offset 0x8 matches search value `a2`. Returns 0 if list is empty or no match found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x8 | R | — | Float value used as search key in each node |
| *(this+0x40) | 0x14 | R | — | Next-node pointer in the linked list |
| this | 0x2C | R | — | Head pointer to the linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x2C] (head pointer) must be non-null — if null, returns 0 immediately. Loop compares node's float at offset 0x8 against a2; if equal, returns node. If not equal and next pointer at offset 0x14 is NULL, returns 0.
