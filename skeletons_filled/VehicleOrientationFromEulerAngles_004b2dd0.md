## VehicleOrientationFromEulerAngles_004b2dd0 — VehicleOrientationFromEulerAngles

**Summary:** Converts packed 16-bit Euler angle data (offsets 0x0-0xD) into a full 3D orientation matrix with cross-product axes, extracts Euler angles, packs results into output structure. Uses TernarySelectByBitfield and SixBitFieldToFloatDecoder values for additional rotation parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatComputation (00464b40), CollisionStateUpdate (00500010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Packed angle X (high byte) |
| this | 0x2 | R | — | Packed angle Y (high word) |
| this | 0x4 | R | — | Packed angle Z (high word) |
| this | 0x8 | R | — | Packed angle X (low byte) |
| this | 0x9 | R | — | Packed int16 orientation X component |
| this | 0xB | R | — | Packed int16 orientation Y component |
| this | 0xD | R | — | Packed int16 orientation Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | Computes collision normal from packed angle data |
| 004b2480 | UtilityFunction_2480 | Copies and normalizes float vector |
| 004b25d0 | FloatToFixedConversionWithClamp | Converts float vector to fixed-point with clamping |
| 004b2750 | FloatToShortClampedConversion | Converts float vector components to clamped int16 |
| 004b2930 | FloatToBitfieldPack | Packs float value into bitfield |
| 004b29b0 | BitfieldInsert | Inserts scaled double into bitfield at offset |
| 004b2bf0 | TernarySelectByBitfield | Selects rotation intensity from 2-bit classification field |
| 004b2c50 | sub_4B2C50 | Decodes 6-bit field to float for rotation parameter |
| 004b31a0 | FloatToInt16SaturationPack | Packs 3 float components to saturated int16 |
| 00588570 | FloatConvertWrapper | Float conversion with sign handling |

**Guard conditions:** If all three unscaled orientation components (v21, v22, v23) are zero → BLOCKED: skips entire orientation matrix computation and Euler angle extraction path. Otherwise PASSES to full 3D math.
