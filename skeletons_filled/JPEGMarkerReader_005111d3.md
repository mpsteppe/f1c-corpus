## JPEGMarkerReader_005111d3 — JPEG SOI marker validator

**Summary:** Reads 2 bytes from a byte stream and validates them as the JPEG SOI (Start of Image) marker 0xFF 0xD8. Reports error state 52 with the unexpected bytes if the marker doesn't match. Stores the second byte at this+0x178.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x0 | R | — | vtable base for state dispatcher (vfunc 0 for error state 52) |
| obj | 0x14 | RW | 52 | state code — 52 when marker is not 0xFF 0xD8 |
| obj | 0x18 | RW | — | first byte read from stream |
| obj | 0x1C | RW | — | second byte read from stream |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |
| this | 0x178 | RW | — | marker storage — written with second byte (regardless of validity) |

**Written-by note (persistence):**
- obj 0x14: written to 52 on non-SOI marker
- obj 0x18: written with first byte on error
- obj 0x1C: written with second byte on error
- this 0x14: stream pointer — updated as buffer consumed
- this 0x18: may be updated as buffer position cache
- this 0x178: set to second byte unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** First byte must be 0xFF AND second byte must be 0xD8 (JPEG SOI marker). If either condition fails (PASS to error): dispatch state 52 with byte values. If both match (BLOCKED from error): skip error state, continue to store marker.
