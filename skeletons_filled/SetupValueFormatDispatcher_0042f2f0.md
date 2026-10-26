## SetupValueFormatDispatcher_0042f2f0 — SetupValueFormatDispatcher

**Summary:** Dispatches vehicle setup value formatting by type (a3: 0=angle, 1=pressure, 2=length with offset, 3/9=length, 4=ds, 5-8=1f, 10=integer). Indexes into 64-byte stride array per group/slot.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuOptionValueDisplay (004673b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Unit system flag: non-zero = imperial (PSI/inches), zero = metric |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042f440 | jpt_42F31A | R | Jump table for switch on a3 (value type 0-10) |
| 0059ea28 | dbl_59EA28 | R | Pressure-to-PSI conversion constant |
| 0059ea30 | dbl_59EA30 | R | Length offset threshold for wheel type selection |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042f180 | SetupValueFormatDS | Format degrees/seconds setup value |
| 0042f1e0 | SetupValueFormat1fS | Format 1-float or integer setup value with unit |
| 0042f260 | SetupValueFormatWithOffset | Format length/value with optional offset term |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe vsnprintf-style format string with overflow guard |

**Guard conditions:** Switch on a3 (value type): 0=angle (direct format), 1=pressure (branch on this[4] for PSI/metric), 2=length with wheel-dependent offset, 3/9=length without offset, 4=DS format, 5-8=1fS format, 10=integer, default=return without formatting.
