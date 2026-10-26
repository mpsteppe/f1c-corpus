## TrackPositionNameFormatter_0049d320 — Gear indicator formatting and display

**Summary:** Formats the current gear position (numeric, neutral "N", or error text) into a display buffer and renders it to the HUD. Called from steering wheel animation chain.

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
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c36fc | aN | R | StringN [DERIVED] — "N" string for neutral gear |
| 005ccec4 | byte_5CCEC4 | R | aError_CEC4 [DERIVED] — gear error string source |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] — output buffer for gear text |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | searches string table for matching entry |
| 0049b8f0 | EngineRevValueAccessor | reads engine rev/gear state value |
| 00553070 | sub_553070 | renders formatted text to HUD at screen position |
| 00587dd0 | sub_587DD0 | formats gear text into output buffer with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | safe integer-to-string format ("%d") |

**Guard conditions:** Calls EngineRevValueAccessor(). If return >= 0 and non-zero: formats number via StringFormatWithBufferOverflowCheck, then renders via sub_553070. If return == 0: copies "N" (neutral) string to MessageDisplayBuffer. If return < 0: copies error string (byte_5CCEC4) to MessageDisplayBuffer. Both string-copy paths then format via sub_587DD0 and render via sub_553070 with display resource at *(this[4] + 84).
