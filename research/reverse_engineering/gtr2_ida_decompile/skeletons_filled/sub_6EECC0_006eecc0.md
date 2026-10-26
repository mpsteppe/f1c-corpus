## sub_6EECC0_006eecc0 — Wrapper forwarding &dbl_B66040 to sub_44B520

**Summary:** Thin wrapper: passes the address of the global double dbl_B66040 to sub_44B520 and returns. Trampoline-style adapter routing work on that global floating-point value to the shared handler.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b66040 | dbl_B66040 | R | Address is taken and passed to sub_44B520; the callee receives a pointer to this global double (value or state). Concrete semantics unknown; R flag reflects only the address load. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call, no branches; every invocation passes &dbl_B66040 to sub_44B520.
