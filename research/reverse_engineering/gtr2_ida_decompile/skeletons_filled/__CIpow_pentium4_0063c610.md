## __CIpow_pentium4_0063c610 — x87 _CIpow thunk to __pow_pentium4

**Summary:** CRT x87 transcendental entry stub: takes the two double operands from the x87 stack (st1 = a1, st0 = a2), swaps them into register order and forwards to __pow_pentium4(a2, a1), which performs the actual power computation. It is the "compute intermediate" binding of the pow dispatch for the Pentium 4 code path.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063c629 | __pow_pentium4 | Performs the pow(x, y) computation for the Pentium 4 code path; receives the two operands with the stack order swapped relative to the x87 register order |

**Guard conditions:** None — unconditional tail call. The only argument handling is the swap of the x87 operand order: the st0 value (a2) becomes the first argument and the st1 value (a1) becomes the second.
