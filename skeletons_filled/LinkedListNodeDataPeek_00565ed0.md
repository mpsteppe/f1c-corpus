## LinkedListNodeDataPeek_00565ed0 — peek first node data payload

**Summary:** Returns pointer to data payload (+4 offset) from first linked list node, or 0 if list empty or node has no data. Lite accessor for file/directory enumeration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileEnumerationByExtension (00421b10), sub_47BF30 (0047bf30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x8) | 0x0 | R | — | data pointer from first node |
| obj | 0x8 | R | — | first node pointer (saved in list head) |
| this | 0x0 | R | — | pointer to list head structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 if node pointer (at obj+0x8) is NULL, or if node's data pointer (*v1) is NULL. On success returns data+4.
