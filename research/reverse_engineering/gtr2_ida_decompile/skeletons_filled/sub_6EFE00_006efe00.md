## sub_6EFE00_006efe00 — Wrapper: forward byte_FAEC84 to sub_617060

**Summary:** Thin wrapper that loads byte global byte_FAEC84 and passes it to sub_617060, returning that call's result. No static callers, so it is reached indirectly (likely a vtable/hook entry).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00faec84 | byte_FAEC84 | R | Byte global passed by value to sub_617060 as its only argument |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional global load and single call; no branches, nothing passes or is blocked.
