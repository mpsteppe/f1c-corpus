## SEHAwareVirtualCallDispatchLoop_0059379b — ScopeTableUnwindLoop

**Summary:** C++ exception unwind loop that iterates scope table entries from current try level to target index, calling cleanup/destructor functions for each level traversed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_593446 (00593446), MultiArgRenderingDispatchWithLayout (00593839)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Current try level / unwind index (updated as unwind progresses) |

**Written-by note (persistence):**
- this 0x8: written once per call with final target index after loop completes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH/frame processing helper (misnamed) |
| 005b9940 | stru_5B9940 | R | ExceptionHandlerStruct3 [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | TEB-related compiler SEH data |
| ff00000000001695 | byte_FF00000000001695 | W | TEB-related compiler SEH data |
| ff00000000001699 | byte_FF00000000001699 | RW | TEB-related compiler SEH data |
| ff0000000000169a | byte_FF0000000000169A | R | TEB-related compiler SEH data |
| ff0000000000169b | byte_FF0000000000169B | RW | TEB-related compiler SEH data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a6d5 | StreamMagicNumberCheck | Scope table entry validation (misnamed: probably validates scope entry) |
| 00593c50 | sub_593C50 | Invoke cleanup/destructor function with context and flag |
| 00593cfd | SEHGuardedFunctionPointerCall | Guard against invalid scope table index (out of bounds) |

**Guard conditions:** Loop index `i` (current try level from `a1+8`) must be in range [0, table_size) where table_size = `*(a3 + 4)`. If out of bounds, calls `SEHGuardedFunctionPointerCall`. Loop exits when `i == a4` (target level). Cleanup function is called only if the 8-byte scope entry's second DWORD (handler data) is non-zero. Final index written to `a1+8` is the target level `a4`.
