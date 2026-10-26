## SEHAwareVirtualCallDispatchLoop_0059379b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_593446 (00593446), MultiArgRenderingDispatchWithLayout (00593839)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | [LLM] |
| 005b9940 | stru_5B9940 | R | ExceptionHandlerStruct3 [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | [LLM] |
| ff00000000001695 | byte_FF00000000001695 | W | [LLM] |
| ff00000000001699 | byte_FF00000000001699 | RW | [LLM] |
| ff0000000000169a | byte_FF0000000000169A | R | [LLM] |
| ff0000000000169b | byte_FF0000000000169B | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a6d5 | StreamMagicNumberCheck | [LLM] |
| 00593c50 | sub_593C50 | [LLM] |
| 00593cfd | SEHGuardedFunctionPointerCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
