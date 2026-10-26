## SingleFunctionDispatch_00462300 — COMDelegateDispatch

**Summary:** Delegates to SingleFunctionCallWrapper_a810 with the COM interface pointer from the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710), sub_462E20 (00462e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM interface pointer passed to wrapper |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional guards, always executes the delegation call.
