## sub_5E5BB0_005e5bb0 — Member destructor chain

**Summary:** Tears down a composite object by invoking per-member cleanup routines in descending offset order — two at this+114/this+110, one each at this+106 and this+102, four at this+98 through this+86 — and finishes with a null no-op call on `this`. Looks like a destructor for an object containing several embedded containers.

**Called by:** sub_5DB6D0 (005db6d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ec76a | SEH_5E5BB0 | R | SEH scope/handler record emitted by the compiler for this function's unwind path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | No-op stub invoked with `this` (likely stripped base-destructor/empty cleanup placeholder) |
| 00525140 | sub_525140 | Destructor-style cleanup for one of four member objects at this+98, +94, +90, +86 |
| 005970e0 | sub_5970E0 | Destructor-style cleanup for member at this+102 |
| 005db6d0 | sub_5DB6D0 | Destructor-style cleanup for members at this+114 and this+110 |
| 006067d0 | sub_6067D0 | Destructor-style cleanup for member at this+106 |

**Guard conditions:** None — all nine calls execute unconditionally and in fixed order; no branches or early exits.
