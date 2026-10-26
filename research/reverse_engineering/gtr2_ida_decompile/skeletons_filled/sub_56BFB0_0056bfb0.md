## sub_56BFB0_0056bfb0 — Thunk to destructor sub_569FD0

**Summary:** Compiler-generated thunk: forwards this directly to sub_569FD0, the container teardown routine that frees the two dynamic arrays and zeroes the pointer/count fields. Likely the vtable slot that invokes this class's destructor body.

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

**Guard conditions:** None — an unconditional direct jump to sub_569FD0 with this passed through. No checks, no return value; the callee performs the actual array destruction and field clearing.
