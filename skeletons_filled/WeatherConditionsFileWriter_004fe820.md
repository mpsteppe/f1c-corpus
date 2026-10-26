## WeatherConditionsFileWriter_004fe820 — WeatherConditionsFileWriter

**Summary:** Writes per-session weather conditions (on-path wetness, off-path wetness, ambient/track temperature, minute-by-minute data) to a formatted output file. Iterates 8 sessions, simulates weather transitions via AudioADSREnvelope, and logs errors on file-open failure. Returns 0 on success, -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | first float value in weather data array (timestamp reference point) |
| this | 0x38 | RW | — | current weather data iterator pointer (this[14], advanced through linked array) |
| this | 0x3C | R | — | iterator limit/count or maximum index (this[15]) |
| this | 0x44 | R | — | weather data array base pointer (this[17], pointer to float array) |

**Written-by note (persistence):**
- this 0x38: repeatedly written per session (advanced through weather data point linked list via node+12); external poke resets traversal

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
| 0042ce30 | SessionTypeNameLookup | get session type name string for given session index |
| 004d7a50 | StringSplitLoop | split/config debug message for error logging |
| 004d7aa0 | DebugLogWrite | write error log message when file open fails |
| 004fb910 | sub_4FB910 | get weather session duration (float, in seconds) for session index |
| 004fdeb0 | AudioADSREnvelope | simulate weather transition envelope over 10-second steps for the session duration |
| 00587d02 | FileCloseWithLock | close the weather output file with mutex release |
| 00587db0 | sub_587DB0 | open/create weather output file using config directory path |
| 005887b1 | StringFormatWithNestedIO | write formatted string to the open file handle |

**Guard conditions:** File open via sub_587DB0 succeeds (returns non-null handle) → write all weather data; returns null → log "Could not write to file %s" error, return -1.
