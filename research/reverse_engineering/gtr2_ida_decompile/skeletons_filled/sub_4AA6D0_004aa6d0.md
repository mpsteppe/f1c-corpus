## sub_4AA6D0_004aa6d0 — ResolveIndexedListEntryByName

**Summary:** Bounds-checks the selected index (this+0x358, against the count at this+0x354), walks the list at this+0x348 to that index (one node per step via the +4 link), then resolves the node's name string (or WindowName when null) through the lookup sub_41D840 on the global table &byte_91CC38 and passes the result to sub_4CE770.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x348) | 0x0 | R | — | Node's first field: pointer to the name-pointer used for the lookup (null = no action). |
| *(this+0x34C) | 0x4 | R | — | Node's next link used while stepping to the selected index. |
| this | 0x348 | R | — | List base/head pointer (index 210 in DWORD view). |
| this | 0x354 | R | — | Entry count used as the upper bound for the index (index 213). |
| this | 0x358 | R | — | Selected index to resolve (index 214); walk decrements it to 0. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback name used when the node's name pointer is null. |
| 0091cc38 | byte_91CC38 | R | Base address of the lookup container passed to sub_41D840. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | Name lookup against &byte_91CC38; returns a handle/pointer for the matched name. |
| 004ce770 | sub_4CE770 | Consumer of the looked-up handle. |

**Guard conditions:** Action requires 0 <= this[214] < this[213] (index in bounds); out-of-range indexes make the function a no-op. The list walk continues only while the node pointer is non-null, and if the list ends before reaching the index, nothing happens. Final lookup requires the node at the index to be non-null AND its first field (name pointer array) to be non-null.
