## SetupValueFormat1fS_0042f1e0 — SetupValueFormat1fS

**Summary:** Formats a vehicle setup value with one decimal float or integer ("%.1f %s" or "%d %s"). Selects float format with unit conversion (~0.0057) when format flag is non-zero, integer format otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupValueFormatDispatcher (0042f2f0), VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Format flag: non-zero = float "%.1f" with conversion, zero = integer "%d" |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea10 | dbl_59EA10 | R | GearChangeThreshold [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Safe vsnprintf-style format string with overflow guard |

**Guard conditions:** Guard: this[1] (offset 0x4) non-zero → PASSES (float format "%.1f %s" with unit conversion). Zero → BLOCKED (integer format "%d %s", no conversion).
