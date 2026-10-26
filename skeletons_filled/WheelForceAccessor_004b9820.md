## WheelForceAccessor_004b9820 — WheelForceAccessor

**Summary:** Dereferences `this` to get an object pointer, then reads an int value at offset 0xF1C from that object. Part of wheel/force feedback data access.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF1C | R | — | wheel force/feedback value from dereferenced object |
| this | 0x0 | R | — | pointer to the actual object containing force data |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always reads and returns the value. No null-checks on the dereferenced pointer.
