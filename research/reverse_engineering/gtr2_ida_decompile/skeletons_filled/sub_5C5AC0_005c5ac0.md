## sub_5C5AC0_005c5ac0 — Lazy singleton getter (allocate-on-first-use)

**Summary:** Checks a cached pointer in this[2] (offset 0x8); if null, allocates a 12-byte object via operator new, runs its initializer, stores and returns it. Classic lazy-init accessor.

**Called by:** sub_5C6157 (005c6157)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | cached pointer to lazily created 12-byte object (this[2]) |

**Written-by note (persistence):**
- this 0x8: written once, conditionally — only when it is currently null. Once non-null it is never rewritten here; an external poke of 0 would force a fresh allocation on next call, any nonzero value would be returned as-is.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006eb1ab | SEH_5C5AC0 | R | SEH/exception-unwind metadata for this function (IDB-generated reference around the operator new call) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | operator new — allocates the 12-byte object |
| 00643d80 | unknown_libname_25 | initializer/constructor called on the freshly allocated object |

**Guard conditions:** `if (!this[2])` — if the cached pointer at offset 0x8 is zero, the allocation + init path runs; if already non-null, allocation is skipped and the existing pointer is returned immediately.
