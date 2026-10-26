## UtilityFunction_d1a0_0048d1a0 — ListIndexStep

**Summary:** Steps list target index forward (a2==1) or backward (a2!=1), wraps within [0, count-1], sets direction flag at this+0x33C. Calls vtable[11] update then vtable[47] dispatch with new index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | VTable entry 11 (offset 44) — update callback after index change |
| obj | 0xBC | R | — | VTable entry 47 (offset 188) — action dispatch with new index |
| this | 0x0 | R | — | VTable pointer (to read vtable entries) |
| this | 0x328 | R | — | Item count (this[202]) — max index is count - 1 |
| this | 0x338 | RW | v4 | Target index (this[206]) — incremented/decremented with wrap |
| this | 0x33C | RW | a2==1 | Direction byte flag — 1 for forward, 0 for backward |

**Written-by note (persistence):**
- this 0x338: updated with new target index each call. Persists.
- this 0x33C: set to (a2==1) each call. Persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early return guards. Index wraps: if new index < 0 → set to last (count-1). If new index > count-1 → set to 0. Both vtable calls execute unconditionally.
