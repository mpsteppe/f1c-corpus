## _GetPrimaryLen_0063a80c — Leading-letter-run length counter

**Summary:** String helper that returns the number of leading ASCII letters (A–Z, a–z) in a language-name string, stopping at the first non-letter or NUL; used by the locale language-matching helpers to split primary language names.

**Called by:** _TestDefaultLanguage (0063a8bd), _GetLcidFromLangCountry (0063ac4a), _GetLcidFromLanguage (0063acd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop increments the count for each character that is an ASCII letter; it breaks — returning the count so far — at the first character with `c < 65 || c > 90` and `c < 97 || c > 122` (i.e., outside 'A'–'Z' and 'a'–'z'), which includes the terminating NUL. No other value is tested.
