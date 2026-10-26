## SingleFunctionCallWrapper_3490_00423490 — ClearEmptyStringBuffer

**Summary:** Zeroes EmptyStringBuffer (byte_5EC4C0, 13 bytes) and returns pointer to it.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004234b0 | loc_4234B0 | R | Address of instruction after function body (return point) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587b3e | BooleanToIntConversion | Convert boolean to integer 0/1 (not called in this function) |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory wrapper (not called in this function) |

**Guard conditions:** No guard conditions — unconditional clear and return.
