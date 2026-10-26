## AudioCodecBufferAllocation_0058f4f2 — LocaleDataInitAndDecimalSeparatorSet

**Summary:** Initializes locale data for number formatting. If locale flag (dword_8D3F40) is set, queries system locale info for digit grouping (0xE), leading zero (0xF), and decimal separator (0x10) via sub_5968F6, converts via InPlaceDigitCharConversionStripSemicolons, stores three buffers in off_5E9AC0, and sets byte_5E6BD8 (decimal separator). If flag is zero, allocates empty 2-byte buffers. Returns 0 on success, -1 on allocation failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] — unused in this context? |
| 005e6bd8 | byte_5E6BD8 | W | DecimalSeparatorChar [DERIVED] — set to first byte of locale decimal separator string |
| 005e6bdc | dword_5E6BDC | W | LocaleInitFlag [DERIVED] — set to 1 after locale data initialized |
| 005e9a88 | unk_5E9A88 | R | LocaleDataPtr [DERIVED] — sentinel value compared against off_5E9AC0[0] |
| 005e9ac0 | off_5E9AC0 | R | PTR_AudioStreamBuffer [DERIVED] — array of 3 locale buffer pointers (digit grouping, leading zero, decimal sep) |
| 008d3f40 | dword_8D3F40 | R | LocaleInitFlag [DERIVED] — nonzero = use system locale, zero = use defaults |
| 008d3f5c | dword_8D3F5C | RW | CRTLocaleAllocBlock [DERIVED] — allocated buffer for LOCALE_SGROUPING digit grouping data |
| 008d3f60 | dword_8D3F60 | RW | Dword_LocaleBuffer [DERIVED] — allocated buffer for LOCALE_ILZERO leading zero data |
| 008d3f64 | dword_8D3F64 | RW | LocaleBufferHandle [DERIVED] — allocated buffer for LOCALE_SDECIMAL decimal separator data |
| 008d3f8e | word_8D3F8E | R | LocaleLanguageID [DERIVED] — language ID used for locale queries |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | Allocate 2-byte default buffers when locale flag is zero |
| 0058aa6f | sub_58AA6F | Free locale buffers on cleanup or error path |
| 0058f6c7 | InPlaceDigitCharConversionStripSemicolons | Convert locale digit string (semicolon-separated ASCII digits) to nibble array |
| 0058fca0 | sub_58FCA0 | Initialize buffer with null terminator |
| 005968f6 | sub_5968F6 | Query system locale info for a specified LCTYPE category |

**Guard conditions:**
- `dword_8D3F40` (LocaleInitFlag) nonzero → query system locale via sub_5968F6 for categories 0xE, 0xF, 0x10
- Any sub_5968F6 call fails (v3 != 0) → free all buffers, set to NULL, return -1
- `*off_5E9AC0 != &unk_5E9A88` → old locale buffers exist, free them before replacing
- `dword_8D3F40` zero → free old buffers, allocate default 2-byte empty buffers, check each for NULL
- `MallocWrapperForNhMalloc(2)` returns NULL on any of 3 allocations → return -1
- Success → set byte_5E6BD8 (decimal separator), dword_5E6BDC = 1, return 0
