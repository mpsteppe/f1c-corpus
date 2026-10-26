## FunctionCallWrapper_1470_00421470 — InitSeasonParentPathArray

**Summary:** Initializes SeasonParentPath array (dword_5EC3D0) with alternating 0/-1 values, calls ConfigDirectoryPathRegistration, returns pointer to array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00421490 | loc_421490 | R | Address of instruction after function body (return point) |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004216f0 | ConfigDirectoryPathRegistration | Register season parent directory paths into initialized array |
| 00587b3e | BooleanToIntConversion | Convert boolean flag to integer 0/1 (not called in this function) |

**Guard conditions:** No guard conditions — unconditional initialization and registration; always returns pointer to dword_5EC3D0.
