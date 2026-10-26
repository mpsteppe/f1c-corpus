## sub_54BAB0_0054bab0 — Thunk forwarding to function-pointer global off_16CA2A0

**Summary:** Trivial tail-call thunk: forwards `this` and integer argument a2 to the function pointer stored in global off_16CA2A0 and returns its int result unchanged. A fixed entry point over a dynamically-assigned handler.

**Called by:** sub_438180 (00438180), sub_54BBB0 (0054bbb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016ca2a0 | off_16CA2A0 | R | Function pointer; target of the tail call, invoked with (`this`, a2) and supplying the int result |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional tail call. Both arguments are passed through and the callee's int result returned verbatim.
