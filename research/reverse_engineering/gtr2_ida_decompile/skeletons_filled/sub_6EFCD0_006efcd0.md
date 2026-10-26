## sub_6EFCD0_006efcd0 — Wrapper: forward (edi, arg) to sub_53C1D0

**Summary:** Register-convention wrapper that forwards its first argument (passed in EDI) and a stack argument unchanged to sub_53C1D0, returning that call's result. No static callers, so it is reached indirectly (likely a vtable/hook entry).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00be1ce0 | unk_BE1CE0 | R | Listed as read by this function; decompiled body only forwards arguments, exact role unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight forwarding of both arguments with no branches; nothing passes or is blocked.
