## sub_6EEC80_006eec80 — Wrapper forwarding &dword_B66000 to sub_437E00

**Summary:** Thin wrapper: casts the address of the global dword_B66000 to a char pointer and forwards it to sub_437E00. No other logic — a trampoline routing operations on that global to a shared handler.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b66000 | dword_B66000 | R | Address is taken (cast to char *) and passed to sub_437E00; the callee receives a pointer to this global storage/object. Concrete semantics unknown; R flag reflects only the pointer load. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call, no branches; every invocation passes &dword_B66000 to sub_437E00.
