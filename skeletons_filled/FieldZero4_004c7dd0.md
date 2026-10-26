## FieldZero4_004c7dd0 — Zero field at offset +0x4

**Summary:** Sets the DWORD at offset +0x4 of the struct to 0. Simple field zeroing function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Sound_Restart (004c8b20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | field zeroed on call, likely a reset/state flag |

**Written-by note (persistence):**
- this 0x4: set to 0 unconditionally; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always writes zero
