## FTIMTimerBitmapSelector_0046b5f0 — FTimerOverlayStringBuilder

**Summary:** Builds composite display string for FTIM timer overlay. Extracts vehicle data (lap number, session state, vehicle name strings) from vehicle array dword_7C54F0. Formats lap count with session type awareness, selects color string (red/green/grey) based on crash/outline state, concatenates components into output buffer a3 with path delimiters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BA20 (0046ba20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | R | — | display filter mask — skips certain component indices when == 1 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c692c | word_5C692C | R | PathDelimiterChar [DERIVED] — backslash path separator |
| 005c6a28 | aFtim14redoutli | R | StrCrashOutline [DERIVED] — red outline string for crashed state |
| 005c6a40 | aFtim14greenout | R | FTim14GreenOutString [DERIVED] — green outline string for OK state |
| 005c6a58 | aFtim14greyoutl | R | Str_FTImg14GreyOutL [DERIVED] — grey outline string for in/out state |
| 005c6a70 | aDS_4 | R | DS4Field [DERIVED] |
| 005c6a78 | asc_5C6A78 | R | UI_ASCString [DERIVED] — string for infinite laps ("---") |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] — vehicle pointers array |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — current session type (5=race, 7=?) |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] — disqualification flag |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] — total race laps |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bdd0 | sub_42BDD0 | returns vehicle crash/outline state (0=crash/red, 1=green, 2=grey) |
| 0046b830 | sub_46B830 | copies vehicle name string to buffer |
| 00587dd0 | sub_587DD0 | copies fixed-length string from vehicle data struct |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string formatting for lap numbers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x17C | != | 1 | display mode filter at this[95] |

**Guard interpretation:** PASSES if this[95] != 1 → includes all 6 component indices (0-5). BLOCKED if this[95] == 1 → only includes indices 1, 4, 5 (skips 0, 2, 3) during string assembly.
