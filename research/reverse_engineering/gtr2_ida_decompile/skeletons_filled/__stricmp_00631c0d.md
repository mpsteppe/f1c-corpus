## __stricmp_00631c0d — CRT _stricmp (case-insensitive compare)

**Summary:** ANSI CRT `_stricmp`: compares two NUL-terminated strings case-insensitively. Uses a fast ASCII-only comparison when the thread's locale has no collation table; otherwise lowercases each character through the locale's case-mapping routine before comparing.

**Called by:** sub_405CA0 (00405ca0), sub_405E20 (00405e20), sub_4076B0 (004076b0), QuickRace [structural] (00409a90), sub_409D90 (00409d90), sub_40BBA0 (0040bba0), sub_40CB90 (0040cb90), sub_40E950 (0040e950), FilePathListSearch [structural] (0040f2e0), sub_4103C0 (004103c0), sub_41D8B0 (0041d8b0), sub_41D920 (0041d920) … +96 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091290c | off_91290C | R | Sentinel/default locale-info pointer compared with the thread's cached tlocinfo; mismatch triggers `__updatetlocinfo` refresh |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006323cd | ___updatetlocinfo | Refreshes the thread's locale information block when the cached pointer differs from the default sentinel |
| 00636698 | __getptd | Returns per-thread data; offset +100 holds the cached locale-info pointer |
| 00638550 | ___ascii_stricmp | Fast ASCII-only case-insensitive compare used when the locale has no collation table |

**Guard conditions:** `if (!v2[5]) return __ascii_stricmp(...)` — when the locale-info has no case-mapping/collation table installed (field index 5 == 0), the ASCII fast path handles everything. Otherwise the loop lowercases each character through the locale case-mapping helper (code pointer at loc_63508D) and continues `while (v7 && v7 == v6)` — i.e., stops at the NUL of the first string or at the first differing mapped character. Returns `v7 - v6` (difference of the last mapped characters).
