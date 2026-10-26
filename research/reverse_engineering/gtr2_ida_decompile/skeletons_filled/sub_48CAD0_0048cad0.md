## sub_48CAD0_0048cad0 — Compare string with global and set match flag

**Summary:** Compares the caller-supplied string a2 against the global string referenced through off_759F1C; stores the boolean result as 1/0 into this+0x254 and returns it. Looks like a name/type identification check for the object.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x254 | RW | 0 | Boolean match-result flag: set 1 when a2 equals the global string, 0 otherwise |

**Written-by note (persistence):**
- this 0x254: Written unconditionally on every call — one of two values (1 or 0) is stored on both branches. Not a frame recalc, but an external poke would be overwritten the next time this function runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00759f1c | off_759F1C | R | Global pointer whose first element is the reference string compared against a2 via strcmp |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Single comparison `strcmp(off_759F1C[0], a2) == 0`. Equal → this+0x254 = 1 and return 1 (match path). Not equal → this+0x254 = 0 and return 0 (mismatch path). Both paths write the flag; no early return other than the branch return.
