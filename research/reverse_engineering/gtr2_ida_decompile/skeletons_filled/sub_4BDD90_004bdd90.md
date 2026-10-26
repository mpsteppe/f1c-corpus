## sub_4BDD90_004bdd90 — set byte flag at 0x13C to 1

**Summary:** Trivial setter: writes byte value 1 to `this + 0x13C`. No reads, no calls — likely sets a boolean state/flag on the object.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13C | RW | 1 | Boolean state flag byte; unconditionally set to 1 |

**Written-by note (persistence):**
- this 0x13C: written unconditionally each call — a set-only flag; an external poke to 0 would survive until this setter (or another writer of 0x13C) runs again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional single-byte store.
