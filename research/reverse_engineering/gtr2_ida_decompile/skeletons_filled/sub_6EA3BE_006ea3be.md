## sub_6EA3BE_006ea3be — CxxFrameHandler thunk (FuncInfo 0x7510E4)

**Summary:** MSVC C++ exception-handling thunk: forwards all EH dispatch arguments unconditionally to `__CxxFrameHandler` with the function's static FuncInfo descriptor at 0x7510E4. Generated compiler support code, not game logic.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007510e4 | unk_7510E4 | R | MSVC `_s_FuncInfo` descriptor holding the EH unwind/try-block table for the owning function; passed as the first argument to `__CxxFrameHandler`. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; every call is passed straight through to `__CxxFrameHandler`. Callers (the OS/CRT unwinder) decide when to invoke it.
