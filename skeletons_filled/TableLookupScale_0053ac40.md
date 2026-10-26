## TableLookupScale_0053ac40 — Curve table lookup with scale

**Summary:** Looks up a value from a precomputed curve/spline table. Indexes into buffer at this[3] using floor(this[0] * a2) as offset, reads float value, multiplies by 255.0. Used for gamma/volume/alpha scaling from normalized input.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55DA50 (0055da50), sub_55E320 (0055e320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | table size / entry count (this[0]), used as multiplier for indexing |
| this | 0xC | R | — | curve/spline buffer pointer at this[3], contains float values at stride 8 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches. Always computes index and returns scaled value unconditionally.
