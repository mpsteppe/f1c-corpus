## ___free_lconv_mon_0063a09b — Monetary lconv string releaser

**Summary:** CRT locale cleanup helper that frees the seven monetary-format string pointers held by a lconv structure (offsets 0xC–0x24), skipping any that still point at the built-in default locale strings.

**Called by:** ___freetlocinfo (006320ee), ___init_monetary (0063a174)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Monetary string pointer 1 (structure slot 3); freed unless it is a default |
| this | 0x10 | R | — | Monetary string pointer 2 (slot 4); freed unless it is a default |
| this | 0x14 | R | — | Monetary string pointer 3 (slot 5); freed unless it is a default |
| this | 0x18 | R | — | Monetary string pointer 4 (slot 6); freed unless it is a default |
| this | 0x1C | R | — | Monetary string pointer 5 (slot 7); freed unless it is a default |
| this | 0x20 | R | — | Monetary string pointer 6 (slot 8); freed unless it is a default |
| this | 0x24 | R | — | Monetary string pointer 7 (slot 9); freed unless it is a default |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00913168 | off_913168 | R | Default monetary string compared against slot 3 |
| 0091316c | off_91316C | R | Default monetary string compared against slot 4 |
| 00913170 | off_913170 | R | Default monetary string compared against slot 5 |
| 00913174 | off_913174 | R | Default monetary string compared against slot 6 |
| 00913178 | off_913178 | R | Default monetary string compared against slot 7 |
| 0091317c | off_91317C | R | Default monetary string compared against slot 8 |
| 00913180 | off_913180 | R | Default monetary string compared against slot 9 |
| 0091318c | off_91318C | R | Pointer to the default locale string array; its [3]..[9] elements are the first no-free comparison for slots 3–9 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases a monetary string pointer when it is not one of the default strings |

**Guard conditions:** If `a1 == 0` → returns immediately (NULL structure). For each of the seven pointers at offsets 0xC–0x24: it is freed only when it differs from both the matching default-array element (off_91318C[3..9]) and the matching static default string (off_913168..913180). Pointers equal to a default are left alone, preventing frees of shared static data.
