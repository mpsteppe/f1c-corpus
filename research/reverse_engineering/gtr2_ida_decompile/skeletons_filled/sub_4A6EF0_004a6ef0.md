## sub_4A6EF0_004a6ef0 — thunk forwarding to sub_497E00

**Summary:** Thin thunk/trampoline (marked `attributes: thunk`): forwards the `this` pointer unchanged to sub_497E00. It exists to provide a stable call target for the underlying routine.

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

**Guard conditions:** None — no branches, no field tests. The call to sub_497E00 is unconditional and its result (if any) is discarded; the function has no return value.
