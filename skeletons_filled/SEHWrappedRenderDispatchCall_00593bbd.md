## SEHWrappedRenderDispatchCall_00593bbd — CppCatchHandlerDispatch

**Summary:** Dispatches C++ catch handler by reading handler function pointer from exception record's handler table and calling via atomic lock/unlock wrapper with handler context data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5934E1 (005934e1), SEHWrapperAroundCRTFunctionCall (005938b4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | Handler function pointer from the handler table |
| this | 0x18 | R | — | ExceptionInformation[3] — handler context/data passed to handler |
| this | 0x1C | R | — | ExceptionInformation[4] — pointer to handler table structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH frame processing helper (misnamed) |
| 005b9978 | stru_5B9978 | R | CRT_ExRegFrame2 [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | TEB-related compiler SEH data |
| ff00000000001695 | byte_FF00000000001695 | W | TEB-related compiler SEH data |
| ff00000000001699 | byte_FF00000000001699 | RW | TEB-related compiler SEH data |
| ff0000000000169b | byte_FF0000000000169B | RW | TEB-related compiler SEH data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a323 | AtomicLOCKUNLOCKWithIndirectCall | Execute catch handler with atomic lock/unlock synchronization |

**Guard conditions:** Returns `a1` directly (no-op) if exception record pointer is NULL, or if handler function pointer at `*(a1+28)+4` is NULL. Only calls `AtomicLOCKUNLOCKWithIndirectCall` when both the handler pointer and context data at `a1+24` are valid.
