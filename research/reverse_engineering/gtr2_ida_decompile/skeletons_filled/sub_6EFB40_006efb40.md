## sub_6EFB40_006efb40 — Wrapper: forward dword_B6E4E8 to sub_4E5B70

**Summary:** Thin wrapper that loads global dword_B6E4E8 and passes it as the sole argument to sub_4E5B70, returning that call's result. No static callers, so it is reached indirectly (likely a vtable/hook entry).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6e4e8 | dword_B6E4E8 | R | Stored pointer/handle; read and forwarded to sub_4E5B70 as the only argument |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional global load followed by a single call; no branches, nothing passes or is blocked.
