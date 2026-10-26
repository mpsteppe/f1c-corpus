## sub_60ADA0_0060ada0 — reset 20-dword block and two globals

**Summary:** Reset routine that zeroes the 20 dwords this[0]..this[19] (offsets 0x00–0x4C) and clears the globals byte_FB2320 and dword_FB2748, then returns this.

**Called by:** sub_60BA00 (0060ba00), sub_611350 (00611350), sub_611C80 (00611c80), sub_611FC0 (00611fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | cleared to 0; slot 0 of a 20-dword state block |
| this | 0x4 | RW | 0 | cleared to 0; slot 1 |
| this | 0x8 | RW | 0 | cleared to 0; slot 2 |
| this | 0xC | RW | 0 | cleared to 0; slot 3 |
| this | 0x10 | RW | 0 | cleared to 0; slot 4 |
| this | 0x14 | RW | 0 | cleared to 0; slot 5 |
| this | 0x18 | RW | 0 | cleared to 0; slot 6 |
| this | 0x1C | RW | 0 | cleared to 0; slot 7 |
| this | 0x20 | RW | 0 | cleared to 0; slot 8 |
| this | 0x24 | RW | 0 | cleared to 0; slot 9 |
| this | 0x28 | RW | 0 | cleared to 0; slot 10 |
| this | 0x2C | RW | 0 | cleared to 0; slot 11 |
| this | 0x30 | RW | 0 | cleared to 0; slot 12 |
| this | 0x34 | RW | 0 | cleared to 0; slot 13 |
| this | 0x38 | RW | 0 | cleared to 0; slot 14 |
| this | 0x3C | RW | 0 | cleared to 0; slot 15 |
| this | 0x40 | RW | 0 | cleared to 0; slot 16 |
| this | 0x44 | RW | 0 | cleared to 0; slot 17 |
| this | 0x48 | RW | 0 | cleared to 0; slot 18 |
| this | 0x4C | RW | 0 | cleared to 0; slot 19 |

**Written-by note (persistence):**
- this 0x0 through 0x4C: all written unconditionally to 0 on every call; an external poke of any of these 20 dwords survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb2320 | byte_FB2320 | W | global byte flag cleared to 0 on every call |
| 00fb2748 | dword_FB2748 | W | global dword state cleared to 0 on every call |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — the two global stores and the 20 field stores execute unconditionally; no field or argument is tested.
