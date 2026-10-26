## sub_5C5BB0_005c5bb0 — vtable pointer initializer (constructor stub)

**Summary:** Writes a function-table pointer into the object's first word, then immediately overwrites it with a second one (final value from the second store). Typical constructor stub that installs the final class vtable.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | object vptr — receives two successive pointer stores (second wins) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at construction time (twice; the second write wins). External pokes to the vptr do not survive re-construction; nothing here recalcs it later.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072a1e8 | off_72A1E8 | R | function/vtable pointer loaded and stored into this[0] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — both stores execute unconditionally, no branches.
