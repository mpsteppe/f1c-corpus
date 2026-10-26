## IteratorCheck_004d88b0 — Iterator advance check

**Summary:** Advances a sequential iterator: reads current index from `this[0]`, calls a vtable method (offset 20) on the associated entry object, and resets index to -1 when iteration completes (method returns 1). Acts as a "step and check done" for an entry list walk.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | Current iterator index; -1 means no active iterator / iteration complete |
| this | this[this[0]+4] | R | — | Entry object at current iterator position; vtable+20 is advance/done-check method |

**Written-by note (persistence):**
- this 0x0: Set to -1 when advance method returns 1 (iteration complete). External poke survives (direct assignment).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 18446744073709551615 | Current iterator index must not be -1 |

**Guard interpretation:** PASSES when `this[0] != -1` (there is an active iterator to advance). BLOCKED when `this[0] == -1` (no current iterator, returns -1 immediately).
