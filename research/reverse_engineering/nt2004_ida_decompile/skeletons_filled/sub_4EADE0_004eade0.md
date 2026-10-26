## sub_4EADE0_004eade0 — SerializeSkinModelConfigToString

**Summary:** Serializes a skin/model/style/layer/word/decal configuration structure (at `this+0x60` / `this[24]`) into a formatted string buffer. Iterates linked lists within the config to dump all sub-objects (model files, layers, words, stamps/decals, AlphaStamp).

**Called by:** sub_4EAD30 (004ead30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x84)+0x0) | 0x0 | R | — | Linked list node — next pointer (MASFile list) |
| *(*(this+0x94)+0x0) | 0xC | R | — | Layer entry — string at offset 12 (layer name) |
| *(*(this+0x94)+0x0) | 0x14 | R | — | Layer entry — DWORD at offset 20 (color data) |
| *(*(this+0xA4)+0x0) | 0x0 | R | — | Word entry — string at offset 0 (word text) |
| *(*(this+0xA4)+0x0) | 0x8 | R | — | Word entry — float at offset 8 (position X) |
| *(*(this+0xA4)+0x0) | 0xC | R | — | Word entry — float at offset 12 (position Y) |
| *(*(this+0xB4)+0x0) | 0x0 | R | — | Decal/Stamp entry — string at offset 0 (name) |
| *(*(this+0xB4)+0x0) | 0x8 | R | — | Decal/Stamp entry — int at offset 8 (type: 1=decal, 2=stamp) |
| *(*(this+0xB4)+0x0) | 0xC | R | — | Decal/Stamp entry — string at offset 12 (stamp name) |
| *(*(this+0xB4)+0x0) | 0x10 | R | — | Decal/Stamp entry — float at offset 16 (orientation) |
| *(*(this+0xB4)+0x0) | 0x14 | R | — | Decal/Stamp entry — float at offset 20 (size?) |
| *(*(this+0xB4)+0x0) | 0x1C | R | — | Decal/Stamp entry — string at offset 28 (font) |
| *(*(this+0xB4)+0x0) | 0x20 | R | — | Decal/Stamp entry — DWORD at offset 32 (color) |
| *(*(this+0xB4)+0x0) | 0x24 | R | — | Decal/Stamp entry — unknown |
| *(this+0x84) | 0x0 | R | — | Model files linked list head pointer |
| *(this+0x8C) | 0x4 | R | — | Model files linked list — current node next pointer |
| *(this+0x94) | 0x0 | R | — | Layers linked list head pointer |
| *(this+0x9C) | 0x0 | R | — | Layers linked list — current node pointer |
| *(this+0x9C) | 0x4 | R | — | Layers linked list — current node next pointer |
| *(this+0xA4) | 0x0 | R | — | Words linked list head pointer |
| *(this+0xAC) | 0x4 | R | — | Words linked list — current node next pointer |
| *(this+0xB4) | 0x0 | R | — | Stamps/Decals linked list head pointer |
| *(this+0xBC) | 0x0 | R | — | Stamps/Decals linked list — current node pointer |
| *(this+0xBC) | 0x4 | R | — | Stamps/Decals linked list — current node next pointer |
| this | 0x60 | R | — | Pointer to master config struct (this[24]) |
| this | 0x64 | R | — | Config struct field — unknown |
| this | 0x74 | R | — | Config struct field — unknown |
| this | 0x7C | R | — | Config struct field — unknown |
| this | 0x84 | R | — | Config struct field — MASFile list pointer |
| this | 0x8C | RW | — | Config struct field — MASFile list cursor |
| this | 0x94 | R | — | Config struct field — Layer list pointer |
| this | 0x9C | RW | — | Config struct field — Layer list cursor |
| this | 0xA4 | R | — | Config struct field — Word list pointer |
| this | 0xAC | RW | — | Config struct field — Word list cursor |
| this | 0xB4 | R | — | Config struct field — Decal/Stamp list pointer |
| this | 0xBC | RW | — | Config struct field — Decal/Stamp list cursor |
| this | 0xD0 | R | — | Config struct field — AlphaStamp string pointer |

**Written-by note (persistence):**
- this 0x8C: written every call (linked-list cursor reset) — external poke likely overwritten on next call
- this 0x9C: written every call (linked-list cursor reset) — external poke likely overwritten on next call
- this 0xAC: written every call (linked-list cursor reset) — external poke likely overwritten on next call
- this 0xBC: written every call (linked-list cursor reset) — external poke likely overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb9d8 | asc_5FB9D8 | R | Format string "  }\n" (closing brace) |
| 005fbf2c | asc_5FBF2C | R | Format string "  }\n" (closing brace for inner section) |
| 005fc03c | asc_5FC03C | R | Format string for model section |
| 005fc484 | asc_5FC484 | R | Format string for layer section |
| 00610f8c | aAlphastampS | R | Format string "  AlphaStamp=\"%s\"\n" |
| 00610fa0 | aStampS | R | Format string "  Stamp=\"%s\"\n" |
| 00610fb0 | aDecalS | R | Format string "  Decal=\"%s\"\n" |
| 00610fc0 | aSize2f2f | R | Format string "    Size=(%.2f, %.2f)\n" |
| 00610fd8 | aOri2f | R | Format string "    Ori=(%.2f)\n" |
| 00610fe8 | aPos2f2f | R | Format string "    Pos=(%.2f, %.2f)\n" |
| 00611000 | aFontS | R | Format string "    Font=\"%s\"\n" |
| 00611010 | aWordS | R | Format string "  Word=\"%s\"\n" |
| 00611020 | asc_611020 | R | Format string "  }\n" |
| 00611028 | aColorDDD | R | Format string "    Color=(%d, %d, %d)\n" |
| 00611040 | aLayerS | R | Format string "  Layer=\"%s\"\n" |
| 00611050 | aMasfileS | R | Format string "  MASFile=\"%s\"\n" |
| 00611060 | aStyleS | R | Format string "  Style=\"%s\"\n" |
| 00611070 | aModelS | R | Format string "  Model=\"%s\"\n" |
| 00611080 | aSkinS | R | Format string "Skin=\"%s\"\n" |
| 00629120 | byte_629120 | R | Empty string sentinel (used as fallback when a string pointer is null) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a080 | ZeroInitSmallStruct [exact] | Zero-initializes the argument list buffer (ArgList) |
| 0057a0a0 | sub_57A0A0 | Destroys/cleans up the argument list buffer |
| 0057a110 | sub_57A110 | Checks if the source string starts with a skin definition (returns bool — gate) |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | Flushes/writes the formatted string to output and closes handle |
| 0057a400 | BufferWriteWithStringLengthCheck [structural] | Appends a formatted printf-style string to the argument list buffer |

**Guard conditions:** Outer guard: `this[24]` must be non-null AND `sub_57A110(Source, 0, 1, 1)` must return true (source string matches skin definition prefix). If either fails (BLOCKED), the buffer is destroyed immediately and function returns 0. Within each linked-list iteration section, null string pointers are replaced with empty string sentinel `byte_629120`. AlphaStamp only serialized if its string has non-zero length.

**String literals referenced (deterministic):**

- `  {\n`
- `  {\n`
- `  AlphaStamp="%s"\n`
- `  Stamp="%s"\n`
- `  Decal="%s"\n`
- `    Size=(%.2f, %.2f)\n`
- `    Ori=(%.2f)\n`
- `    Pos=(%.2f, %.2f)\n`
- `    Font="%s"\n`
- `  Word="%s"\n`
- `  }\n\n`
- `  }\n\n`
- `    Color=(%d, %d, %d)\n`
- `    Color=(%d, %d, %d)\n`
- `  Layer="%s"\n`
- `  MASFile="%s"\n`
- `  Style="%s"\n\n`
- `  Model="%s"\n\n`
- `Skin="%s"\n`
