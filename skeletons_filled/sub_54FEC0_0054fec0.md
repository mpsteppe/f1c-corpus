## sub_54FEC0_0054fec0 — Texture creation with power-of-2 validation

**Summary:** Creates a texture by validating that width and height are powers of two (standard sizes 1-4096), setting up an audio emitter association via sub_54FE50, and calling the main texture initialization function. Reports error and cleans up on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_494690 (00494690), sub_546450 (00546450), sub_552470 (00552470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | Audio emitter pointer (set by sub_54FE50, passed to texture initialization) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0054ffe4 | jpt_54FEE7 | R | Jump table for width validation switch |
| 0054ffec | byte_54FFEC | R | Data byte for jump table / validation |
| 0055002c | jpt_54FF3A | R | Jump table for height validation switch |
| 00550034 | byte_550034 | R | Data byte for jump table / validation |
| 005dbfec | aTextureSSizeNo | R | "Texture %s size not power of 2" error format string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c590 | sub_53C590 | Error/logging function for non-power-of-2 dimension error |
| 00542950 | UtilityFunction_2950 | Main texture initialization routine (takes emitter + dimensions) |
| 0054fe50 | sub_54FE50 | Creates audio emitter and stores filename for this texture |
| 005502c0 | DestructorWithConditionalFreeFlagClear | Cleans up texture object on initialization failure |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting for error message |

**Guard conditions:** If a3 (width) is NOT a power of 2 (value not in {1,2,4,8,16,32,64,128,256,512,1024,2048,4096}), BLOCKED: sets v7=1. Same for a4 (height). After both checks, if v7 != 0, BLOCKED: error message returned, function returns -1 without creating texture. If both dimensions are valid powers of 2, PASSES: continues to audio emitter setup and texture initialization.
