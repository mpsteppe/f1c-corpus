## ShortComputation_f190_0041f190 — SessionDataValidationCheck

**Summary:** Validates a standings entry by checking a boolean from ShortComputation_f1e0 and verifying that a category-dependent field at derived offset (204 + v3*4) does not equal sentinel value 10 when more than 2 categories exist.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f1e0 | ShortComputation_f1e0 | Return boolean validation flag for the standings entry |
| 004c11d0 | FlagsGetter | Get number of scoring categories from standings node |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- `ShortComputation_f1e0(this)` must return true → PASSES: entry passes basic validation. BLOCKED: returns false.
- When `FlagsGetter` == 2: PASSES automatically (after basic validation).
- When `FlagsGetter` > 2: field at `this[v3 + 51]` must not equal 10 (sentinel/invalid value) → PASSES: valid. BLOCKED: value is 10.
