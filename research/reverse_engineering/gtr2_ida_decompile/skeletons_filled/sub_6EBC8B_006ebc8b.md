## sub_6EBC8B_006ebc8b — C++ EH frame handler thunk (funcinfo forwarder)

**Summary:** Thunk that forwards to `__CxxFrameHandler`, passing the constant MSVC C++ exception-handling descriptor at `stru_7528D0` together with the received exception record, registration node, context and dispatcher context. Compiler-generated frame handler for one function's EH scope table.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007528d0 | stru_7528D0 | R | Constant exception-handling descriptor (`_s_FuncInfo`) for the owning function; read-only, passed to `__CxxFrameHandler` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| (none) | __CxxFrameHandler | MSVC runtime C++ exception dispatcher; performs the actual unwind/catch search |

**Guard conditions:** None in the thunk body — arguments are passed through unconditionally; all pass/block decisions on exception type, try level and catch matches are made inside `__CxxFrameHandler` using the `stru_7528D0` descriptor.
