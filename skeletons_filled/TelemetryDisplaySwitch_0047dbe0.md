## TelemetryDisplaySwitch_0047dbe0 — TelemetryModeSwitchDisplay

**Summary:** Dispatches telemetry data to UI display based on mode field at offset 0xEC: vehicle list data (480 = 0x1E0), delta time (481 = 0x1E1), range width (482 = 0x1E2), or engine/RPM status (483 = 0x1E3).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | mode selector; determines which telemetry data to display |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047dcf4 | jpt_47DBFA | R | jump table pointer for switch dispatch on mode field |
| 005c5bcc | a13f | R | FormatString_1_3f [DERIVED] — "%1.3f" float format for delta time and range width |
| 005c7370 | asc_5C7370 | R | EngineStalledString [DERIVED] — default "engine stalled" / no-engine display string |
| 005c7374 | aDS_7 | R | DS_7String [DERIVED] — format string for engine RPM display |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] — engine/post-processing data pointer for RPM readout |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] — scoring/telemetry data root pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | get indexed list item for vehicle data display (mode 480) |
| 00488b40 | UIStringComparison | display/set text string on a UI element |
| 004b9c80 | RangeWidthGetter | get range width value (mode 482) |
| 004b9cb0 | VehicleLifetimeAverageAccessor | get vehicle lifetime average for delta calculation (mode 481) |
| 004b9ce0 | Delegation | get current delegation value for delta calculation (mode 481) |
| 004b9e30 | VehicleDataAccessor | access vehicle data list (mode 480) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string formatting for numeric telemetry values |

**Guard conditions:** switch on this+0xEC: 0x1E0/480 shows vehicle list data; 0x1E1/481 shows delegation - lifetime delta; 0x1E2/482 shows range width; 0x1E3/483 shows engine/RPM status (guarded: if dword_7C54E0 is null, shows engine stalled string); any other value returns 0 immediately.
