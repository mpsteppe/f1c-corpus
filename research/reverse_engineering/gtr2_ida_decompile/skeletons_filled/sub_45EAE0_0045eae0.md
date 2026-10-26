## sub_45EAE0_0045eae0 — global routine thunk (forwards to function pointer)

**Summary:** One-line wrapper that tail-calls the routine held in the function pointer global off_16C9224 and returns its result unchanged. In the decompiled form the incoming parameter is unused and the target is invoked with no arguments.

**Called by:** sub_4769D0 (004769d0), sub_556B40 (00556b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9224 | off_16C9224 | R | function pointer invoked by the thunk; its return value is passed straight back to the caller |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — the function contains no conditional branches; it unconditionally invokes off_16C9224 and returns that call's result. Nothing is checked, nothing is blocked. If the slot is never assigned, the call would target a null/default pointer.
