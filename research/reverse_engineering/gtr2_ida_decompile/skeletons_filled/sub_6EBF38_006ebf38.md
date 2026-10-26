## sub_6EBF38_006ebf38 — C++ exception frame-handler thunk (__ehhandler)

**Summary:** Compiler-generated MSVC C++ exception-handler thunk: unconditionally forwards the exception record, registration node, context and dispatcher context to __CxxFrameHandler, passing the static exception data at stru_752BCC as the handler's first argument. This is the per-function SEH/C++ unwind dispatcher installed via the exception registration chain.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00752bcc | stru_752BCC | R | Static C++ exception data (scope/unwind table) passed by address as the handler's dispatch data to __CxxFrameHandler |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the body is a single unconditional tail call to __CxxFrameHandler; every invocation passes through (no field or value checks, no early return).
