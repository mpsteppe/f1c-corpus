## TimerClockFormat_004d8130 — HUD text render with alpha

**Summary:** Renders a text string (directory path prefix + generated character suffix sequence) at fixed screen position (640, 974) with configurable alpha (`a1`) modulated by audio envelope. String suffix base character is selected by flag `a2`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhaseBasedAudioParticleEnvelope (004d7ff0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4a60 | byte_5D4A60 | R | Base character for suffix sequence when a2 != 0 |
| 005d4a61 | byte_5D4A61 | R | Base character for suffix sequence when a2 == 0 |
| 005d4a64 | dword_5D4A64 | R | Number of suffix characters to generate |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | Renders UI text at given position/color/scale with alpha |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats a single character into buffer for suffix generation |

**Guard conditions:** `a2 == 0` selects `byte_5D4A61` as suffix base; `a2 != 0` selects `byte_5D4A60`. `dword_5D4A64 <= 0` skips suffix generation (renders path only). `a1 <= 0.0` clamped to `0.001` (prevents zero-alpha render).
