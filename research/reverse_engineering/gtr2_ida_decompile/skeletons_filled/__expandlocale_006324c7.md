## __expandlocale_006324c7 — CRT _expandlocale

**Summary:** MSVC CRT `_expandlocale`: normalizes a locale name — validates it, resolves it to a canonical form (`__lc_strtolc` + `__get_qualified_locale` + `__lc_lctostr`), and returns the canonical string while also emitting machine-readable locale data to two optional out-parameters. Short-circuits the special name "C" without any lookup.

**Called by:** __setlocale_lk (006328b2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First character of the input locale name Str2; checked against 'C' (67) |
| this | 0x1 | R | — | Second character of Str2; must be NUL for the bare-"C" fast path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback locale name used when the input is empty or ≥ 0x82 (130) chars long |
| 00912938 | aC_7 | R | Global canonical-locale-name buffer (130-char copy target, also compared against Str2) |
| 009129ba | byte_9129BA | W | NUL terminator byte written after the 130-char copy into aC_7 |
| 009129c0 | Str1 | R | Global buffer holding the resolved canonical locale name (compared, strcpy'd to Destination) |
| 00912b08 | dword_912B08 | R | Global state word saved at entry (v7); not otherwise consumed in this body |
| 00fb8184 | unk_FB8184 | R | 6 bytes of machine-readable locale data copied out to a3 |
| 00fb8188 | word_FB8188 | R | Word whose low 16 bits initialize dword_FB818C |
| 00fb818c | dword_FB818C | RW | Locale data dword: assigned the low word of word_FB8188, then copied out to a4 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | Bounded string copy (130 chars) of the chosen name into the aC_7 canonical buffer |
| 006322a3 | ___lc_strtolc | Parses the input name into language/country/codepage fields in the local Source buffer |
| 0063237f | ___lc_lctostr | Converts the parsed/qualified components back into the canonical string in Str1 |
| 006349bb | sub_6349BB | unknown — no direct call visible in this decompiled body |
| 006354d0 | sub_6354D0 | Measures the input name; a result ≥ 0x82 (130) rejects/reroutes the name and forces the fallback |
| 00635560 | _memcpy_0 | Copies 6 bytes of locale data to a3 and 4 bytes to a4 |
| 00636a70 | _strcpy | Copies the canonical Str1 into the caller's Destination buffer |
| 00636cf0 | _strcmp | Compares Str1 and aC_7 against the input name to detect an already-known locale |
| 0063ad25 | ___get_qualified_locale | Resolves the parsed components to qualified locale info (fills the unk_FB8184 area) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 67 | First char of the input name; not 'C' forces the full expansion path (row G1) |

**Guard interpretation:** `!Str2` returns 0 immediately (null input blocked). If `*Str2 == 'C' (67)` AND `Str2[1] == 0` — the bare "C" case — the fast path writes Destination[0] = 'C', Destination[1] = 0, zeroes the 6-byte a3 block and *a4, and returns. Otherwise (row G1: first char != 67, or second char nonzero) the name is processed: `sub_6354D0(Str2) >= 0x82` OR differing from both cached names (Str1 and aC_7) triggers full resolution — parse failure (`__lc_strtolc` nonzero) or `__get_qualified_locale` failure returns 0; on success the cache globals are refreshed. Outputs a3/a4 are optional (checked for null). Final `strcpy` fills Destination and Str1 is returned.
