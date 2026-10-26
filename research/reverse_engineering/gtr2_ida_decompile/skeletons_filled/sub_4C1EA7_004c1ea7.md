## sub_4C1EA7_004c1ea7 — dispatch thunk for virtual method id 27

**Summary:** Helper thunk that tests object `a1` for support of method id 27 via `sub_4BFDE0`; if supported it dispatches the object's virtual function at vtable offset 28 with id 27, otherwise it tail-calls fallback `sub_4CC3A1` with the original argument `a2`.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | argument/parameter area of the pass-through (accessed on the fallback path) |
| this | 0x0 | R | — | object's vtable pointer (first dword), source of the virtual method at offset 28 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bfde0 | sub_4BFDE0 | probes/validates whether object `a1` handles method id 27; nonzero result enables the virtual dispatch |
| 004cc3a1 | sub_4CC3A1 | fallback handler invoked with the original argument `a2` when the object does not handle method id 27 |

**Guard conditions:** Guard is `sub_4BFDE0(a1, 27) != 0`. PASS (nonzero): calls the virtual method `(*(*a1 + 28))(a1, 27)` and returns its result. BLOCKED (zero): skips the virtual call and returns `sub_4CC3A1(a2)` instead.
