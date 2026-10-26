## PitRepairStatusDisplay_004a58b0 — FormatPitRepairStatusWidget

**Summary:** Formats and refreshes a pit-repair HUD widget by computing fuel/lap-time display strings, looking up part names, formatting repair progress counters, and selecting "Repair"/"Do Not Repair" status labels based on internal mode flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F1C0 (0049f1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4074 | R | — | total part count (denominator for "%s/%d" format, read via vtable dereference) |
| this | 0x0 | R | — | vtable / base object pointer |
| this | 0x28 | R | — | mode flag for part-label row: 1 = show empty/blank, 0 = show part info with count |
| this | 0x2C | R | — | string-table selector for part-label row (chooses off_5C6E14 vs unk_5C6E18) |
| this | 0x58 | R | — | base offset constant in fuel/time computation formula |
| this | 0x60 | R | — | scaling multiplier in fuel/time computation formula |
| this | 0x6C | R | — | integer count/level value in fuel/time computation formula |
| this | 0xAC | R | — | current part index for NthValidPartLookup (which part to name) |
| this | 0xEC | R | — | current repair progress count (numerator) |
| this | 0xF0 | R | — | target/max repair count (denominator) |
| this | 0x128 | R | — | repair-status flag: 1 = hidden/empty, 0 = show "Repair" or "Do Not Repair" |
| this | 0x12C | R | — | repair-action flag: nonzero = show "Repair", zero = show "Do Not Repair" |
| this | 0x17C | R | — | time/lap suffix multiplier for fuel display (0.0 = no suffix appended) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea40 | dbl_59EA40 | R | SuspensionSpringK [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c3810 | off_5C3810 | R | OffsetTable_5C3810 [DERIVED] — used as empty/blank string fallback |
| 005c6e14 | off_5C6E14 | R | VtablePtr_5C6E14 [DERIVED] — default label string when this+0x2C is set |
| 005c6e18 | unk_5C6E18 | R | Unk_StringConstant [DERIVED] — alternate label string when this+0x2C is not set |
| 005ccea4 | off_5CCEA4 | R | GameWidgetVTable_5CCEA4 [DERIVED] — format-string source for fuel/time display |
| 005cd62c | aSD_0 | R | Str_SD [DERIVED] |
| 005cd634 | aDoNotRepair | R | DoNotRepairString [DERIVED] — "Do Not Repair" label text |
| 005cd644 | aRepair | R | RepairString [DERIVED] — "Repair" label text |
| 005cd64c | aDD_3 | R | DDStr [DERIVED] |
| 005cd658 | aDD_2 | R | DDString [DERIVED] |
| 005cd664 | aNoChange | R | NoChangeField [DERIVED] — "No Change" fallback when part lookup fails |
| 005cd670 | aDS_6 | R | FormatDS_6 [DERIVED] |
| 005cd678 | a41fS | R | String_41fS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) — default string when validated part name is null |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — lookup table buffer for BinarySearchInStringTable |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) — temporary scratch buffer for composed strings |
| 007d0450 | dword_7D0450 | R | CostDisplayMode [DERIVED] — 1 = gallons/liters format, otherwise = rounded integer format |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | search a key string in a lookup table; if found, copy result to output buffer |
| 004a5820 | NthValidPartLookup | retrieve pointer to the Nth valid part name string from a part list |
| 00587bdc | CRTFtol | convert float to integer (CRT floating-point truncation) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf with buffer-overflow protection into fixed-size destination |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | == | 1 | part-label mode: 1 = blank/empty row, 0 = show part name with count |
| this | 0x128 | == | 1 | repair-status mode: 1 = hidden/blank, 0 = show "Repair" or "Do Not Repair" |

**Guard interpretation:** Both guards are mode-selector flags. When a flag equals 1 the corresponding HUD row is rendered blank (empty string from off_5C3810). When not 1, full status text is displayed: at 0x28, the widget shows a part name followed by a count-denominator in "%s/%d" format; at 0x128, the widget shows "Repair" (if 0x12C is nonzero) or "Do Not Repair" (if 0x12C is zero).
