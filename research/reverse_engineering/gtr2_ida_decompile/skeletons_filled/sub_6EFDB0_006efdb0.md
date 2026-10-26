## sub_6EFDB0_006efdb0 — Wrapper: forward &dword_FAE908 to sub_560FE0

**Summary:** Thin wrapper that takes the address of global dword_FAE908 and passes it to sub_560FE0 (void result). No static callers, so it is reached indirectly (likely a vtable/hook entry).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fae908 | dword_FAE908 | R | Global whose address is passed to sub_560FE0 (helper receives a pointer to it) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional address-of and single call; no branches, nothing passes or is blocked.
