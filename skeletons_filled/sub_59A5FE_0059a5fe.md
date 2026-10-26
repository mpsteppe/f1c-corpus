## sub_59A5FE_0059a5fe — IO state check and error exception throw

**Summary:** Checks iostream state bits (ios::eofbit/failbit/badbit) against a mask; if error bits are set, constructs and throws a std::ios_base::failure exception with appropriate error message string ("ios::eofbit set", "ios::failbit set", or "ios::badbit set").

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StatusCheckWithErrorDispatch (00598aa0), ObjectInitWithVTableFlagSet (005993eb), StreamCreationWithFlagInit (0059a3a9), StructFieldInitWithConditionalCall (0059a948)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | iostream state flags to check (masked with 7 for eof/fail/bad bits) |
| this | 0xC | R | — | flag: if non-zero, throws immediate exception without constructing error message |
| this | 0xF | R | — | byte setting copied to local for exception cleanup context |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d464 | loc_59D464 | R | address of exception handler code registered by SEHHandlerInit |
| 005b9ce4 | ??_7failure@ios_base@std@@6B@ | R | IosFailureVTable [DERIVED] |
| 005b9cf0 | aIosEofbitSet | R | IosEofbitSetString [DERIVED] |
| 005b9d00 | aIosFailbitSet | R | IOStreamFailbitString [DERIVED] |
| 005b9d14 | aIosBadbitSet | R | IosBadbitSetString [DERIVED] |
| 005bb668 | __TI3?AVfailure@ios_base@std@@ | R | TypeInfo_IOSFailure [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 0058e1b0 | Strlen | computes length of error message string |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrements reference count on exception context object |
| 00599615 | BufferWriteWithNullTerminate | writes error message string to buffer with null terminator |
| 0059a69a | CExceptionInitHandler | prepares C++ exception object for throw |
| 0059bfc3 | CxxThrowException8 | throws C++ typed exception |

**Guard conditions:** If (state_from_offset_0x8 & 7) & mask_at_this+8 yields non-zero (error bits are set), enters error path: optionally throws immediate exception or constructs failure exception with string. If zero, returns normally.
