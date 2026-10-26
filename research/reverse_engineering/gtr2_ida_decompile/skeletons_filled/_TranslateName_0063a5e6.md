## _TranslateName_0063a5e6 — Binary-search name translator (locale name table lookup)

**Summary:** Locale helper that binary-searches a sorted table of name/value pairs (8 bytes per entry) for a case-insensitive match of the input name; on a hit it rewrites the caller's pointer to the value slot and reports success.

**Called by:** ___get_qualified_locale (0063ad25)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631c0d | __stricmp | Case-insensitive comparison of the requested name against the table entry's name string |

**Guard conditions:** Binary search over indices v3..a2: while `v3 <= a2` and the last comparison was nonzero, middle index `v5 = (v3 + a2) / 2`, entry at `a1 + 8*v5`. If _stricmp == 0 (match) → `*a3` is rewritten to point at the entry's second dword (the value) and the loop’s comparison flag stays 0, ending the search. If the comparison is > 0 → search the upper half (v3 = v5+1); if < 0 → lower half (a2 = v5-1). Returns TRUE only when a match ended the loop (`v4 == 0`), FALSE otherwise.
