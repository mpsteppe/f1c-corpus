## ArrayZeroInit_004a40f0 — StructZeroInit

**Summary:** Zero-initializes the entire struct: memset first 0x1A0 bytes to 0, then writes DWORD 0 at offset 0x1A0 (extends memset range). Called during game restart to reset state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A0 | RW | 0 | trailing DWORD beyond memset range, explicitly zeroed |

**Written-by note (persistence):**
- this 0x1A0: once unconditional (0) — total struct reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always zeroes entire struct unconditionally.
