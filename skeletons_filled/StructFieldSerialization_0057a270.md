## StructFieldSerialization_0057a270 — StructFieldBufferSerializer

**Summary:** Serializes struct fields starting at offset 4 into a contiguous buffer using DwordAlignedMemoryCopy. Copies fixed-size fields (4 bytes, 0x20 bytes, five 1-byte fields) followed by a variable-length copy at offset 45 with byte count from offset 44. Returns the total bytes written via a4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | last field accessed during serialization (offset 44, count for variable-length copy) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a180 | DwordAlignedMemoryCopy | copies data from struct field to output buffer (advances destination pointer) |

**Guard conditions:** none.
