## StringArrayMatchSearch_00497f90 — Driver Name Array Search

**Summary:** Searches a stored array of driver name strings for a match against the input string (after truncating at a separator character). Returns 1 if found, 0 if not found or empty/null input.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICustomRenderDispatch (00489fd0), DriverNameStringHandler (00497ec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1514 | R | — | Count of stored driver name entries in the array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc79c | dword_5CC79C | R | Separator character used to truncate input before matching |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c20 | sub_587C20 | Finds separator character in string (points to last occurrence of the separator) |
| 00588410 | sub_588410 | Compares input string against a stored array entry (strcmp-like); returns 0 on match |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1514 | > | 0 | Count of stored driver name entries |

**Guard interpretation:** 
- `a2 == NULL` → return 0 (BLOCKED: null input)
- `strlen(a2) == 0` → return 0 (BLOCKED: empty string)
- `this[1349] <= 0` → return 0 (BLOCKED: no entries in driver name array to search)
- `this[1349] > 0` → iterate array looking for match (PASSES: search proceeds)
- `sub_588410(i, v7) == 0` → match found, return 1 (PASSES)
- Loop completes without match → return 0
