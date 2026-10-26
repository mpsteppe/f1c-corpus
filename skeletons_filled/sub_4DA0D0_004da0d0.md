## sub_4DA0D0_004da0d0 — HUDVehicleInfoRenderer

**Summary:** Renders debug/vehicle info overlay (gear/position, name, indexed extra chars, speed) for two entities (left/right columns) on screen. Part of HUD/debug UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D9F80 (004d9f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4060 | R | — | Gear/position index (0-24 range) for display |
| *(this+0x1C) | 0x46F8 | R | — | Entity name string (null-terminated) |
| this | 0x14 | R | — | Float speed value, rendered with %6.3f |
| this | 0x18 | R | — | Flag: 0 = use this+0x1C pointer as left data source, non-zero = swap sides |
| this | 0x1C | R | — | Pointer to entity data struct (alternative to global dword_7C54E0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf60 | flt_5ACF60 | R | TextColorDefault [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae8 | byte_5D4AE8 | R | PositionNameSuffix [DERIVED] |
| 005d4af0 | byte_5D4AF0 | R | Left-side base character offset for indexed display items |
| 005d4af1 | byte_5D4AF1 | R | Right-side base character offset for indexed display items |
| 005d4af4 | dword_5D4AF4 | R | Count of indexed display items to render per column |
| 005d4b40 | a63f | R | Format string "%6.3f" for speed display |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | Renders text string at screen coordinates with color, alignment, and scale |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with buffer bounds checking (%c and %6.3f) |
| 00589901 | sub_589901 | unknown — called on name string after copy, likely text/encoding post-process |

**Guard conditions:** 
- Line 26: Checks byte at `this+0x18` (swap flag). Non-zero → left column gets dword_7C54E0, right column gets *(this+0x1C). Zero → left column gets dword_7C54E0, right column gets *(this+0x1C). This swaps the data source per column.
- Line 39: Checks both data source pointers are non-null. Either null → skip all rendering (return byte at this+0x18).
- Line 42: Checks `*(v4+0x4060) - 1 <= 0x18` (gear/position index 1-25). PASS: render gear character. FAIL: skip.
- Line 65: Checks `dword_5D4AF4 > 0` (has indexed items). PASS: render loop for left column. FAIL: skip.
- Line 81: Same check as line 42 but for right column (v3).
- Line 105: Same check as line 65 but for right column (v3).
