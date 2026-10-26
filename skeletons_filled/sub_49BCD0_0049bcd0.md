## sub_49BCD0_0049bcd0 — secondary string-table lookup and copy

**Summary:** Binary-searches a secondary string table; on match, copies the found string into the MessageDisplayBuffer and then into the caller-supplied output buffer with null-termination.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D700 (0049d700), MultiLayerTextStringRenderer (004dbc90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccbcc | off_5CCBCC | R | pointer to secondary string table used for binary search |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | search a sorted string table for a key string; returns non-zero on match |
| 00587dd0 | sub_587DD0 | copy or concatenate string from MessageDisplayBuffer into output buffer up to given length |

**Guard conditions:** `BinarySearchInStringTable(byte_5EC4C0, off_5CCBCC[0], byte_5EC4CC)` — if false, the copy of v2 into MessageDisplayBuffer is SKIPPED. If true, `v2` null-check determines whether to strcpy or null-terminate. Execution always continues to `sub_587DD0`.
