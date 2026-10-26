## BitstreamTokenReader_005110fc — Byte-stuffing aware marker reader

**Summary:** Reads a byte stream handling 0xFF byte-stuffing (0xFF 0x00 = data byte 0xFF). Counts data and stuffing bytes until a JPEG marker (0xFF followed by a non-zero, non-0xFF byte) is found. Reports the byte count and marker value via state 112 dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a), StateCounterWithDispatch (00511457), AudioVideoDecodeSubbandLoop (005114d5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (state 112) |
| obj | 0x14 | RW | 112 | state code — 112 when marker found with accumulated byte count |
| obj | 0x18 | RW | — | accumulated byte count before marker (data + stuffing) |
| obj | 0x1C | RW | — | marker byte value (the byte after 0xFF) |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |
| this | 0x178 | RW | — | marker storage — written with the detected marker byte at end |
| this | 0x190 | R | — | pointer to sub-object containing the byte counter at +0x58 |
| this | 0x1E8 | RW | 0 | byte counter — incremented for each data/0x00 stuffing byte, reset after dispatch |

**Written-by note (persistence):**
- obj 0x14: written to 112 when marker found
- obj 0x18: written with accumulated byte count
- obj 0x1C: written with detected marker byte
- this 0x14: stream pointer — updated as buffer consumed
- this 0x18: may be updated as buffer position cache
- this 0x178: set to the detected marker byte
- this 0x1E8: reset to 0 after dispatch; accumulates across loop iterations

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop continues while no marker found. 0xFF detection: byte == 255 triggers stuffing/marker parsing. After 0xFF: 0x00 = stuffed (counter += 2); 0xFF = escaped (continue reading); non-zero = marker found (break). If counter > 0 when marker found: dispatch state 112; otherwise skip dispatch and just store marker.
