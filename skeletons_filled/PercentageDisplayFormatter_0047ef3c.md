## PercentageDisplayFormatter_0047ef3c — PercentageDisplayFormatter

**Summary:** Formats global UI percentage slider value as integer percentage string ("%0.0f%%") and dispatches via conditional call wrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] — not directly used; referenced in same compilation unit |
| 005c74e0 | a00f | R | PercentFormat00f [DERIVED] — "%0.0f%%" format string for percentage display |
| 007d084c | flt_7D084C | R | UIPercentageSlider [DERIVED] — global percentage slider value (0.0-1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047e940 | ConditionalCallWrapper | dispatch formatted percentage string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe format string for float-to-percentage conversion |

**Guard conditions:** none — always formats and dispatches
