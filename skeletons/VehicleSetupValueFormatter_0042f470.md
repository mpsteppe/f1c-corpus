## VehicleSetupValueFormatter_0042f470 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuOptionValueDisplay (004673b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x1644 | R | — | [LLM] |
| this | 0x1884 | R | — | [LLM] |
| this | 0x1980 | R | — | [LLM] |
| this | 0x1984 | R | — | [LLM] |
| this | 0x1989 | R | — | [LLM] |
| this | 0x198C | R | — | [LLM] |
| this | 0x1994 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042fc74 | jpt_42F49D | R | [LLM] |
| 0042fcc4 | byte_42FCC4 | R | [LLM] |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ea18 | dbl_59EA18 | R | TimeDisplayMultMs [DERIVED] |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 0059ea30 | dbl_59EA30 | R | [LLM] |
| 0059ea38 | dbl_59EA38 | R | BodyDragCoeff [DERIVED] |
| 0059ea40 | dbl_59EA40 | R | SuspensionSpringK [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c307c | aUnknown | R | sUnknown [DERIVED] |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c36c0 | aBevel | R | GraphicsParam_Bevel [DERIVED] |
| 005c36f4 | a1fS | R | IntFormatSpecifier [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005c3780 | a3fS | R | FormatStr3fS [DERIVED] |
| 005c3788 | a2f2f | R | [LLM] |
| 005c3794 | a2d2d3f | R | [LLM] |
| 005c37a4 | a2f1 | R | [LLM] |
| 005c37ac | a2d2dS2d2d | R | [LLM] |
| 005c37c4 | aD03d | R | [LLM] |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] |
| 005c37d4 | aDSS | R | [LLM] |
| 005c37e0 | a41fSS | R | [LLM] |
| 005c37ec | aDS_0 | R | [LLM] |
| 005c37f4 | aLaps | R | [LLM] |
| 005c37fc | a1S | R | [LLM] |
| 005c3804 | off_5C3804 | R | [LLM] |
| 005c3808 | aS | R | [LLM] |
| 005c3810 | off_5C3810 | R | OffsetTable_5C3810 [DERIVED] |
| 005c3814 | a41f41f | R | [LLM] |
| 005c3820 | a2fS | R | sFormat_2fS [DERIVED] |
| 005c3828 | aTurns | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042dc80 | BoundedArrayAccessor | [LLM] |
| 0042dca0 | BoundsCheckedArrayLookup | [LLM] |
| 0042dcc0 | ArrayElementGetter | [LLM] |
| 0042dce0 | BoundedArrayElementAccessor | [LLM] |
| 0042dd00 | RatioCalculator | [LLM] |
| 0042f180 | SetupValueFormatDS | [LLM] |
| 0042f1e0 | SetupValueFormat1fS | [LLM] |
| 0042f260 | SetupValueFormatWithOffset | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004d7880 | TireBrandLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 1 | [LLM] |
| this | 0x1884 | < | 1 | [LLM] |
| this | 0x1884 | < | 2 | [LLM] |
| this | 0x1884 | >= | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
