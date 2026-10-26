## SEHWrapperDispatchingToHandlerFunction_00593c9c — CrtTerminateHandlerDispatch

**Summary:** Checks TLS for a registered termination/cleanup handler (slot 24), calls it if present, then performs standard CRT cleanup sequence with fixed parameters and the passed parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH frame processing helper (misnamed) |
| 005b9988 | stru_5B9988 | R | CRTExceptionStruct [DERIVED] |
| ff00000000001695 | byte_FF00000000001695 | W | TEB-related compiler SEH data |
| ff00000000001699 | byte_FF00000000001699 | RW | TEB-related compiler SEH data |
| ff0000000000169b | byte_FF0000000000169B | W | TEB-related compiler SEH data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058e0c7 | TLSValueRetrievalWithInit | Retrieve TLS to check and call registered termination handler at slot 24 |

**Guard conditions:** Termination handler at TLS slot 24 is called only if non-null. The rest of the cleanup sequence (sub_5932F3, sub_597388, sub_589CB5, sub_597388) always executes regardless.
