## BrakeWaterTemperatureHUDDisplay_0049db80 — Temperature display HUD

**Summary:** Renders water, oil, and brake temperatures to HUD with labels. Converts Kelvin to Celsius, formats via temperature formatter, and renders label/value pairs at stepped Y positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | render surface/texture pointer (this[2]) |
| this | 0x14 | R | — | display context pointer (this[5]) |
| this | 0x68 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (= 273.15, Kelvin offset) |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] |
| 005ccbb8 | dword_5CCBB8 | R | UITextLayoutBaseY [DERIVED] — starting Y position |
| 005ccbbc | dword_5CCBBC | R | UISectionOffsetStride [DERIVED] — Y step per row |
| 005ccbc0 | dword_5CCBC0 | R | TextureSurfaceRef1 [DERIVED] — left column texture |
| 005cced8 | aBrakes_0 | R | BrakesUIString [DERIVED] — "Brakes" label |
| 005ccee0 | aOil | R | OilString [DERIVED] — "Oil" label |
| 005ccee8 | aWater | R | Str_Water [DERIVED] — "Water" label |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] — temp string copy buffer |
| 007c7ab8 | dbl_7C7AB8 | R | PhysicsTimestepMultiplier [DERIVED] — brake temp (Kelvin) |
| 007c7f1c | dbl_7C7F1C | R | Unknown_Double_7C7F1C [DERIVED] — additional temp (Kelvin) |
| 007c8380 | dbl_7C8380 | R | Dbl_7C8380_Render [DERIVED] — additional temp (Kelvin) |
| 007c87e4 | dbl_7C87E4 | R | VehiclePhysicsDoubleConst [DERIVED] — additional temp (Kelvin) |
| 007c9174 | dbl_7C9174 | R | ParamBaseValueA [DERIVED] — oil temp (Kelvin) |
| 007c91b4 | dbl_7C91B4 | R | ParameterBaseCase1 [DERIVED] — water temp (Kelvin) |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] |
| 007ce238 | dword_7CE238 | R | TextDataBatchSource [DERIVED] — right column text batch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | searches string table for label text |
| 0049db00 | sub_49DB00 | formats temperature value with unit suffix |
| 0049f6a0 | StringFormatAndRender | formats string and renders to HUD at position |

**Guard conditions:** Checks `this[2]` (0x8) non-null — blocks entire display if null. No other early returns — renders all 3 (Water, Oil, Brakes) rows plus 3 additional temperature readings at bottom.
