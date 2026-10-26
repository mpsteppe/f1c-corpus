## sub_6EE3D0_006ee3d0 — Read dword_B6CEA8, store to lParam, return it

**Summary:** Simple accessor: loads the global dword_B6CEA8, copies it into the global lParam, and returns the same value. Acts as a getter that also publishes the value through the lParam global (typical message/parameter staging).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6cea8 | dword_B6CEA8 | R | Source value read once — getter input |
| 00b6cee8 | lParam | W | Destination copy of dword_B6CEA8; serves as an exposed parameter/message word |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; always reads dword_B6CEA8 and always writes lParam before returning.
