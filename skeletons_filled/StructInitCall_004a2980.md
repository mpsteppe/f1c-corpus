## StructInitCall_004a2980 — StructInitCall

**Summary:** Zeros three consecutive DWORD fields (offsets 0xC, 0x10, 0x14) then calls ArrayResourceCleanup. Simple struct field reinitialization stub.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A4900 (004a4900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | DWORD zeroed on init |
| this | 0x10 | RW | 0 | DWORD zeroed on init |
| this | 0x14 | RW | 0 | DWORD zeroed on init |

**Written-by note (persistence):**
- this 0xC: once unconditional (0)
- this 0x10: once unconditional (0)
- this 0x14: once unconditional (0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a29a0 | ArrayResourceCleanup | performs cleanup/release of array resources before reinit |

**Guard conditions:** No guards. Always zeros 3 fields and calls ArrayResourceCleanup unconditionally.
