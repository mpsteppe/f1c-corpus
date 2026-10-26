## CollisionStructCopy_efc0_0044efc0 — CollisionStructDataStore

**Summary:** Stores a type ID (a2) at offset 0x278 of the target struct (a1 via ecx), then copies 0x244 bytes (580 bytes = 145 ints) from stack parameters a3..a63 into offset 0x8 of the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44ED10 (0044ed10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x278 | RW | — | Type ID field (set from a2 parameter, marks data type) |

**Written-by note (persistence):**
- this 0x278: Set each call from a2 param. Last write survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional copy, no branches.
