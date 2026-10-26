## __check_overflow_exit_00638495 — Overflow-check exit tail-jump stub

**Summary:** Trivial CRT helper that unconditionally tail-jumps to the shared overflow-handling code at 0x6384BD; part of the floating-point conversion exit path.

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

**Guard conditions:** None — the body is a single unconditional `JUMPOUT(0x6384BD)`; no value is tested and no path is blocked. Control always transfers to the overflow handler fragment at 0x6384BD.
