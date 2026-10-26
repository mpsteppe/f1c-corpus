## sub_4E4DD0_004e4dd0 — Simple getter for a dword field in the dword_91E07C block

**Summary:** Returns the dword at index 4330 of the data block based at dword_91E07C — a trivial accessor with no parameters or side effects.

**Called by:** sub_564A10 (00564a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091e07c | dword_91E07C | R | base pointer of the data block; the returned dword is read at index 4330 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional read of the field at index 4330; the value is returned as-is.
