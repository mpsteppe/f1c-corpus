## TimestampedRenderStringUpdate_0049da60 — Timestamped HUD string update

**Summary:** Renders a single timestamped data row (label + value) for HUD display. Formats value via sub_49C8F0 and label via sub_49C960, then renders as label/value pair.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | render surface/texture pointer (this[2]) |
| this | 0x14 | R | — | display context pointer (this[5]) |
| this | 0x68 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccbb8 | dword_5CCBB8 | R | UITextLayoutBaseY [DERIVED] — starting Y position |
| 005ccbbc | dword_5CCBBC | R | UISectionOffsetStride [DERIVED] — Y step |
| 005ccbc0 | dword_5CCBC0 | R | TextureSurfaceRef1 [DERIVED] — left column texture |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007ce238 | dword_7CE238 | R | TextDataBatchSource [DERIVED] — right column text batch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049c8f0 | sub_49C8F0 | formats timestamp value text into buffer |
| 0049c960 | sub_49C960 | formats timestamp label text into buffer |
| 0049e410 | DualTextDisplay | dual text static display element |
| 0049f6a0 | StringFormatAndRender | formats string and renders to HUD at position |

**Guard conditions:** Checks this[2] (0x8) non-null — blocks entire render if null.
