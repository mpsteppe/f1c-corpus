## __get_lc_time_00639919 — Locale time-format string loader

**Summary:** CRT locale initializer that populates a time-locale structure with the ~46 localized strings (day names, month names, AM/PM markers, time formats) by calling the locale-string loader for each string ID and OR-ing the per-load status; stores the locale identifier at offset 0xAC.

**Called by:** ___init_time (00639e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | RW | — | Destination for the locale identifier value v46 (zero-extended word_FB8420), written after all string loads complete |

**Written-by note (persistence):**
- this 0xAC: written unconditionally on every call (after the string-load chain), from the current word_FB8420 value; an external poke is overwritten the next time the time locale is re-initialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb841e | word_FB841E | R | Locale identifier passed to the string loader as the locale argument for the bulk of the string IDs (days, months, time formats) |
| 00fb8420 | word_FB8420 | R | Second locale identifier used for the final three string loads and stored into this+0xAC |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006422f4 | sub_6422F4 | Locale string loader called once per string ID (31–79, 4099, 4105); first argument is 1 for the bulk of the loads and 0 for the final load (distinct flag value); returns a status that is OR-accumulated |

**Guard conditions:** If `a1 == 0` (NULL destination structure) → returns -1 immediately. Otherwise all string loads are executed unconditionally and their return values OR-ed together; the final result is that OR combined with the last load's status.
