## ___lc_strtolc_006322a3 — CRT __lc_strtolc (locale string parser)

**Summary:** MSVC CRT helper `__lc_strtolc`: parses a locale name string of the form `language_country.codepage` (separators `_`, `.`, `,`) into a 0x90-byte structure — language at +0, country at +64, codepage at +128. Returns 0 on success, -1 on malformed input.

**Called by:** __expandlocale (006324c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8F | RW | 0 | Byte at end of the codepage field (128+15); written as NUL after copying a bare ".xxx" codepage suffix (the memset already zeroes it in other paths) |

**Written-by note (persistence):**
- this 0x8F: written only in the early `.<codepage>` branch after the 15-char copy; otherwise covered by the initial memset of the whole struct. Rewritten on every parse call, so an external poke would not survive the next parse.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00730468 | Control | R | unknown — not directly referenced in this body; only appears via the called helpers |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | Bounded string copy used to fill the language/country/codepage fields (lengths 63/63/15) |
| 00635180 | _memset | Zeroes the 0x90-byte destination structure before parsing |
| 0063a5a0 | _strcspn | Scans for the next separator character from the set `_.,` to delimit the current token |

**Guard conditions:** `if (!*Str) return 0` — empty locale string yields the zeroed struct (success). `if (*Str == 46 ('.') && Str[1])` — leading-dot form: copies the codepage suffix to +128 and NULs byte 0x8F, returns 0. Main loop: `strcspn` result `v7` must be nonzero or return -1 (empty token). First token (Stra==0): reject if `v7 >= 0x40` or terminator is '.' (46), else copy into +0. Second (Stra==1): reject if `v7 >= 0x40` or terminator is '_' (95), else copy into +64. Third (Stra==2): reject if `v7 >= 0x10` or terminator is a char other than ',' (44), else copy into +128; any further token also returns -1. Loop ends when the terminator is ',' or NUL; otherwise it advances past the separator and parses again.

**String literals referenced (deterministic):**

- `_.,`
