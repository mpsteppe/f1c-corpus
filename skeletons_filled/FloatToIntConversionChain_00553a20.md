## FloatToIntConversionChain_00553a20 — FloatToIntConversionChain

**Summary:** Converts float array values to integers via CRTFtol, then dispatches to sub_553AA0. Has an alternate path (sub_55C860) when flag 0x40000 is set on this[6]. Part of geometry/transform processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatVectorWithConditionalTransform (00494c20), F_2DTextRenderingWithScissorRectangle (0049b370), sub_49F1C0 (0049f1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | Flags field; bit 0x40000 selects alternate processing path; bit 0x400 cleared after main path |

**Written-by note (persistence):**
- this 0x18: Flags updated conditionally each call; external poke affects path selection

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553aa0 | sub_553AA0 | Processes converted int values with this context |
| 0055c860 | sub_55C860 | Alternate processing path when flag 0x40000 is set |
| 00587bdc | CRTFtol | CRT string-to-float conversion |

**Guard conditions:** Flag 0x40000 in this[6] gates the path. If set → sub_55C860 path (then clears 0x400). If clear → CRTFtol conversions then sub_553AA0 (also clears 0x400).
