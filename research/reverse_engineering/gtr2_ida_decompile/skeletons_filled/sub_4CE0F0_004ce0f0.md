## sub_4CE0F0_004ce0f0 — TrimNodeListToLimit

**Summary:** Trimming routine: if the limit value at 0x250 is nonnegative and the current count at 0x94 exceeds it, pops the surplus number of nodes from the singly-linked list headed at 0x90, advances the head to each node's link field at +0x8C, invokes each node's first virtual method with (node, 1), then reduces the count by the number popped.

**Called by:** sub_4D93B7 (004d93b7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x90) | 0x0 | R | — | Vtable pointer of a list node (node+0x0) read to make the node's first virtual call before unlinking |
| this | 0x90 | RW | — | Head pointer (this[36]) of the singly-linked node list; advanced to node+0x8C each pop |
| this | 0x94 | RW | — | Current count (this[37]); reduced by the number of nodes popped |
| this | 0x11C | R | — | unknown — not visibly used in the provided code (likely extraction artifact) |
| this | 0x250 | R | — | Limit/target count (this[148]); if negative, no trimming happens |

**Written-by note (persistence):**
- this 0x90: Conditional — rewritten only inside the trim loop (once per popped node); with no trimming it is untouched, so an external poke survives until the next call that actually trims
- this 0x94: Conditional — written only when the count exceeds the limit (minus the surplus); no write otherwise, so an external poke survives while count <= limit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** v2 = this[0x250]. If v2 < 0 → whole body skipped. Else v3 = this[0x94]: if v3 <= v2 → no action (BLOCKED). If v3 > v2 → PASS: surplus = v3 - v2 (always > 0 so the do-while runs exactly surplus times), each iteration pops the head node (calling its vtable slot 0 with (node, 1)) while head != 0; finally this[0x94] -= surplus.
