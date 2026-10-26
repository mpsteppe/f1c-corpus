## VTableDispatchWithFieldCheck_00541670 — Dispatch vtable call with guard check

**Summary:** Checks guard flag at 0x13D8, then calls virtual function at vtable+0xC8 on the object at 0x1100 with parameter 139 and a2. Stores result in this[0].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DPositionSetWithUIRefresh (00543800)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xC8 | R | — | vtable offset 200 (0xC8) — dispatch function |
| this | 0x0 | RW | — | stores result of vtable call |
| this | 0x1100 | R | — | pointer to vtable-bearing object |
| this | 0x13D8 | R | — | guard flag; must be non-zero to proceed |

**Written-by note (persistence):**
- this 0x0: written on every successful call (result of vtable dispatch); overwritten each invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x13D8] (guard flag) must be non‑zero. If zero, vtable call is skipped — returns 0 directly.
