## CreditsTxtParser_00467e40 — CreditsTxtParser

**Summary:** Opens and parses the "credits.txt" file from the application directory, reading lines into a linked list of string nodes. Each line is split at a delimiter, allocated as a node, and appended to the list. Belongs to credits/menu text loading system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuLayoutCalculator (00467dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF8 | RW | — | linked list head pointer (this[62]); set to first node |
| this | 0xFC | RW | — | linked list tail pointer (this[63]); updated on each append |
| this | 0x100 | RW | — | linked list current/iter pointer (this[64]); set with head |
| this | 0x104 | R | — | element count (this[65]); incremented per node added |

**Written-by note (persistence):**
- this 0xF8: set to first node when list was empty; overwritten on each call.
- this 0xFC: updated to each newly appended node; overwritten on each call.
- this 0x100: set to head on each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
| 005c30b0 | asc_5C30B0 | R | StringDelimiter_CStr [DERIVED] |
| 005c6734 | aCreditsTxt | R | s_CreditsTxt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string with potential buffer reallocation |
| 005668b0 | ZeroInitSmallStruct | zero-initializes a small structure on the stack |
| 005668d0 | SubCallWithConditionalFieldFree | cleanup call that conditionally frees a field |
| 00566b20 | AudioStreamOpen | opens a file stream for reading (mode 1) |
| 00566cc0 | ConditionalDispatchBasedOnFlag | reads next line from file buffer; returns false when done |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory for a new node (operator new / malloc) |
| 00587c20 | sub_587C20 | searches for delimiter character in string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string format for path construction ("%s%s") |

**Guard conditions:** Checks AudioStreamOpen return value (file open success). If falsy (BLOCKED), skips parsing. Also checks ConditionalDispatchBasedOnFlag for line read success; loop continues while it returns true (PASSES). Also checks this[62] (list head) to decide whether to link new node as head or append to tail.
