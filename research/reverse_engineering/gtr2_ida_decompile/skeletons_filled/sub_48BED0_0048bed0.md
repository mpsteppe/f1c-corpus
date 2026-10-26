## sub_48BED0_0048bed0 — shutdown/reset routine (helper call + global clear)

**Summary:** Calls sub_4CF590 (a global cleanup/reset routine), then writes 0 to the global dword at 00B6E070, and returns 1 (success). A small teardown/reset step, likely a keyed callback or state-reset entry.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6e070 | dword_B6E070 | W | Global state/handle zeroed after the cleanup call |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf590 | sub_4CF590 | Cleanup/reset work performed before the global is cleared |

**Guard conditions:** None. Straight-line: cleanup call, global clear, return 1.
