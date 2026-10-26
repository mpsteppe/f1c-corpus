## TexturePaletteColorLookup_0051ce2a — Palette-indexed texture color lookup

**Summary:** Converts palette-indexed texture data to RGB output using four color lookup tables. Processes source index bytes in pairs, performing table lookups to produce 6 output bytes (2 pixels) per iteration, with fallback for odd-width rows.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Row width in bytes — half-width used as pixel-pair loop count; odd check for remainder |
| this | 0x11C | R | — | Base offset value added to all table lookup results |
| this | 0x19C | R | — | Pointer to palette lookup sub-struct (v4) containing four tables |
| this | 0x1AC | R | — | v4[4]: First lookup table — indexed by third source channel for first output channel |
| this | 0x1B0 | R | — | v4[5]: Second lookup table — indexed by second source channel for third output channel |
| this | 0x1B4 | R | — | v4[6]: Third lookup table — combined with v4[7] for second output channel |
| this | 0x1B8 | R | — | v4[7]: Fourth lookup table — combined with v4[6] via 16-bit shift for second output channel |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard at `a1[23] >> 1` (line 41): if half row width > 0, enter 2-pixel-per-iteration loop. If 0, skip loop. Guard at `(a1[23] & 1)` (line 73): if row width is odd, process the remaining single pixel at the end.
