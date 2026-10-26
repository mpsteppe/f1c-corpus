## BitPackedDataDecodeViaLookupTable_00597cc0 — Packed96BitScaleByPowerOf10

**Summary:** Scales a packed 96-bit floating-point value (a1) by 10^a2 using lookup tables. Positive a2 uses dword_5E9C38-based table (powers of 10), negative a2 uses unk_5E9D98-based table (reciprocal powers). Each iteration processes 3 bits of the exponent (octal), selecting a precomputed table entry and multiplying via sub_597AA0. If a3 is zero, initializes output to zero first.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_596245 (00596245), sub_5976E8 (005976e8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | output 96-bit packed value (updated iteratively) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9c38 | dword_5E9C38 | R | CodePageTableEnd [DERIVED] |
| 005e9d98 | unk_5E9D98 | R | CRTDecimalLookup [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00597aa0 | sub_597AA0 | multiplies two packed 96-bit values during each octal digit iteration |

**Guard conditions:** If a2 is zero, returns without modification. For a2 < 0, negates a2 and selects reciprocal table. If a3 is zero, initializes *a1 to zero. Then iterates while a2 != 0, consuming 3 bits per step. If the 3-bit digit (v5) is non-zero, loads the corresponding precomputed entry and multiplies via sub_597AA0. PASSES: always, result in a1.
