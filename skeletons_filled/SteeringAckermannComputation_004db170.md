## SteeringAckermannComputation_004db170 — DebugTelemetryBarRenderer

**Summary:** Renders debug telemetry overlay: a path/name label string and a 40-segment color-coded bar indicator (white vs red based on threshold). Gated by global flag flt_5EA4E8. Part of HUD/debug system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | String pointer for display label (may be null, defaults to app directory path) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 005acee4 | flt_5ACEE4 | R | G6B5ScaleFactor [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aec | byte_5D4AEC | R | DefaultTextColor [DERIVED] (also: ` — frame counter value) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] — enables/disables debug telemetry display |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408490 | ShortComputation_8490 | Computes float value from input for Y-coordinate placement |
| 00423a00 | BinarySearchInStringTable | Looks up localized string in string table |
| 004b9a00 | PackedFlagRead_9a00 | Reads packed flag from scoring data to control bar rendering |
| 004b9a10 | sub_4B9A10 | Returns float threshold value from scoring data for bar color cutoff |
| 004d7e40 | UITextRenderWithScale | Renders text at screen coordinates with color/alignment/scale |
| 00587bdc | CRTFtol | Converts double to integer (floor truncation) for Y-coordinate and bar position |
| 00587dd0 | sub_587DD0 | Safe string copy with max length (127 bytes) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting (%c) for bar segment character |

**Guard conditions:**
- Line 15: `flt_5EA4E8 <= 0.0` (debug telemetry disabled). PASS: return 1 immediately. BLOCK: render telemetry.
- Line 22: `this[4]` (label string pointer) is NULL. PASS: use default app directory path. BLOCK: use this+0x10 directly.
- Line 24: Label string differs from default path. PASS: look up in string table, render localized label. BLOCK: skip label rendering.
- Line 40: `PackedFlagRead_9a00` returns true AND `flt_5EA4E8 == 1.0` (specific debug mode). PASS: render 40-segment bar. BLOCK: skip bar.
- Line 48: `segment_index * 0.025 > threshold` (above cutoff). PASS: render segment white. BLOCK: render segment red.
