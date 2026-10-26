## LargeZeroInitConstructor_0048d740 — ScrollAreaConstructor

**Summary:** Constructs a scroll area UI object. Calls ConstructorWithByteParams for base init, zeros 16 consecutive fields (this[58] through this[73], offsets 0xE8-0x124), and sets the vtable to off_5AC328.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC328 |
| this | 0xE8 | RW | 0 | Scroll configuration / state field 58 |
| this | 0xEC | RW | 0 | Scroll configuration / state field 59 |
| this | 0xF0 | RW | 0 | Scroll configuration / state field 60 |
| this | 0xF4 | RW | 0 | Scroll configuration / state field 61 |
| this | 0xF8 | RW | 0 | Scroll configuration / state field 62 |
| this | 0xFC | RW | 0 | Scroll configuration / state field 63 |
| this | 0x100 | RW | 0 | Scroll configuration / state field 64 |
| this | 0x104 | RW | 0 | Scroll configuration / state field 65 |
| this | 0x108 | RW | 0 | Scroll configuration / state field 66 |
| this | 0x10C | RW | 0 | Scroll configuration / state field 67 |
| this | 0x110 | RW | 0 | Scroll configuration / state field 68 |
| this | 0x114 | RW | 0 | Scroll configuration / state field 69 |
| this | 0x118 | RW | 0 | Scroll configuration / state field 70 |
| this | 0x11C | RW | 0 | Scroll configuration / state field 71 |
| this | 0x120 | RW | 0 | Scroll configuration / state field 72 |
| this | 0x124 | RW | 0 | Scroll configuration / state field 73 |

**Written-by note (persistence):**
- this 0x0: set every call (vtable init); survives external poke
- this 0xE8: zeroed every call; survives external poke
- this 0xEC: zeroed every call; survives external poke
- this 0xF0: zeroed every call; survives external poke
- this 0xF4: zeroed every call; survives external poke
- this 0xF8: zeroed every call; survives external poke
- this 0xFC: zeroed every call; survives external poke
- this 0x100: zeroed every call; survives external poke
- this 0x104: zeroed every call; survives external poke
- this 0x108: zeroed every call; survives external poke
- this 0x10C: zeroed every call; survives external poke
- this 0x110: zeroed every call; survives external poke
- this 0x114: zeroed every call; survives external poke
- this 0x118: zeroed every call; survives external poke
- this 0x11C: zeroed every call; survives external poke
- this 0x120: zeroed every call; survives external poke
- this 0x124: zeroed every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac328 | off_5AC328 | R | Ptr_VTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | Base UI widget constructor with byte parameters |

**Guard conditions:** None — unconditional.
