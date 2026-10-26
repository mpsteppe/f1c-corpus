## MonitorsChangedSelection_00478220 — MonitorsChangedSelection

**Summary:** Queries game command dispatch interface (dword_7CD8C0) for current selection ID; compares against cached value at this[58]; updates and triggers vtable notification callback on change.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | field read from game dispatch result object |
| this | 0x0 | R | — | vtable pointer (method at +44 called on change) |
| this | 0xE8 | RW | — | cached selection ID updated when changed |

**Written-by note (persistence):**
- this 0xE8: updated when dispatch result differs from current value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** First: dispatch call result (v2) must be non-null (early return 0 if null). Second: this[58] must differ from v2+372 value to trigger update + notification (skips if same).
