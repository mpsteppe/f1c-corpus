## WeatherConditionsFileWriter_004fe820 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |
| 0059e9c0 | flt_59E9C0 | R | TimeConversionFactor [DERIVED] |
| 005acb08 | flt_5ACB08 | R | FloatThreshold_5ACB08 [DERIVED] (also: ` — upper bound threshold (undocumented) |
| 005c2ab0 | unk_5C2AB0 | R | ConfigDirectoryPath [DERIVED] |
| 005c4060 | asc_5C4060 | R | Str_FormatSpec_5C4060 [DERIVED] |
| 005d7034 | asc_5D7034 | R | Asc_Unknown_Weather [DERIVED] |
| 005d7038 | asc_5D7038 | R | ASCIISeparator_5D7038 [DERIVED] |
| 005d703c | asc_5D703C | R | AscString_5D703C [DERIVED] |
| 005d7044 | aAmbienttemp2f_0 | R | AmbienttempString [DERIVED] |
| 005d705c | aConditions2f_0 | R | ConditionsFormatStr [DERIVED] |
| 005d7070 | asc_5D7070 | R | Unknown_Asc_5D7070 [DERIVED] |
| 005d7078 | aMinute2f | R | MinuteFormatField [DERIVED] |
| 005d7088 | aTracktemp2f | R | aTrackTempFormat [DERIVED] |
| 005d709c | aAmbienttemp2f | R | String_AmbientTemp2f [DERIVED] |
| 005d70b0 | aOffpathwetness | R | OffPathWetnessString [DERIVED] |
| 005d70c8 | aOnpathwetness2 | R | Onpathwetness2String [DERIVED] |
| 005d70e0 | aConditions2f | R | ConditionsFormatString [DERIVED] |
| 005d70f4 | asc_5D70F4 | R | String_Desc [DERIVED] |
| 005d70f8 | aS_3 | R | FormatPctS_2 [DERIVED] |
| 005d7100 | aWeather | R | Weather [DERIVED] |
| 005d710c | aCouldNotWriteT | R | CouldNotWriteTraceString [DERIVED] |
| 005d7128 | aDDevF119992002_9 | R | DevPathString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ce30 | SessionTypeNameLookup | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004fb910 | sub_4FB910 | [LLM] |
| 004fdeb0 | AudioADSREnvelope | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 005887b1 | StringFormatWithNestedIO | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
