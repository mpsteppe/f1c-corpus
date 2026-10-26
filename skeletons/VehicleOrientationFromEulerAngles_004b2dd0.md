## VehicleOrientationFromEulerAngles_004b2dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatComputation (00464b40), CollisionStateUpdate (00500010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x2 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x9 | R | — | [LLM] |
| this | 0xB | R | — | [LLM] |
| this | 0xD | R | — | [LLM] |

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
| 0044c550 | CollisionNormalFromFeature | [LLM] |
| 004b2480 | UtilityFunction_2480 | [LLM] |
| 004b25d0 | FloatToFixedConversionWithClamp | [LLM] |
| 004b2750 | FloatToShortClampedConversion | [LLM] |
| 004b2930 | FloatToBitfieldPack | [LLM] |
| 004b29b0 | BitfieldInsert | [LLM] |
| 004b2bf0 | TernarySelectByBitfield | [LLM] |
| 004b2c50 | sub_4B2C50 | [LLM] |
| 004b31a0 | FloatToInt16SaturationPack | [LLM] |
| 00588570 | FloatConvertWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
