## _GetLcidFromLangCountry_0063ac4a — LCID resolver for language+country pairs

**Summary:** Locale helper that configures the matching globals (3-letter-code flags, prefix length), enumerates system locales via EnumSystemLocalesA with the LangCountryEnumProc callback, and returns the accumulated match flags — clearing them when the result is incomplete.

**Called by:** ___get_qualified_locale (0063ad25)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0063a92e | _LangCountryEnumProc@4 | R | Address of the enumeration callback passed to EnumSystemLocalesA |
| 006f1284 | EnumSystemLocalesA | R | Import thunk: enumerates the installed locales (flag 1) |
| 00fb83b8 | dword_FB83B8 | RW | Result flags accumulated by the callback; captured into the return value before being cleared on incomplete matches |
| 00fb83bc | Locale | W | Cleared to 0 before enumeration; the callback stores the matched LCID here |
| 00fb83c4 | dword_FB83C4 | RW | Set to whether the language string length equals 3; read by the callback to pick its match mode |
| 00fb83c8 | dword_FB83C8 | W | Set to whether the country string (dword_FB83CC) length equals 3 |
| 00fb83cc | dword_FB83CC | R | Country-name string whose length is measured |
| 00fb83d0 | MaxCount | W | Prefix-match limit: 2 when the language string is a 3-letter code, else the leading-letter run of dword_FB83D4 |
| 00fb83d4 | dword_FB83D4 | R | Language-name string measured for the 3-letter test |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006354d0 | sub_6354D0 | String length helper; its result compared == 3 to detect 3-letter language/country codes |
| 0063a80c | _GetPrimaryLen | Counts the leading ASCII letters of dword_FB83D4 to set MaxCount when the name is not a 3-letter code |

**Guard conditions:** No early returns. Final result handling: if `(flags & 0x100) == 0 || (flags & 0x200) == 0 || (flags & 7) == 0` → dword_FB83B8 is cleared to 0, but the function still returns the previously captured flag value (result). MaxCount selection: 2 if `strlen(dword_FB83D4) == 3`, otherwise `GetPrimaryLen(dword_FB83D4)`. Locale is reset to 0 before the enumeration starts.
