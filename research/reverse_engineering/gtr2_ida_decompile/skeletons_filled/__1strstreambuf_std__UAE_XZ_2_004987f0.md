## ??1strstreambuf@std@@UAE@XZ_2_004987f0 — DerivedDestructor_ResetVtable_ClearGlobal

**Summary:** Destructor teardown: overwrites the object's vtable with off_6F80B0, runs the shared cleanup helper sub_4CF590, zeroes global dword_B6E070, then chains to sub_4D8780(this) for the remaining destruction work.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer slot — overwritten with off_6F80B0 at the start of destruction |

**Written-by note (persistence):**
- this 0x0: written once, unconditionally, during destruction; the object is being torn down, so an external poke here would be overwritten at destroy time and has no post-teardown meaning.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2848 | ??1strstreambuf@std@@UAE@XZ_2_SEH | R | SEH/unwind metadata entry associated with this destructor frame (exception bookkeeping, not data) |
| 006f80b0 | off_6F80B0 | R | vtable constant installed at this+0x0 — marks the dying object as its own class before chaining to the base teardown |
| 00b6e070 | dword_B6E070 | W | shared global state word cleared to 0 during teardown; other routines test it as an enable/handle flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf590 | sub_4CF590 | shared cleanup helper: releases the resource held in global dword_B6E198 and zeroes field this[67] |
| 004d8780 | sub_4D8780 | teardown forwarder invoked on this; jumps to sub_4D8787, which installs another vtable and continues object destruction |

**Guard conditions:** None — straight-line body, no branches. The vtable write, the global clear and the chained destructor call all execute unconditionally.
