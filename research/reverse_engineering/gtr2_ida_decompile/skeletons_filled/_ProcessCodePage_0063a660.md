## _ProcessCodePage_0063a660 — Code page spec parser (ACP/OCP/numeric)

**Summary:** Locale helper that resolves a code-page specification string to a numeric code page: recognizes the "ACP" and "OCP" markers (resolving them through the locale-info getter) and otherwise parses the string directly as a number.

**Called by:** ___get_qualified_locale (0063ad25)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First character of the input spec string; tested for non-NUL before any comparison |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731ccc | off_731CCC | R | "OCP" string literal compared against the input to select the OEM code page lookup (info ID 11) |
| 00731cd0 | off_731CD0 | R | "ACP" string literal compared against the input to select the ANSI code page lookup (info ID 4100) |
| 00912b08 | dword_912B08 | R | Runtime state word saved to a local at entry |
| 00fb83c0 | dword_FB83C0 | R | Locale handle/identifier passed as the first argument to the locale-info getter |
| 00fb83d8 | dword_FB83D8 | R | Function pointer to the locale-info retrieval routine, invoked as (locale, info ID, buffer, size) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631a35 | _atol | Parses the numeric code page from either the raw input string or the fetched locale-info text buffer |
| 006349bb | sub_6349BB | unknown — no call visible in the decompiled body |
| 00636cf0 | _strcmp | Compares the input against the "ACP" and "OCP" literals |

**Guard conditions:** If `Str1 == NULL`, `*Str1 == 0`, or `strcmp(Str1, "ACP") == 0` → uses the fetched-locale path with info ID 4100 (ANSI code page). Otherwise, if `strcmp(Str1, "OCP") != 0` → returns `atol(Str1)` directly (numeric input). If it equals "OCP" → fetches info ID 11 (OEM code page). After either fetch, a zero getter result returns 0; a nonzero result is parsed with atol on the fetched 8-byte buffer.

**String literals referenced (deterministic):**

- `OCP`
- `ACP`
