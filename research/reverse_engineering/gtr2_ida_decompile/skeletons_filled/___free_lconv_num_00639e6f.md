## ___free_lconv_num_00639e6f — Numeric lconv string releaser

**Summary:** CRT locale cleanup helper that frees the three string pointers held by a numeric lconv-style structure, skipping any pointer that still references the built-in default locale strings.

**Called by:** ___freetlocinfo (006320ee), ___init_numeric (00639ece)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First string pointer of the structure (e.g., decimal-point string); freed unless it is a default |
| this | 0x4 | R | — | Second string pointer (e.g., thousands-separator string); freed unless it is a default |
| this | 0x8 | R | — | Third string pointer (e.g., grouping string); freed unless it is a default |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091315c | off_91315C | R | Default-locale string compared against field 0; a match means the pointer is static and must not be freed |
| 00913160 | off_913160 | R | Default-locale string compared against field 1 |
| 00913164 | off_913164 | R | Default-locale string compared against field 2 |
| 0091318c | off_91318C | R | Pointer to the default locale string array; its [0]/[1]/[2] elements are the second set of no-free comparisons for fields 0, 1, 2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases a structure string pointer when it is not one of the default locale strings |

**Guard conditions:** If `a1 == 0` → returns immediately (NULL structure, nothing to do). For each of the three pointers: it is freed only when it differs from both the corresponding default-array element (off_91318C[0..2]) and the corresponding static default string (off_91315C/913160/913164). Pointers equal to any default are left untouched — no double-free of shared static data.
