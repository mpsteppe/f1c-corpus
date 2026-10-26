## sub_5BC7A0_005bc7a0 — Reinit object, release prior child

**Summary:** Resets the object to its base representation: stores vtable off_729660 into dword 0, clears the child/secondary pointer at 0x4, and if a previous pointer existed calls its virtual slot +4 (release/destroy) on the old value. Combines object (re)initialization with cleanup of the previous sub-object.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | R | — | vtable pointer of the old child object at this+0x4 (read to dispatch slot +4) |
| this | 0x0 | RW | — | vtable pointer; overwritten with &off_729660 |
| this | 0x4 | RW | 0 | child/secondary object pointer; old value saved, then field cleared |

**Written-by note (persistence):**
- this 0x0: written unconditionally every call (constant vtable) — any poke is overwritten on the next call.
- this 0x4: written to 0 unconditionally every call — any poke is cleared on the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729660 | off_729660 | R | vtable pointer stored into this+0x0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** only branch is `if (v2)` on the saved old this[1]: non-null → tail-call its virtual method at vtable+4 (release/destructor) and return its result; null → skip the call and return this.
