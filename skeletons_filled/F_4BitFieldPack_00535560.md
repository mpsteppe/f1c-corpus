## F_4BitFieldPack_00535560 — 4-byte little-endian bitfield pack from stream

**Summary:** Reads 4 bytes from buffered stream via sub_534E70 and packs them into a 32-bit integer (little-endian order). File I/O / binary data reading system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BufferedFileReader (00534f90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | 18446744073709551613 | Error code; set to -3 if any byte read returns -1 (EOF) |

**Written-by note (persistence):**
- this 0x38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534e70 | sub_534E70 | Read one byte from buffered stream |

**Guard conditions:** If the 4th byte read returns -1 (EOF), set `this[14] = -3` (read error code). Result returned is the packed 32-bit value even on partial read.
