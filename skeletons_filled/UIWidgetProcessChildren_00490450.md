## UIWidgetProcessChildren_00490450 — UIWidgetProcessChildren

**Summary:** Processes child widgets by reading input position and checking bounds intersection. For state groups 3-5, iterates the child linked list and dispatches a hit notification when a child rectangle contains the input position.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0x4 | R | — | Next pointer in child linked list node |
| obj | 0x40 | R | — | Vtable function pointer at entry 16 (dispatch) |
| this | 0x0 | R | — | VTable pointer (used for dispatch) |
| this | 0xE0 | R | — | Head of child widget linked list |
| this | 0xEC | R | — | Number of children or iteration limit |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00490538 | jpt_490489 | R | Jump table for switch/case |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Returns state/computation value for dispatch selection |
| 0048ea60 | RectangleBoundsCheck | Tests if a point falls within widget bounding rect |
| 00490660 | VTableDispatchListIteration | Iterates child dispatch list |
| 00498880 | DualFieldRead | Reads input/cursor position (two fields) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xEC | <= | 0 | Child count (skip iteration if zero) |

**Guard interpretation:** ShortComputation_6720 result: cases 0-2 → dispatch vtable+64 with arg 0, iterate, return. Cases 3-5 → dispatch vtable+64 with arg 0, then check `this[59]` (offset 0xEC): if <= 0, BLOCKED (skip child iteration). Otherwise iterate child linked list from `this[56]` (offset 0xE0), index into list to find child at each position, test RectangleBoundsCheck against input position — PASSES (dispatch vtable+64 with arg 4 and skip to end) when hit found.
