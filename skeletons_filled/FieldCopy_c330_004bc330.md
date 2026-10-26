## FieldCopy_c330_004bc330 — CopyField24To2C

**Summary:** Copies int value from offset 0x24 to offset 0x2C and returns the copied value. Simple inverse-direction field copy compared to FieldCopy_004bc320.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiplayerVehiclePlacement (0042cf10), RestartGate (004a0fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | source field (value read and returned) |
| this | 0x2C | RW | — | destination field (receives copy of offset 0x24) |

**Written-by note (persistence):**
- this 0x2C: overwritten each call with value from offset 0x24; external poke survives until next copy

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional copy
