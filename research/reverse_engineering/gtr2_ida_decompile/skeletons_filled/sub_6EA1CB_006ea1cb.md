## sub_6EA1CB_006ea1cb — CxxFrameHandler thunk (FuncInfo 0x750FB8)

**Summary:** MSVC C++ exception-handling thunk: forwards all EH dispatch arguments unconditionally to `__CxxFrameHandler` with the function's static FuncInfo descriptor at 0x750FB8. Generated compiler support code, not game logic.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00750fb8 | unk_750FB8 | R | MSVC `_s_FuncInfo` descriptor holding the EH unwind/try-block table for the owning function; passed as the first argument to `__CxxFrameHandler`. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; every call is passed straight through to `__CxxFrameHandler`. Callers (the OS/CRT unwinder) decide when to invoke it.
