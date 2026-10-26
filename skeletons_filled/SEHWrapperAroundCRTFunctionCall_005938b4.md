## SEHWrapperAroundCRTFunctionCall_005938b4 — CxxExceptionSEHFrameWrapper

**Summary:** SEH wrapper that saves/restores TLS exception context around a try-block execution. On C++ exception (code 0xE06D7363) with non-zero return, dispatches through SEHWrappedRenderDispatchCall after abnormal termination check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiArgRenderingDispatchWithLayout (00593839)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | ExceptionCode from exception record |
| this | 0x10 | R | — | NumberParameters from exception record |
| this | 0x14 | R | — | ExceptionInformation[0] — magic value 0x19930520 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH frame processing helper (misnamed) |
| 005b9950 | stru_5B9950 | R | ExceptionHandler_State [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | TEB-related compiler SEH data |
| ff00000000001695 | byte_FF00000000001695 | W | TEB-related compiler SEH data |
| ff00000000001699 | byte_FF00000000001699 | RW | TEB-related compiler SEH data |
| ff0000000000169a | byte_FF0000000000169A | R | TEB-related compiler SEH data |
| ff0000000000169b | byte_FF0000000000169B | RW | TEB-related compiler SEH data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005888a6 | MSVCRTSEHFrameUnwinder | SEH frame unwind helper for cleanup |
| 0058890e | CRTAbnormalTermination | Check if exception termination was abnormal |
| 0058a3b6 | SEHExceptionFrameWrapper | Execute wrapped code with SEH protection |
| 0058e0c7 | TLSValueRetrievalWithInit | Retrieve TLS for saving/restoring exception context |
| 005939cf | FileMagicNumberValidator | misnamed — exception record validation helper |
| 00593bbd | SEHWrappedRenderDispatchCall | Final dispatch after C++ exception handling |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 18446744073179853667 | ExceptionCode == 0xE06D7363 (CPP_EXCEPTION) |
| this | 0x10 | == | 3 | NumberParameters == 3 |
| this | 0x14 | == | 429065504 | ExceptionInformation[0] == 0x19930520 |

**Guard interpretation:** Only dispatches through `SEHWrappedRenderDispatchCall` when ALL of these hold: exception code is 0xE06D7363, NumberParameters == 3, ExceptionInformation[0] == 0x19930520, AND `SEHExceptionFrameWrapper` returned a non-zero result. Also calls `CRTAbnormalTermination` to determine abnormal-termination flag before dispatch. Returns the result of `SEHExceptionFrameWrapper` to caller.
