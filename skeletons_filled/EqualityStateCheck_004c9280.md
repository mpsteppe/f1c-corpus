## EqualityStateCheck_004c9280 — EqualityStateCheck

**Summary:** Compares a2 against state index (this+0x1C); if match, retrieves indexed field value and checks vtable+28 result != 2. Returns 1 only if all conditions pass.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | State index to compare against a2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9260 | StateIndexedFieldGetter | Returns indexed field value for current selector |

**Guard conditions:** Three sequential guards: (1) a2 must equal this+0x1C, else return 0. (2) StateIndexedFieldGetter result must be non-null, else return 0. (3) vtable+28 on that result must not equal 2, else return 0. Returns 1 only if all pass.
