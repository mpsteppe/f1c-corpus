## AdobePSDHeaderParser_005107fb — Adobe APP14 JPEG marker parser

**Summary:** Parses an Adobe APP14 JPEG marker segment from a byte stream. Validates the "Adobe" signature and extracts DCT encoder version, flags, and color transform value, dispatching parsing states.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch |
| obj | 0x14 | RW | 75 | state code — 75=Adobe OK, 77=not Adobe |
| obj | 0x18 | RW | — | first parsed value: DCT encoder version (big-endian from bytes 5-6) |
| obj | 0x1C | RW | — | second parsed value: APP14 flags0 (big-endian from bytes 7-8) |
| obj | 0x20 | RW | — | third parsed value: APP14 flags1 (big-endian from bytes 9-10) |
| obj | 0x24 | RW | — | fourth parsed value: color transform (byte 11, 0=CMYK, 1=YCbCr, 2=YCCK) |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |
| this | 0x24 | R | — | some constant/limit (unused in this function) |
| this | 0x106 | RW | 1 | Adobe marker present flag — set to 1 on successful parse |
| this | 0x107 | RW | — | Adobe color transform value (byte 11 of marker) |

**Written-by note (persistence):**
- obj 0x14: written once — 75 (Adobe) or 77 (other)
- obj 0x18: written with DCT encoder version
- obj 0x1C: written with APP14 flags0
- obj 0x20: written with APP14 flags1
- obj 0x24: written with color transform
- this 0x14: stream state pointer — external setup
- this 0x18: may be updated as buffer position cache
- this 0x106: set to 1 unconditionally on Adobe signature match
- this 0x107: set from color transform byte

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Marker data length check (v20 < 12) — if too short, skip Adobe parsing, set state 77. Signature check: bytes 0-4 must equal {'A','d','o','b','e'}. If signature mismatch, state 77 with remaining size.
