## sub_4FB1B0_004fb1b0 — teardown of embedded object

**Summary:** Two-step teardown shim: tears down/reset the embedded object at this+0x3C via sub_54B280, then tail-chains into the global cleanup helper sub_4094C0.

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
| 004094c0 | sub_4094C0 | global cleanup/finalize step, called with no arguments after the embedded object teardown |
| 0054b280 | sub_54B280 | destructor/reset of the embedded object at this+0x3C |

**Guard conditions:** None — both calls are unconditional, no field or literal is tested.
