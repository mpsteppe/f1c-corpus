## LocaleEnumProc_0058ffec — LocaleEnumProc

**Summary:** Callback for EnumSystemLocalesA. Parses locale hex string to integer, queries locale region/language names via dword_8D3FB8 (locale info function), compares against target strings via sub_588410. Sets validation flags (dword_8D3FB0 bits) to track match quality: bit 0 = partial match, bit 1 = close match, bit 8 = region matched, bit 9 = charset matched. Returns TRUE to continue enumeration, FALSE to stop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3f98 | Locale | RW | CurrentLocaleID [DERIVED] — set to matched locale ID when close enough match found |
| 008d3f9c | dword_8D3F9C | R | LocaleMatchFlag [DERIVED] — nonzero = region is 3-letter code (affects LCTYPE query) |
| 008d3fa0 | dword_8D3FA0 | R | Locale_CharsetMode [DERIVED] — charset comparison mode (2=exact 3-letter, else count) |
| 008d3fa4 | dword_8D3FA4 | R | LocaleIsThreeLetterFlag [DERIVED] — nonzero = use LCTYPE 3 (3-letter language name) vs 4097 |
| 008d3fa8 | dword_8D3FA8 | R | LocaleLanguageStr [DERIVED] — target language string for comparison |
| 008d3fac | dword_8D3FAC | R | LocaleLanguageRegionPtr [DERIVED] — target region string for comparison |
| 008d3fb0 | dword_8D3FB0 | RW | LocaleValidationFlags [DERIVED] — match quality flags (bit 0=partial, 1=close, 8=region, 9=charset) |
| 008d3fb1 | byte_8D3FB1 | W | Unknown_Byte_Config [DERIVED] — unknown flag written during locale match |
| 008d3fb4 | dword_8D3FB4 | W | LocaleLanguageID [DERIVED] — matched language ID from the best-matching locale |
| 008d3fb8 | dword_8D3FB8 | R | LocaleInfoFunc [DERIVED] — locale info query function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | Compare two locale/language strings for equality (case-insensitive or normalized) |
| 0058e1b0 | Strlen | Get string length for comparison against charset mode value |
| 00590440 | ShortInRangeCheckAgainstStaticTable | Validate locale ID against a static range/table of valid locales |
| 0059045f | sub_59045F | Handle close locale match (set flags and possibly override current Locale) |
| 005905dd | HexStringToIntParser | Convert hex locale string (e.g. "0409") to integer locale ID |
| 00596c80 | sub_596C80 | Compare language string against buffer with charset-aware matching |

**Guard conditions:**
- If locale info query for region name (LCTYPE 4098 or modified) fails → set dword_8D3FB0=0, return 1 (continue)
- If region name matches target → set flags 0x304 (bits 8, 9, 2), record language ID
- If language name matches exactly → go to LABEL_6 (set Locale = v1)
- If language name matches via charset (sub_596C80) → set flag bit 2, record language ID
- If language name matches via charset AND string length == charset mode → close match, set Locale = v1
- If language name length matches charset mode exactly → call sub_59045F for further processing
- If full match found ((dword_8D3FB0 & 0x300) == 0x300) AND language matches → consider stopping enumeration
- Returns `((~dword_8D3FB0) >> 2) & 1` — continues while bit 2 is clear (no charset-exact match found)
