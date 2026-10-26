## PathPathRegistryWriter_004b1600 — PathRegistryBulkCopy

**Summary:** Copies six path string pointers from object fields (offsets 0x1F8C, 0x1F94, 0x1F9C, 0x1A4, 0x1AC, 0x1B4) into reallocated string buffers. Each null pointer falls back to default directory. Returns result of last copy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A4 | R | — | 4th path string pointer (this[105]) |
| this | 0x1AC | R | — | 5th path string pointer (this[107]) |
| this | 0x1B4 | R | — | 6th path string pointer (this[109]) |
| this | 0x1F8C | R | — | 1st path string pointer (this[2019]) |
| this | 0x1F94 | R | — | 2nd path string pointer (this[2021]) |
| this | 0x1F9C | R | — | 3rd path string pointer (this[2023]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string into reallocated buffer |

**Guard conditions:** Each of the 6 string pointers is null-checked individually. If null, uses byte_5EA438 as fallback before copying.
