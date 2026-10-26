## SEHExceptionHandlerTrampolineSetup_0058a42f — SEHTrampolineBuilder

**Summary:** Builds an SEH exception handler trampoline structure with callback (RenderStateSetupWithFlagChecks), parameters, and link to current exception chain. Retrieves TLS handler and dispatches via vtable offset +104.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontGlyphRender (00593694)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | TLS index value used to retrieve thread-local handler |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058a4b7 | loc_58A4B7 | R | Continuation/landing pad address stored in trampoline |
| 0058a4e5 | RenderStateSetupWithFlagChecks | R | Callback function pointer stored in trampoline |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058e0c7 | TLSValueRetrievalWithInit | Get thread-local storage value and initialize trampoline structure |

**Guard conditions:** Checks v13 (0x0 at init, modified by trampoline callback): if non-zero after callback, re-links exception list (Next = Next). Always returns v11 (1 = success, 0 = exception occurred).
