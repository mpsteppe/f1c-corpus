## sub_4D5AD0_004d5ad0 — No-argument indirect thunk through off_16C9718

**Summary:** Minimal thunk that invokes the function pointer at off_16C9718 with no arguments (its own parameter a1 is discarded) and returns that call's result — an import/hook indirection slot.

**Called by:** sub_4DA220 (004da220), sub_4DA6C0 (004da6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9718 | off_16C9718 | R | function pointer invoked with no arguments; the real implementation lives behind this indirection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — off_16C9718() is called unconditionally; the incoming parameter a1 is not even forwarded.
