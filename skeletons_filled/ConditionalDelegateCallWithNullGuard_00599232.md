## ConditionalDelegateCallWithNullGuard_00599232 — DelegateCallWithNullGuard

**Summary:** Calls delegate function via pointer at this+0x50. Returns this on success, 0 if delegate is NULL or call fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | delegate/target function pointer or object to call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059bb00 | sub_59BB00 | delegate call — takes target pointer, a2, 0, a3; returns 0 on success |

**Guard conditions:** if this+0x50 is NULL → return 0 immediately. If sub_59BB00 returns non-zero (failure) → return 0. Otherwise return this.
