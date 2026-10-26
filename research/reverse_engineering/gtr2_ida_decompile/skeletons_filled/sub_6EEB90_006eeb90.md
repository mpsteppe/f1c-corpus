## sub_6EEB90_006eeb90 — Forwarder to sub_40C2A0 with dword_91BE58

**Summary:** Tiny wrapper that calls sub_40C2A0 with the value of the global dword_91BE58 and returns its result. Likely a shim exporting a helper operation bound to that global argument.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091be58 | dword_91BE58 | R | Argument value read and passed to sub_40C2A0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional call to sub_40C2A0; no checks or branches.
