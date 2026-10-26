## UIElementPositionSetter_00543870 — UIElementPositionSetter

**Summary:** Sets the X/Y/Z position of a UI element (offsets 0x188, 0x18A, 0x18C) from short integer parameters and sets the 0x10000 update flag at offset 0xEC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | flags/state field; bit 0x10000 set to signal UI update needed |
| this | 0x188 | RW | — | X position (16-bit) |
| this | 0x18A | RW | — | Y position (16-bit) |
| this | 0x18C | RW | — | Z position (16-bit) |

**Written-by note (persistence):**
- this 0xEC: bit 0x10000 OR'd in each call; other bits survive
- this 0x188: overwritten with a4 each call
- this 0x18A: overwritten with a3 each call
- this 0x18C: overwritten with a2 each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always writes all three positions and sets update flag.
