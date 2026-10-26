## DisplayModeSetter_00543960 — DisplayModeSetter

**Summary:** Sets a display mode value (offset 0x19C) from one of three recognized constants (0x20000, 0x40000, 0x80000) or clears it, and always sets the 0x10000 UI update flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | flags/state field; bit 0x10000 set to signal UI update needed |
| this | 0x19C | RW | 0 | display mode value (0x20000, 0x40000, 0x80000, or 0) |

**Written-by note (persistence):**
- this 0xEC: bit 0x10000 OR'd in each call; other bits survive
- this 0x19C: written each call (0x20000, 0x40000, 0x80000, or 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always set flag. Mode value depends on a2: 0x20000, 0x40000, or 0x80000 are stored as-is; anything else stores 0.
