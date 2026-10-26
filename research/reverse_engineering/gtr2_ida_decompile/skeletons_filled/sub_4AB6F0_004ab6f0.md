## sub_4AB6F0_004ab6f0 — Driving school .dst initializer

**Summary:** Loads the selected driving-school description file (`%s%s.dst`), reads its `DrivingSchool`/`Track`/`Car`/`Filter` entries and updates global track/vehicle/filter state; stores the filter text plus list counters into the object at offsets 0x254–0x267.

**Called by:** sub_4AB950 (004ab950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x254 | RW | 0 | list/count value cleared unconditionally, then set from sub_41DA80() when a `Filter` entry exists |
| this | 0x258 | RW | 0 | second list/count value cleared unconditionally, then set from sub_41DA80() when a `Filter` entry exists |
| this | 0x25C | RW | — | result of enumerating `%s*.ds` files (sub_615D30), set only inside the `Filter` branch |
| this | 0x260 | RW | 0 | filter string buffer (copied with a 7-char limit by sub_630FE0) |
| this | 0x267 | RW | 0 | terminating byte after the filter string buffer |

**Written-by note (persistence):**
- this 0x254: written on every call — zero first, then overwritten only if the loaded file has a `Filter` entry. Survives until the next call; not a per-frame recalc.
- this 0x258: same as 0x254 (zeroed, conditionally refilled from the `Filter` branch).
- this 0x25C: zeroed state is not reset explicitly — only written inside the `Filter` branch; retains its previous value if no `Filter` entry exists.
- this 0x260: filter string rewritten only when a `Filter` entry exists (bounded copy + explicit terminator).
- this 0x267: the byte after the bounded copy is explicitly set to 0 (string termination) only in the `Filter` branch.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e29fb | SEH_4AB6F0 | R | SEH scope record for the function |
| 006f16bc | WindowName | R | fallback base path/name string when the global path pointer is null |
| 006f2da4 | aSDs | R | `*.ds` search pattern suffix (driving-school data files) |
| 006f3b04 | aTrack | R | `Track` config entry name |
| 006fd550 | aFilter_0 | R | `Filter` config entry name |
| 006fd558 | aDrivingschool | R | `DrivingSchool` config entry name |
| 006ff7a8 | aAndSimFull | R | `AND: SIM_FULL` filter spec string for the vehicle selection |
| 006ff7b8 | off_6FF7B8 | R | pointer to config entry name used to fetch the car/vehicle list |
| 006ff7bc | aSSDst | R | `%s%s.dst` path format |
| 0091cac8 | dword_91CAC8 | R | pointer to the global data-directory path string (null → WindowName) |
| 00b6f708 | dword_B6F708 | R | unknown global (not identifiable from the visible code) |
| 00b6f740 | dword_B6F740 | R | unknown global (not identifiable from the visible code) |
| 00b761ec | dword_B761EC | R | unknown global (not identifiable from the visible code) |
| 00be1bd0 | dword_BE1BD0 | W | stores the vehicle-selection result returned by sub_53A0E0 |
| 00be1cdc | unk_BE1CDC | R | global vehicle-list object passed to sub_53AE90 / sub_538790 |
| 00be1ce0 | unk_BE1CE0 | R | global filter object passed to sub_53BDE0 / sub_539FF0 / sub_53A0E0 |
| 00be1cfd | unk_BE1CFD | R | global track object passed to sub_538860 |
| 00faec84 | byte_FAEC84 | R | unknown global (not identifiable from the visible code) |
| 00faecbc | dword_FAECBC | R | file-enumeration context used by sub_615FC0 / sub_615FE0 / sub_615D30 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d810 | sub_41D810 | sprintf-style formatting (`%s%s.dst`, `%s*.ds`) into bounded buffers |
| 0041da80 | sub_41DA80 | produces a list/count value stored into this+0x254 and this+0x258 |
| 0048d380 | sub_48D380 | returns the string value stored in a config node |
| 00538790 | sub_538790 | returns a pointer to the parsed vehicle list held in unk_BE1CDC |
| 00538860 | sub_538860 | initializes the track object from a name string + extra context |
| 00539ff0 | sub_539FF0 | finalizes the vehicle filter object (unk_BE1CE0) |
| 0053a0e0 | sub_53A0E0 | returns the count/result of the prepared vehicle filter (stored in dword_BE1BD0) |
| 0053a160 | AIW [structural] | AIW-related update called with 0 after a track name is applied |
| 0053ae90 | sub_53AE90 | loads/parses the vehicle list (from the node string) into unk_BE1CDC |
| 0053bde0 | sub_53BDE0 | sets the filter constraint string (`AND: SIM_FULL` / `Car`) on unk_BE1CE0 |
| 00615860 | StringCopyWithBufferRealloc [structural] | assigns a string through the global string helper (name/path storage) |
| 00615d30 | ShortComputation_5f70 [exact] | counts entries in the enumeration context (stored at this+0x25C) |
| 00615fc0 | sub_615FC0 | resets/clears the file-enumeration context |
| 00615fe0 | sub_615FE0 | starts wildcard file enumeration (`%s*.ds`) with recursive flag 0 |
| 00616630 | sub_616630 | config node lookup by name |
| 00616840 | FileStreamReader [structural] | opens/reads the .dst config file for the given path |
| 00616960 | sub_616960 | releases/closes a config node returned by the reader |
| 00616f90 | sub_616F90 | selects the loaded file context by name (Buffer, 0) |
| 006308d8 | j_j__free | frees heap blocks allocated during node/reader processing (paired with operator new; not visible in the C text) |
| 00630fe0 | sub_630FE0 | bounded string copy of the filter text into this+0x260 (7 chars) |

**Guard conditions:** Entire body is guarded by `a4 != 0` (a .dst name argument); a null argument makes the function a no-op (early skip, nothing cleared). `Track` node exists → track object refresh + AIW update; otherwise skipped. The car-list block only runs when the node named by `off_6FF7B8` exists; if so it also rebuilds the filter and writes dword_BE1BD0. The `Filter` block only runs when a `Filter` node exists; if so it copies the string, forces the terminator at +0x267 and refreshes 0x254/0x258/0x25C; otherwise all four values keep their previous state. The `%s%s.dst` reader call is only made when the path string resolved (fallback WindowName).

**String literals referenced (deterministic):**

- `Track`
- `Filter`
- `DrivingSchool`
- `AND: SIM_FULL`
- `Car`
- `%s%s.dst`
