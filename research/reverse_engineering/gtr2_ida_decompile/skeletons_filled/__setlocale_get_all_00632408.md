## __setlocale_get_all_00632408 — CRT _setlocale_get_all

**Summary:** MSVC CRT `_setlocale_get_all`: builds (and caches in a heap buffer) the combined locale string for all categories, then — if every category still matches the default — frees the buffer and returns the static default string instead. Called by `setlocale(LC_ALL, NULL)`.

**Called by:** __setlocale_lk (006328b2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f30ac | asc_6F30AC | R | String constant consumed during the category-string assembly (argument to the _strcats/strcat construction) |
| 00721098 | Source | R | String data used as a source string in the assembly of the all-categories locale string |
| 00912a4c | dword_912A4C | RW | Cached heap pointer (0x351 bytes) holding the combined locale string; set on malloc, cleared after free when the default result is returned |
| 00912a54 | off_912A54 | R | Locale category string table entry (start of the per-category string data walked by the loop) |
| 00912a58 | off_912A58 | R | First walk pointer of the category-string triple array; loop advances by 3 entries per iteration |
| 00912a64 | off_912A64 | R | Returned when all categories are equal — the static default locale string |
| 00912a88 | off_912A88 | R | End sentinel of the category-string table; loop runs while the walk pointer is below it |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063227f | __strcats | Concatenates the (hidden) variadic category strings onto the output buffer |
| 00634919 | _free | Releases the cached buffer when the default result path is taken |
| 00634c1d | _malloc | Allocates the 0x351-byte cache buffer on first use |
| 00636a80 | _strcat | Appends the `;` separator between category groups |
| 00636cf0 | _strcmp | Compares the current category entry with the previous one to detect any non-default category |

**Guard conditions:** `if (dword_912A4C || (result = malloc(0x351)) != 0)` — uses the cached buffer if present; otherwise mallocs; malloc failure returns 0 (outer return). Loop walks entries by 3 pointers from off_912A58 while `< &off_912A88`, appending `;` then the group; any `strcmp(*v3, *v2) != 0` sets v1 = 0. `if (v1)` — all categories matched: free the buffer, clear dword_912A4C, return the static off_912A64. Otherwise return the freshly built cached buffer.
