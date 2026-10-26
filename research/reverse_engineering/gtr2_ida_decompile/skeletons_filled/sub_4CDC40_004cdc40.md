## sub_4CDC40_004cdc40 — AttemptClickActivation

**Summary:** Attempts to activate/click this element at the current cursor position: reads a cursor position pair from the input system, gates on a local busy flag and two virtual predicates (hit test at vtable+0x14, state predicate at vtable+0x94), and on success forwards to a global handler via sub_4CD5A0. Returns 0 when the activation was dispatched, -1 when blocked.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | Virtual method slot (vtable+0x14) called with the two cursor coordinates; nonzero means the position passes the hit/activation test |
| obj | 0x94 | R | — | Virtual method slot (vtable+0x94) called with no extra args; a nonzero result vetoes the activation |
| this | 0x0 | R | — | Vtable pointer used to reach the two virtual methods above |
| this | 0x64 | R | — | Byte flag; nonzero marks the element as busy/blocked and aborts the attempt |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd5a0 | sub_4CD5A0 | Thunk forwarding to a global function pointer; invoked with (this, 0) as the actual activation dispatch on success |
| 004de540 | sub_4DE540 | Reads a two-int position pair (its own this[22], this[23]) into the two byref locals; supplies the coordinates given to the vtable+0x14 predicate |

**Guard conditions:** PASS requires all three: (1) this[0x64] == 0 — a nonzero byte immediately returns -1; (2) virtual call (*(*this+0x14))(this, v4, v3) returns nonzero — zero returns -1; (3) virtual call (*(*this+0x94))(this) returns 0 — nonzero returns -1. Only when none of the three early-return branches fire does it call sub_4CD5A0(this, 0) and return 0 (success).
