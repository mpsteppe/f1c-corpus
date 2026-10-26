## UtilityFunction_7e10_00487e10 — Validated dispatch with pointer toggle

**Summary:** Validates UI value, sets state to 1, handles radio/check state, toggles a pointer value (0↔1) via vtable+172, validates via vtable+152, then finalizes via sub_486600.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x98 | R | — | validation check value read via vtable+152 for secondary validation |
| obj | 0xAC | R | — | value toggled via vtable+172 returned pointer (0 becomes 1, non-zero becomes 0) |
| this | 0x0 | R | — | vtable pointer for virtual dispatch calls |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486600 | sub_486600 | finalizes computation after all validations pass |
| 00487260 | sub_487260 | sets handler state to valid (1) |
| 00487460 | UIRadioCheckStateChangeHandler | manages radio/check button state with string validation |
| 004874e0 | UIValueValidator | validates current UI value, returns non-zero if valid |

**Guard conditions:** UIValueValidator(this) returns 0 — BLOCKS and returns -1 (early failure). v2 (from vtable+172) == NULL — skips value toggle. Vtable+152 returns non-zero — BLOCKS and returns -1 (secondary validation fails).
