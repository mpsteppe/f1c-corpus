## nullsub_121_004cccc0 — empty no-op stub

**Summary:** No-op/null stub function (IDA `nullsub`). The decompiler renders it as `return MK_FP(*(_WORD*)retaddr, *(_DWORD*)retaddr)()`, an artifact of a bare return; the routine performs no work and has no side effects. Typical filler / vtable placeholder.

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

**Guard conditions:** None — unconditional bare return; no fields or values checked, no code paths blocked.
