## FloatToIntMultiply_0054fc50 — Float-to-color packed ARGB conversion

**Summary:** Converts a float (0-100 scale) to a packed 32-bit ARGB color by multiplying by 2.55 to reach byte range, then replicating the byte across all 4 channels using constant 0x01010101. Stores the result as a texture/color parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DTextureResourceCreation (00548190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68 | RW | — | Packed ARGB color field; set to replicated byte value from float conversion |

**Written-by note (persistence):**
- this 0x68: unconditionally overwritten each call; survives until next call or external modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8988 | flt_5B8988 | R | 2.55 conversion constant (0-100 → 0-255 scale) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | CRT float-to-long conversion (ftol) |

**Guard conditions:** No guard — unconditionally computes and writes the packed color value.
