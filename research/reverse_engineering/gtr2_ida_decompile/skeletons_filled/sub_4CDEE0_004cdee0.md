## sub_4CDEE0_004cdee0 — ClearFlagThenNotifyList

**Summary:** Clears byte flag 0x11A, then — unless the virtual predicate at vtable+0x94 returns nonzero — walks the linked list headed at 0xFC and calls sub_4E3B60(this, 0) once per node. Always returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xFC)+0x18) | 0x18 | R | — | Next-pointer of each list node (node offset 0x18) used to iterate the list headed at 0xFC |
| obj | 0x94 | R | — | Virtual predicate (vtable+0x94); a nonzero result aborts the list walk early |
| this | 0x0 | R | — | Vtable pointer used to reach the vtable+0x94 predicate |
| this | 0xFC | R | — | Head pointer (this[63]) of the linked list that gets visited |
| this | 0x11A | RW | 0 | Byte flag cleared at function entry |

**Written-by note (persistence):**
- this 0x11A: Written unconditionally to 0 at entry on every call — an external poke would be overwritten by the next invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e3b60 | sub_4E3B60 | Per-node callback invoked as sub_4E3B60(this, 0) for every node in the list |

**Guard conditions:** this[0x11A] is cleared first, unconditionally. Then: if virtual(vtable+0x94)() != 0 → BLOCKED, returns 0 without touching the list. If it returns 0 → PASS, iterate i = this[0xFC]; while i != 0: call sub_4E3B60(this, 0), i = *(i+0x18). Function returns 0 in all cases.
