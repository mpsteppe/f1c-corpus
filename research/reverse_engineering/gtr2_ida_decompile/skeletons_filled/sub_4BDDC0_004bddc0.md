## sub_4BDDC0_004bddc0 — virtual dispatch: call vtable slot +0x28 with 0

**Summary:** Loads the vtable pointer from `this[0]` and invokes the virtual function at vtable offset 0x28, passing `(this, 0)`. Likely a thin wrapper/thunk forwarding to a virtual method (e.g. reset/disable-style call with argument 0).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x28 | R | — | Virtual function pointer slot (vtable index 10); invoked with args `(this, 0)` |
| this | 0x0 | R | — | C++ vtable/class pointer slot; read to reach the virtual method |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — the virtual method is dispatched unconditionally with constant argument 0; no null check on `this[0]`.
