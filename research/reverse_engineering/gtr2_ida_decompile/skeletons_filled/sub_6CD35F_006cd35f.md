## sub_6CD35F_006cd35f — unsigned ascending comparator

**Summary:** Minimal comparator returning -1/0/1 for unsigned a1 vs a2 in ascending order (a1 < a2 → -1, equal → 0, a1 > a2 → 1); the third parameter a3 is unused.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards; single branch: a2 <= a1 → returns (a2 < a1) (1 when a1 > a2, 0 when equal); a2 > a1 → returns -1. Parameter a3 ignored.
