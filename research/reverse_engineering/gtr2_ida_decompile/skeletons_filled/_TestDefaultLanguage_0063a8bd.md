## _TestDefaultLanguage_0063a8bd — Default-language predicate for enumeration callbacks

**Summary:** Locale helper used by the language/LCID enumeration callbacks: fetches the language identifier for a candidate LCID, compares it against the candidate, and otherwise checks the default-language name length; returns TRUE when the candidate matches or the flag requires permissive acceptance.

**Called by:** _LangCountryEnumProc@4 (0063a92e), _LanguageEnumProc@4 (0063ab48)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b08 | dword_912B08 | R | Runtime state word saved to a local at entry |
| 00fb83d4 | dword_FB83D4 | R | Global buffer holding the default-language name string; its leading-letter run is measured |
| 00fb83d8 | dword_FB83D8 | R | Function pointer to the locale-info retrieval routine, used to fetch language ID 1 for the candidate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006349bb | sub_6349BB | unknown — no call visible in the decompiled body |
| 006354d0 | sub_6354D0 | Computes the length of the dword_FB83D4 string, used as the comparison baseline for the primary-name length |
| 0063a7d7 | ByteBufferSwap [structural] | Converts the fetched language-identifier string into an LCID value (invoked in the decompiled body as the hex-string→LCID call whose result is compared with a1) |
| 0063a80c | _GetPrimaryLen | Counts the leading ASCII letters of the dword_FB83D4 string |

**Guard conditions:** First, the locale-info getter is called with `a1 & 0x3FF | 0x400` and info ID 1 into a 120-byte stack buffer; if it fails, the function returns 0. If the converted language ID equals `a1` → return 1. If `a2 == 0` → return 1 (flag suppresses the deeper check). Otherwise, if `GetPrimaryLen(dword_FB83D4) != sub_6354D0(dword_FB83D4)` → return 1. Falling through all checks returns the initial 0.
