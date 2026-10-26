## VTableDispatchListIteration_00490660 — VTableDispatchListIteration

**Summary:** Iterates a linked list of child widgets and dispatches a vtable method at offset 16 on each, passing a boolean flag derived from state computation. Used for broadcasting state/flag changes to children.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_490330 (00490330), sub_490390 (00490390), UtilityFunction_03f0 (004903f0), UIWidgetProcessChildren (00490450), PanelMouseInteractionHandler (00490550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xE0)+0x0) | 0x10 | R | — | Vtable function pointer of child node at entry 4 (dispatch target) |
| *(this+0xE0) | 0x0 | R | — | Vtable pointer of first child in linked list |
| this | 0xE0 | R | — | Head pointer of child widget linked list |
| this | 0xE8 | R | — | Tail/end pointer of child linked list |
| this | 0xEC | R | — | Number of children to iterate |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Returns state value to determine dispatch flag (true if 3-5) |

**Guard conditions:** Iterates `this[59]` (offset 0xEC) times. For each index, walks linked list from `this[56]` (offset 0xE0) to reach the target node. BLOCKED if node has no vtable pointer. PASSES (dispatches vtable method at offset 16 with boolean flag) for each valid node.
