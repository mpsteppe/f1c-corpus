## sub_48FAB0_0048fab0 — Previous-year results table import (Drivers × Times pairs)

**Summary:** Season/result-data importer: resolves the `PrevYear` section (via `sub_53A250(0)`) and requires the `PrevYear`, `Grid`, `Drivers` and `Times` entries; when the `Drivers` and `Times` counts are equal it walks them index by index, concatenates each driver name and time string with `sprintf` and appends one result row per pair via `sub_4D93B0(buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1)`.

**Called by:** sub_4A2DF0 (004a2df0), sub_4A2E00 (004a2e00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2d8c | aSSS_1 | R | Format string `"%s%s%s"` used to join the two strings in `Buffer` |
| 006faff0 | aTimes_0 | R | Config entry key `"Times"` looked up via `sub_616630` (time strings list) |
| 006faff8 | aDrivers_0 | R | Config entry key `"Drivers"` looked up via `sub_616630` (driver-name list) |
| 006fb000 | aGrid_0 | R | Config entry key `"Grid"` looked up via `sub_616630` (required section presence gate) |
| 006fb008 | aPrevyear | R | Config entry key `"PrevYear"` looked up via `sub_616630` (previous-year data presence gate) |
| 00be1cfd | unk_BE1CFD | R | Context object passed to `sub_53A250(0)` to resolve the season/section |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d380 | sub_48D380 | Extracts the string payload from an entry (used for both the time and driver entry) |
| 004ce140 | sub_4CE140 | Registers/reads the result-set context against `this` and `&v14` |
| 004d0ac0 | sub_4D0AC0 | Initializes the result-row context (`v10`) before rows are appended |
| 004d93b0 | sub_4D93B0 | Appends one result row from `Buffer` (all remaining args 0, trailing -1, -1, -1, -1) |
| 0053a250 | SeasonRacesSectionFinder [structural] | Finds the season section (`sub_53A250(0)`); 0 → no import |
| 006165f0 | LinkedListCount [exact] | Returns the entry count of a located list (used for both `Times` and `Drivers`) |
| 00616610 | sub_616610 | Returns the i-th entry of a list (`v5` index) for both lists |
| 00616630 | sub_616630 | Looks up a named entry (`"PrevYear"`, `"Grid"`, `"Drivers"`, `"Times"`) |
| 00631761 | _sprintf | Formats `Buffer` as `"%s%s%s"` from driver string, an empty/zero string `v11`, and time string |

**Guard conditions:** Progressive short-circuit chain — any failure returns immediately with `result` 0: (1) `sub_53A250(0)` == 0 → return; (2) `sub_616630("PrevYear")` == 0 → return; (3) `sub_616630("Grid")` == 0 → return; (4) `sub_616630("Drivers")` == 0 → return; (5) `sub_616630("Times")` == 0 → return. Then `sub_6165F0(Times) == sub_6165F0(Drivers)` required — unequal counts block the whole loop (nothing imported). Loop runs while `v5 < sub_6165F0(Drivers)`; per iteration both `sub_616610(v5)` lookups are null-checked before `sprintf`; the row append `sub_4D93B0` is called unconditionally within the loop body.

**String literals referenced (deterministic):**

- `Times`
- `Drivers`
- `Grid`
- `PrevYear`
