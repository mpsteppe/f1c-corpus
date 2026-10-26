## RingBufferCounterWithWrap_004b69d0 — Ring Buffer Read Advance

**Summary:** Advances the circular buffer read index (this[0x9BC]) by 1 with modulo wrap, consuming one entry. Returns the old read index value (with division overflow flag).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7860 (004b7860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B4 | R | — | Buffer size/modulus for wrap calculation |
| this | 0x9B8 | R | — | Write index (compared to guard against empty) |
| this | 0x9BC | RW | — | Read index (advanced only if != write index) |

**Written-by note (persistence):**
- this 0x9BC: Updated when read != write; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If read index (this[0x9BC]) equals write index (this[0x9B8]), buffer is empty — return without advancing (return read index unchanged).
