## sub_4CE5F0_004ce5f0 — Virtual dispatch wrapper (vtable+0xA4)

**Summary:** Forwards this plus four integer arguments to the virtual method at vtable offset 0xA4, then returns a constant 0. Thin call-through/notification helper.

**Called by:** sub_4949C0 (004949c0), sub_49CF90 (0049cf90), sub_4A75E0 (004a75e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA4 | R | — | vtable slot (function pointer) for the virtual method this wrapper dispatches to |
| this | 0x0 | R | — | Object vtable pointer used to locate slot +0xA4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the virtual call always executes; the function simply returns 0 afterward.
