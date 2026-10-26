## FloatToByteShortEncoding_004b2840 — Indexed float-to-byte/short encoding

**Summary:** Converts two floats to packed fixed-point at indexed offsets: a3 clamped ±0.496 ×256 → byte at this[0x12 + a2]; a4 clamped ±327.67 ×100 → short at this[0x16 + 2*a2]. Used by SetupCarLightingAndRender for indexed parameter packing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: — scale factors) |
| 0059f10c | flt_59F10C | R | SignedByteScale [DERIVED] |
| 005accc0 | flt_5ACCC0 | R | QuantizationLowerBound [DERIVED] |
| 005accc4 | flt_5ACCC4 | R | SignedClampThreshold [DERIVED] (also: /8/c` — threshold constants) |
| 005accc8 | flt_5ACCC8 | R | FloatClampMax [DERIVED] |
| 005acccc | flt_5ACCCC | R | AudioClipThreshold_Max [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each float independently guarded by two-sided range check. a3: within [-0.496, 0.496] -> ×256 to byte; below -0.496 -> -127; above 0.496 -> 127. a4: within [-327.67, 327.67] -> ×100 to short; below -327.67 -> -32767; above 327.67 -> 32767.
