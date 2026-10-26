## ListWalkWithUserCancelCheck_004b5460 — List Walk With Cancel Check

**Summary:** Walks a linked list, testing each node's first field via FieldCompareConstant. Returns 0 if a node fails the comparison (user cancel detected), 1 if list is empty or all nodes pass.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | Pointer to list head node |
| this | 0x28 | RW | — | Current walk position pointer (advanced through list) |
| this | 0x2C | R | — | unknown |

**Written-by note (persistence):**
- this 0x28: Written each call with current walk pointer; overwritten on every invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005001d0 | FieldCompareConstant | Tests whether a node's first field matches a constant value |

**Guard conditions:** If this[0x20] (head pointer) is NULL, return 1 immediately — empty list. If head node's first DWORD is 0, return 1. While FieldCompareConstant(node) returns TRUE (field matches constant), advance to next node; if next pointer is NULL or its first DWORD is 0, return 1 (end of list). Return 0 only when FieldCompareConstant returns FALSE (mismatch = cancel detected).
