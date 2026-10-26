## sub_6EF9F0_006ef9f0 — Tail-call jump thunk to 0x484150

**Summary:** Trivial thunk with no body of its own: it unconditionally transfers control to 0x484150 (decompiled as `JUMPOUT(0x484150)`). Likely an alias/fixup entry in a function table that forwards into the real implementation.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6cf20 | unk_B6CF20 | R | unknown (reference not visible in the JUMPOUT-only decompiled body) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the thunk contains an unconditional jump to 0x484150. Nothing is checked; every entry passes straight through to the target.
