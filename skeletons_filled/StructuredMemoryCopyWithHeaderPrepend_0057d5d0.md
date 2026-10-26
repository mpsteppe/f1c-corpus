## StructuredMemoryCopyWithHeaderPrepend_0057d5d0 — BuildStructuredPacketWithHeader

**Summary:** Builds structured packet in output buffer: writes byte count (from bit field at source+0x24) and FieldAccessor result as header, copies payload from source+0x14, then appends a final copy using BufferQueryReturnPtrSizeIfValid's adjusted pointer/size.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57D6C0 (0057d6c0), NetworkPacketSendWithQueryMatching (0057d8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | pointer to payload data to copy into output |
| this | 0x24 | R | — | bit count of payload (converted to byte count via ceil(bits/8)) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d880 | FieldAccessor | compute/retrieve field value stored at output header offset 2 |
| 00587580 | BufferQueryReturnPtrSizeIfValid | validate buffer and return adjusted pointer/size for final copy |

**Guard conditions:** none — always returns 1 unconditionally.
