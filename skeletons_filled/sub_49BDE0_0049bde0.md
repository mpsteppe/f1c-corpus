## sub_49BDE0_0049bde0 — third string-table lookup and copy

**Summary:** Binary-searches a third string table (off_5CCBE4); on match, copies the found string into MessageDisplayBuffer and then into the caller-supplied output buffer with null-termination.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_d8b0 (0049d8b0), MultiColorTextRender (004dbf90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccbe4 | off_5CCBE4 | R | Ptr_FunctionTable2 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | search a sorted string table for a key string; returns non-zero on match |
| 00587dd0 | sub_587DD0 | copy or concatenate string from MessageDisplayBuffer into output buffer up to given length |

**Guard conditions:** `BinarySearchInStringTable(byte_5EC4C0, off_5CCBE4[0], byte_5EC4CC)` — if false, the copy of v2 into MessageDisplayBuffer is SKIPPED. If true, `v2` null-check determines whether to strcpy or null-terminate. Execution always continues to `sub_587DD0`.
