## sub_4E3AF0_004e3af0 — Thunk to indirect function pointer off_16CA934

**Summary:** Forwarder (`thunk`) that passes `this` and one integer argument to the function pointer stored at off_16CA934 and returns the result.

**Called by:** sub_4DB690 (004db690), sub_4DC3C0 (004dc3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016ca934 | off_16CA934 | R | function pointer used as the trampoline target |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional pass-through of (this, a2); the target's return value is returned unchanged.
