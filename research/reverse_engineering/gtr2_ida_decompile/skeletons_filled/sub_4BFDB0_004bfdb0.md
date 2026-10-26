## sub_4BFDB0_004bfdb0 — destructor: resets vtable, cleans sub-object, frees +0x258 buffer

**Summary:** Destructor body: overwrites the object vtable with off_711490, runs cleanup on the embedded sub-object at this+0x260 (this+152 dwords), frees the owned buffer at offset 0x258, then returns the result of the final chain cleanup call.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vtable pointer; overwritten with off_711490 by this destructor |
| this | 0x258 | R | — | Owned heap pointer (this[150]); freed with j_j__free if non-null |

**Written-by note (persistence):**
- this 0x0: written by the destructor once per destruction (vtable re-install). An external poke survives until this destructor runs, then is overwritten; not a per-frame recalculated field.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00711490 | off_711490 | R | Vtable/offset-table pointer stored to object offset 0 by the destructor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ed50 | sub_41ED50 | Cleanup/destructor call on the embedded sub-object at this+0x260 (this+152 dwords) |
| 006308d8 | j_j__free | CRT free wrapper; releases the buffer owned at +0x258 |

**Guard conditions:** `if (this[150] != 0)` — the 0x258 buffer is freed only when non-null; a null pointer skips the free. No other branches: vtable store and sub-object cleanup always run, and the final chain call is always made.
