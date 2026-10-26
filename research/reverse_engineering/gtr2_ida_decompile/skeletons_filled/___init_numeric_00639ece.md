## ___init_numeric_00639ece — Numeric locale (lconv) initializer

**Summary:** CRT startup routine that builds and installs the active numeric locale structure: allocates a 0x30-byte lconv copy plus companion blocks, loads localized decimal/thousands/grouping strings, normalizes the grouping string, and refreshes the cached decimal-point character.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091290c | off_91290C | R | Points to a context block whose element [11] is the default numeric lconv pointer; used to avoid freeing the built-in locale blocks |
| 0091315c | off_91315C | R | Default string 1 installed instead of a loaded string when only the partial locale flag is set |
| 00913160 | off_913160 | R | Default string 2 for the partial path |
| 00913164 | off_913164 | R | Default string 3 for the partial path |
| 0091318c | off_91318C | RW | Active numeric lconv pointer: read as the 0x30-byte template copied into the new structure, later overwritten with the new (or default) structure |
| 009131a4 | byte_9131A4 | W | Cached first byte of the active lconv's first string (the decimal-point character) |
| 009131a8 | dword_9131A8 | W | Set to 1 to mark numeric locale initialization complete |
| 00fb83b4 | dword_FB83B4 | RW | Global pointer to the allocated 0x30-byte structure (or 0 on the default path); stale copies are freed before reassignment |
| 00fb83e8 | dword_FB83E8 | R | Locale-active flag; either this or dword_FB83EC selects the dynamic build path |
| 00fb83ec | dword_FB83EC | R | Locale-active flag; when zero (with dword_FB83E8 set) only the default strings are installed |
| 00fb841a | word_FB841A | R | Locale identifier passed to the string loader for IDs 14/15/16 |
| 00fbb5f4 | dword_FBB5F4 | RW | Pointer to the 4-byte companion block associated with the structure; stale block freed, then set to the new block (or 0) |
| 00fbb5f8 | dword_FBB5F8 | W | Second 4-byte companion block pointer; zeroed on the default path, set to the block allocated on the load path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases stale companion blocks/structures and cleanup on failure paths |
| 00634c1d | _malloc | Allocates the 4-byte companion blocks (and the second one on the load path) |
| 006353f3 | _calloc | Allocates the zero-initialized 0x30-byte numeric lconv structure |
| 00639e6f | ___free_lconv_num | Frees the three string members of the structure when the string loader fails |
| 006422f4 | sub_6422F4 | Locale string loader invoked for string IDs 14, 15, 16; nonzero returns signal failure |

**Guard conditions:** Entry: if `dword_FB83EC || dword_FB83E8` → dynamic path, else default path. Dynamic path: calloc failure → return 1; first malloc failure → free structure, return 1; if `!dword_FB83EC` → install the three static default strings and skip loading; otherwise second malloc failure → free both, return 1; any loader return nonzero → __free_lconv_num + frees, return -1. Grouping-string normalization scans v0[2]: '0'–'9' are replaced by value−48 (48 ≤ c ≤ 57), ';' characters are deleted by left-shifting the tail, NUL ends the scan. Stale-block cleanup condition on both paths: `old != 0 && *(int*)old == 0 && old != ((void**)off_91290C)[11]`. Final: off_91318C = v0, byte_9131A4 = first byte of the first string, dword_9131A8 = 1, return 0.
