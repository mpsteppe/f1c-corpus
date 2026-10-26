## nullsub_115_004ccca8 — empty no-op stub

**Summary:** No-op/null stub function (IDA `nullsub`). The decompiler renders it as `return MK_FP(*(_WORD*)retaddr, *(_DWORD*)retaddr)()` on the word at the return address, but the routine is a bare stub with no observable behavior — it simply returns. Typical filler / vtable placeholder with no side effects.

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
