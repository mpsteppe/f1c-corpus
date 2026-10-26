## sub_5FDD80_005fdd80 — Unregister object from one of three lists

**Summary:** Given an object pointer a2, dispatches it to the list that currently holds it (main list at +0x294 or one of two secondary lists at +0x2A4/+0x2B4) and removes it from that list via sub_5DB730; returns 0 unconditionally when a2 is nonzero.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x294 | R | — | head of linked list traversed to locate a2 (read as this[165]) |
| this | 0x298 | R | — | next-node pointer read while walking the 0x294 list (v3[1]) |
| this | 0x29C | R | — | unknown — no clearly identifiable use visible in this function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059d540 | sub_59D540 | membership/contains test on a list; nonzero result means a2 is present |
| 005db730 | sub_5DB730 | remove a2 from the given list (called with flag 1 for search-and-remove semantics) |
| 005fdbd0 | sub_5FDBD0 | first helper run with a2 as receiver and this as argument; detaches/normalizes a2's association with this before list search |

**Guard conditions:** If `a2 == 0` the function returns 0 immediately (no-op). Otherwise the list at +0x294 is walked; a matching entry (`*v3 == a2`) PASSES to immediate removal via sub_5DB730(this+165, a2, 1). Only when the 0x294 list is empty/exhausted are the two fallback lists tested: `sub_59D540(this+169, a2)` is checked first and short-circuits; if it fails, `sub_59D540(this+173, a2)` is checked. Whichever list reports membership gets the sub_5DB730 removal. Not being present in any list is not an error — the function still returns 0.
