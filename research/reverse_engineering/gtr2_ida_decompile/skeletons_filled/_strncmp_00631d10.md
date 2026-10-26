## _strncmp_00631d10 — CRT strncmp

**Summary:** ANSI CRT `strncmp`: compares at most MaxCount bytes of two strings, as unsigned chars. First determines the effective length (bounded by the first NUL in Str1), then compares byte by byte. Returns <0, 0, or >0.

**Called by:** sub_4188D0 (004188d0), sub_4F8120 (004f8120), sub_520820 (00520820), CriticalSectionLazyInitEnter [structural] (005246e0), sub_529530 (00529530), sub_529E10 (00529e10), sub_52A620 (0052a620), sub_549500 (00549500), sub_58CD60 (0058cd60), sub_5A1300 (005a1300), sub_5DECD0 (005decd0), sub_615FE0 (00615fe0) … +2 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `if (MaxCount)`: with MaxCount == 0 the function returns 0 without examining either string. Bytes directly visible in the loops: first scan stops at MaxCount or at the first NUL of Str1 (`*v4++ == 0`), yielding the effective compare count `MaxCount - v3`. Second scan compares Str2 against Str1 byte by byte while equal and count remains. Final classification on unsigned bytes: if Str2's byte > Str1's byte return ~0 (-1); if unequal the other way return ~(-2) (1); if all compared bytes equal return 0.
