## AudioChannelInit_0045d530 — AudioChannelConstructor

**Summary:** One-time constructor for an AudioChannel object (struct size ~112KB): initializes vtable, zeroes sub-structs (104×140-byte and 104×872-byte arrays), sets default volume/gain/frequency parameters, and stores the owner handle from parameter a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SingleFunctionCallWrapper_bf50 (0045bf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | postProcessInput [CONFIRMED] |
| this | 0x4 | RW | — | sample rate divisor (1.0f / 24.0f ≈ 0.041667 Hz) |
| this | 0x8 | RW | 0 | audio playback flags / state |
| this | 0xC | RW | 1097859072 → 15.0f | default volume / gain level |
| this | 0x10 | RW | 1097859072 → 15.0f | maximum volume / gain ceiling |
| this | 0x14 | RW | 0 | mute flag (byte, 0 = not muted) |
| this | 0x18 | RW | 0 | playback cursor / sample position |
| this | 0x1C | RW | 0 | PhysX [FACT] |
| this | 0x20 | RW | 0 | PhysY [FACT] |
| this | 0x21 | RW | 0 | unknown flag byte (zeroed) |
| this | 0x24 | RW | 1106247680 → 30.0f | PhysZ [FACT] |
| this | 0x28 | RW | 0 | unknown flag byte (zeroed) |
| this | 0x29 | RW | 1 | enabled flag (1 = channel active) |
| this | 0x2C | RW | 18446744072627421184 → -1.0f | sentinel / invalid handle marker |
| this | 0x30 | RW | 0 | unknown byte (zeroed) |
| this | 0xB4 | RW | 0 | channel priority / group index (zeroed) |
| this | 0xB8 | RW | 18446744073709551615 | audio handle ID 1 (set to -1 = invalid) |
| this | 0xBC | RW | 0 | unknown field (zeroed) |
| this | 0xC0 | RW | 18446744073709551615 | audio handle ID 2 (set to -1 = invalid) |
| this | 0xC4 | RW | 1 | isHumanInControl / isInDrsZone [CONFIRMED] |
| this | 0xC5 | RW | 0 | unknown byte (zeroed) |
| this | 0xC6 | RW | 0 | unknown byte (zeroed) |
| this | 0xC7 | RW | 0 | unknown byte (zeroed) |
| this | 0xC8 | RW | 0 | unknown byte (zeroed) |
| this | 0x11C | RW | 0 | unknown byte (zeroed) |
| this | 0x16C | RW | 0 | unknown byte (zeroed) |
| this | 0x1AC | RW | 18446744073709551615 | audio param sentinel (set to -1 = invalid) |
| this | 0x1B0 | RW | 0 | unknown byte (zeroed) |
| this | 0x1D0 | RW | 0 | unknown dword (zeroed) |
| this | 0x374 | RW | 0 | unknown byte (zeroed) |
| this | 0x378 | RW | 0 | audio filter / effect parameter 1 |
| this | 0x37C | RW | 0 | audio filter / effect parameter 2 |
| this | 0x380 | RW | 0 | audio filter / effect parameter 3 |
| this | 0x384 | RW | 0 | audio filter / effect parameter 4 |
| this | 0x388 | RW | 0 | audio filter / effect parameter 5 |
| this | 0x38C | RW | 0 | audio filter / effect parameter 6 |
| this | 0x390 | RW | 0 | audio filter / effect parameter 7 |
| this | 0x3E14 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FB8 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FBC | RW | — | vtable pointer (off_59F0CC) |
| this | 0x3FC0 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FC4 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FC8 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FCC | RW | 0 | unknown dword (zeroed) |
| this | 0x3FD0 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FD4 | RW | 0 | unknown dword (zeroed) |
| this | 0x3FD8 | RW | 8 | audio buffer alignment / stride constant |
| this | 0x3FD9 | RW | 0 | unknown byte (zeroed) |
| this | 0x1B768 | RW | 0 | unknown byte (zeroed) |
| this | 0x1B769 | RW | 0 | unknown byte (zeroed) |
| this | 0x1B76A | RW | 0 | unknown byte (zeroed) |
| this | 0x1B76B | RW | 0 | unknown byte (zeroed) |
| this | 0x1B76C | RW | 0 | unknown byte (zeroed) |
| this | 0x1B76D | RW | 0 | unknown byte (zeroed) |
| this | 0x1B76E | RW | 0 | unknown byte (zeroed) |
| this | 0x1B770 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B774 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B778 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B77C | RW | 0 | unknown dword (zeroed) |
| this | 0x1B780 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B784 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B788 | RW | 0 | unknown dword (zeroed) |
| this | 0x1B78C | RW | 0 | unknown dword (zeroed) |

**Written-by note (persistence):**
- this 0x0: one-time init — external poke survives until next constructor call
- this 0x4: one-time init — external poke survives until next constructor call
- this 0x8: one-time init — external poke survives until next constructor call
- this 0xC: one-time init — external poke survives until next constructor call
- this 0x10: one-time init — external poke survives until next constructor call
- this 0x14: one-time init — external poke survives until next constructor call
- this 0x18: one-time init — external poke survives until next constructor call
- this 0x1C: one-time init — external poke survives until next constructor call
- this 0x20: one-time init — external poke survives until next constructor call
- this 0x21: one-time init — external poke survives until next constructor call
- this 0x24: one-time init — external poke survives until next constructor call
- this 0x28: one-time init — external poke survives until next constructor call
- this 0x29: one-time init — external poke survives until next constructor call
- this 0x2C: one-time init — external poke survives until next constructor call
- this 0x30: one-time init — external poke survives until next constructor call
- this 0xB4: one-time init — external poke survives until next constructor call
- this 0xB8: one-time init — external poke survives until next constructor call
- this 0xBC: one-time init — external poke survives until next constructor call
- this 0xC0: one-time init — external poke survives until next constructor call
- this 0xC4: one-time init — external poke survives until next constructor call
- this 0xC5: one-time init — external poke survives until next constructor call
- this 0xC6: one-time init — external poke survives until next constructor call
- this 0xC7: one-time init — external poke survives until next constructor call
- this 0xC8: one-time init — external poke survives until next constructor call
- this 0x11C: one-time init — external poke survives until next constructor call
- this 0x16C: one-time init — external poke survives until next constructor call
- this 0x1AC: one-time init — external poke survives until next constructor call
- this 0x1B0: one-time init — external poke survives until next constructor call
- this 0x1D0: one-time init — external poke survives until next constructor call
- this 0x374: one-time init — external poke survives until next constructor call
- this 0x378: one-time init — external poke survives until next constructor call
- this 0x37C: one-time init — external poke survives until next constructor call
- this 0x380: one-time init — external poke survives until next constructor call
- this 0x384: one-time init — external poke survives until next constructor call
- this 0x388: one-time init — external poke survives until next constructor call
- this 0x38C: one-time init — external poke survives until next constructor call
- this 0x390: one-time init — external poke survives until next constructor call
- this 0x3E14: one-time init — external poke survives until next constructor call
- this 0x3FB8: one-time init — external poke survives until next constructor call
- this 0x3FBC: one-time init — external poke survives until next constructor call
- this 0x3FC0: one-time init — external poke survives until next constructor call
- this 0x3FC4: one-time init — external poke survives until next constructor call
- this 0x3FC8: one-time init — external poke survives until next constructor call
- this 0x3FCC: one-time init — external poke survives until next constructor call
- this 0x3FD0: one-time init — external poke survives until next constructor call
- this 0x3FD4: one-time init — external poke survives until next constructor call
- this 0x3FD8: one-time init — external poke survives until next constructor call
- this 0x3FD9: one-time init — external poke survives until next constructor call
- this 0x1B768: one-time init — external poke survives until next constructor call
- this 0x1B769: one-time init — external poke survives until next constructor call
- this 0x1B76A: one-time init — external poke survives until next constructor call
- this 0x1B76B: one-time init — external poke survives until next constructor call
- this 0x1B76C: one-time init — external poke survives until next constructor call
- this 0x1B76D: one-time init — external poke survives until next constructor call
- this 0x1B76E: one-time init — external poke survives until next constructor call
- this 0x1B770: one-time init — external poke survives until next constructor call
- this 0x1B774: one-time init — external poke survives until next constructor call
- this 0x1B778: one-time init — external poke survives until next constructor call
- this 0x1B77C: one-time init — external poke survives until next constructor call
- this 0x1B780: one-time init — external poke survives until next constructor call
- this 0x1B784: one-time init — external poke survives until next constructor call
- this 0x1B788: one-time init — external poke survives until next constructor call
- this 0x1B78C: one-time init — external poke survives until next constructor call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059f098 | flt_59F098 | R | AspectRatioDivisor [DERIVED] |
| 0059f09c | dword_59F09C | R | NetCommInitConstant [DERIVED] |
| 0059f0a4 | dword_59F0A4 | R | NetCommInitParam [DERIVED] |
| 0059f0cc | off_59F0CC | R | VTable_59F0CC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c0a0 | ZeroInit5FloatStruct | zero-initialize a 5-float sub-struct (audio coefficients) |
| 0045c750 | WrapperWithConstant | initialize sub-struct with constant/default values |
| 0045cd50 | StructInitializer_cd50 | initialize sub-struct at offset 112528 (audio playback region) |
| 0045e590 | BufferFillWith0xFFFFFFFF | fill audio handle array with -1 (invalid sentinels) |
| 00461470 | ThunkToFUN00461480 | initialize one 140-byte audio sample / voice sub-struct (called 104 times) |
| 00461550 | FAILWRONGDESCRIPTION | initialize range of bytes with marker/check pattern |
| 004ff670 | PassthroughWrapper_f670 | initialize one 872-byte audio buffer / mixer sub-struct (called 104 times) |

**Guard conditions:** none — straight-line constructor, no branches or early returns
