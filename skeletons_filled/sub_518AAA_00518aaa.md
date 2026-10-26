## sub_518AAA_00518aaa — PNGPLTEChunkParser

**Summary:** Parses and validates a PNG PLTE (palette) chunk. Checks chunk ordering (requires IHDR first, no IDAT before PLTE, no duplicate PLTE), validates palette length is multiple of 3, allocates and fills palette entries, and stores palette info. Part of PNG decoder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | flags register: bit 1 set after PLTE parsed |
| this | 0x5D | RW | — | flags low byte: bit 4 set (0x10) to mark palette active |
| this | 0x104 | RW | — | palette data pointer (allocated via sub_513C80) |
| this | 0x108 | RW | — | palette entry count (number of RGB triplets) |
| this | 0x10A | RW | — | tRNS entry count for color type 3 truncation check |
| this | 0x116 | R | — | color type (check == 3 for palette-indexed images) |

**Written-by note (persistence):**
- this 0x58: bit 1 set once; external poke survives
- this 0x5D: bit 4 set once; external poke survives
- this 0x104: allocated pointer; external poke leaks
- this 0x108: set to palette entry count; external poke corrupts palette
- this 0x10A: set from tRNS length; external poke corrupts alpha

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005afc74 | aTruncatingInco | R | String_TruncatingInco [DERIVED] |
| 005afc9c | aInvalidPalette | R | aInvalidPalette [DERIVED] |
| 005afcb4 | aDuplicatePlteC | R | DuplicatePlteC [DERIVED] |
| 005afccc | aInvalidPlteAft | R | InvalidPlteAfterString [DERIVED] |
| 005afce4 | aMissingIhdrBef_0 | R | PNG_NoIHDRString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00511869 | GuardedCallWithLongjmp | longjmp abort on critical errors |
| 00511887 | CallbackDispatch | dispatch warning/error messages |
| 00513b12 | FlagSetterWithGuard | set flag and store palette reference |
| 00513c80 | sub_513C80 | allocate palette data buffer (entry count * sample size) |
| 00517f58 | sub_517F58 | feed palette data into CRC32 |
| 00518828 | sub_518828 | post-CRC error check and dispatch |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x116 | != | 3 | color type != palette (3) |
| this | 0x116 | == | 3 | color type == palette (3) |

**Guard interpretation:** Color type at 0x116 selects validation path. If != 3 (PASSES non-palette), palette chunk is still allowed but triggers "Invalid palette chunk" dispatch. If == 3 (PASSES palette), palette entries are validated and stored normally. Entry count must be multiple of 3; if not and color type == 3, GuardedCallWithLongjmp abort; if not and color type != 3, CallbackDispatch warning.
