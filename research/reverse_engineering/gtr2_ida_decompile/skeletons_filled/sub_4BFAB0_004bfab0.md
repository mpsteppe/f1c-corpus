## sub_4BFAB0_004bfab0 — thunk forwarding `this` to destructor body

**Summary:** Pure forwarding thunk: passes the object pointer as `this` to the destructor body and returns its result. No logic of its own.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional `this`-forwarding call; nothing checked or blocked.
