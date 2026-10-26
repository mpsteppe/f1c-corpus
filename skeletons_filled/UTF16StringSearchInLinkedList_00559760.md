## UTF16StringSearchInLinkedList_00559760 — StringNodeListSearch

**Summary:** Walk linked list of string nodes, compare each node's string with target via strcmp, return matching node pointer or 0 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5594B0 (005594b0), sub_559820 (00559820), sub_5598B0 (005598b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x1C) | 0x1C | R | — | Next pointer within each linked list node |
| this | 0x0 | R | — | Head pointer of linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Head pointer — null means empty list |
| (walk) | *(obj+0x1C) | == | 0 | Next pointer — null means end of list |

**Guard interpretation:** First guard: if head null, return 0 immediately (BLOCKED). Walk: compare node string via strcmp; PASS if match (return node), BLOCKED if no match and next is null (return 0).
