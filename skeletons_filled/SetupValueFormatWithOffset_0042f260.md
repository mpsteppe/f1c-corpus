## SetupValueFormatWithOffset_0042f260 — SetupValueFormatWithOffset

**Summary:** Formats a vehicle setup value with optional offset term. Outputs "%.3f %s" (inches) when format flag is non-zero, "%.1f %s" (metric) otherwise. Adds an indexed offset from config fields when a3 != 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupValueFormatDispatcher (0042f2f0), VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Format flag: non-zero = inches ("%.3f") with 0.3937 conversion, zero = metric ("%.1f") |
| this | 0xC70 | R | — | Offset term base value (double) |
| this | 0xC78 | R | — | Offset term multiplier (double) |
| this | 0xC84 | R | — | Offset term index/int value (int) |
| this | 0x199C | R | — | Offset scale factor (double), applied when a3 != 0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea18 | dbl_59EA18 | R | TimeDisplayMultMs [DERIVED] |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3780 | a3fS | R | FormatStr3fS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Safe vsnprintf-style format string with overflow guard |

**Guard conditions:** Guard: a3 != 0.0 → PASSES (adds offset term computed from config fields). Zero → BLOCKED (no offset). Guard: this[1] != 0 → inches format "%.3f" with 0.3937 conversion. Zero → metric format "%.1f".
