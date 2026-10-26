## TripleVirtualCallDispatch_0047b1b0 — TripleVirtualCallDispatch

**Summary:** Dispatches three virtual calls in sequence: zeroes a field at offset 0x104, calls vtable+64(arg=0), vtable+44(this,1), then returns result of vtable+156(this).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual function at vtable offset 44 (index 11) — called as (this, 1) |
| obj | 0x40 | R | — | Virtual function at vtable offset 64 (index 16) — called as (0) |
| obj | 0x9C | R | — | Virtual function at vtable offset 156 (index 39) — return value is function result |
| this | 0x0 | R | — | Vtable pointer (read for virtual dispatch) |
| this | 0x104 | RW | 0 | DWORD field zeroed before virtual calls |

**Written-by note (persistence):**
- this 0x104: Written to 0 once; persists until modified externally

**Globals referenced:** None

**Functions called:** None (all via vtable dispatch)

**Guard conditions:** None — unconditional; all operations always execute.
