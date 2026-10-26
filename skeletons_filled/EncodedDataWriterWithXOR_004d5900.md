## EncodedDataWriterWithXOR_004d5900 — XOREncodedDataWriter

**Summary:** Writes encoded data to a byte stream: maps a type selector (0→3, 1→1, 2→2, else→0xFF), writes as 1-byte tag, then XORs a payload value with key at this+0x8 and writes 4 bytes. Used by LapSplitTimeEvent for encoding split event data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapSplitTimeEvent (004bc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | XOR key for obfuscating 4-byte payload value |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d5be0 | sub_4D5BE0 | byte-stream write sink (writes raw bytes to output) |

**Guard conditions:** none — all a2 values handled exhaustively (0→3, 1→1, 2→2, else→0xFF). No early return.
