## ___get_qualified_locale_0063ad25 — Qualified locale resolver (__get_qualified_locale)

**Summary:** CRT locale routine behind setlocale: takes a "language[\\0...64...]country[\\0...64...]codepage" spec string, resolves it to an LCID/language/code-page triple with name-table lookups and enumeration helpers, and optionally writes the canonical locale name into a 192-byte destination.

**Called by:** __expandlocale (006324c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Language portion of the input spec string; tested for non-empty |
| this | 0x40 | R | — | Country portion of the input spec string (a1+64); tested for non-empty |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0063a6f4 | _crtGetLocaleInfoA@16 | R | Internal locale-info getter used to initialize dword_FB83D8 when dword_FB8194 != 2 |
| 006f1144 | GetLocaleInfoA | R | Win32 import used to initialize dword_FB83D8 when dword_FB8194 == 2 |
| 006f1288 | IsValidLocale | R | Validates the resolved LCID (flags 1) before committing |
| 006f128c | IsValidCodePage | R | Validates the resolved code page (low 16 bits) |
| 00731500 | off_731500 | R | Country-name translation table (22 entries) passed to _TranslateName |
| 007316b0 | off_7316B0 | R | Language-name translation table (64 entries) passed to _TranslateName |
| 00731cd4 | aNorwegianNynor | R | Special-case locale name string used when the resolved LCID is 2068 |
| 00fb8194 | dword_FB8194 | R | Platform/CRT flavor selector: value 2 selects the Win32 GetLocaleInfoA pointer |
| 00fb83b8 | dword_FB83B8 | RW | Match-result flags: cleared before resolution, read after each helper to decide success |
| 00fb83bc | Locale | R | Resolved LCID from the enumeration helpers; validated with IsValidLocale and written to a2[0] |
| 00fb83c0 | dword_FB83C0 | R | Secondary resolved LCID; written to a2[1] and used for the ID-4098 name fetch |
| 00fb83cc | dword_FB83CC | RW | Global country-name pointer: set to a1+64, may be rewritten by _TranslateName |
| 00fb83d4 | dword_FB83D4 | RW | Global language-name pointer: set to a1, may be rewritten by _TranslateName |
| 00fb83d8 | dword_FB83D8 | RW | Function pointer to the locale-info getter, lazily initialized at entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00633b19 | __itoa | Converts the resolved code page to decimal text appended at Destination+128 |
| 00636a70 | _strcpy | Copies the "Norwegian-Nynorsk" special-case name into Destination |
| 0063a5e6 | _TranslateName | Binary-search name translation against the country table (22 entries) and language table (64 entries) |
| 0063a646 | _GetLcidFromDefault | Resolves the default locale when no usable language is supplied |
| 0063a660 | _ProcessCodePage | Resolves the code page part of the spec (at a1+128) |
| 0063ac13 | _GetLcidFromCountry | Resolves an LCID from the country alone |
| 0063ac4a | _GetLcidFromLangCountry | Resolves an LCID from language + country |
| 0063acd0 | _GetLcidFromLanguage | Resolves an LCID from the language alone |

**Guard conditions:** Entry: if dword_FB83D8 is 0 → initialize from GetLocaleInfoA when dword_FB8194 == 2, else from crtGetLocaleInfoA. `a1 == NULL` → default-locale path. The country sub-string (a1+64) is translated via _TranslateName only when it is non-empty. Resolution dispatch: empty language → country-only if the country is non-empty, else default; non-empty language → language+country when country non-empty, else language-only. If no helper sets dword_FB83B8, a second attempt translates the language through the 64-entry table and retries; still zero → return 0. Post-resolution: code page from a1+128 must be nonzero, pass IsValidCodePage(low 16 bits), and IsValidLocale(Locale, 1) must succeed, else return 0. With no Destination → return 1. LCID 2068 → "Norwegian-Nynorsk" copy; otherwise the ID-4097 fetch must succeed or return 0. The ID-4098 fetch for dword_FB83C0 must succeed or return 0; on success the code page is appended as decimal text and the function returns 1.

**String literals referenced (deterministic):**

- `Norwegian-Nynorsk`
