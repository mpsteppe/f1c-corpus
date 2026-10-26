## sub_4BF1A0_004bf1a0 — scalar deleting destructor (calls dtor sub_4BF1C0, frees if delete flag)

**Summary:** MSVC scalar deleting destructor: runs the real destructor sub_4BF1C0, then frees the object's storage when the low bit of the flag argument is set, and returns the pointer. Standard compiler-generated `delete` helper.

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
| 004bf1c0 | sub_4BF1C0 | Class destructor body (member cleanup) executed before any deallocation |
| 006308d3 | j__free | CRT free; releases the object memory when delete flag bit 0 is set |

**Guard conditions:** `if ((a2 & 1) != 0)` — when bit 0 of the flag byte is set the object storage is freed via j__free; when clear, the destructor still runs but memory is kept (the object is returned unchanged). No other branches.
