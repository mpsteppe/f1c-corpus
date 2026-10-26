## MultiStageVTableDispatch_00487e70 — Multi-stage validated dispatch with dual field read

**Summary:** Reads two DWORD values via DualFieldRead from this+0x40, validates UI value, calls vtable+48 with both values for processing, validates via vtable+156, then traverses linked list with callback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x30 | R | — | first value read by DualFieldRead for vtable+48 dispatch |
| obj | 0x9C | R | — | second value read by DualFieldRead for vtable+48 dispatch |
| this | 0x0 | R | — | vtable pointer for virtual dispatch calls (offsets 48, 156) |
| this | 0x40 | R | — | base pointer passed to DualFieldRead for reading two values |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486630 | LinkedListTraversalWithCallback | traverses linked list with callback after all validations pass |
| 004874e0 | UIValueValidator | validates current UI value, returns non-zero if valid |
| 00498880 | DualFieldRead | reads two DWORD fields from object at offset this+0x40 |

**Guard conditions:** UIValueValidator returns 0 — BLOCKS and returns -1. Vtable+48 returns 0 — BLOCKS and returns -1 (processing failure). Vtable+156 returns non-zero — BLOCKS and returns -1 (validation failure). All three must pass to reach LinkedListTraversalWithCallback.
