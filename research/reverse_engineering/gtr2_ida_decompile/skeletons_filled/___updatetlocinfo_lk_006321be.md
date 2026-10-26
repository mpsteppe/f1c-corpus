## ___updatetlocinfo_lk_006321be — CRT __updatetlocinfo_lk

**Summary:** MSVC CRT locale refcount helper `__updatetlocinfo_lk`: releases the thread's current locale-info block (decrementing per-table refcounts), switches the thread to the default locale block (off_91290C, incrementing its refcounts), and frees the old block if its refcount hits zero. Returns the now-active locale-info pointer.

**Called by:** ___updatetlocinfo (006323cd), _setlocale (00632a8b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009128b8 | unk_9128B8 | R | Static default locale-info block; if the old block equals it, it is never freed |
| 0091290c | off_91290C | R | Default locale-info block pointer restored into the thread slot (ptd+100); its refcount and sub-table refcounts are incremented |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006320ee | ___freetlocinfo | Frees the old locale-info block and its owned tables once its refcount reaches zero |
| 00636698 | __getptd | Returns the per-thread data block; offset +100 holds the cached locale-info pointer |

**Guard conditions:** Outer `if (v1 != off_91290C)` — nothing happens when the thread already points at the default block (returns it). When a previous distinct block exists: its own refcount, and the refcounts of its sub-tables at indices 11, 13, 12, 16 and at `[19]+180`, are decremented only where the pointers are nonzero. Then the slot is set to the default block and the default's refcount and its nonzero sub-tables (indices 11, 13, 12, 16, `[19][45]`) are incremented. Finally `if (v1 && !*v1 && v1 != &unk_9128B8)` frees the old block — i.e., only when it is not the static default and its refcount reached 0; otherwise it survives.
