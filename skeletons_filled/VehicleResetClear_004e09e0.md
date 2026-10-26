## VehicleResetClear_004e09e0 — VehicleStateResetAndReinit

**Summary:** Resets and reinitializes a vehicle state structure — zeroes large blocks of fields (timers, counters, flags, collision state, audio handles), calls destructor loops on embedded array objects, and conditionally runs multi-system init + 3D sound cleanup when collision geometry is loaded. Returns void pointer from freed memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C6E80 (004c6e80), sub_4DFBB0 (004dfbb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | collision geometry status field — read from global instance via StatusFieldCopy |
| this | 0x0 | R | — | vtable/base pointer — dereferenced for MultiSystemStructInitializer and StatusFieldCopy |
| this | 0x4 | R | — | secondary object pointer (likely 3D sound source handle) — checked for non-null before destructor |
| this | 0x48 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x4C | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x50 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x54 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x58 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x5C | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x60 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x64 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x68 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x6C | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x70 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x74 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x78 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x7C | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x80 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x84 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x88 | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x8C | RW | 0 | vehicle state field — zeroed as part of 17-element init block |
| this | 0x88C | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x890 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x894 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x898 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x89C | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8A0 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8A4 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8A8 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8AC | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8B0 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8B4 | RW | 0 | vehicle counter/flag — zeroed in dword-zero block |
| this | 0x8B8 | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8C0 | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8C4 | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8C8 | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8CC | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8D0 | RW | 0 | vehicle struct field — zeroed in 2-iteration struct zero loop |
| this | 0x8E4 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x8F4 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x8F8 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x8FC | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x900 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x904 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x908 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x90C | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x910 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x914 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x934 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x938 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x93C | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x940 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x944 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x948 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x94C | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x950 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x954 | RW | 0 | vehicle state dword — zeroed individually |
| this | 0x964 | RW | 0 | vehicle byte flag — zeroed individually |
| this | 0x968 | RW | 0 | vehicle word/dword — zeroed individually |
| this | 0x96C | RW | 0 | vehicle byte — zeroed individually |
| this | 0x96D | RW | 0 | vehicle byte — zeroed individually |
| this | 0x970 | RW | 0 | vehicle dword — zeroed individually |
| this | 0x974 | RW | 0 | vehicle dword — zeroed individually |
| this | 0x975 | RW | 0 | vehicle byte — zeroed individually |
| this | 0x976 | RW | 0 | vehicle byte — zeroed individually |
| this | 0x977 | RW | 0 | vehicle byte — zeroed individually |
| this | 0x978 | RW | 0 | vehicle byte — zeroed individually |
| this | 0x979 | RW | 0 | vehicle byte — zeroed individually |
| this | 0x97C | RW | 0 | vehicle dword — zeroed individually |
| this | 0x980 | RW | 18446744073709551615 | sentinel value (-1) — marks field as unset/inactive |
| this | 0x984 | RW | 18446744073701163007 | sentinel value (0xFF7FFFFF) — marks field as unset |
| this | 0x988 | RW | 1065353216 → 1.0f | default float (1.0) — scale or multiplier reset value |
| this | 0x98C | RW | 0 | vehicle dword/byte — zeroed individually |
| this | 0xB6C | RW | 0 | vehicle dword — zeroed individually |
| this | 0xBA8 | RW | 0 | vehicle dword — zeroed via memset of 0x38 bytes |
| this | 0x2BD0 | RW | 0 | pointer field — zeroed before conditional free |
| this | 0x2BD4 | RW | 0 | pointer field — conditionally freed then zeroed |

**Written-by note (persistence):**
- this 0x48: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x4C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x50: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x54: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x58: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x5C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x60: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x64: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x68: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x6C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x70: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x74: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x78: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x7C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x80: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x84: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x88: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x88C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x890: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x894: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x898: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x89C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8A0: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8A4: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8A8: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8AC: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8B0: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8B4: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8B8: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8C0: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8C4: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8C8: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8CC: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8D0: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8E4: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8F4: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8F8: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x8FC: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x900: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x904: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x908: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x90C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x910: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x914: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x934: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x938: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x93C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x940: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x944: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x948: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x94C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x950: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x954: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x964: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x968: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x96C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x96D: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x970: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x974: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x975: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x976: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x977: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x978: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x979: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x97C: unconditional — explicitly set to 0 on every call; external poke does NOT survive
- this 0x980: unconditional — set to -1 sentinel on every call; external poke does NOT survive
- this 0x984: unconditional — set to 0xFF7FFFFF sentinel on every call; external poke does NOT survive
- this 0x988: unconditional — set to 1.0f on every call; external poke does NOT survive
- this 0x98C: unconditional — set to 0 on every call; external poke does NOT survive
- this 0xB6C: unconditional — set to 0 on every call; external poke does NOT survive
- this 0xBA8: unconditional — zeroed via memset on every call; external poke does NOT survive
- this 0x2BD0: unconditional — set to 0 on every call; external poke does NOT survive
- this 0x2BD4: conditional — zeroed only if pointer at 0x2BD4 was non-null (freed then set to 0); external poke survives only after the free path runs once

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411570 | StatusFieldCopy | copies status field value from source object — reads obj+0x4894 from global instance |
| 004ded20 | DualArrayDestructor | destroys/frees dual-array structure (11 iterations, 187-byte stride) |
| 004dfa50 | F_17ElementZeroInitLoop | zeros 17-element structure array (68 bytes each) — batch init of grouped fields |
| 004dfb60 | InitWithDualCall | calls initializer function twice on a structure (4 iterations, 74-byte stride) |
| 004dfb90 | sub_4DFB90 | sub-struct field cleanup/reset (28-byte stride loop) |
| 004e0db0 | MultiSystemStructInitializer | initializes multi-system data structures in vehicle object |
| 004e3050 | ArrayCleanup | cleans up/frees arrays embedded in vehicle struct |
| 004e38d0 | TimerClampAndProcess | clamps and processes timer values in vehicle state |
| 00545150 | F_3DSoundSourceDestructor | destroys 3D sound source object (audio subsystem cleanup) |
| 00566650 | StringCopyWithBufferRealloc | copies string with dynamic buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | frees heap memory via operator delete wrapper |

**Guard conditions:** Conditional block at entry: `dword_8AFE88 != 0 && *(this+0x4) != 0` — both collision geometry handle AND secondary pointer must be non-null to run MultiSystemStructInitializer + F_3DSoundSourceDestructor + StatusFieldCopy. If either is zero, these three calls are SKIPPED. All other zero-initialization and cleanup calls execute unconditionally every call. The final free at offset 0x2BD4 is conditional on the pointer being non-null.