## MessageNameBufferUpdate_0046ad50 — MessageNameBufferUpdate

**Summary:** Builds display string for a menu item from action index. Retrieves module name from ppvOut array and action name from dword_7D1B08, copies to MessageDisplayBuffer (byte_5EC4CC) via binary search check, concatenates path/name into output buffer. Optionally creates UI menu item if flag a3 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionEntryListCleanup (0046ae60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default fallback directory path |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | R | MessageDisplayBuffer [DERIVED] — current message display buffer |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007d1b08 | dword_7D1B08 | R | ActionTypeArray [DERIVED] — action type array with stride 7 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | checks if string exists in string table before copying |
| 00455260 | sub_455260 | retrieves action name string from action type entry |
| 00455560 | ArrayIndexedAccessor | indexes into ppvOut array by a1 |
| 004894d0 | StrlenOverwrite | strlen-based buffer operation on output |
| 00489600 | UIMenuItemCreator | creates UI menu item if a3 flag is set |

**Guard conditions:** v3 (module ptr) AND a2 (output buffer) both non-null → enters build path. BLOCKED if either null → returns early.
