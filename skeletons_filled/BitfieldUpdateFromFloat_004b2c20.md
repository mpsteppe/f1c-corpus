## BitfieldUpdateFromFloat_004b2c20 — FloatToSixBitFieldEncoder

**Summary:** Encodes a float value into a 6-bit field at bits [7:2] of byte at offset 0xF. Float is multiplied by ~0.018 (1/55.55), truncated to int, masked to 6 bits, then inserted via XOR merge.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VectorToShort3Conversion (004b2c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF | RW | — | Six-bit encoded field (bits [7:2]) |

**Written-by note (persistence):**
- this 0xF: bits [1:0] preserved, bits [7:2] overwritten each call; external poke partially survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acce0 | flt_5ACCE0 | R | Unknown_Float_Skidding [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Float-to-int conversion for bitfield packing |

**Guard conditions:** none — always encodes and stores unconditionally
