## sub_59A5FE_0059a5fe — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StatusCheckWithErrorDispatch (00598aa0), ObjectInitWithVTableFlagSet (005993eb), StreamCreationWithFlagInit (0059a3a9), StructFieldInitWithConditionalCall (0059a948)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0xF | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d464 | loc_59D464 | R | [LLM] |
| 005b9ce4 | ??_7failure@ios_base@std@@6B@ | R | IosFailureVTable [DERIVED] |
| 005b9cf0 | aIosEofbitSet | R | IosEofbitSetString [DERIVED] |
| 005b9d00 | aIosFailbitSet | R | IOStreamFailbitString [DERIVED] |
| 005b9d14 | aIosBadbitSet | R | IosBadbitSetString [DERIVED] |
| 005bb668 | __TI3?AVfailure@ios_base@std@@ | R | TypeInfo_IOSFailure [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 0058e1b0 | Strlen | [LLM] |
| 005993af | ReferenceCountDecrementWithConditionalFree | [LLM] |
| 00599615 | BufferWriteWithNullTerminate | [LLM] |
| 0059a69a | CExceptionInitHandler | [LLM] |
| 0059bfc3 | CxxThrowException8 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
