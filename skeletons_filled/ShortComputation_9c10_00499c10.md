## ShortComputation_9c10_00499c10 — StructUpdateAndSnapshot

**Summary:** Copies six selected DWORD fields (offsets 0x00-0x0C, 0x1C, 0x20) from source struct `a3` into `this`, then copies the entire 52-byte (0x34) content of `this` into buffer `a2` via qmemcpy. Returns the buffer pointer `a2`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | field overwritten from a3[0] |
| this | 0x4 | RW | — | field overwritten from a3[1] |
| this | 0x8 | RW | — | field overwritten from a3[2] |
| this | 0xC | RW | — | field overwritten from a3[3] |
| this | 0x1C | RW | — | field overwritten from a3[7] |
| this | 0x20 | RW | — | field overwritten from a3[8] |

**Written-by note (persistence):**
- this 0x0: written from a3[0]; external poke survives
- this 0x4: written from a3[1]; external poke survives
- this 0x8: written from a3[2]; external poke survives
- this 0xC: written from a3[3]; external poke survives
- this 0x1C: written from a3[7]; external poke survives
- this 0x20: written from a3[8]; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line copy with qmemcpy; no branches.
