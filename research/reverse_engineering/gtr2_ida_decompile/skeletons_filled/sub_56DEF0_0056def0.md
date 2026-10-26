## sub_56DEF0_0056def0 — destroy embedded object array and free heap buffer

**Summary:** Cleanup/destructor helper: runs the EH vector destructor iterator over an embedded array of 11 objects (stride 0x2EC bytes, base this+0xF20) using sub_56BFB0 as the per-element destructor, then frees the heap block stored at this+0x98 if it is non-null. Compiler EH bookkeeping (SEH_56DEF0) is present for unwind.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x98 | R | — | heap pointer freed in cleanup if non-null (this[38]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0056bfb0 | sub_56BFB0 | R | per-element destructor callback passed to the EH vector destructor iterator for the 11 embedded objects |
| 006e9d7e | SEH_56DEF0 | R | compiler-generated SEH exception-unwind scope record for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d8 | j_j__free | frees the heap block at this+0x98 |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | `eh vector destructor iterator' — destroys the 11-element array (stride 0x2EC) by calling sub_56BFB0 on each element |

**Guard conditions:** Only the free is guarded: if this[38] (offset 0x98) is non-null it is freed via j_j__free; a null pointer skips the free. The vector destructor iterator over the 11 embedded elements runs unconditionally.
