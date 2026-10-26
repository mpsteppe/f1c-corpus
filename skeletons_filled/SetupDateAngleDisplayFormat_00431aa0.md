## SetupDateAngleDisplayFormat_00431aa0 — TemperatureDateDisplayFormatter

**Summary:** Formats three temperature values into a date-style display string (e.g., "85/90/88 °C") for telemetry HUD. Converts Kelvin inputs to Celsius or Fahrenheit based on unit flag, formats a triplet or single value via StringFormatWithBufferOverflowCheck.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuCommandDispatcher (004674e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Unit selection flag: 0 = Celsius, 1 = Fahrenheit |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eab0 | dbl_59EAB0 | R | LinearTransformBias [DERIVED] (also: ` — linear transform coefficients) |
| 0059eab8 | dbl_59EAB8 | R | LinearTransformCoeffB [DERIVED] |
| 0059eac0 | dbl_59EAC0 | R | UnitConvCoeffA [DERIVED] |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 005c3734 | byte_5C3734 | R | MessageBufferConfig [DERIVED] |
| 005c3738 | byte_5C3738 | R | MessageFormatBuffer [DERIVED] |
| 005c3f70 | off_5C3F70 | R | Off5C3F70 [DERIVED] |
| 005c3f74 | a3d3d3dS | R | Format_3DEquals [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with overflow protection |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 1 | Unit mode flag |

**Guard interpretation:** When this[0x4] == 1, temperatures are converted from Celsius to Fahrenheit before formatting. Otherwise values stay in Celsius. This affects only the unit conversion, not the format string selection.
