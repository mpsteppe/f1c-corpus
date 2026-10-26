## BinaryPacketFieldParserWithOffsetMath_00587310 — Parse binary packet header with field extraction

**Summary:** Parses a binary packet: header WORD encodes total payload size less 11. If non-zero, copies payload via MemcpyLikeWithRealloc, then extracts three trailing fields (DWORD at 0x10, DWORD at 0x14, BYTE at 0x18) from the end of the payload and stores into struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5813E0 (005813e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | First DWORD field parsed from packet tail |
| this | 0x14 | RW | — | Second DWORD field parsed from packet tail |
| this | 0x18 | RW | — | BYTE field parsed from packet tail |

**Written-by note (persistence):**
- this 0x10: written from parsed packet data every call on success; external poke overwrites it
- this 0x14: written from parsed packet data every call on success; external poke overwrites it
- this 0x18: written from parsed packet data every call on success; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587510 | MemcpyLikeWithRealloc | Copies variable-length payload data before field extraction |

**Guard conditions:** `*a2 == 0` → returns 0 immediately (empty/invalid packet). `v4 > 0 && !MemcpyLikeWithRealloc(...)` → returns 0 if copy fails (allocation issue). Otherwise proceeds to field extraction.
