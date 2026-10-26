## ?_JumpToContinuation@@YGXPAXPAUEHRegistrationNode@@@Z_00630b06 — _JumpToContinuation (EH continuation invoker)

**Summary:** MSVC C++ exception-handling helper: calls the supplied continuation function a1, passing the continuation pointer itself and the EH registration node a2. Invoked by ?CatchIt to hand control to a handler continuation with the current registration state.

**Called by:** ?CatchIt@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@PBU_s_HandlerType@@PBU_s_CatchableType@@PBU_s_TryBlockMapEntry@@H1E@Z (006362a7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional indirect call `a1(a1, a2)`: the continuation pointer is passed as both the function and its first argument, followed by the registration node. No values checked; nothing skipped or blocked.
