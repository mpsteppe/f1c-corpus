## BrakeWaterTemperatureHUDDisplay_0049db80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] (also: ` — additive offset) |
| 005ccbb8 | dword_5CCBB8 | R | UITextLayoutBaseY [DERIVED] |
| 005ccbbc | dword_5CCBBC | R | UISectionOffsetStride [DERIVED] |
| 005ccbc0 | dword_5CCBC0 | R | TextureSurfaceRef1 [DERIVED] |
| 005cced8 | aBrakes_0 | R | BrakesUIString [DERIVED] |
| 005ccee0 | aOil | R | OilString [DERIVED] |
| 005ccee8 | aWater | R | Str_Water [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c7ab8 | dbl_7C7AB8 | R | PhysicsTimestepMultiplier [DERIVED] |
| 007c7f1c | dbl_7C7F1C | R | Unknown_Double_7C7F1C [DERIVED] |
| 007c8380 | dbl_7C8380 | R | Dbl_7C8380_Render [DERIVED] |
| 007c87e4 | dbl_7C87E4 | R | VehiclePhysicsDoubleConst [DERIVED] |
| 007c9174 | dbl_7C9174 | R | ParamBaseValueA [DERIVED] |
| 007c91b4 | dbl_7C91B4 | R | ParameterBaseCase1 [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce238 | dword_7CE238 | R | TextDataBatchSource [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0049db00 | sub_49DB00 | [LLM] |
| 0049f6a0 | StringFormatAndRender | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
