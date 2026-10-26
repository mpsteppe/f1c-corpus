## sub_52CAF0_0052caf0 — WriteWeatherDataToFile

**Summary:** Serializes weather state to a text file. Iterates 9 weather zones, writes zone name and simulates weather progression in 10-minute steps, then outputs Conditions, wetness, ambient/track temperatures, and per-minute event markers from a linked list of weather changes.

**Called by:** sub_52AD20 (0052ad20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x34)+0xC) | 0x0 | R | — | Float: time value of next weather event node |
| *(*(this+0x34)+0xC) | 0x8 | R | — | Float: conditions value of next weather event node |
| *(this+0x34) | 0x0 | R | — | Float: base time of current weather node |
| *(this+0x34) | 0x4 | R | — | Float: ambient temperature at current node |
| *(this+0x34) | 0x8 | R | — | Float: conditions value at current node (scaled by 100 for output) |
| *(this+0x34) | 0xC | R | — | Pointer to next node in weather event linked list |
| this | 0x24 | R | — | OnPathWetness (scaled by 100 for output) |
| this | 0x28 | R | — | OffPathWetness (scaled by 100 for output) |
| this | 0x2C | R | — | AmbientTemp (degrees) |
| this | 0x30 | R | — | TrackTemp (degrees) |
| this | 0x34 | RW | — | Current weather node pointer — reset to base node, then advanced through linked list |
| this | 0x38 | R | — | Base/initial weather node pointer used to reset this+0x34 each zone iteration |

**Written-by note (persistence):**
- this 0x34: recalc per zone — reset from this+0x38, then advanced through linked list; poke survives only until next zone iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | Physics constant (unused directly visible, likely in callee) |
| 005d56a8 | flt_5D56A8 | R | Constant 10.0 — simulation step interval in minutes |
| 005d5914 | flt_5D5914 | R | Constant 0.016666668 — conversion factor (1/60, minutes to hours) |
| 005d5d88 | flt_5D5D88 | R | Constant 100.0 — scaling factor for percentage output |
| 005d5db0 | flt_5D5DB0 | R | Constant 150.0 — max minute threshold for event output |
| 005fbf2c | asc_5FBF2C | R | Format string "  }\n" |
| 005fc03c | asc_5FC03C | R | Format string "  {\n" |
| 005fc2c8 | asc_5FC2C8 | R | Format string " }\n" |
| 005fc484 | asc_5FC484 | R | Format string " {\n" |
| 005fca60 | aWb | R | File mode string "wb" |
| 00615664 | asc_615664 | R | Format string "  Conditions=%.2f\n" |
| 00615668 | aAmbienttemp2f_0 | R | Format string "   AmbientTemp=%.2f\n" (indented, for minute events) |
| 00615680 | aConditions2f_0 | R | Format string "   Conditions=%.2f\n" (indented, for minute events) |
| 00615694 | aMinute2f | R | Format string "  Minute=%.2f\n" |
| 006156a4 | aTracktemp2f | R | Format string "  TrackTemp=%.2f\n" |
| 006156b8 | aAmbienttemp2f | R | Format string "  AmbientTemp=%.2f\n" |
| 006156cc | aOffpathwetness_0 | R | Format string "  OffPathWetness=%.2f\n" |
| 006156e4 | aOnpathwetness2 | R | Format string "  OnPathWetness=%.2f\n" |
| 006156fc | aConditions2f | R | Format string "  Conditions=%.2f\n" |
| 00615710 | asc_615710 | R | Format string " %s\n" |
| 00615714 | aS_4 | R | Format string "Weather\n" |
| 0061571c | aWeather_1 | R | Format string "{\n" (top-level opening brace) |
| 00615728 | aCouldNotWriteT | R | Format string "Could not write to file %s" |
| 00615744 | aDDevNascar2004_27 | R | Source file path "D:\\dev\\NASCAR_2004\\Source\\weather.cpp" |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042f570 | sub_42F570 | Get weather zone name string for index i |
| 00500f90 | sub_500F90 | Check debug/log condition before writing error |
| 00500fe0 | sub_500FE0 | Log error message when file open fails |
| 00529ca0 | sub_529CA0 | Get total duration (in minutes) for weather zone i |
| 0052c170 | sub_52C170 | Simulate weather progression for one 10-minute step |
| 005be9e2 | FileCloseWithLock [structural] | fclose — close the written file |
| 005bea90 | _fopen | Open file with mode "wb" for writing weather data |
| 005bf6df | StringFormatWithNestedIO [structural] | fprintf — write formatted weather data to file |

**Guard conditions:** File open succeeds → write all weather data and return 0. File open fails → log error "Could not write to file %s" and return -1. In minute-event output loop: breaks when `(*v12 - v15) * 0.016666668 > 150.0` (minutes from current time exceed 150).

**String literals referenced (deterministic):**

- `  }
`
- `  {
`
- ` }
`
- `   AmbientTemp=%.2f
`
- `   Conditions=%.2f
`
- `  Minute=%.2f
`
- `  TrackTemp=%.2f
`
- `  AmbientTemp=%.2f
`
- `  OffPathWetness=%.2f
`
- `  OnPathWetness=%.2f
`
- `  Conditions=%.2f
`
- ` {
`
- ` %s
`
- `Weather
`
- `Could not write to file %s`
- `D:\dev\NASCAR_2004\Source\weather.cpp`
