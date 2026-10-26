## sub_5BBFE0_005bbfe0 — indirect tail thunk through off_16C95CC

**Summary:** `__thiscall` thunk that forwards its `this` pointer to the function stored in the global function-pointer slot off_16C95CC and returns whatever that target returns. Callers use it as a stable entry point while the real implementation is resolved through the pointer.

**Called by:** sub_4F3910 (004f3910), sub_4F6590 (004f6590), sub_54CD40 (0054cd40), sub_54D1C0 (0054d1c0), sub_54D5C0 (0054d5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c95cc | off_16C95CC | R | Function pointer through which the real implementation is dispatched; called with the incoming `this`. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional indirect call through off_16C95CC with the `this` argument; no checks, nothing blocked.
