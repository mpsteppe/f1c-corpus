## StateArrayWordSignExtension_0054bf10 — Sign-extend upper 16 bits of state array words

**Summary:** Walks UI element linked list (head at this+0x204, next at node+0x10). For each element, iterates state array entries (count at node+0x118, array at node+0x11C). For each state word: reads upper 16 bits as signed 16-bit value, sign-extends to 32 bits, and writes result back, effectively replicating the signed upper half into the lower half. Ensures signed 16-bit state values are correctly extended for downstream processing. Part of UI scene node state initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveTraversal (0054bcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Head of UI element linked list |
| this | 0x224 | R | — | Accessed during iteration (node linkage) |
| this | 0x32C | R | — | State entry count; iterated for each state word |
| this | 0x330 | RW | — | State word: upper 16 bits read as signed value; result written back |
| this | 0x332 | R | — | Upper 16 bits of state word read as signed short for sign extension |

**Written-by note (persistence):**
- this 0x330: written once per state entry; sign-extended value overwrites original each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** List walk BLOCKED if `this[0x204]` (head) is null. Inner loop continues while index < node's state count. No count guard — if count is 0, inner loop body never executes.
