## VehicleStatsEstimationDisplay_00430f00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ValidateVehicleConfigurationFile (00433ed0), ConfigObjectDestructor (00466a70), ShortComputation_6c40 (00466c40), SubCallVirtualDispatch (0047d060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea68 | dbl_59EA68 | R | WheelSpeedFactor [DERIVED] |
| 0059ea88 | dbl_59EA88 | R | Physics_DoubleConstant_59EA88 [DERIVED] |
| 0059ea90 | dbl_59EA90 | R | Unknown_Double_59EA90 [DERIVED] |
| 0059ea98 | dbl_59EA98 | R | Dbl_UnknownPhysics [DERIVED] |
| 0059eaa0 | dbl_59EAA0 | R | Unknown_DoubleConst_59EAA0 [DERIVED] |
| 0059eaa8 | dbl_59EAA8 | R | Unknown_Double_59EAA8 [DERIVED] |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c3758 | aS_2 | R | StringFormatS [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005c3810 | off_5C3810 | R | OffsetTable_5C3810 [DERIVED] |
| 005c3820 | a2fS | R | sFormat_2fS [DERIVED] |
| 005c3f24 | aG | R | GString [DERIVED] |
| 005c3f28 | aEstCornering | R | EstCorneringString [DERIVED] |
| 005c3f38 | aEstTopSpeed | R | EstTopSpeed [DERIVED] |
| 005c3f48 | aS0DSS | R | FormatString_S0Ds [DERIVED] |
| 005c3f58 | aEstAccel | R | EstAccelString [DERIVED] |
| 005c3f64 | off_5C3F64 | R | SetupOptionsVTable [DERIVED] |
| 005c3f68 | off_5C3F68 | R | off_5C3F68 [DERIVED] |
| 005c3f6c | byte_5C3F6C | R | ConfigDefaultValue [DERIVED] (also: Lookup/config data) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00430750 | sub_430750 | [LLM] |
| 00430a50 | BrakeTemperatureFadeModel | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
