## SetFourColorsToWhite_00486ed0 — SetFourColorsToWhite

**Summary:** Sets four DWORD values pointed to by arguments to 0xFFFFFF (white RGB color). Utility function for initializing UI color values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 16777215 | first output color — set to 0xFFFFFF (white) |

**Written-by note (persistence):**
- this 0x0: Set unconditionally every call; external poke overwritten when function is called

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None (unconditional — all four pointers are written without checks).
