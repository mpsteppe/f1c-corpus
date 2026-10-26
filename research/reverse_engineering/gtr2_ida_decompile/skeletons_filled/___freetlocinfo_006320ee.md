## ___freetlocinfo_006320ee — CRT __freetlocinfo

**Summary:** MSVC CRT locale destructor `__freetlocinfo`: releases a thread's locale-info block — freeing the owned locale tables (collate, numeric, monetary, time, and associated lconv data) and finally the block itself. Shared static "C"-locale tables and nonzero-refcount tables are skipped, then the main block is freed unconditionally.

**Called by:** ___updatetlocinfo_lk (006321be), _setlocale (00632a8b), __freefls@4 (00636709)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2C) | 0x0 | R | — | Refcount (first dword) of the table pointed to by Block+0x2C (collate table); must be 0 to free |
| *(this+0x30) | 0x0 | R | — | Refcount (first dword) of the table at Block+0x30 (numeric table); must be 0 to free |
| *(this+0x34) | 0x0 | R | — | Refcount (first dword) of the table at Block+0x34 (monetary table); must be 0 to free |
| *(this+0x40) | 0x0 | R | — | Refcount (first dword) of the block at Block+0x40; must be 0 to free |
| *(this+0x50) | 0xB4 | R | — | Refcount word at +0xB4 of the lc_time table at Block+0x50; must be 0 to free the time table |
| this | 0x2C | R | — | Pointer to the collate table sub-allocation (freed) |
| this | 0x30 | R | — | Pointer to the numeric-conventions table sub-allocation (freed) |
| this | 0x34 | R | — | Pointer to the monetary-conventions table sub-allocation (freed) |
| this | 0x3C | R | — | Pointer compared against the static default (dword_FB83B4) before the monetary/numeric sub-frees |
| this | 0x40 | R | — | Pointer to a table freed together with its companion (guarded against dword_FBB5EC) |
| this | 0x44 | R | — | Pointer into a combined allocation; 254 is subtracted to recover the allocation base that gets freed |
| this | 0x50 | R | — | Pointer to the lc_time table; freed via `_free_lc_time` when its +0xB4 refcount is 0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb83b0 | dword_FB83B0 | R | Static default lc_time table sentinel; matching pointer at Block+0x50 is not freed |
| 00fb83b4 | dword_FB83B4 | R | Static default sentinel compared against Block+0x3C; match skips the monetary/numeric sub-frees |
| 00fbb5ec | dword_FBB5EC | R | Static default sentinel for the Block+0x40 table; match skips that free |
| 00fbb5f0 | dword_FBB5F0 | R | Static default monetary table sentinel for Block+0x34; match skips the free |
| 00fbb5f8 | dword_FBB5F8 | R | Static default numeric table sentinel for Block+0x30; match skips the free |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | CRT heap free for the individual locale tables and the final block |
| 00639c80 | __free_lc_time | Releases sub-allocations owned by the lc_time table |
| 00639e6f | ___free_lconv_num | Releases the numeric-conventions (lconv) sub-allocation |
| 0063a09b | ___free_lconv_mon | Releases the monetary-conventions (lconv) sub-allocation |

**Guard conditions:** Group 1 runs only if `Block[15] != dword_FB83B4 && Block[15] && !**(Block+0x2C)` (not the static default, non-null, collate refcount zero). Inside: Block+0x34 table (v2, monetary) freed only if `v2 && !*v2 && v2 != dword_FBB5F0` (then also `__free_lconv_mon`); Block+0x30 table (v3, numeric) only if `v3 && !*v3 && v3 != dword_FBB5F8` (then `__free_lconv_num`); then Block[11] (0x2C) and Block[15] (0x3C) are freed. Group 2: Block+0x40 freed only if `v4 != dword_FBB5EC && v4 && !*v4`, additionally freeing `Block[17] - 254`. Group 3: Block+0x50 freed only if `v5 != dword_FB83B0 && v5 && *(v5+0xB4) == 0` (frees lc_time sub-block then the table). `free(Block)` runs unconditionally.
