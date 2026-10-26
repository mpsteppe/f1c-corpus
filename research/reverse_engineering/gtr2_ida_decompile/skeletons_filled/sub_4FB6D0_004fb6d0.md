## sub_4FB6D0_004fb6d0 — thunk to function pointer

**Summary:** Thin thunk that forwards the object pointer to the global function pointer off_16CB328 and returns its result.

**Called by:** sub_421930 (00421930), sub_421B50 (00421b50), sub_426FC0 (00426fc0), sub_4FD860 (004fd860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016cb328 | off_16CB328 | R | target function pointer invoked as off_16CB328(this) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional tail call through the pointer.
