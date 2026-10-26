## sub_4FBA40_004fba40 — parse tire/wheel MESHFILE definitions and build wheel mesh records

**Summary:** Recursive parser for a vehicle's hierarchical tire/mesh definition text (GMT-style block format). It classifies the wheel by name (LFTIRE/RFTIRE/LRTIRE/RRTIRE), walks the file through the reader object `a2` + the virtual reader method, reads INSTANCE/MESHFILE/SHADOWOBJECT fields, applies LODIN/LODOUT culling, and allocates a 0x88-byte per-wheel record (mesh name, shadow flag) that is linked into the wheel's list at `v35[120] + 4*wheelIndex`.

**Called by:** sub_4FBA40 (004fba40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1b60 | aMeshfile | R | Literal `"MESHFILE"` — name of the mesh-filename field read from the tire block. |
| 006f5c2c | aTrue_0 | R | Literal `"TRUE"` — required value of the SHADOWOBJECT field to enable the shadow mesh. |
| 006ff7e8 | aLftire | R | Literal `"LFTIRE"` — left-front wheel identifier matched against `String1` (index 0). |
| 006ff7f0 | aRftire | R | Literal `"RFTIRE"` — right-front wheel identifier (`String1` match, index 1). |
| 006ff7f8 | aLrtire | R | Literal `"LRTIRE"` — left-rear wheel identifier (`String1` match, index 2). |
| 006ff800 | aRrtire | R | Literal `"RRTIRE"` — right-rear wheel identifier (`String1` match, index 3). |
| 00712824 | asc_712824 | R | String constant referenced by this routine (not emitted in the decompiled body); most plausibly the `"}"` end-of-block literal used in the `strcmp` at line 69 — treat as inferred. |
| 007149f8 | aLodout | R | Literal `"LODOUT"` — upper LOD bound parameter fetched into `v19` via sub_6134B0. |
| 00714ac0 | aGmt_0 | R | Literal `".GMT"` — mesh file suffix. |
| 00714ac4 | byte_714AC4 | R | Not referenced in the emitted body — unknown. |
| 00714ac8 | aShadowobject | R | Literal `"SHADOWOBJECT"` — field/block name tested (with `"TRUE"`) to set the shadow flag `v9`. |
| 00714ad8 | aLodin | R | Literal `"LODIN"` — lower LOD bound parameter fetched into `v20` via sub_6134B0. |
| 00714ae0 | aInstance | R | Literal `"INSTANCE"` — nested block name; when present the function recurses on `v25`/`v35[126..127]`. |
| 00b71278 | dword_B71278 | R | Global setting read only as `dword_B71278 >= 2`; when below 2, shadow-object creation is skipped, so it gates shadow detail. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fba40 | sub_4FBA40 | Self-recursion to process a nested `INSTANCE` block (passes the child name `v25` and its two params `v35[126]`,`v35[127]`). |
| 00612eb0 | sub_612EB0 | Reads the next token/section from the parse buffer `v29`; nonzero result routes to LABEL_25 (advance), zero means `"}"` end-of-block was seen (returns). |
| 006134b0 | sub_6134B0 | Named-parameter fetch: called twice to load `"LODIN"` into `v20` and `"LODOUT"` into `v19` (defaults -1.0 set just before). |
| 006137e0 | sub_6137E0 | Field-presence test on a parsed stack buffer; used to detect `INSTANCE` (v29), `MESHFILE` (v28) and `SHADOWOBJECT` (v27) — nonzero when present. |
| 00616480 | sub_616480 | Suffix check of the copied mesh name against `".GMT"`; returns 0 when the suffix is absent, in which case `.GMT` is appended. |
| 00630739 | ??2@YAPAXI@Z | `operator new` — allocates the 0x88-byte wheel mesh record `v10`. |
| 00631c0d | __stricmp | Case-insensitive comparison: wheel-name classification and the `"TRUE"` check on the SHADOWOBJECT value. |

**Guard conditions:**
- Wheel classification: `String1` compared case-insensitively to `"LFTIRE"`→v5=0, `"RFTIRE"`→1, `"LRTIRE"`→2, `"RRTIRE"`→3, otherwise v5=-1. Failure to match any wheel name (v5==-1) blocks all MESHFILE processing (jumps to LABEL_25 to fetch the next record).
- Reader entry: after the virtual call `(*(v7+36))(a2, v35, 512)`, result==0 returns immediately; the token loop only runs while that reader keeps succeeding.
- End of block: token equal to `"}"` (via `strcmp` on `v34`) returns from the function.
- INSTANCE: only if sub_6137E0(v29) reports the field present does it recurse; missing field means the record is abandoned (LABEL_25).
- MESHFILE: if sub_6137E0(v28) reports the field missing, processing jumps to LABEL_25 (no record built).
- LOD range: LODIN/LODOUT default to -1.0; if `v35[124] < LODIN` or `v35[124] >= LODOUT`, processing jumps to LABEL_25, i.e. the record is culled outside the [LODIN, LODOUT) window.
- SHADOWOBJECT: if the field is absent or its value is not `"TRUE"` (case-insensitive), v9=0 and allocation proceeds without shadow; if it is `"TRUE"`, v9=1 but allocation is skipped entirely when `dword_B71278 < 2` (LABEL_24), so shadow meshes require that global setting >= 2.

**String literals referenced (deterministic):**

- `MESHFILE`
- `TRUE`
- `LFTIRE`
- `RFTIRE`
- `LRTIRE`
- `RRTIRE`
- `LODOUT`
- `.GMT`
- `.GMT`
- `SHADOWOBJECT`
- `LODIN`
- `INSTANCE`
