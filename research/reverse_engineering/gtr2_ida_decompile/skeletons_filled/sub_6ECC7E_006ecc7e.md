## sub_6ECC7E_006ecc7e — C++ exception frame-handler thunk (__ehhandler)

**Summary:** Compiler-generated MSVC C++ exception-handler thunk: unconditionally forwards the exception record, registration node, context and dispatcher context to __CxxFrameHandler, passing the static exception data at unk_7537F4 as the handler's function-info argument. Serves as the SEH/C++ unwind dispatcher registered for its owning function.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007537f4 | unk_7537F4 | R | Static C++ exception data (_s_FuncInfo/scope table) passed by address as dispatch data to __CxxFrameHandler |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional tail call to __CxxFrameHandler; all invocations pass through, no value checks or early return.
