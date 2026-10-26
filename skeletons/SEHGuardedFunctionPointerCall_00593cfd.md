## SEHGuardedFunctionPointerCall_00593cfd — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BinaryIntervalSearchForMatchingRange (0058a55a), sub_593446 (00593446), sub_5934E1 (005934e1), SEHAwareVirtualCallDispatchLoop (0059379b), sub_5939F9 (005939f9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | [LLM] |
| 005b99a0 | stru_5B99A0 | R | CRTEHFrame [DERIVED] |
| 005e7960 | off_5E7960 | R | CRTOnexitFuncPtr [DERIVED] |
| ff00000000001695 | byte_FF00000000001695 | W | [LLM] |
| ff00000000001699 | byte_FF00000000001699 | RW | [LLM] |
| ff0000000000169b | byte_FF0000000000169B | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00593c9c | SEHWrapperDispatchingToHandlerFunction | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
