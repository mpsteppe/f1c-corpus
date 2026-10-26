## FloatToIntConversion_00489e90 — Scroll position pixel conversion

**Summary:** Converts scroll index (this[0x14C]) to pixel position (this[0x150]) via ratio: round(scroll_index / max_scroll * display_size). Uses CRTFtol for float-to-int truncation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecrementCounterVirtualCall (00489500), UINavigationAdvanceHandler (00489530), StateUpdateWithDecrement (00489560), sub_4895B0 (004895b0), UIListSelectionHandler (00489ab0), sub_489D00 (00489d00), UIScrollbarThumbDragHandler (0048a650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14C | R | — | this[83] — scroll offset (numerator for ratio) |
| this | 0x150 | RW | 0 | this[84] — computed pixel position (output) |
| this | 0x154 | R | — | this[85] — display size (pixel range for ratio) |
| this | 0x160 | R | — | this[88] — max scroll value (denominator for ratio) |

**Written-by note (persistence):**
- this 0x150: set to 0 if this[0x160] is 0; otherwise set to rounded pixel position; survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | CRT float-to-long truncation (floor/lrint equivalent) |

**Guard conditions:** If this[0x160] (max scroll value) is 0, skips conversion — sets this[0x150] = 0 and returns 0.
