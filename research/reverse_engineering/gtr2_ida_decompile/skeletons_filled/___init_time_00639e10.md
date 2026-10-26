## ___init_time_00639e10 — Time-locale structure initializer

**Summary:** CRT startup locale routine that allocates and fills the global time-locale structure when a time locale is active, falling back to pointing at a static default block otherwise.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00913090 | off_913090 | W | Global pointer to the active time-locale structure; set to the allocated block or to &off_913098 on the default path |
| 00913098 | off_913098 | R | Address of the static default time-locale block; its address is taken (`&off_913098`) as the fallback pointer |
| 00fb83b0 | dword_FB83B0 | W | Secondary global mirroring the active pointer (same block address, or 0 on the default path) |
| 00fb83f0 | dword_FB83F0 | R | Flag checked before allocating: nonzero means a time locale is configured and the dynamic structure is built |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases the allocated locale block after a failed fill |
| 006353f3 | _calloc | Allocates the zero-initialized 0xB8-byte (184) time-locale structure |
| 00639919 | __get_lc_time | Fills the allocated structure with localized time strings; nonzero return means failure |
| 00639c80 | __free_lc_time | Releases the string members already loaded into the structure when the fill fails partway |

**Guard conditions:** If `dword_FB83F0 == 0` → takes the default path: clears dword_FB83B0, sets off_913090 to &off_913098, returns 0. Otherwise allocates via calloc; if allocation returns NULL → returns 1 (failure). If _get_lc_time returns nonzero → runs __free_lc_time + _free and returns 1. Only when the fill succeeds are off_913090/dword_FB83B0 updated and 0 returned.
