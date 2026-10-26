## StringHashTokenParsing_004236f0 — ParseQuotedTokens

**Summary:** Parses quoted tokens from input string: removes delimiter characters, splits at period separator, extracts two quoted substrings into output buffers a2 and a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_423890 (00423890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First character of input string (checked for quote char 0x22) |
| this | 0x1 | R | — | Second character of input string (quote content start) |
| this | 0x2 | R | — | Third character of input string (quote content continuation) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30ac | asc_5C30AC | R | StrDelimiter_Period [DERIVED] (also: ` — first lookup key string or identifier) |
| 005c30b0 | asc_5C30B0 | R | StringDelimiter_CStr [DERIVED] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c30b8 | unk_5C30B8 | R | QuoteDelimiter [DERIVED] (also: /b4/b0/ac` — delimiter/separator character constants) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c20 | sub_587C20 | Find character position in string (strchr equivalent) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 34 | First char of a1 is '"' (ASCII 34) |

**Guard interpretation:** a1 == NULL: return -1 (blocked). strlen(a1) == 0 after nullifying delimiters: return -1 (blocked). sub_587C20(a1, asc_5C30AC) returns NULL (period separator not found): skip parsing entirely, return 0. First char of a1 is 34 ('"'): parse content directly following quote (skip leading-char scan). When leading char is not quote: scan forward until quote found, then parse content.
