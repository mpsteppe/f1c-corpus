## sub_5E4DF0_005e4df0 — set pair of values (0x30C, 0x310)

**Summary:** Minimal setter that stores the two incoming integers into adjacent DWORD fields of `this` (0x30C and 0x310) and returns the first argument. A plain accessor-pair write.

**Called by:** sub_411100 (00411100), sub_51F480 (0051f480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30C | RW | — | first value destination (DWORD index 195) receiving argument a2; value also returned |
| this | 0x310 | RW | — | second value destination (DWORD index 196) receiving argument a3 |

**Written-by note (persistence):**
- this 0x30C: written unconditionally on every call from argument a2 — an external poke survives only until the next call.
- this 0x310: written unconditionally on every call from argument a3 — an external poke survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; both fields are stored unconditionally and a2 is returned.
