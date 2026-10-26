## MenuOptionValueDisplay_004673b0 — MenuOptionValueDisplay

**Summary:** Formats and displays the current value of a menu option by dispatching to the appropriate formatter (vehicle setup vs generic), then replaces the displayed string if it changed. Belongs to menu option system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedCallWith1Increment (00467340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | R | — | pointer to option value data (string offset at +30) |
| this | 0x324 | R | — | current selected value/index for formatter |
| this | 0x328 | R | — | additional parameter for SetupValueFormatDispatcher |
| this | 0x32C | R | — | selection type (4 = vehicle setup formatter, else generic) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042f2f0 | SetupValueFormatDispatcher | formats option value using generic dispatcher for non-type-4 options |
| 0042f470 | VehicleSetupValueFormatter | formats option value using vehicle-specific formatter for type-4 options |
| 00467430 | StringCompareAndConditionalReplace | compares formatted string with current display and replaces if different |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string format into local buffer using "%s" format |

**Guard conditions:** Checks this+812 (type at offset 0x32C) against literal 4 to select formatter path. No early-return guard — both paths always execute.
