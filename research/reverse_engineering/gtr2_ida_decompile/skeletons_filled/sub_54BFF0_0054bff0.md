## sub_54BFF0_0054bff0 — Apply game-option block (clamped) to config globals

**Summary:** Applies a block of setup/option values (three player-name strings plus a run of race-format, weather, driving-aid and penalty fields) into the engine's config globals, clamping every numeric field to its stored min/max range, then commits the player/session strings and finalizes. Part of the game options/setup path.

**Called by:** sub_54C880 (0054c880)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | R | — | player/driver name string 1 (stored via sub_615860) |
| this | 0x184 | R | — | field a1+388 |
| this | 0x188 | R | — | field a1+392 |
| this | 0x18C | R | — | field a1+396 (byte, clamped) |
| this | 0x190 | R | — | field a1+400 |
| this | 0x194 | R | — | field a1+404 |
| this | 0x198 | R | — | field a1+408 (byte, clamped) |
| this | 0x19C | R | — | field a1+412 |
| this | 0x1A0 | R | — | player/driver name string 2 |
| this | 0x1A4 | R | — | field a1+420 |
| this | 0x1A8 | R | — | field a1+424 (float, clamped) |
| this | 0x1AC | R | — | field a1+428 |
| this | 0x1B0 | R | — | race state value a1+432 (clamped into dword_B72314) |
| this | 0x1B4 | R | — | field a1+436 (passed to sub_50F030) |
| this | 0x1B8 | R | — | field a1+440 |
| this | 0x1BC | R | — | field a1+444 |
| this | 0x1C0 | R | — | player/driver name string 3 |
| this | 0x1C4 | R | — | field a1+452 (float, clamped) |
| this | 0x248 | R | — | field a1+584 (clamped) |
| this | 0x24C | R | — | field a1+588 (clamped) |
| this | 0x250 | R | — | field a1+592 (clamped, unsigned compare) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6f530 | byte_B6F530 | R | session/team object receiving the name values via sub_50F030/sub_5100A0 |
| 00b6f68c | dword_B6F68C | R | min bound for dword_B70030 |
| 00b6f6c4 | dword_B6F6C4 | R | min bound for dword_B70174 |
| 00b6f708 | dword_B6F708 | R | min bound for dword_B7000C |
| 00b7000c | dword_B7000C | W | clamped output field 3 |
| 00b70014 | dword_B70014 | R | min bound for dword_B7000C |
| 00b70018 | dword_B70018 | R | max bound for dword_B7000C |
| 00b70030 | dword_B70030 | W | clamped output field 1 (also a guard value elsewhere) |
| 00b70038 | dword_B70038 | R | min bound for dword_B70030 |
| 00b7003c | dword_B7003C | R | max bound for dword_B70030 |
| 00b70174 | dword_B70174 | W | clamped output field 2 |
| 00b7017c | dword_B7017C | R | min bound for dword_B70174 |
| 00b70180 | dword_B70180 | R | max bound for dword_B70174 |
| 00b702b8 | byte_B702B8 | W | clamped output byte 1 |
| 00b702ba | byte_B702BA | R | min bound for byte_B702B8 |
| 00b702bb | byte_B702BB | R | max bound for byte_B702B8 |
| 00b704d4 | dword_B704D4 | W | clamped output field 4 |
| 00b704dc | dword_B704DC | R | min bound for dword_B704D4 |
| 00b704e0 | dword_B704E0 | R | max bound for dword_B704D4 |
| 00b70618 | dword_B70618 | W | clamped output field 5 |
| 00b70620 | dword_B70620 | R | min bound for dword_B70618 |
| 00b70624 | dword_B70624 | R | max bound for dword_B70618 |
| 00b7075c | byte_B7075C | W | clamped output byte 2 |
| 00b7075e | byte_B7075E | R | min bound for byte_B7075C |
| 00b7075f | byte_B7075F | R | max bound for byte_B7075C |
| 00b71dec | dword_B71DEC | W | clamped output field 6 |
| 00b71df4 | dword_B71DF4 | R | min bound for dword_B71DEC |
| 00b71df8 | dword_B71DF8 | R | max bound for dword_B71DEC |
| 00b71f24 | dword_B71F24 | W | clamped output field 7 |
| 00b71f2c | dword_B71F2C | R | min bound for dword_B71F24 |
| 00b71f30 | dword_B71F30 | R | max bound for dword_B71F24 |
| 00b71f90 | dword_B71F90 | W | clamped output field 8 |
| 00b71f98 | dword_B71F98 | R | min bound for dword_B71F90 |
| 00b71f9c | dword_B71F9C | R | max bound for dword_B71F90 |
| 00b71fb4 | dword_B71FB4 | RW | float output field (bit-cast) clamped to [flt_B71FBC, flt_B71FC0] |
| 00b71fbc | flt_B71FBC | R | lower bound for dword_B71FB4 |
| 00b71fc0 | flt_B71FC0 | R | upper bound for dword_B71FB4 |
| 00b71fd8 | dword_B71FD8 | W | clamped output field 9 |
| 00b71fe0 | dword_B71FE0 | R | min bound for dword_B71FD8 |
| 00b71fe4 | dword_B71FE4 | R | max bound for dword_B71FD8 |
| 00b72314 | dword_B72314 | W | global race state, clamped to [dword_B7231C, dword_B72320] |
| 00b7231c | dword_B7231C | R | min bound for dword_B72314 |
| 00b72320 | dword_B72320 | R | max bound for dword_B72314 |
| 00b723cc | dword_B723CC | W | clamped unsigned output field 10 |
| 00b723d4 | dword_B723D4 | R | min bound for dword_B723CC |
| 00b723d8 | dword_B723D8 | R | max bound for dword_B723CC |
| 00b7261c | dword_B7261C | W | clamped output field 11 |
| 00b72624 | dword_B72624 | R | min bound for dword_B7261C |
| 00b72628 | dword_B72628 | R | max bound for dword_B7261C |
| 00b72760 | dword_B72760 | W | clamped output field 12 |
| 00b72768 | dword_B72768 | R | min bound for dword_B72760 |
| 00b7276c | dword_B7276C | R | max bound for dword_B72760 |
| 00b728a4 | flt_B728A4 | RW | float output clamped to [flt_B728AC, flt_B728B0] |
| 00b728ac | flt_B728AC | R | lower bound for flt_B728A4 |
| 00b728b0 | flt_B728B0 | R | upper bound for flt_B728A4 |
| 00b72a00 | dword_B72A00 | RW | float output (bit-cast) clamped to [flt_B72A08, flt_B72A0C] |
| 00b72a08 | flt_B72A08 | R | lower bound for dword_B72A00 |
| 00b72a0c | flt_B72A0C | R | upper bound for dword_B72A00 |
| 00b72e08 | dword_B72E08 | W | clamped output field 13 |
| 00b72e10 | dword_B72E10 | R | min bound for dword_B72E08 |
| 00b72e14 | dword_B72E14 | R | max bound for dword_B72E08 |
| 00b72f4c | dword_B72F4C | W | clamped output field 14 |
| 00b72f54 | dword_B72F54 | R | min bound for dword_B72F4C |
| 00b72f58 | dword_B72F58 | R | max bound for dword_B72F4C |
| 00be1cfd | unk_BE1CFD | R | argument to sub_538940 together with a1 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f030 | sub_50F030 | set a numeric session/team value (on byte_B6F530) from a1+436 |
| 005100a0 | sub_5100A0 | set the session/team name from the string at a1+456 |
| 00538940 | sub_538940 | final processing on unk_BE1CFD with the option block |
| 00615860 | StringCopyWithBufferRealloc [structural] | store the three option strings (a1, a1+128, a1+256) |

**Guard conditions:** Every numeric field is clamped: the value written from the a1 block is replaced by the min bound when below it, or by the max bound when above it — `dword_B70030` (bounds dword_B70038/dword_B7003C), `dword_B70174` (dword_B7017C/dword_B70180), `dword_B7000C` (dword_B70014/dword_B70018), `byte_B702B8` (byte_B702BA/byte_B702BB), `dword_B704D4`, `dword_B70618`, `byte_B7075C`, `dword_B71DEC`, `dword_B71F24`, `dword_B71F90`, `dword_B71FB4` (float bounds flt_B71FBC/flt_B71FC0), `dword_B71FD8`, `dword_B72314` (dword_B7231C/dword_B72320), `dword_B7261C`, `dword_B72760`, `flt_B728A4` (flt_B728AC/flt_B728B0), `dword_B72A00` (flt_B72A08/flt_B72A0C), `dword_B723CC` (unsigned compare against dword_B723D4/dword_B723D8), `dword_B72E08` and `dword_B72F4C`. Values within range pass through unchanged.

