## __setlocale_lk_006328b2 — CRT _setlocale_lk

**Summary:** MSVC CRT internal `_setlocale_lk`: the locked core of `setlocale`. Either queries current locale data (category name or the combined all-category string) or applies a new locale — a single name to all categories, or a semicolon-separated `category=value` list when the string starts with "LC_". Returns the resulting locale string (or 0 on failure).

**Called by:** _setlocale (00632a8b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First char of Str2; must be 'L' (76) for the LC_ category-list form |
| this | 0x1 | R | — | Second char of Str2; must be 'C' (67) for the LC_ form |
| this | 0x2 | R | — | Third char of Str2; must be '_' (95) for the LC_ form |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00721098 | Source | R | String data consumed by the parsing calls (separator literals such as "=;" / ";" used with the string-scan helpers) |
| 0073047c | asc_73047C | R | String constant referenced during locale processing (text data adjacent to the parsing constants) |
| 00912a4c | dword_912A4C | RW | Base of the locale-category descriptor array (3-dword stride, category names) and cached combined-string slot; freed and zeroed when all categories are applied |
| 00912a54 | off_912A54 | R | First category descriptor entry; the search loop walks entries by 3 dwords |
| 00912a84 | off_912A84 | R | Last category descriptor bound for the LC_ name-search loop (break when walk exceeds it) |
| 00912a88 | off_912A88 | R | End bound for the apply-all loop (`v15 <= &off_912A88`) |
| 00912b08 | dword_912B08 | R | Global state word saved at entry (v21) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | Bounded copy of a category value into the local Str1[132] buffer |
| 00631d10 | _strncmp | Compares the parsed category token with each table category name |
| 00632408 | __setlocale_get_all | Returns/builds the combined all-categories locale string |
| 006324c7 | __expandlocale | Normalizes a single locale name into the local Str1 buffer |
| 00632623 | sub_632623 | Per-category setter/validator: applies the value (or the expanded name) for one category and reports success |
| 00634919 | _free | Releases the cached string slot dword_912A4C in the all-applied path |
| 006349bb | sub_6349BB | unknown — no direct call visible in this decompiled body |
| 006354d0 | sub_6354D0 | String length measure used to require an exact category-name match together with strncmp |
| 00636cf0 | _strcmp | Compares the expanded name with each category descriptor string |
| 0063a5a0 | _strcspn | Finds the next ';' in the value portion of a category entry |
| 0063b160 | InPlaceStringShift [structural] | String scan helper invoked in the LC_ parsing path (locates the '=' / ';' separators in the body) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 76 | First char 'L' — selects the LC_ category-list parsing path |
| this | 0x1 | == | 67 | Second char 'C' — part of the LC_ prefix |
| this | 0x2 | == | 95 | Third char '_' — part of the LC_ prefix |

**Guard interpretation:** With `a2 == 0` (LC_ALL) and a name that begins "LC_" (rows all true), the string is parsed as `category=value` pairs: a missing '=' / ';' separator, an empty category name, an immediate ';', or an empty value (when not ';') returns 0; entries whose category index ≤ 5 are copied into Str1 and applied via sub_632623 (counted in v19). If none applied (`v19 == 0`) returns 0, else returns `_setlocale_get_all()`. For any other name: `__expandlocale` failure returns 0; the expanded name is applied to every table category; if any category fails, v17 = 0 and either the partial apply is reported or 0 is returned; an all-categories success frees dword_912A4C, zeroes it and returns `_setlocale_get_all()`. With `a2 == 0` and `Str2 == 0` the query path returns `_setlocale_get_all()`. With `a2 != 0`: a non-null name returns `sub_632623()` (set that category), null returns `(&dword_912A4C)[3 * a2]` (query that category's name).
