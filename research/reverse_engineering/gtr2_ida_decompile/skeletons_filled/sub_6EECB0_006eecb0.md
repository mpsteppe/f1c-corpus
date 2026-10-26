## sub_6EECB0_006eecb0 — Wrapper returning sub_438450(dword_757C78)

**Summary:** Thin wrapper: loads the global dword_757C78 and passes its value to sub_438450, returning the callee's result unchanged. Acts as an adapter exposing sub_438450's result for whatever object/state that global holds.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00757c78 | dword_757C78 | R | Value is loaded and passed as argument to sub_438450; likely a handle/pointer or integer state identifying the target of that call. Concrete meaning unknown. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call, no branches; result of sub_438450 is returned directly.
