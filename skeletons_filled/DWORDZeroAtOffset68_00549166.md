## DWORDZeroAtOffset68_00549166 — ZeroFieldAtOffset68

**Summary:** Zeroes the DWORD at offset 0x44 (68) of the object passed as the second parameter (a2/EDX). The first and third parameters are unused.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | 0 | DWORD field at offset 0x44 — unconditionally zeroed |

**Written-by note (persistence):**
- this 0x44: Written once unconditionally; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function always executes unconditionally with no checks.
