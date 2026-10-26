## HUDFlagRendererSecondary_004dbac3 — FlagIndicatorComposer

**Summary:** Composes and renders HUD flag/status indicator string by checking multiple conditions (vehicle flag, pit state, disqualification, race phase). Renders text overlay at screen position. Part of HUD flag/status system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf48 | flt_5ACF48 | R | unknown — rendering parameter (not directly read in this function) |
| 005acf4c | flt_5ACF4C | R | unknown — rendering parameter (not directly read in this function) |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] — checked for value 8 to add 'B' flag indicator |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ba90 | PitStateFlagCheck | Returns true if vehicle is in pit state (adds 'f' indicator) |
| 0049bab0 | DisqualificationCheck | Returns true if vehicle is disqualified (adds '?' indicator) |
| 0049bb20 | VehicleFlagCheck | Returns true if vehicle flag condition active (adds 'A' indicator) |
| 004d7e40 | UITextRenderWithScale | Renders flag string at screen position in white with scale 2.0 |

**Guard conditions:**
- Line 8: `a1` parameter (caller-provided flag) non-zero. PASS: add '>' (62) indicator. BLOCK: skip.
- Line 13: `VehicleFlagCheck()` returns true. PASS: add 'A' (65) indicator. BLOCK: skip.
- Line 15: `PitStateFlagCheck()` returns true. PASS: add 'f' (102) indicator. BLOCK: skip.
- Line 17: `DisqualificationCheck()` returns true. PASS: add '?' (63) indicator. BLOCK: skip.
- Line 20: `dword_7C56A8 == 8` (race phase 8). PASS: add 'B' (66) indicator. BLOCK: skip.
- Line 22: `a2 > 0` (at least one flag active). PASS: render composed flag string. BLOCK: return last check result.
