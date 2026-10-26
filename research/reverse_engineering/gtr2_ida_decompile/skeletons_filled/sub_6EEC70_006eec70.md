## sub_6EEC70_006eec70 — Wrapper forwarding &byte_B64150 to sub_431AF0

**Summary:** Thin wrapper with no logic of its own: it takes the address of the global byte_B64150 and passes it to sub_431AF0, then returns. Likely a callback/dispatch trampoline that routes work on that global object to a shared handler.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b64150 | byte_B64150 | R | Address is taken and handed to sub_431AF0; the callee receives a pointer to this global object/state. Concrete semantics unknown; the R flag reflects only the pointer load. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call, no branches; every invocation passes &byte_B64150 to sub_431AF0.
