## sub_4CE0E0_004ce0e0 — SetProgressCounter

**Summary:** Plain setter: stores the argument into the counter dword at 0x10C (this[67]) and returns it. Same field advanced/clamped by sub_4CDF40 / sub_4CDE30.

**Called by:** sub_4B3290 (004b3290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10C | RW | — | Counter this[67] overwritten with the caller-supplied value a2 |

**Written-by note (persistence):**
- this 0x10C: Written unconditionally with a2 on every call — an external poke would be overwritten by the next invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional store (this[0x10C] = a2) and returns a2. No branches, nothing blocked.
