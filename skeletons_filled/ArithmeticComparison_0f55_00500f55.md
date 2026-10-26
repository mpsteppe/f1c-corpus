## ArithmeticComparison_0f55_00500f55 — RecursiveTreeDestructor

**Summary:** Recursively destructs and frees a tree/list structure. Conditionally frees data pointers at this+4/this+8 (guarded by flags at this+56/this+60), then recursively destructs and frees child nodes at this+76 and this+80.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LockUnlockWrapper (005006d5), sub_5008E4 (005008e4), ShortComputation_0fae (00500fae)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Data pointer A (conditionally freed) |
| this | 0x8 | R | — | Data pointer B (conditionally freed) |
| this | 0x38 | R | — | Flag: if non-zero, free data pointer at this+4 |
| this | 0x3C | R | — | Flag: if non-zero, free data pointer at this+8 |
| this | 0x4C | R | — | Child node pointer A (recursively destructed then freed) |
| this | 0x50 | R | — | Child node pointer B (recursively destructed then freed) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00500f55 | ArithmeticComparison_0f55 | Recursively destruct child tree node |
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory block |

**Guard conditions:** this+4 freed only if non-NULL AND this+56 flag non-zero. this+8 freed only if non-NULL AND this+60 flag non-zero. Children at this+76/this+80 freed only if non-NULL (after recursive destructor call).
