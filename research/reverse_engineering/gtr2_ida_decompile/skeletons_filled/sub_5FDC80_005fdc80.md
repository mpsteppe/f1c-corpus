## sub_5FDC80_005fdc80 — Create and initialize object (factory, two init paths)

**Summary:** Allocates a 0x80-byte object, constructs it with sub_5FC6D0, then initializes it either through sub_5FD1C0 (when flag bit 3 of *a3 is set) or sub_5FD5E0; on success finalizes via sub_5FDFB0 and returns 0 with the object in *a2, on failure frees the object and returns -1.

**Called by:** sub_547DC0 (00547dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ecd8b | SEH_5FDC80 | R | SEH scope table for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | no-op placeholder (MSVC EH/debug hook stub) invoked before freeing object |
| 005fc6d0 | sub_5FC6D0 | constructor for freshly allocated 0x80-byte object |
| 005fd1c0 | sub_5FD1C0 | initialization path taken when *a3 bit 3 set; returns 0 on success |
| 005fd5e0 | sub_5FD5E0 | default initialization path; returns 0 on success |
| 005fdfb0 | sub_5FDFB0 | post-init finalize/activate step for created object; called with flag 1 |
| 00630739 | ??2@YAPAXI@Z | operator new(size) — allocates 0x80 bytes |
| 006308d3 | j__free | operator delete — frees object on failure path |

**Guard conditions:** After construction, if `(*a3 & 8) != 0` the object is initialized via sub_5FD1C0, otherwise via sub_5FD5E0. A return value of 0 from the chosen initializer PASSES: sub_5FDFB0(v6, 1) runs, *a2 receives the object, function returns 0. A nonzero (failure) return DISCARDS the object: nullsub_7 + j__free run, *a2 is set to 0, function returns -1. If operator new fails (v6 = 0), both initializer calls fail and the discard path is taken.
