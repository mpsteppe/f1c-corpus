## sub_6E94AB_006e94ab — C++ exception frame handler thunk

**Summary:** Thin MSVC C++ exception-handling wrapper that forwards its four arguments straight to `__CxxFrameHandler`, supplying a module exception func-info table. Runtime support glue, not game logic.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007500c8 | unk_7500C8 | R | `_s_FuncInfo` exception-handling descriptor table passed to `__CxxFrameHandler` (scope/unwind metadata) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the function has no branches; all four arguments (exception record, registration node, context, dispatcher context) are unconditionally forwarded to `__CxxFrameHandler`, which performs the actual scope-table lookup and unwinding.
