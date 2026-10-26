## sub_6CD96E_006cd96e — Run object-order refinement over all objects

**Summary:** Drives one full pass of the object-ordering optimizer: recomputes metrics via sub_6CD3BF (results stored at this+0x50 and this+0x4C), fills the work-order array at +0x30 with the identity permutation, copies the current order list (+0x3C) into the backup (+0x40), sorts the work order with comparator sub_6CD318 via sub_682274, then calls sub_6CD4DC once for every object index in that sorted order. Returns 1 when all objects were handled, 0 when a refinement pass is rejected, or the negative error code returned by sub_6CD4DC.

**Called by:** sub_6CD9DB (006cd9db)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R/W | — | work-order array of object indices: filled with 0..count-1, sorted by the comparator, then iterated |
| this | 0x38 | R | — | number of objects (loop bound and count passed to the sorter) |
| this | 0x3C | R | — | current object order list, copied into the backup array |
| this | 0x40 | W | — | backup copy of the order list, used by sub_6CD4DC to restore state |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006cd318 | sub_6CD318 | R | comparator callback passed to sub_682274 to sort the work-order array (runs with `this` as context) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00682274 | sub_682274 | qsort-style sorter: (comparator, base pointer, count, context) over the work-order array |
| 006cd3bf | sub_6CD3BF | recomputes per-object offsets/counters; writes total to this+0x50 and max to this+0x4C |
| 006cd4dc | sub_6CD4DC | refines the ordering window for one object index; 1 = success, 0 = rejected, negative = error |

**Guard conditions:** before the loop: if count `*(this+0x38)` is zero the function returns 1 immediately (nothing to do). In the loop over sorted work-order entries: result < 0 breaks out and returns that error code; result == 0 returns 0 (attempt rejected); after the counter reaches the object count the function returns 1 (all objects processed).
