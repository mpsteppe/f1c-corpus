## ___init_monetary_0063a174 — Monetary locale (lconv) initializer

**Summary:** CRT startup routine that builds and installs the active monetary locale structure: allocates a 0x30-byte lconv plus companion blocks, loads localized currency strings (IDs 20–26, 80–87), normalizes the grouping string, and refreshes the shared numeric string slots.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091315c | off_91315C | R | Default 0x30-byte locale block; copied into the new structure on the partial path, and installed directly as off_91318C when no locale is active |
| 0091318c | off_91318C | RW | Active lconv pointer: its first three dwords are copied into the new structure's numeric slots on the partial path; later overwritten with the new (or default) structure |
| 00fb83b4 | dword_FB83B4 | W | Set to the new structure pointer on the dynamic path, else 0 |
| 00fb83e8 | dword_FB83E8 | R | Full monetary-locale flag; when zero (partial path) the default block is copied and no strings are loaded |
| 00fb83ec | dword_FB83EC | R | Monetary-locale flag; either this or dword_FB83E8 selects the dynamic build path |
| 00fb8414 | word_FB8414 | R | Locale identifier passed to the string loader |
| 00fbb5f0 | dword_FBB5F0 | W | Companion block pointer: allocated on the load path, zeroed on the partial/default paths |
| 00fbb5f4 | dword_FBB5F4 | W | Companion block pointer set to the first 4-byte block (Block) on the dynamic path (0 on the fully-default path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases structures/blocks on failure paths |
| 00634c1d | _malloc | Allocates the 4-byte companion blocks |
| 006353f3 | _calloc | Allocates the zero-initialized 0x30-byte monetary lconv structure |
| 0063a09b | ___free_lconv_mon | Frees the loaded monetary string members when the string load fails |
| 006422f4 | sub_6422F4 | Locale string loader invoked for string IDs 21/20/22/23/24/80/81 (mode 1) and 26/25/84/85/86/87/82/83 (mode 0); nonzero returns signal failure |

**Guard conditions:** Entry: if `dword_FB83E8 || dword_FB83EC` → dynamic path, else default path (clear dword_FBB5F0, dword_FBB5F4, dword_FB83B4; off_91318C = &off_91315C; return 0). Dynamic path: calloc failure → return 1; first malloc failure → free structure, return 1; if `!dword_FB83E8` → copy 30 bytes from &off_91315C, clear dword_FBB5F0, then splice the old off_91318C[0..2] strings into slots 0–2 and install. Otherwise second malloc failure → free both, return 1; any string-loader return nonzero → ___free_lconv_mon + frees, return 1. Grouping-string normalization on slot 7: '0'–'9' replaced by value−48, ';' deleted by left-shift, NUL terminates. Success installs off_91318C = v0, dword_FBB5F4 = Block, dword_FB83B4 = v0, return 0.
