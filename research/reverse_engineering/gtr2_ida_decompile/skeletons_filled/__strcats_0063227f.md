## __strcats_0063227f — CRT _strcats

**Summary:** MSVC CRT `_strcats`: concatenates a count-prefixed list of strings onto a destination with repeated `strcat` calls. Used by the locale-string assembly helpers.

**Called by:** ___lc_lctostr (0063237f), __setlocale_get_all (00632408)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00636a80 | _strcat | Appends one source string per iteration onto Destination |

**Guard conditions:** `if (a2 > 0)` — when the string count passed in a2 is zero or negative the loop body never runs (no concatenation); with a positive count the loop runs exactly a2 times (`do { strcat(...); --v2; } while (v2)`), consuming successive variadic argument slots. Returns the result of the last strcat.
