## GlobalStateBranchFormat_0049d3f0 — Speed value formatting and display

**Summary:** Reads speed magnitude via one of two accessor functions (selected by encoding flag), formats as zero-padded 3-digit number, and renders to HUD.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | display resource context pointer (this[4]) |
| this | 0x64 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccec8 | a3d | R | FormatStringToken [DERIVED] ("%.3d" format string) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag [DERIVED] — selects speed accessor variant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b900 | SpeedMagnitude | reads speed magnitude (standard encoding) |
| 0049b950 | SpeedMagnitude_b950 | reads speed magnitude (alternate encoding) |
| 00553070 | sub_553070 | renders formatted text to HUD at screen position |
| 0058815f | StringFormatWithBufferOverflowCheck | safe integer-to-string format ("%.3d") |

**Guard conditions:** Checks `byte_7D0474` (UITextEncodingFlag): if non-zero calls SpeedMagnitude (standard), else calls SpeedMagnitude_b950 (alternate). No early-exit guards — always renders.
