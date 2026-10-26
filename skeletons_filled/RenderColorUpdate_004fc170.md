## RenderColorUpdate_004fc170 — UpdateRenderEntryColors

**Summary:** Updates color value across all render entries in a scene graph. Converts float alpha to 24-bit grayscale color, collects up to 16 node pointers, then patches color field (offset 24) in each node's packed array while preserving existing alpha channel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first node pointer |
| this | 0x10 | R | — | second node pointer |
| this | 0x40 | RW | — | stored color value (0x00RRGGBB format) |
| this | 0x48 | R | — | count of entries in node pointer array at +0x4C |
| this | 0x4C | R | — | pointer to first node pointer array |
| this | 0x7C | R | — | count of entries in node pointer array at +0x80 |
| this | 0x80 | R | — | pointer to second node pointer array |

**Written-by note (persistence):**
- this 0x40: conditional — written when new color differs from stored value; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c230 | LinkedListIndexedAccessor_c230 | get indexed render list (index 0) from linked structure |
| 0054e100 | PackedArrayTotalSize | get total entry count in packed array |
| 0054e120 | PackedArrayIndexLookup | get pointer to packed array entry by index |

**Guard conditions:** this[16] (color at +0x40) already matches new value → skip entire update. *this (first node at +0x00) == 0 → skip collecting first node. this[4] (second node at +0x10) == 0 → skip second node. v3 < 16 prevents overflow of temp array (max 16 entries). LinkedListIndexedAccessor_c230 returns 0 → skip that node's packed array.
