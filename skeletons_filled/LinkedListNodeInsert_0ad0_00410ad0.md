## LinkedListNodeInsert_0ad0_00410ad0 — ArraySlotInsert

**Summary:** Inserts a pointer into a growable pointer-array slot. Part of a dynamic array or handle table management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_f0d0 (0040f0d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R/W | — | Current count/index (number of elements inserted) |
| this | 0x8 | R | — | Pointer to array of pointer slots |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branch checks; always executes insertion and count increment.
