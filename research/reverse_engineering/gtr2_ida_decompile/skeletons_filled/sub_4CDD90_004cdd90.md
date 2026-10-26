## sub_4CDD90_004cdd90 — ConditionalFlaggedQuery

**Summary:** Trivial gate: when flag 0xF4 is set it forwards to sub_4E29F0(0) and returns that result; when the flag is clear it returns 0. Likely a guarded query of some external/global state.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF4 | R | — | Flag (this[61]); only when nonzero is the sub_4E29F0 query performed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e29f0 | sub_4E29F0 | Query function invoked with constant 0; its return value is propagated (exact semantics unknown) |

**Guard conditions:** this[0xF4] != 0 → PASS: returns sub_4E29F0(0). this[0xF4] == 0 → BLOCKED: returns 0 without calling anything.
