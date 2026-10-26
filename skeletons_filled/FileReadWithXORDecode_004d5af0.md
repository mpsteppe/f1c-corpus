## FileReadWithXORDecode_004d5af0 — FileReadXORDecodeTripleKey

**Summary:** Opens a binary file, counts its size, writes 4-byte size header to output stream, then reads file contents decoding each byte with a 3-key cycling XOR scheme (keys 0x5C, 0xB4, 0x12). Used by TelemetryDataDump to load XOR-encoded telemetry data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TelemetryDataDump (004d4a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] — string "rb" for fopen read-binary mode |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d5be0 | sub_4D5BE0 | output byte-stream sink (writes decoded data) |
| 00587d02 | FileCloseWithLock | closes file handle with synchronization |
| 00587db0 | sub_587DB0 | file open function (opens "rb" mode) |
| 00587f64 | sub_587F64 | file seek (rewind to beginning) |
| 00589fcc | StreamGetcWithUnderflowHandler | reads single byte from stream (getc with buffer refill) |

**Guard conditions:** if file open (sub_587DB0) returns null, writes 4 zero bytes to output sink and returns immediately. Otherwise proceeds with full decode.
