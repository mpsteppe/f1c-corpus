## sub_6EBAC5_006ebac5 — C++ EH frame handler thunk (funcinfo forwarder)

**Summary:** Thunk that forwards to `__CxxFrameHandler`, passing the constant MSVC C++ exception-handling `_s_FuncInfo` descriptor at `unk_752698` together with the received exception record, registration node, context and dispatcher context. Compiler-generated frame handler for one function's EH scope table.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00752698 | unk_752698 | R | Constant `_s_FuncInfo` exception-handling descriptor (try-level / catch / unwind tables) for the owning function; read-only, passed to `__CxxFrameHandler` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| (none) | __CxxFrameHandler | MSVC runtime C++ exception dispatcher; performs the actual unwind/catch search |

**Guard conditions:** None in the thunk body — arguments are passed through unconditionally; all pass/block decisions on exception type, try level and catch matches are made inside `__CxxFrameHandler` using the `unk_752698` descriptor.
