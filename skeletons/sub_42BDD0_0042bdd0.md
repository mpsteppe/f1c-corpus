## sub_42BDD0_0042bdd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FTIMTimerBitmapSelector (0046b5f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e9a4 | asc_59E9A4 | R | AscString_59E9A4 [DERIVED] |
| 0059e9b8 | flt_59E9B8 | R | RemainderScaleFactor [DERIVED] (also: ` — float, ~1.0f (scale factor for remainder computation) |
| 0059e9bc | flt_59E9BC | R | AngleConversionFactor [DERIVED] |
| 0059e9c0 | flt_59E9C0 | R | TimeConversionFactor [DERIVED] |
| 0059e9c8 | dbl_59E9C8 | R | Unknown_Double_59E9C8 [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c3298 | off_5C3298 | R | VehicleArrayPtrPtr [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c32dc | aD022d063f | R | Str_D022D063F [DERIVED] |
| 005c32f0 | aD063f_0 | R | StringD063f [DERIVED] |
| 005c32fc | aLaps_1 | R | LapsLabel [DERIVED] |
| 005c3304 | aDS_5 | R | DS5Format [DERIVED] |
| 005c330c | off_5C330C | R | PTR_SetupVTable [DERIVED] |
| 005c3310 | aD063f | R | StrD063F [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004bb730 | FailureCategoryNameLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
