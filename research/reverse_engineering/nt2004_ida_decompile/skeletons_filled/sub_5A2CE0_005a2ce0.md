## sub_5A2CE0_005a2ce0 — FontLoaderAndRasterizer

**Summary:** Loads and rasterizes a font (TTF or bitmap) into a texture atlas for in-game text rendering — creates GDI font objects, measures metrics, and builds the font-texture cache.

**Called by:** sub_592910 (00592910), sub_592A60 (00592a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10B8) | 0x10 | R | — | Font texture atlas surface pointer |
| *(this+0xB4) | 0x1C | R | — | Font glyph cache width |
| *(this+0xB4) | 0x20 | R | — | Font glyph cache height |
| this | 0x18 | RW | — | Font face name string buffer |
| this | 0x24 | R | — | Font data / glyph cache pointer |
| this | 0x64 | RW | 1179648 | Font rendering flags (0x120000) |
| this | 0x6C | RW | 18446744073709551615 | Foreground/background color (0xFFFFFFFFFFFFFFFF) |
| this | 0x90 | RW | — | Font point/height parameter |
| this | 0x98 | RW | — | Font weight parameter |
| this | 0x9B | R | — | Font texture-atlas valid flag |
| this | 0x9C | RW | — | Font style flags (italic/underline/strikethrough) |
| this | 0xA0 | RW | — | Additional render flags |
| this | 0xA8 | RW | 0 | Text alignment / shadow offset |
| this | 0xB0 | R | — | Device DPI scaling factor |
| this | 0xB4 | RW | — | Font glyph cache / texture pointer |
| this | 0x10B8 | RW | — | Final font texture atlas handle |

**Written-by note (persistence):**
- this 0x18: written once during font load (face name copy); poke survives until reload
- this 0x64: written once during font init (flags); poke may corrupt rendering if changed
- this 0x6C: written as sentinel 0xFFFFFFFFFFFFFFFF during init; likely unused/placeholder
- this 0x90: written once during font load (point size); poke may affect text size
- this 0x98: written once (font weight); poke may affect boldness
- this 0x9C: written once from a7 flags; poke would change italic/underline state
- this 0xA0: written once from a7 flags; poke would affect rendering
- this 0xA8: initialized to 0; used as alignment, poke would shift text
- this 0xB4: written once (font cache pointer); poke would break text rendering
- this 0x10B8: written once (texture atlas); poke would corrupt all text

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5060 | DeleteObject | R | GDI DeleteObject import |
| 005d5064 | DeleteDC | R | GDI DeleteDC import |
| 005d5068 | CreateFontIndirectA | R | GDI CreateFontIndirectA import |
| 005d506c | GetDeviceCaps | R | GDI GetDeviceCaps import |
| 005d5070 | SetMapMode | R | GDI SetMapMode import |
| 005d5074 | CreateCompatibleDC | R | GDI CreateCompatibleDC import |
| 005d525c | MulDiv | R | GDI MulDiv import (font height calc) |
| 0061b970 | aFonttex | R | "FONTTEX" string (texture atlas tag) |
| 0061b978 | aTtf_0 | R | ".ttf" lowercase extension string |
| 0061b980 | aTtf | R | ".TTF" uppercase extension string |
| 007e6b48 | dword_7E6B48 | R | Render device / DirectX device pointer |
| 007e8cf0 | dword_7E8CF0 | R | Screen bit-depth (used for format selection) |
| ff00000000005ea3 | byte_FF00000000005EA3 | W | Texture atlas pixel data write |
| ff00000000005ea4 | byte_FF00000000005EA4 | W | Texture atlas pixel data write |
| ff00000000005ea5 | byte_FF00000000005EA5 | W | Texture atlas pixel data write |
| ff00000000005ea6 | byte_FF00000000005EA6 | W | Texture atlas pixel data write |
| ff00000000005ea7 | byte_FF00000000005EA7 | W | Texture atlas pixel data write |
| ff00000000005ea8 | byte_FF00000000005EA8 | W | Texture atlas pixel data write |
| ff00000000005ea9 | byte_FF00000000005EA9 | W | Texture atlas pixel data write |
| ff00000000005eaa | byte_FF00000000005EAA | W | Texture atlas pixel data write |
| ff00000000005eab | byte_FF00000000005EAB | W | Texture atlas pixel data write |
| ff00000000005eac | byte_FF00000000005EAC | W | Texture atlas pixel data write |
| ff00000000005ead | byte_FF00000000005EAD | W | Texture atlas pixel data write |
| ff00000000005eae | byte_FF00000000005EAE | W | Texture atlas pixel data write |
| ff00000000005eaf | byte_FF00000000005EAF | W | Texture atlas pixel data write |
| ff00000000005eb0 | byte_FF00000000005EB0 | R | Texture atlas pixel data read |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005922a0 | sub_5922A0 | Load bitmap/raster font from file |
| 0059fa90 | sub_59FA90 | Release font texture surface |
| 0059fdc0 | ClippedRenderRegion [structural] | Blit glyph data into texture atlas region |
| 005a1d10 | sub_5A1D10 | Allocate font texture atlas structure |
| 005a1dc0 | sub_5A1DC0 | Initialize texture atlas from "FONTTEX" |
| 005a3200 | sub_5A3200 | Build font glyph cache / validate texture |
| 005a36b0 | sub_5A36B0 | Rasterize TTF glyphs into GDI DC |
| 005a3ea0 | sub_5A3EA0 | Validate/load bitmap font file |
| 005a4720 | sub_5A4720 | Get render-device texture manager |
| 005a4740 | sub_5A4740 | Get render device / Direct3D device |
| 005a4750 | sub_5A4750 | Get render device capabilities |
| 005b5940 | j_nullsub_6 | Release COM/texture object |
| 005be8ae | sub_5BE8AE | Debug/log error |
| 005be8bc | __ftol | Float-to-long conversion |
| 005be8e3 | ??2@YAPAXI@Z | operator new |
| 005be900 | _strstr | Substring search (TTF check) |
| 005c0803 | __strupr | Uppercase conversion |
| 005c24b0 | _strrchr | Find last backslash in path |

**Guard conditions:** If font file has .ttf/.TTF extension: uses GDI TrueType path (CreateFontIndirectA + glyph rasterization). Otherwise: bitmap/raster font path. If CreateFontIndirectA fails, returns -1. If `(a7 & 0x20000)` (texture atlas mode), builds FONTTEX atlas with power-of-two dimensions. If `(a7 & 0x10000) && !(a7 & 0x800)`: sets color key to -1 (transparent). No early-return guard on this-struct fields; all flows are driven by font file type and a7 flags.

**String literals referenced (deterministic):**

- `FONTTEX`
- `.ttf`
- `.TTF`
