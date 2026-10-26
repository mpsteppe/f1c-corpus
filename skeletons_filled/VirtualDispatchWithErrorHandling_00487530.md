## VirtualDispatchWithErrorHandling_00487530 — Validated virtual dispatch with error return

**Summary:** Orchestrates UI value validation, state setup, radio/check state handling, and a secondary virtual validation via vtable+152; returns -1 on any validation failure, 0 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x98 | R | — | validation check value; read via vtable+152 for secondary validation |
| this | 0x0 | R | — | vtable pointer used for virtual dispatch (offset 152) |

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

**Guard conditions:** UIValueValidator(this) returns 0 — BLOCKS and returns -1 (early failure). Vtable+152 returns non-zero — BLOCKS and returns -1 (secondary validation fails).
