## StructZeroInit_6bc0_004f6bc0 — StructZeroInit_6bc0

**Summary:** Zeros 17 consecutive dwords (offsets 0x0 through 0x40) of a struct, including listed fields at 0x0, 0x8, 0xC, and 0x40. Initialization helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F6F20 (004f6f20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First dword of struct (header/flag) |
| this | 0x8 | RW | 0 | Third dword of struct (data field, zeroed in loop) |
| this | 0xC | RW | 0 | Fourth dword of struct (data field, zeroed in loop) |
| this | 0x40 | RW | 0 | Dword at index 16 (loop fills 5*3+2 = 17 dwords total) |

**Written-by note (persistence):**
- this 0x0: Written once on init; external poke overwrites
- this 0x8: Written once on init; external poke overwrites
- this 0xC: Written once on init; external poke overwrites
- this 0x40: Written once on init; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None.
