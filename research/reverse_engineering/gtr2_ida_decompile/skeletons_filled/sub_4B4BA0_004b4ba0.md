## sub_4B4BA0_004b4ba0 — `.svm` filename match + path build/validate helper

**Summary:** Checks whether the provided string `a1` equals the global `.svm`-related name (`off_759F1C[0]`), resolves an associated id via `sub_4DE540`/`sub_4D0D20`, and builds a `...".svm"` path from a formatted `.svm` name and an integer argument; returns 1 only if the built name passes `sub_617D00`, else 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2acb | SEH_4B4BA0 | R | SEH/string helper marker referenced by this function's exception machinery |
| 006f16bc | WindowName | R | Window/title string source used in the path-building sequence |
| 006f4928 | aSvm | R | The `.svm` string literal used in `sub_615A50(".svm")` |
| 00759f1c | off_759F1C | R | Table/path of names; `off_759F1C[0]` is the string compared against `a1` |
| 00b65ff8 | dword_B65FF8 | R | Context passed to `sub_436620` (structural path accessor) to fetch a base string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d6e0 | sub_40D6E0 | Resets/reinitializes a string-building context (called twice around name composition) |
| 00436620 | PathAccessor_28e0 [structural] | Structural path accessor: fetches a base string using `dword_B65FF8` |
| 004aba50 | sub_4ABA50 | Provides path/name component used together with the `.svm` build |
| 004ce2d0 | sub_4CE2D0 | Formats/converts the resolved id `v3` into a string for the name |
| 004d0d20 | sub_4D0D20 | Validates/derives an id from the value returned by `sub_4DE540`; `<= 0` short-circuits to return 0 |
| 004de540 | sub_4DE540 | Reads/configures a pair (writes `v9`, `v8`) used to obtain the id |
| 00615860 | StringCopyWithBufferRealloc [structural] | Appends a fetched string (returned by `sub_436620`) to the growable buffer |
| 00615a50 | sub_615A50 | Appends/consumes a string in the same buffer (used for id string, `a2`, and `".svm"`) |
| 00617680 | sub_617680 | Formats/builds the resulting filename into `FileName` |
| 00617930 | sub_617930 | Initializes/clears a 256-byte buffer before use |
| 00617d00 | RaceLapsStringLoadOnTrigger [structural] | Validates/loads the built filename (`v11`, `FileName`); nonzero = success |
| 00630734 | j_??2@YAPAXI@Z | `operator new(0x50)` — allocates a 0x50-byte scratch block (first byte zeroed) |
| 006308d8 | j_j__free | Frees the scratch block on both exit paths if non-null |

**Guard conditions:** (1) `strcmp(off_759F1C[0], a1) != 0` → immediate return 0 (only an exact name match passes). (2) `sub_4D0D20(v8) <= 0` → return 0 (invalid/absent id blocks the path build). (3) `sub_617D00(v11, FileName)` returning 0 → free block and return 0; nonzero → free and return 1. Scratch block `Block` is freed on every returning path after allocation.

**String literals referenced (deterministic):**

- `.svm`
