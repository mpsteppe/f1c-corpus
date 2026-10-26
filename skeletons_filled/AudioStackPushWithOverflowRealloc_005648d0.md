## AudioStackPushWithOverflowRealloc_005648d0 — push element with realloc-on-full and shift

**Summary:** Pushes element onto dynamic stack/buffer. If count equals capacity, triggers realloc via AccumulatorWithReallocOnGrowth. If inserting before current top, shifts elements forward with LinearInterpolation + sub_58B130 (memmove). Copies new element via AlignedMemoryCopyFromStructBuffer. Audio buffer management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkConnection (00563260), DisplayModeQueryWrapper (005633d0), SingleFunctionCallWrapper_48c0 (005648c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | current element count |
| this | 0x4 | R | — | buffer capacity |
| this | 0x8 | R | — | element stride multiplier |

**Written-by note (persistence):**
- this 0x0: once/conditional? does external poke survive? unconditionally incremented each call; external write to this[0] could corrupt count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005648b0 | LinearInterpolation | computes byte offset into buffer for given index |
| 00564930 | AccumulatorWithReallocOnGrowth | reallocates buffer when count reaches capacity |
| 00564960 | AlignedMemoryCopyFromStructBuffer | copies element data into buffer at computed offset |
| 0058b130 | sub_58B130 | memory move/shift for elements (likely memmove) |

**Guard conditions:** If *this == this[1] (count == capacity) → trigger realloc. Then if a2 < v3-1 (insertion not at end) → shift elements to make room.
