## sub_60AED0_0060aed0 — release sub-object (drain pending ops, then free)

**Summary:** Teardown helper: while the pending counter this+0x10 is positive it polls the sub-object at this+0x20 (vtable slot 0x30) and decrements the counter when the poll returns 0; it then clears the counter and, if the sub-object exists, releases it via vtable slot 8 and nulls the pointer.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x8 | R | — | vtable slot 8 of the sub-object — release/destroy method called once before the pointer is cleared |
| *(this+0x20) | 0x30 | R | — | vtable slot 0x30 of the sub-object — poll method called in the drain loop; a 0 return decrements the counter |
| this | 0x10 | RW | 0 | pending-operations counter; decremented while > 0, cleared to 0 unconditionally after the loop |
| this | 0x20 | RW | 0 | sub-object pointer; polled in the loop, released via vtable slot 8 and set to 0 |

**Written-by note (persistence):**
- this 0x10: written on every call — decremented inside the loop and set to 0 after it; an external poke is overwritten on the next call (or drives loop iterations before that).
- this 0x20: written to 0 on every call where the pointer was non-null (after release); a poked value is overwritten with 0 on the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | > | 0 | pending counter at +0x10; loop continues while it is positive |

**Guard interpretation:** this+0x10 <= 0 → drain loop skipped entirely; the counter is still cleared and, if this+0x20 is non-null, the object is released and the pointer cleared. this+0x10 > 0 → each iteration: if this+0x20 is null the counter is not decremented (possible infinite loop with a null object, since nothing else exits the loop); if the object's vtable slot 0x30 returns 0 the counter is decremented. After the loop, non-null sub-object → vtable slot 8 called, this+0x20 = 0.
