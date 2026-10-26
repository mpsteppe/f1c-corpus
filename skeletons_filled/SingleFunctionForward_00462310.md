## SingleFunctionForward_00462310 — COMShortComputationForward

**Summary:** Calls ShortComputation_a820 with the COM interface pointer and returns the result as a byte.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM interface pointer passed to computation |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a820 | ShortComputation_a820 | Execute COM computation and return boolean result |

**Guard conditions:** None — no conditional guards, always executes.
