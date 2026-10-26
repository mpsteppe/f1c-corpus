## F_3FieldInitCall_0b00_004d0b00 — ThreeFieldZeroInit

**Summary:** Zeros three specific fields at offsets 0x64, 0x6C, and 0x74, then calls sub_4A2220 to perform full zero-initialization of the remaining struct. Returns the struct pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D0110 (004d0110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | 0 | first field zeroed (e.g. count or pointer) |
| this | 0x6C | RW | 0 | second field zeroed (e.g. count or pointer) |
| this | 0x74 | RW | 0 | third field zeroed (e.g. count or pointer) |

**Written-by note (persistence):**
- this 0x64: written once to 0 during init; may be modified later externally
- this 0x6C: written once to 0 during init; may be modified later externally
- this 0x74: written once to 0 during init; may be modified later externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a2220 | sub_4A2220 | full zero-initialization of struct memory |

**Guard conditions:** None — always zeros the three fields and calls sub_4A2220 unconditionally.
