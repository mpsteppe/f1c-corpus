## ___ascii_stricmp_00638550 — ASCII case-insensitive string compare

**Summary:** C runtime ASCII-only case-insensitive string comparison: walks both strings byte by byte, folds 'A'–'Z' to lowercase, and returns a sign result; used as the non-locale backend of __stricmp.

**Called by:** __stricmp (00631c0d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop condition: continue while the last-read a2 byte (stored in the low byte of result) is nonzero. If the two bytes are equal → continue to next pair (reaching a NUL on both returns 0). If they differ → each byte is lowercased by testing `(c - 65) < 26` and adding 0x20 for uppercase A–Z; if still different → returns -1 when the lowercased a1 char is less than the lowercased a2 char, otherwise +1. No locale table is consulted — pure ASCII folding.
