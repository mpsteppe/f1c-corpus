## LinkedListFieldReader_00491d10 — LinkedListAdvanceAndRead

**Summary:** Advances linked list iterator stored at struct offset 0x24: if current node pointer is non-null, follows its next pointer (+4) to advance. Returns first DWORD of new current node, or 0 if end of list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderDispatchWithIteration (004993d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x24) | 0x0 | R | — | First DWORD (value) of the node pointed to by current pointer — returned if non-null |
| *(obj+0x24) | 0x4 | R | — | Next pointer (offset +4 in node) — used to advance the current pointer |
| obj | 0x24 | RW | — | Current iteration pointer — advanced to node->next if non-null |
| this | 0x0 | R | — | Pointer to struct; *this contains current pointer at offset 0x24 |

**Written-by note (persistence):**
- obj 0x24: conditionally written each call (advanced to next node); persists across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If current pointer at offset 0x24 is null → skip advance (remain null). If (potentially advanced) current at offset 0x24 is null → return 0. Otherwise return first DWORD of current node.
