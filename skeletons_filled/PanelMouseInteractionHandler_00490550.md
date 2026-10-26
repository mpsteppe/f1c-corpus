## PanelMouseInteractionHandler_00490550 — PanelMouseInteraction

**Summary:** Handles mouse/input interaction for a panel: for state groups 3-5, reads input position, tests against a custom hit-test vtable method, then iterates child widgets and dispatches hit notification on bounds match. Always iterates child dispatch list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0x4 | R | — | Next pointer in child linked list node |
| obj | 0x30 | R | — | Vtable function pointer at entry 12 (hit-test with position) |
| obj | 0x40 | R | — | Vtable function pointer at entry 16 (dispatch) |
| this | 0x0 | R | — | VTable pointer (used for dispatch) |
| this | 0xE0 | R | — | Head of child widget linked list |
| this | 0xEC | R | — | Number of children or iteration limit |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Returns state/computation value for dispatch selection |
| 0048ea60 | RectangleBoundsCheck | Tests if a point falls within widget bounding rect |
| 00490660 | VTableDispatchListIteration | Iterates child dispatch list |
| 00498880 | DualFieldRead | Reads input/cursor position (two fields) |

**Guard conditions:** Checks ShortComputation_6720 result: only processes if result is 3-5 (BLOCKED for 0-2). Then calls vtable hit-test at offset 48 with input position — BLOCKED (skips children) if hit-test returns non-zero (already handled). Otherwise dispatches vtable+64 with arg 0, iterates children, tests RectangleBoundsCheck — on first hit dispatches vtable+64 with arg 4 and breaks.
