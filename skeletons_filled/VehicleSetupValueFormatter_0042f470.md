## VehicleSetupValueFormatter_0042f470 — VehicleSetupValueFormatter

**Summary:** Formats vehicle setup parameter values (suspension, aero, gearing, tires, etc.) into display strings for a garage/setup menu UI, dispatching on a 52+ case index to select the correct format specifier, unit conversion (metric/imperial), and optional label lookup. Writes formatted output to per-option destination buffers within the setup data structure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuOptionValueDisplay (004673b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | unit system flag (1 = metric/imperial, determines display unit for length values) |
| this | 0x1644 | R | — | track/circuit parameter count (this+5700), used as divisor in gear ratio calculations |
| this | 0x1884 | R | — | counter/threshold (this+6276), gates "N/A" fallback display vs computed value in cases 4/0x34-0x36 |
| this | 0x1980 | R | — | saved gear ratio value 1 (this+6528), used in differential gear display |
| this | 0x1984 | R | — | saved gear ratio value 2 (this+6532), used in differential gear display |
| this | 0x1989 | R | — | byte flag (this+6537): if set, forces "%d %s" format path in cases 5/6 (override) |
| this | 0x198C | R | — | bitfield flags (this+6540): bit 0 = hide unit label for case 0x1B, bit 1 = hide unit for 0x1D, bit 2 = verbose gear display |
| this | 0x1994 | R | — | fuel/laps conversion factor (this+6548): if 0.0, shows "N/A"; else converts raw value to laps count for fuel display |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042fc74 | jpt_42F49D | R | jump table for the large switch statement (52+ cases dispatching format paths) |
| 0042fcc4 | byte_42FCC4 | R | unknown byte data referenced by the function |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea18 | dbl_59EA18 | R | TimeDisplayMultMs [DERIVED] |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 0059ea30 | dbl_59EA30 | R | unknown double constant used in setup value calculations |
| 0059ea38 | dbl_59EA38 | R | BodyDragCoeff [DERIVED] |
| 0059ea40 | dbl_59EA40 | R | SuspensionSpringK [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c307c | aUnknown | R | sUnknown [DERIVED] |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c36c0 | aBevel | R | GraphicsParam_Bevel [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005c3780 | a3fS | R | FormatStr3fS [DERIVED] |
| 005c3788 | a2f2f | R | format string "%.2f:1" for gear ratio display |
| 005c3794 | a2d2d3f | R | format string "%2d/%2d (%.3f)" for numeric ratio display |
| 005c37a4 | a2f1 | R | format string "%.2f (%.2f)" for dual-value display |
| 005c37ac | a2d2dS2d2d | R | format string "%2d/%2d (%s %2d/%2d)" for gear ratio with label |
| 005c37c4 | aD03d | R | format string "%d%03d" for RPM-style thousand-separated display |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] |
| 005c37d4 | aDSS | R | format string "%d %s %s" for value with unit and label |
| 005c37e0 | a41fSS | R | format string "%4.1f %s %s" for metric fuel display with unit |
| 005c37ec | aDS_0 | R | format string "%d %s" for integer value with unit label |
| 005c37f4 | aLaps | R | string "laps" (plural fuel/laps label) |
| 005c37fc | a1S | R | format string "(1 %s)" for singular lap label |
| 005c3804 | off_5C3804 | R | pointer to singular "lap" label string (used when value rounds to 1) |
| 005c3808 | aS | R | format string "(%s)" for parenthesized label |
| 005c3810 | off_5C3810 | R | OffsetTable_5C3810 [DERIVED] |
| 005c3814 | a41f41f | R | format string "%4.1f:%4.1f" for ratio-pair display |
| 005c3820 | a2fS | R | sFormat_2fS [DERIVED] |
| 005c3828 | aTurns | R | string "turns" (spring/damper label) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | looks up a string in table, copies result into destination buffer (used to populate byte_5EC4CC) |
| 0042dc80 | BoundedArrayAccessor | accesses bounded array element from this+6512 gear ratio array |
| 0042dca0 | BoundsCheckedArrayLookup | bounds-checked array lookup from this+6512 array |
| 0042dcc0 | ArrayElementGetter | gets a raw element from array at this+6512 |
| 0042dce0 | BoundedArrayElementAccessor | bounded array element accessor returning adjacent index value |
| 0042dd00 | RatioCalculator | computes a ratio value from array at this+6512 using track parameter divisor |
| 0042f180 | SetupValueFormatDS | formats value as "%d %s" (integer with unit label) |
| 0042f1e0 | SetupValueFormat1fS | formats value as "%.1f %s" (float with unit label) |
| 0042f260 | SetupValueFormatWithOffset | formats value with offset adjustment, output as "%.1f %s" |
| 004d7570 | CompoundIndexLookup | compound index lookup into tire/brand data structure |
| 004d7880 | TireBrandLookup | looks up tire brand name from this+112 tire setup data |
| 00587bdc | CRTFtol | floating-point to integer conversion (truncation) |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with buffer overflow protection, writes formatted string to destination |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 1 | unit system: if 1 (metric), display liters; else display gallons for fuel |
| this | 0x1884 | < | 1 | counter threshold: if < 1, show "N/A" label (value not yet configured) |
| this | 0x1884 | < | 2 | counter threshold: if < 2, show "N/A" label for certain display modes |
| this | 0x1884 | >= | 3 | counter threshold: if >= 3, proceed with computed value display |

**Guard interpretation:** The switch on a2 (menu option index) selects the formatting path. Within each path, additional guards control display: this+0x4 selects metric (liters, cm, km/h) vs imperial (gallons, inches, mph) units with different format specifiers; this+0x1884 acts as a configuration-completeness counter — values below threshold show "N/A" (via off_5C3810) instead of computed numbers, indicating unconfigured setup parameters; this+0x1989 is a byte flag that forces a "%d %s" path for cases 5/6; this+0x198C bitfield controls whether unit labels are hidden (bit 0 for case 0x1B, bit 1 for case 0x1D, bit 2 for verbose gear ratio display); this+0x1994 is a fuel-to-laps conversion factor — if 0.0, shows "N/A", otherwise converts the raw value to a lap count displayed in parentheses.
