## sub_4E3EE0_004e3ee0 — Thunk to indirect function pointer off_16CAB40

**Summary:** Forwarder (`thunk`) that passes `this` and two integer arguments to the function pointer at off_16CAB40 and returns the result.

**Called by:** sub_4DB690 (004db690), sub_4DC3C0 (004dc3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016cab40 | off_16CAB40 | R | function pointer used as the trampoline target |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional pass-through of (this, a2, a3); the target's return value is returned unchanged.
