## sub_4CE1C0_004ce1c0 — ForwardThisToGlobalCallback

**Summary:** Thiscall thunk: forwards only `this` to the global function pointer off_16CB55C and returns its result. A no-argument (besides this) trampoline used by several callers.

**Called by:** sub_495CD0 (00495cd0), sub_49A830 (0049a830), sub_49AA90 (0049aa90), sub_49C470 (0049c470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016cb55c | off_16CB55C | R | Global function pointer invoked as off_16CB55C(this); its return value is propagated |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional indirect call through off_16CB55C with this only; no checks, nothing blocked.
