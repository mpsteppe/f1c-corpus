## BooleanFlagSetterVirtualCall_00490160 — BoolFlagSetVirtualCall

**Summary:** Sets a boolean state flag (0 or 1) based on input parameter, then dispatches a vtable method. Used for UI toggle/hover state management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchWithConditionalCreation (0046fdc0), ResourceCheckDispatch (0046fdf0), StateCheckConditionalDispatch (0046fe20), ConditionalUISubsystemDispatch (0046fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable function pointer at entry 11 (dispatch target) |
| this | 0x0 | R | — | VTable pointer (used for dispatch) |
| this | 0xE0 | RW | 1 | Boolean state flag (0 or 1) |

**Written-by note (persistence):**
- this 0xE0: Written each call based on `a2`; survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `a2` — truthy (non-zero): sets this[56] to 0. Falsy (zero): sets this[56] to 1. Always dispatches vtable method after setting flag.
