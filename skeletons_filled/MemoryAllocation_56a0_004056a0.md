## MemoryAllocation_56a0_004056a0 — WavHeaderStructBuilder

**Summary:** Constructs a complete WAV audio file header (RIFF/WAVE/fmt/data chunks) in a buffer at offset 0x44, using audio parameters extracted from a 40-byte input header (sample rate, channels, bits per sample, flags).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BinaryDataDeserialization (004054e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be82c | aData_0 | R | serialization constant [DERIVED] — "data" RIFF chunk ID |
| 005be834 | aFmt | R | serialization constant [DERIVED] — "fmt " RIFF sub-chunk ID |
| 005be83c | aWave | R | serialization constant [DERIVED] — "WAVE" RIFF format tag |
| 005be844 | aRiff | R | serialization constant [DERIVED] — "RIFF" RIFF container ID |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405670 | sub_405670 | appends data to WAV header buffer at offset 0x44 with size tracking |

**Guard conditions:** Checks flag bits at byte 27 of input header: bit 5 (0x20) and bit 2 (0x04) select between sample rate source at offset 32 vs offset 4 in the input header.
