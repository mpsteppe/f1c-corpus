## sub_6EFBC0_006efbc0 — Wrapper: forward address of byte_B6F530 to sub_510C90

**Summary:** Thin wrapper that takes the address of global byte_B6F530 and passes it to sub_510C90, returning that call's result. No static callers, so it is reached indirectly (likely a vtable/hook entry).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6f530 | byte_B6F530 | R | Byte global whose address is passed to sub_510C90 (helper receives a pointer to it) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional address-of and single call; no branches, nothing passes or is blocked.
