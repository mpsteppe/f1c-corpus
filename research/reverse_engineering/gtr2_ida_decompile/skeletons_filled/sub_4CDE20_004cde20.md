## sub_4CDE20_004cde20 — ThunkToGlobalHandler

**Summary:** Trivial forwarder/thunk: ignores its char argument and calls the global function pointer off_16C98E4, returning that call's result. Likely a registered callback trampoline.

**Called by:** sub_498D80 (00498d80), sub_4AA810 (004aa810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c98e4 | off_16C98E4 | R | Global function pointer that is called with no arguments supplied by this wrapper; its return value is propagated |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the function unconditionally calls off_16C98E4() and returns its value. The incoming char argument a1 is not read or forwarded anywhere.
