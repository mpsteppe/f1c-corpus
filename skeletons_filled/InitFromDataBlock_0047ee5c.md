## InitFromDataBlock_0047ee5c — ConnectionStringInitFromData

**Summary:** Copies 36-byte data block from global connection string data, formats it as integer string, and conditionally dispatches via call wrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] — "%d" format string for integer conversion |
| 007d0a30 | unk_7D0A30 | R | ConnectionStringData [DERIVED] — 36-byte data block copied and processed |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047e940 | ConditionalCallWrapper | conditionally invoke target based on formatted integer |
| 0058815f | StringFormatWithBufferOverflowCheck | safe format string for data-to-string conversion |

**Guard conditions:** none — always executes copy, format, and conditional call
