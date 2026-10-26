## ZeroTwoFields_004bb800 — Two-field zero initializer

**Summary:** Zeroes two DWORD fields at offsets 0x30 and 0xA4 (this[12] and this[41]). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | 0 | First field to zero (this[12]) |
| this | 0xA4 | RW | 0 | Second field to zero (this[41]) |

**Written-by note (persistence):**
- this 0x30: written to 0 per call; persists until next write
- this 0xA4: written to 0 per call; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
