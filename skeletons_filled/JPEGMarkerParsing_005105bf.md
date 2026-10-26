## JPEGMarkerParsing_005105bf — JFIF marker header parser

**Summary:** Parses a JFIF (JPEG File Interchange Format) APP0 marker segment from a byte stream. Validates the "JFIF\0" signature, extracts version, aspect ratio/density units, X/Y density, and thumbnail dimensions, dispatching state transitions throughout.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch |
| obj | 0x14 | RW | 76 | state code — set during parsing (76, 86, 87, 88, 89, 115) |
| obj | 0x18 | RW | 1 | first parsed value (remaining size, version, X density, thumbnail width) |
| obj | 0x1C | RW | — | second parsed value (minor version, Y density, thumbnail height) |
| obj | 0x20 | RW | — | third parsed value (density units) |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct (buffer ptr + remaining + refill fn) |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer (updated on refill) |
| this | 0x20 | R | — | table entry count (unused in this function — listed from skeleton analysis) |
| this | 0x24 | R | — | some constant/limit (unused in this function — listed from skeleton analysis) |
| this | 0x100 | RW | 1 | density-present flag — set to 1 when JFIF densities are parsed |
| this | 0x101 | RW | — | density units byte (0=no aspect, 1=dpi, 2=dpcm) |
| this | 0x102 | RW | — | X density (WORD, big-endian from JFIF header) |
| this | 0x104 | RW | — | Y density (WORD, big-endian from JFIF header) |

**Written-by note (persistence):**
- obj 0x14: written each parsing stage — final state depends on marker content
- obj 0x18: written once per dispatch with the primary parsed value
- obj 0x1C: written once per dispatch with secondary parsed value
- obj 0x20: written with density units
- this 0x14: stream state pointer — external setup
- this 0x18: may be updated as buffer position cache
- this 0x100: set to 1 unconditionally on JFIF match
- this 0x101: set from JFIF units byte
- this 0x102: set to big-endian X density word
- this 0x104: set to big-endian Y density word

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Segment data length check (v29 < 14) — if too short, skip JFIF parsing and go to state 76 directly. JFIF signature check: bytes 0-4 must equal {'J','F','I','F',0}. Version check: major version must be 1 for normal path; major != 1 triggers state 115; minor > 2 triggers state 88 (extension needed). Thumbnail data validation: remaining data must equal 3 * thumb_width * thumb_height or state 87 is set.
