## SEHGuardedFunctionPointerCall_00593cfd — LastResortSEHGuardFrame

**Summary:** Sets up an SEH guard frame (__except_handler3) around an optional global function pointer call (off_5E7960, likely atexit/onexit handler), then delegates to CrtTerminateHandlerDispatch for final processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BinaryIntervalSearchForMatchingRange (0058a55a), sub_593446 (00593446), sub_5934E1 (005934e1), SEHAwareVirtualCallDispatchLoop (0059379b), sub_5939F9 (005939f9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH exception handler for the guard frame |
| 005b99a0 | stru_5B99A0 | R | CRTEHFrame [DERIVED] — scope table for guard frame |
| 005e7960 | off_5E7960 | R | CRTOnexitFuncPtr [DERIVED] — optional function pointer called within SEH guard |
| ff00000000001695 | byte_FF00000000001695 | W | TEB-related compiler SEH data |
| ff00000000001699 | byte_FF00000000001699 | RW | TEB-related compiler SEH data |
| ff0000000000169b | byte_FF0000000000169B | W | TEB-related compiler SEH data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00593c9c | SEHWrapperDispatchingToHandlerFunction | Final handler/cleanup after SEH frame processing |

**Guard conditions:** SEH TryLevel is set to 1 before calling `off_5E7960` (if non-null), protecting the call with the SEH frame. TryLevel is set back to 0 after the call completes, then to -1 (no handler) before final dispatch. The SEH frame's Next pointer is linked to the current TEB exception list head, allowing standard SEH unwind.
