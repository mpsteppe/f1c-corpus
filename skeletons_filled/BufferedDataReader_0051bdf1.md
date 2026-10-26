## BufferedDataReader_0051bdf1 — Ring buffer read manager

**Summary:** Reads audio data from a ring buffer into an output buffer, with clamping against available data and a size limit. Allocates read buffer on first use, copies via virtual dispatch, and wraps read position at buffer capacity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Vtable for buffer allocation (read mode, flag=0) |
| this | 0x20 | R | — | Not accessed in this function; part of shared struct layout |
| this | 0x60 | R | — | Read size limit — caps bytes copied per call |
| this | 0x188 | R | — | Pointer to ring buffer sub-struct (v7) |
| this | 0x190 | R | — | Parameter passed to allocation function |
| this | 0x194 | RW | — | Allocated read buffer address |
| this | 0x198 | R | — | Ring buffer capacity |
| this | 0x19C | RW | — | Accumulated read offset counter, incremented on wrap |
| this | 0x1A0 | RW | 0 | Current read position in ring buffer |
| this | 0x1A4 | R | — | Function pointer table for data copy operations |
| this | 0x1A8 | R | — | Not accessed in this function; part of shared struct layout |

**Written-by note (persistence):**
- this 0x194: Written once by alloc when read position is 0 (first use or after wrap). Survives external pokes.
- this 0x19C: Accumulated read offset, incremented by buffer capacity on each wrap. Cumulative counter, persists.
- this 0x1A0: Read position — advanced by bytes read, reset to 0 on wrap. Init 0 on first alloc. Survives external pokes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard at `!v7[6]` (line 8): if read position is 0, allocate buffer. PASS: position == 0 (first read or after wrap) → allocates. BLOCKED: position != 0 → buffer exists, skip alloc. Clamping guards (lines 11-14): cap read size to min(available data, remaining output space, size limit at offset 0x60). Wrap guard (line 19): if read position >= buffer capacity, increment accumulated offset and reset position to 0.
