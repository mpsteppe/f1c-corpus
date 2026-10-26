## sub_4BE0B6_004be0b6 — EFLAGS save/restore thunk

**Summary:** Decompiler-visible behavior: reads the caller's EFLAGS via `__getcallerseflags()`, writes them straight back with `__writeeflags()`, then returns the result of `nullsub_25()` — effectively a flags-preserving tail call/thunk artifact.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0053a071 | dword_53A071 | R | unknown — not visible as an explicit access in the decompiled C; tied to the intrinsic/control-flow artifact sequence |
| 016c6f08 | dword_16C6F08 | R | unknown — not visible as an explicit access in the decompiled C; tied to the intrinsic/control-flow artifact sequence |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — get/write EFLAGS and the tail call occur unconditionally; no values are tested.
