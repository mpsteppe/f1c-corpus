## VectorToShort3Conversion_004b2c80 — FloatVectorToInt16SaturationPackWithClassification

**Summary:** Converts a 3D float vector to packed int16 values with ±511.98001 saturation and 64.0 scale factor, storing results at offsets 0x9, 0xB, 0xD. Also runs RGB color conversion, float rescaling, threshold classification, and bitfield update on the same data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9 | RW | — | Packed int16 X component (vector * 64, sat ±32767) |
| this | 0xB | RW | — | Packed int16 Y component (vector * 64, sat ±32767) |
| this | 0xD | RW | — | Packed int16 Z component (vector * 64, sat ±32767) |

**Written-by note (persistence):**
- this 0x9: overwritten each call with clamped scaled X; external poke overwritten
- this 0xB: overwritten each call with clamped scaled Y; external poke overwritten
- this 0xD: overwritten each call with clamped scaled Z; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e70c | flt_59E70C | R | FFBMinThreshold [DERIVED] (also: ` — FFB minimum threshold) |
| 0059e710 | flt_59E710 | R | FFB_SaturationThreshold [DERIVED] (also: ` — FFB maximum threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b21f0 | FloatToRGBColorConversion | Converts float vector components to packed RGB-like color |
| 004b2580 | ShortVectorToFloatWithScale | Rescales input short vector to float range |
| 004b2980 | BitfieldExtractScale | Extracts bitfield from vector and computes scale factor |
| 004b29f0 | ShortComputation_29f0 | Computes classification metric from vector |
| 004b2b90 | FloatThresholdClassification | Classifies computed metric into 2-bit category at offset 0xF |
| 004b2c20 | BitfieldUpdateFromFloat | Encodes scaled bitfield value into bits [7:2] at offset 0xF |

**Guard conditions:** Per-component: value > 511.98001 → BLOCKED from linear scale, clamps to 0x7FFF. Value < -511.98001 → clamps to -32767. In-range values PASS: multiply by 64.0, truncate to int16.
