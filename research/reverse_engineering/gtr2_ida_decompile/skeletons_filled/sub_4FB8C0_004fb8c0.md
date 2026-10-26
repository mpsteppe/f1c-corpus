## sub_4FB8C0_004fb8c0 — forwarder to sub_415CD0 with field at this+0xE70

**Summary:** One-instruction trampoline: calls sub_415CD0 passing a pointer to the float field at byte offset 0xE70 (231 floats) of the object. Called by sub_42EF60; delegates a state/update operation to the sub-object living at that offset.

**Called by:** sub_42EF60 (0042ef60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches, no comparisons. The call to sub_415CD0 with `this + 231` (0xE70 bytes) is unconditional; there is no early-out or blocked path.
