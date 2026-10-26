## TLSValueRetrievalWithInit_0058e0c7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TLSFieldSetter (005884e0), RandLCGRandomNumberGenerator (005884ed), sub_5897CA (005897ca), SEHExceptionHandlerTrampolineSetup (0058a42f), TLSOffsetGetter (0058afcf), TLSOffsetGetter_afd8 (0058afd8), sub_592787 (00592787), sub_592924 (00592924), sub_5934E1 (005934e1), FontGlyphRender (00593694), SEHWrapperAroundCRTFunctionCall (005938b4), SEHWrapperDispatchingToHandlerFunction (00593c9c), sub_597388 (00597388)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e14c | TlsGetValue | R | [LLM] |
| 0059e150 | SetLastError | R | [LLM] |
| 0059e158 | TlsSetValue | R | [LLM] |
| 0059e15c | GetCurrentThreadId | R | [LLM] |
| 0059e188 | GetLastError | R | [LLM] |
| 005e6d40 | dwTlsIndex | R | TlsIndex [DERIVED] (also: ` — TLS index (used by FUN_0058e0c7) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | [LLM] |
| 0058ab58 | sub_58AB58 | [LLM] |
| 0058e0b4 | TwoFieldInitializer_e0b4 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
