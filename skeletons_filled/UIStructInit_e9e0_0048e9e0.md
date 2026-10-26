## UIStructInit_e9e0_0048e9e0 — UIBaseControlStructInit

**Summary:** Initializes a base UI control struct: sets vtable to off_5A443C, zeroes fields at offsets 0x4/0xC/0x10/0x14/0x18/0x1C/0x20/0x24/0x28, sets sentinel -1 at offset 0x8, copies default directory string. Called by UI object constructors.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIObjectConstructor_fc50 (0048fc50), Constructor_fd60 (0048fd60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x4 | RW | 0 | counter / state field |
| this | 0x8 | RW | 18446744073709551615 | sentinel "no selection" / invalid index (-1) |
| this | 0xC | RW | 0 | rectangle width / dimension field |
| this | 0x10 | RW | 0 | rectangle height / dimension field |
| this | 0x14 | RW | 0 | rectangle left edge / x position |
| this | 0x18 | RW | 0 | rectangle top edge / y position |
| this | 0x1C | RW | 0 | additional dimension / offset field |
| this | 0x20 | RW | 0 | additional dimension / offset field |
| this | 0x24 | RW | 0 | additional dimension / offset field |
| this | 0x28 | RW | 0 | additional dimension / offset field |

**Written-by note (persistence):**
- this 0x0: once during construction; overwritten only by another constructor/destructor
- this 0x4: once during construction; survives until explicitly changed
- this 0x8: once during construction; survives until explicitly changed
- this 0xC: once during construction; survives until explicitly changed
- this 0x10: once during construction; survives until explicitly changed
- this 0x14: once during construction; survives until explicitly changed
- this 0x18: once during construction; survives until explicitly changed
- this 0x1C: once during construction; survives until explicitly changed
- this 0x20: once during construction; survives until explicitly changed
- this 0x24: once during construction; survives until explicitly changed
- this 0x28: once during construction; survives until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copy default directory string into struct buffer |

**Guard conditions:** None — unconditional initialization with no branches.
