## sub_5AEB53_005aeb53 — Function pointer table initializer

**Summary:** Straight-line initializer that fills a 72-dword function-pointer table: 43 slots from a1[0] through a1[71] are assigned fixed function addresses (sub_5AF697 … sub_5B35EE, plus the byte address byte_5B352F at a1[26]). Returns the table pointer unchanged.

**Called by:** sub_5AE8DD (005ae8dd)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | table slot 0 — assigned sub_5AFA1D |
| this | 0x4 | RW | — | slot 1 — assigned sub_5B11E4 |
| this | 0x8 | RW | — | slot 2 — assigned sub_5B2FBC |
| this | 0xC | RW | — | slot 3 — assigned sub_5AFAEF |
| this | 0x10 | RW | — | slot 4 — assigned sub_5B0007 |
| this | 0x14 | RW | — | slot 5 — assigned sub_5AFAB6 |
| this | 0x18 | RW | — | slot 6 — assigned sub_5B1118 |
| this | 0x1C | RW | — | slot 7 — assigned sub_5B307C |
| this | 0x20 | RW | — | slot 8 — assigned sub_5B0210 |
| this | 0x24 | RW | — | slot 9 — assigned sub_5AFA5D |
| this | 0x28 | RW | — | slot 10 — assigned sub_5B12AB |
| this | 0x2C | RW | — | slot 11 — assigned sub_5B080C |
| this | 0x38 | RW | — | slot 14 — assigned sub_5B3273 |
| this | 0x44 | RW | — | slot 17 — assigned sub_5B31B2 |
| this | 0x48 | RW | — | slot 18 — assigned sub_5B05DF |
| this | 0x4C | RW | — | slot 19 — assigned sub_5AFD5B |
| this | 0x50 | RW | — | slot 20 — assigned sub_5AF697 |
| this | 0x54 | RW | — | slot 21 — assigned sub_5AF712 |
| this | 0x58 | RW | — | slot 22 — assigned sub_5B3110 |
| this | 0x5C | RW | — | slot 23 — assigned sub_5B075C |
| this | 0x64 | RW | — | slot 25 — assigned sub_5B35EE |
| this | 0x68 | RW | — | slot 26 — assigned the byte address byte_5B352F |
| this | 0x70 | RW | — | slot 28 — assigned sub_5B335F |
| this | 0x74 | RW | — | slot 29 — assigned sub_5B3457 |
| this | 0x8C | RW | — | slot 35 — assigned sub_5B2FBC (same function as slot 2) |
| this | 0xC0 | RW | — | slot 48 — assigned sub_5B0360 |
| this | 0xC4 | RW | — | slot 49 — assigned sub_5B070B |
| this | 0xC8 | RW | — | slot 50 — assigned sub_5B048E |
| this | 0xCC | RW | — | slot 51 — assigned sub_5B02AC |
| this | 0xD0 | RW | — | slot 52 — assigned sub_5B0667 |
| this | 0xD4 | RW | — | slot 53 — assigned sub_5B0543 |
| this | 0xD8 | RW | — | slot 54 — assigned sub_5B03E7 |
| this | 0xDC | RW | — | slot 55 — assigned sub_5B06C3 |
| this | 0xEC | RW | — | slot 59 — assigned sub_5B2EE8 |
| this | 0xF0 | RW | — | slot 60 — assigned sub_5B2450 |
| this | 0xF4 | RW | — | slot 61 — assigned sub_5B25D0 |
| this | 0xF8 | RW | — | slot 62 — assigned sub_5B272C |
| this | 0xFC | RW | — | slot 63 — assigned sub_5B227D |
| this | 0x100 | RW | — | slot 64 — assigned sub_5B2BF1 |
| this | 0x104 | RW | — | slot 65 — assigned sub_5B2A3D |
| this | 0x108 | RW | — | slot 66 — assigned sub_5B283D |
| this | 0x114 | RW | — | slot 69 — assigned sub_5B283D (same function as slot 66) |
| this | 0x11C | RW | — | slot 71 — assigned sub_5B0BA0 |

**Written-by note (persistence):**
- this 0x0: written unconditionally every call — an external poke survives until the next call.
- this 0x4: written unconditionally every call — poke survives until the next call.
- this 0x8: written unconditionally every call — poke survives until the next call.
- this 0xC: written unconditionally every call — poke survives until the next call.
- this 0x10: written unconditionally every call — poke survives until the next call.
- this 0x14: written unconditionally every call — poke survives until the next call.
- this 0x18: written unconditionally every call — poke survives until the next call.
- this 0x1C: written unconditionally every call — poke survives until the next call.
- this 0x20: written unconditionally every call — poke survives until the next call.
- this 0x24: written unconditionally every call — poke survives until the next call.
- this 0x28: written unconditionally every call — poke survives until the next call.
- this 0x2C: written unconditionally every call — poke survives until the next call.
- this 0x38: written unconditionally every call — poke survives until the next call.
- this 0x44: written unconditionally every call — poke survives until the next call.
- this 0x48: written unconditionally every call — poke survives until the next call.
- this 0x4C: written unconditionally every call — poke survives until the next call.
- this 0x50: written unconditionally every call — poke survives until the next call.
- this 0x54: written unconditionally every call — poke survives until the next call.
- this 0x58: written unconditionally every call — poke survives until the next call.
- this 0x5C: written unconditionally every call — poke survives until the next call.
- this 0x64: written unconditionally every call — poke survives until the next call.
- this 0x68: written unconditionally every call — poke survives until the next call.
- this 0x70: written unconditionally every call — poke survives until the next call.
- this 0x74: written unconditionally every call — poke survives until the next call.
- this 0x8C: written unconditionally every call — poke survives until the next call.
- this 0xC0: written unconditionally every call — poke survives until the next call.
- this 0xC4: written unconditionally every call — poke survives until the next call.
- this 0xC8: written unconditionally every call — poke survives until the next call.
- this 0xCC: written unconditionally every call — poke survives until the next call.
- this 0xD0: written unconditionally every call — poke survives until the next call.
- this 0xD4: written unconditionally every call — poke survives until the next call.
- this 0xD8: written unconditionally every call — poke survives until the next call.
- this 0xDC: written unconditionally every call — poke survives until the next call.
- this 0xEC: written unconditionally every call — poke survives until the next call.
- this 0xF0: written unconditionally every call — poke survives until the next call.
- this 0xF4: written unconditionally every call — poke survives until the next call.
- this 0xF8: written unconditionally every call — poke survives until the next call.
- this 0xFC: written unconditionally every call — poke survives until the next call.
- this 0x100: written unconditionally every call — poke survives until the next call.
- this 0x104: written unconditionally every call — poke survives until the next call.
- this 0x108: written unconditionally every call — poke survives until the next call.
- this 0x114: written unconditionally every call — poke survives until the next call.
- this 0x11C: written unconditionally every call — poke survives until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af697 | sub_5AF697 | R | function address stored into slot a1[20] |
| 005af712 | sub_5AF712 | R | function address stored into slot a1[21] |
| 005afa1d | sub_5AFA1D | R | function address stored into slot a1[0] |
| 005afa5d | sub_5AFA5D | R | function address stored into slot a1[9] |
| 005afab6 | sub_5AFAB6 | R | function address stored into slot a1[5] |
| 005afaef | sub_5AFAEF | R | function address stored into slot a1[3] |
| 005afd5b | sub_5AFD5B | R | function address stored into slot a1[19] |
| 005b0007 | sub_5B0007 | R | function address stored into slot a1[4] |
| 005b0210 | sub_5B0210 | R | function address stored into slot a1[8] |
| 005b02ac | sub_5B02AC | R | function address stored into slot a1[51] |
| 005b0360 | sub_5B0360 | R | function address stored into slot a1[48] |
| 005b03e7 | sub_5B03E7 | R | function address stored into slot a1[54] |
| 005b048e | sub_5B048E | R | function address stored into slot a1[50] |
| 005b0543 | sub_5B0543 | R | function address stored into slot a1[53] |
| 005b05df | sub_5B05DF | R | function address stored into slot a1[18] |
| 005b0667 | sub_5B0667 | R | function address stored into slot a1[52] |
| 005b06c3 | sub_5B06C3 | R | function address stored into slot a1[55] |
| 005b070b | sub_5B070B | R | function address stored into slot a1[49] |
| 005b075c | sub_5B075C | R | function address stored into slot a1[23] |
| 005b080c | sub_5B080C | R | function address stored into slot a1[11] |
| 005b0ba0 | sub_5B0BA0 | R | function address stored into slot a1[71] |
| 005b1118 | sub_5B1118 | R | function address stored into slot a1[6] |
| 005b11e4 | sub_5B11E4 | R | function address stored into slot a1[1] |
| 005b12ab | sub_5B12AB | R | function address stored into slot a1[10] |
| 005b227d | sub_5B227D | R | function address stored into slot a1[63] |
| 005b2450 | sub_5B2450 | R | function address stored into slot a1[60] |
| 005b25d0 | sub_5B25D0 | R | function address stored into slot a1[61] |
| 005b272c | sub_5B272C | R | function address stored into slot a1[62] |
| 005b283d | sub_5B283D | R | function address stored into slots a1[66] and a1[69] |
| 005b2a3d | sub_5B2A3D | R | function address stored into slot a1[65] |
| 005b2bf1 | sub_5B2BF1 | R | function address stored into slot a1[64] |
| 005b2ee8 | sub_5B2EE8 | R | function address stored into slot a1[59] |
| 005b2fbc | sub_5B2FBC | R | function address stored into slots a1[2] and a1[35] |
| 005b307c | sub_5B307C | R | function address stored into slot a1[7] |
| 005b3110 | sub_5B3110 | R | function address stored into slot a1[22] |
| 005b31b2 | sub_5B31B2 | R | function address stored into slot a1[17] |
| 005b3273 | sub_5B3273 | R | function address stored into slot a1[14] |
| 005b335f | sub_5B335F | R | function address stored into slot a1[28] |
| 005b3457 | sub_5B3457 | R | function address stored into slot a1[29] |
| 005b352f | byte_5B352F | R | byte address stored into slot a1[26] |
| 005b35ee | sub_5B35EE | R | function address stored into slot a1[25] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the body is straight-line code with no branches; every slot listed above is written unconditionally on each call.
