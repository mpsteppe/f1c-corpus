## SetupValueDisplayFormatter_00466910 — FormatValueAsPercentString

**Summary:** Retrieves a float value via virtual call (vtable+180), converts to percentage (value*100+0.5) via CRTFtol, formats as "%d%%" string, and stores result via StringCopyWithBufferRealloc.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParameterValueClampingAcrossArray (0047a080), SuspensionFloatClamp (0047a290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | accessed via virtual call +180 (float getter) |
| this | 0x0 | R | — | vtable pointer for virtual method dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | store formatted string to persistent buffer |
| 00587bdc | CRTFtol | convert float to integer (truncate) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf with "%d%%" format |

**Guard conditions:** If virtual call at vtable+180 returns non-NULL → format and store string (PASS). If returns NULL → skip formatting (BLOCKED).
