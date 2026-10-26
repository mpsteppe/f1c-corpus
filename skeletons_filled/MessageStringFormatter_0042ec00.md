## MessageStringFormatter_0042ec00 — MessageStringFormatter

**Summary:** Formats a UI message string by looking up format config (based on flag at this[4]), copying it to display buffer, then applying format arguments with overflow check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuCommandDispatcher (004674e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Format selection flag: 1 = main format, else alternate format |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3730 | off_5C3730 | R | Ptr_FormatStringArray [DERIVED] |
| 005c3734 | byte_5C3734 | R | MessageBufferConfig [DERIVED] |
| 005c3738 | byte_5C3738 | R | MessageFormatBuffer [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Look up format string in game string table |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe vsnprintf-style format with overflow protection |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | != | 1 | Format selection flag != 1 |

**Guard interpretation:** this[1] != 1: BLOCKED from using main format (byte_5C3738); falls through to alternate format (byte_5C3734). this[1] == 1: PASSES (uses main format). Both paths then call BinarySearchInStringTable unconditionally.
