## sub_4CC3A1_004cc3a1 — ESI-argument identity return (factory fallback target)

**Summary:** Trivial function that returns the value passed in the ESI register unchanged and ignores its stack argument. It serves as the fallback target invoked as `sub_4CC3A1(0)` by the 0x114-byte object factories when allocation fails.

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

**Guard conditions:** None — no branches. Returns a1 (ESI) unconditionally; the stack argument a2 has no effect on the result. Decompiler flags a positive sp value, consistent with the register-based (`__userpurge`) calling convention.
