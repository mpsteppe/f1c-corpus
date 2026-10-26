## BrakeBiasAdjustmentControl_00447d00 — BrakeBiasAdjustmentControl

**Summary:** Adjusts brake bias index based on signed input delta, computes final bias value from index * step + base offset, formats as percentage string and renders OSD display. Belongs to vehicle setup/UI system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1564 | RW | — | Computed final brake bias value (index * step + base) |
| this | 0x156C | R | — | Brake bias base offset (starting bias) |
| this | 0x1574 | R | — | Brake bias step increment per index unit |
| this | 0x157C | R | — | Maximum brake bias index limit (cap) |
| this | 0x1580 | RW | 0 | Current brake bias index (adjusted by input, clamped 0..max-1) |

**Written-by note (persistence):**
- this 0x1564: recalc every frame — external poke does NOT persist
- this 0x1580: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005c4394 | aS41f41f | R | Str_S41F41F [DERIVED] |
| 005c43a4 | aBrakeBias | R | StringBrakeBias [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Look up "BrakeBias" string in string table; if found, copy localized text to display buffer |
| 0045bd10 | TextLineWrappingAndRendering | Render formatted bias display string to screen at specified coordinates |
| 0045bdf0 | ShortComputation_bdf0 | Per-frame tick computation on resource dispatch context (unknown detail) |
| 0058815f | StringFormatWithBufferOverflowCheck | Format bias percentages into display string with overflow check |

**Guard conditions:** Input direction check: a2 > 0 increments bias index (capped at max-1); a2 < 0 decrements (floored at 0); a2 == 0 skips adjustment. No early return — bias value is always recomputed and display always updated.
