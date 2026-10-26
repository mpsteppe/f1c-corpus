## StridedArraySearchAndCall_004cefe0 — StridedArraySearchAndCall

**Summary:** Searches a strided array (108 bytes per entry) for an element whose second DWORD (offset +4) matches a2, then calls sub_4CD8D0 (ParticleColorFadeRenderer) on the matched entry. Returns entry index or array count if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | array element count |
| this | 0x14 | R | — | pointer to first array element |
| this | 0x18 | R | — | unknown (not directly accessed in visible code) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd8d0 | sub_4CD8D0 | render particle color fade on matched entry |

**Guard conditions:** Array count (this[4] / this+0x10) > 0. PASSES: linear search through 27-DWORD-stride (108 byte) entries comparing i[1] (offset +4) against a2. BLOCKED (<= 0): return 0 immediately.
