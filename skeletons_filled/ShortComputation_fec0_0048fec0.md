## ShortComputation_fec0_0048fec0 — ShortComputation

**Summary:** Dispatches a vtable method with a state flag, then runs window type detection. Part of a UI component update cycle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchWithConditionalCreation (0046fdc0), ResourceCheckDispatch (0046fdf0), StateCheckConditionalDispatch (0046fe20), ConditionalUISubsystemDispatch (0046fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | Vtable function pointer at entry 16 |
| this | 0x0 | R | — | VTable pointer (used for dispatch) |
| this | 0xE0 | R | — | State/flag field passed to vtable method |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004901a0 | UIWindowTypeDetection | Detects or updates UI window type classification |

**Guard conditions:** None — unconditional; no branches.
