## VertexColorPackRGBto16_0050a92d — PackVertexColorsTo16bit

**Summary:** Iterates vertex color float data, performs RGB-to-YCbCr-like color conversion, clamps channels to 8-bit range, and packs results into 16-bit values per pixel. Part of rendering pipeline for vertex color encoding to texture format.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50AB51 (0050ab51), DestructorWithResourceCleanup_b830 (0050b830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Pointer to destination output buffer |
| this | 0x1050 | R | — | Width or horizontal stride component |
| this | 0x1054 | R | — | Height or vertical stride component |
| this | 0x106C | R | — | Pointer to source vertex color float data (cast to float*) |
| this | 0x1070 | R | — | Starting vertex index / loop counter initial value |
| this | 0x1074 | R | — | Horizontal pitch multiplier for destination buffer offset |
| this | 0x1078 | R | — | Vertex count — loop upper bound |
| this | 0x107C | R | — | unknown (not directly accessed in this function) |
| this | 0x1080 | R | — | Vertical stride multiplier for destination buffer offset |
| this | 0x1084 | R | — | unknown (not directly accessed in this function) |
| this | 0x108C | RW | 0 | Completion flag — set to 0 when processing finishes |
| this | 0x1090 | R | — | Enable/validity flag for the second processing channel |
| this | 0x1094 | R | — | Shift amount for R/Cr channel in 16-bit packing |
| this | 0x1098 | R | — | Shift amount for B/Cb channel in 16-bit packing |

**Written-by note (persistence):**
- this 0x108C: set to 0 once at end of processing; survives as cleared flag until externally reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005adbf8 | flt_5ADBF8 | R | Render_ColorMatrix_DBF8 [DERIVED] |
| 005adbfc | flt_5ADBFC | R | LightAttenuationConst [DERIVED] |
| 005adc00 | flt_5ADC00 | R | ColorMatrixCol1 [DERIVED] |
| 005adc04 | flt_5ADC04 | R | ColorMatrixCoeff_04 [DERIVED] |
| 005adc08 | flt_5ADC08 | R | VertexMatrixCoeff [DERIVED] |
| 005adc0c | flt_5ADC0C | R | ColorMatrixCoeff [DERIVED] |
| 005adc10 | flt_5ADC10 | R | VertexColorMatrixCoeff [DERIVED] |
| 005adc14 | flt_5ADC14 | R | unknown (not directly referenced in decompiled code) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks that field at offset 0x108C (completion/validity flag) AND field at offset 0x1090 (second enable flag) are both non-zero. If either is zero, function skips all processing and returns 0 immediately.
