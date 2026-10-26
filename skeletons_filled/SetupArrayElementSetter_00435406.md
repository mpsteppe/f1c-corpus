## SetupArrayElementSetter_00435406 — SetupArrayElementSetter

**Summary:** Sets three consecutive DWORD fields (offsets 0x58, 0x5C, 0x60) in the struct to the same value passed via ECX. Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | array element / field 22 — set to input value |
| this | 0x5C | RW | — | array element / field 23 — set to same input value |
| this | 0x60 | RW | — | array element / field 24 — set to same input value |

**Written-by note (persistence):**
- this 0x58: written once. Survives.
- this 0x5C: written once. Survives.
- this 0x60: written once. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all writes unconditional.
