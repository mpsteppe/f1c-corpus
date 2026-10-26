## UIMessageCompose_004dba00 — WarningIconComposer

**Summary:** Composes a HUD warning string by checking multiple warning conditions (general, fuel, and two state icons) and appending corresponding icon bytes. Renders at screen position if any warnings active. Part of HUD warning system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf50 | flt_5ACF50 | R | TextRenderParam1 [DERIVED] (also: ` — text render param) |
| 005acf54 | flt_5ACF54 | R | TextRenderParam [DERIVED] |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b9a0 | sub_49B9A0 | Returns true if general warning indicator is active (appends icon 0x82) |
| 0049ba30 | sub_49BA30 | Returns state code (1 → icon 0x8C, 2 → icon 0x8D, else nothing) |
| 0049ba50 | FuelWeightComputation | Returns true if fuel/low-fuel warning is active (appends 'D' icon) |
| 004d7e40 | UITextRenderWithScale | Renders composed warning string at screen position |

**Guard conditions:**
- Line 8: `sub_49B9A0()` returns true (general warning active). PASS: append icon byte 0x82. BLOCK: skip.
- Line 13: `FuelWeightComputation()` returns true (fuel warning active). PASS: append 'D' (68). BLOCK: skip.
- Line 16: `sub_49BA30()` returns 1 (state 1). PASS: append icon byte 0x8C. BLOCK: check state 2.
- Line 23: `sub_49BA30()` returns 2 (state 2). PASS: append icon byte 0x8D. BLOCK: skip icon.
- Line 29: `v2 > 0` (at least one warning active). PASS: render composed string. BLOCK: return 0 (no warnings to display).
