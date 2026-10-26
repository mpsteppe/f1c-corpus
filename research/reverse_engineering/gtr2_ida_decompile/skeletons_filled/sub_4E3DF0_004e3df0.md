## sub_4E3DF0_004e3df0 — Thunk to indirect function pointer off_16C9DC0

**Summary:** Forwarder (`thunk`) that calls the function pointer at off_16C9DC0 with `this` and returns its result.

**Called by:** sub_48E050 (0048e050), sub_4B7CA0 (004b7ca0), sub_4D2B30 (004d2b30), sub_4DFE50 (004dfe50), sub_4E1950 (004e1950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9dc0 | off_16C9DC0 | R | function pointer used as the trampoline target |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional call; the target's return value is returned unchanged.
