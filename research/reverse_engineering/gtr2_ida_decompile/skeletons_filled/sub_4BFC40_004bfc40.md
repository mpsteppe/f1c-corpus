## sub_4BFC40_004bfc40 — destructor body: cleans sub-object at +0x470, chains cleanup

**Summary:** Destructor body for the class: runs cleanup on the embedded sub-object at this+0x470 (this+284 dwords), then returns the result of the subsequent destructor-chain call on this object. Storage deallocation also handled by this helper's call site.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409fb0 | sub_409FB0 | Cleanup/destructor call on the embedded sub-object at this+0x470 |

**Guard conditions:** No branches — the sub-object cleanup and the final chain call execute unconditionally; nothing is checked or blocked.
