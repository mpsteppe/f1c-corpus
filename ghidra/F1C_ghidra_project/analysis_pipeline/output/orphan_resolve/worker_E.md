=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00405e60 | game_logic_isolated | MEDIUM | collision response computation with vtable dispatch; reads physics globals _DAT_0059e43c, _DAT_0059e4d8, DAT_0059e440; no cross-refs found | — |
| 0x0044c6e0 | game_logic_isolated | MEDIUM | collision material init (ID=3 at DAT_007ca3e8); globals used as lookup keys in FUN_00452810, FUN_0044ff50; likely called via init function pointer table | — |
| 0x0044cc80 | game_logic_isolated | MEDIUM | collision material init (ID=0x1f at DAT_007cc9bc); globals used in FUN_00452810, FUN_0044ff50; likely called via init function pointer table | — |
| 0x0044d220 | game_logic_isolated | MEDIUM | collision material init (ID=0x3c at DAT_007ca4f8); globals used in FUN_00452810; likely called via init function pointer table | — |
| 0x0044d7c0 | game_logic_isolated | MEDIUM | collision material init (ID=0x18 at DAT_007ccc08); globals used in FUN_00452b10; likely called via init function pointer table | — |
| 0x0044dd60 | game_logic_isolated | MEDIUM | collision material init (ID=0x34 at DAT_007cce10); globals used in FUN_00452b10; likely called via init function pointer table | — |
| 0x0044e300 | game_logic_isolated | MEDIUM | collision material init (ID=0x4b at DAT_007cd0b0, distance=9000); globals used in FUN_00452b10; likely called via init function pointer table | — |
| 0x0044e8a0 | game_logic_isolated | MEDIUM | collision material init (ID=0x5a at DAT_007ca534); globals used in FUN_00452b10; likely called via init function pointer table | — |
| 0x0044f6f0 | game_logic_isolated | MEDIUM | spring-damper controller with state struct; uses param_1[0x2c..0x2f] fields, no game globals but non-trivial stateful logic; likely called as member function via object pointer | — |
| 0x00478200 | game_logic_isolated | MEDIUM | game command dispatch via DAT_007cd8c0 vtable+0x1c(0x16); stores result at param_1+0xe0; references known GameCommandDispatchInterface global | — |
| 0x0048f330 | vtable_member | MEDIUM | writes byte at param_1+0x17f=0, int at param_1[0x5c]=-1; calls (**(code**)(*param_1+0x2c))(1); vtable dispatch at offset +0x2c | FUN_00?????? (vtable offset +0x??) |
| 0x004b9cc0 | game_logic_isolated | MEDIUM | vehicle speed accessor: reads float at *param_1+0xf34 (vehicle struct field, speed); 3-line body, __fastcall; vehicle struct offset not in docs/13 | — |
| 0x0050c2b3 | jump_table | HIGH | thunk to FUN_0050c2a6 via indirect jump through DAT_005d77e4; jump table dispatch artifact | — |
| 0x0050d85d | utility_isolated | HIGH | pure math: quaternion(4 floats)→rotation matrix(4x4); uses _DAT_0059e800 (1.0f constant); no game globals, no vtable | — |
| 0x0051030d | utility_isolated | HIGH | bitstream decompression with state context (unaff_ESI); vtable dispatch to read buffer; processes nibble-packed sub-resource data; no game globals | — |
| 0x0052d8b0 | import_thunk | HIGH | DirectInput8Create import stub; jumps to dinput8.dll | — |
| 0x00556790 | utility_isolated | HIGH | fixed-point multiply with rounding: (a*b+0x8000)>>16; pure math, no globals | — |
| 0x00564640 | import_thunk | HIGH | GetTickCount import stub; jumps to kernel32.dll | — |
| 0x00587c03 | crt_runtime | HIGH | operator new(uint) → __nh_malloc(param_1, 1); MSVC CRT heap allocation | — |
| 0x0058b59f | game_logic_isolated | HIGH | GetSystemTimeAsFileTime→64-bit tick; writes DAT_008d3ec0 (SystemTimeTick64, docs/12); used for game timing | — |
| 0x00596840 | crt_runtime | HIGH | CRT __allshl (64-bit left shift); MSVC compiler intrinsic | — |
| 0x00598684 | import_thunk | HIGH | recv() import stub; jumps to ws2_32.dll | — |
| 0x0059bfc3 | crt_runtime | HIGH | __CxxThrowException@8; MSVC CRT exception throw; RaiseException via SEH | — |
| 0x0059cb48 | crt_runtime | HIGH | SEH unwind cleanup; calls FUN_00581880; MSVC exception handler stub | — |
| 0x0059d308 | crt_runtime | HIGH | MSVC exception handler unwind; calls FUN_00599796 with DAT_008d4510 context | — |

=== FULL ENTRIES ===
<!-- target: docs/17-physics-collision.md -->
## FUN_00405e60 — Physics Collision Response Computation

Source: collision_response.cpp likely. Computes collision response forces/impulse with vtable-based sub-object dispatch.

**Key logic:**
- Reads threshold `_DAT_0059e4d8`; if param_2 < threshold, clamps to 0.0
- Stores collision parameters at param_1[0x12]=param_3, param_1[10..0xf] from param_4/param_5 (contact position, normal?)
- Dispatches via sub-vtable at param_1[0x15]+0x58 → returns status code (1=active)
- If active: scales by param_2, clamps to `_DAT_0059e43c` max
- If inactive/scaled to 0 (equals `DAT_0059e440`): calls vtable cleanup at (*param_1+8), returns 1
- If flag at param_1+6 bit 3 set: zeroes output length, returns 0
- Otherwise: computes vector delta and its length → output at param_6, param_7

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48 | SubObjectPtr | ptr to sub-object at param_1[0x12] |
| +0x54 | SubVtablePtr | vtable for sub-object dispatch at param_1[0x15] |
| +0x28 | ContactPosX | param_1[10], float from param_4[0] |
| +0x2c | ContactPosY | param_1[0xb], float from param_4[1] |
| +0x30 | ContactPosZ | param_1[0xc], float from param_4[2] |
| +0x34 | ContactNormalX | param_1[0xd], from param_5[0] |
| +0x38 | ContactNormalY | param_1[0xe], from param_5[1] |
| +0x3c | ContactNormalZ | param_1[0xf], from param_5[2] |
| +0x40 | ResponseScale | param_1[0x10], computed impulse/force scale |
| +0x18 | FlagsByte | byte flag at param_1+6, bit 3 tested |

**Globals:**
- `_DAT_0059e4d8` (VertexShortScale) — used as collision velocity threshold
- `_DAT_0059e43c` (PhysicsBaseSpeed/1.0f) — response scale clamp
- `DAT_0059e440` (ZeroThreshold/0.0f) — zero comparison for inactive response

**Calls:** via vtable: (*param_1[0x15]+0x58), (*param_1[0x15]+0x30), (*param_1+8)

**Moddability:** `hardcoded` — uses physics constants, no config file field

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044c6e0 — Collision Material Init (ID=3)

Source: collision_init.cpp. Initializes collision material/state entry at DAT_007ca3e8.

**Key logic:**
- Sets DAT_007ca3e8 = 3 (material/surface type ID)
- Initializes DAT_007ca3ec = 0 (friction coefficient?)
- Initializes DAT_007ca3f0 = 0 (restitution coefficient?)
- Initializes DAT_007ca3f4 = 0x3f800000 (1.0f, restitution bound?)

**Globals:**
- `DAT_007ca3e8` — collision material ID (lookup key in FUN_00452810, FUN_0044ff50)
- `DAT_007ca3ec` — friction coefficient default
- `DAT_007ca3f0` — restitution coefficient default
- `DAT_007ca3f4` — 1.0f bound constant

**Calls:** none

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044cc80 — Collision Material Init (ID=0x1f)

Source: collision_init.cpp. Initializes collision material entry at DAT_007cc9bc.

**Key logic:**
- Sets DAT_007cc9bc = 0x1f (material ID 31)
- DAT_007cc9c0 = 0 (coeff)
- DAT_007cc9c4 = 0xbf800000 (-1.0f, bound/offset)
- DAT_007cc9c8 = 0 (coeff)

**Globals:**
- `DAT_007cc9bc` — material ID key (lookup in FUN_00452810, FUN_0044ff50)
- `DAT_007cc9c0`, `DAT_007cc9c8` — zero coefficients
- `DAT_007cc9c4` — -1.0f constant

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d220 — Collision Material Init (ID=0x3c)

Source: collision_init.cpp. Initializes collision material entry at DAT_007ca4f8.

**Key logic:**
- Sets DAT_007ca4f8 = 0x3c (material ID 60)
- DAT_007ca4fc = 0, DAT_007ca500 = 0 (coefficients)
- DAT_007ca504 = 0x3f800000 (1.0f)

**Globals:**
- `DAT_007ca4f8` — material ID key (lookup in FUN_00452810)
- `DAT_007ca4fc`, `DAT_007ca500` — zero coefficients
- `DAT_007ca504` — 1.0f constant

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d7c0 — Collision Material Init (ID=0x18)

Source: collision_init.cpp. Initializes collision material entry at DAT_007ccc08.

**Key logic:**
- Sets DAT_007ccc08 = 0x18 (material ID 24)
- Zeroes DAT_007ccc0c through DAT_007ccc1c (5 consecutive fields)

**Globals:**
- `DAT_007ccc08` — material ID key (lookup in FUN_00452b10)
- `DAT_007ccc0c` through `DAT_007ccc1c` — cleared to 0

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044dd60 — Collision Material Init (ID=0x34)

Source: collision_init.cpp. Initializes collision material entry at DAT_007cce10.

**Key logic:**
- Sets DAT_007cce10 = 0x34 (material ID 52)
- Zeroes DAT_007cce14 through DAT_007cce24 (5 consecutive fields)

**Globals:**
- `DAT_007cce10` — material ID key (lookup in FUN_00452b10)
- `DAT_007cce14` through `DAT_007cce24` — cleared to 0

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e300 — Collision Spatial Node Init (index 75, distance 9000)

Source: collision_init.cpp. Initializes broadphase spatial partitioning node.

**Key logic:**
- Sets DAT_007cd0b0 = 0x4b (75 entries/node count)
- Sets DAT_007cd0c4 = 9000 (max search distance in world units)
- Zeroes DAT_007cd0b4 through DAT_007cd0c0 (3 fields)

**Globals:**
- `DAT_007cd0b0` — node element count 75
- `DAT_007cd0c4` — broadphase search distance 9000 units
- `DAT_007cd0b4`, `DAT_007cd0b8`, `DAT_007cd0bc` — cleared

**Moddability:** `configurable` — distance 9000 could be tuning parameter

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e8a0 — Collision Material Init (ID=0x5a)

Source: collision_init.cpp. Initializes collision material entry at DAT_007ca534.

**Key logic:**
- Sets DAT_007ca534 = 0x5a (material ID 90)
- Zeroes DAT_007ca538 through DAT_007ca544 (4 fields)
- DAT_007ca548 = 0 (extra field)

**Globals:**
- `DAT_007ca534` — material ID key (lookup in FUN_00452b10)
- `DAT_007ca538` through `DAT_007ca548` — cleared

**Moddability:** `hardcoded`

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044f6f0 — Spring-Damper Controller Update

Source: collision_spring.cpp. Stateful spring-damper controller with accumulator and clamping.

**Key logic:**
- Switch on param_4 (command):
  - case 0: store param_5 at param_1[0x2c] (set min bound)
  - case 1: store param_5 at param_1[0x2d] (set max bound)
  - case 2: store param_5 at param_1[0x2e] (set rate/scale)
  - case 3: accumulate param_5 into param_1[0x2f] (add impulse)
  - default: compute displacement = (param_2 - param_1[4]) * param_1[6]; store to param_1[8]; update position. Same for Y axis. Clamp to [param_1[2], param_1[3]] and [param_1[0], param_1[1]] bounds. Final output at param_1[0x2c..0x2e] scaled by rates.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | MinYBound | param_1[0] |
| +0x04 | MaxYBound | param_1[1] |
| +0x08 | MinXBound | param_1[2] |
| +0x0c | MaxXBound | param_1[3] |
| +0x10 | CurrentX | param_1[4] |
| +0x14 | CurrentY | param_1[5] |
| +0x18 | XScale | param_1[6] |
| +0x1c | YScale | param_1[7] |
| +0x20 | VelocityX | param_1[8] |
| +0x24 | VelocityY | param_1[9] |
| +0x28 | ScaledPosX | param_1[10] |
| +0x2c | ScaledPosY | param_1[0xb] |
| +0xb0 | SpringMin | param_1[0x2c] |
| +0xb4 | SpringMax | param_1[0x2d] |
| +0xb8 | SpringRate | param_1[0x2e] |
| +0xbc | SpringAccum | param_1[0x2f] |

**Calls:** none

**Moddability:** `hardcoded` — stateful controller, no config fields read

---

<!-- target: docs/01-engine-architecture.md -->
## FUN_00478200 — Game Command Dispatch (Type 0x16)

Source: command_dispatch.cpp. Dispatches command ID 0x16 through global game command interface.

**Key logic:**
- Calls virtual method at (*DAT_007cd8c0 + 0x1c) with argument 0x16
- If result non-null: stores at param_1 + 0xe0 (resource/handle slot)
- Returns 0

**Globals:**
- `DAT_007cd8c0` — GameCommandDispatchInterface (docs/01, docs/12)
- `DAT_007cd8c0+0x1c` — virtual method at offset 0x1c (7th vtable entry), acts as factory/loader

**Calls:** virtual dispatch via DAT_007cd8c0+0x1c(0x16)

**Moddability:** `hardcoded` — command ID 0x16 fixed

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0048f330 — VTable Method Reset

Source: object_method.cpp. Small __fastcall method that resets state fields and calls base class virtual.

**Key logic:**
- Writes 0 to byte at (int)param_1 + 0x17f (flag field)
- Writes -1 to param_1[0x5c] (state/index reset)
- Calls (**(code**)(*param_1 + 0x2c))(1) — vtable dispatch at offset 0x2c with arg 1

**Calls:** virtual method at (*param_1 + 0x2c) with argument 1

**Moddability:** `hookable` — vtable dispatch point

---

<!-- target: docs/06-session-race-logic.md -->
## FUN_004b9cc0 — Vehicle Speed Accessor

Source: vehicle_access.cpp. Reads vehicle speed from struct at offset +0xf34.

**Key logic:**
- param_1 is __fastcall (ECX = this pointer)
- Dereferences *param_1 as vehicle struct pointer
- Returns float at offset +0xf34 (vehicle speed field, location unknown in docs/13)

**Calls:** none

**Moddability:** `hardcoded` — pure accessor

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0050c2b3 — Indirect Jump Thunk to FUN_0050c2a6

Source: jumptable_thunk.cpp. Thunk through global indirect jump target.

**Key logic:**
- Reads DAT_005d77e4 (IndirectJumpTarget global)
- Jumps indirectly to address stored there
- Used for jump table dispatch or import redirection

**Globals:**
- `DAT_005d77e4` — IndirectJumpTarget (docs/12)

**Moddability:** `hardcoded` — intrinsic

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0050d85d — Quaternion to Rotation Matrix

Source: math_quaternion.cpp. Converts quaternion (4 floats) to 4x4 rotation matrix.

**Key logic:**
- Takes quaternion q = [w, x, y, z] at param_2
- Uses _DAT_0059e800 (1.0f) as scale factor
- Computes 3x3 rotation submatrix + identity last row/col
- Formula: standard quaternion-to-matrix: 
  - m[0][0] = 1 - 2(y²+z²); m[0][1] = 2(xy+zw); m[0][2] = 2(xz-yw)
  - m[1][0] = 2(xy-zw); m[1][1] = 1 - 2(x²+z²); m[1][2] = 2(yz+xw)
  - m[2][0] = 2(xz+yw); m[2][1] = 2(yz-xw); m[2][2] = 1 - 2(x²+y²)
- Last row/col = [0,0,0,1] (standard 4x4 homogeneous)

**Globals:**
- `_DAT_0059e800` (1.0f constant)

**Calls:** none

**Moddability:** `hardcoded`

---

<!-- target: docs/19-renderer.md -->
## FUN_0051030d — Bitstream Sub-Resource Decoder

Source: model_loader.cpp. Reads nibble-packed sub-resource entries from bitstream.

**Key logic:**
- Uses state context in unaff_ESI (this pointer)
- Reads from input buffer via vtable at puVar3[3] (read callback)
- Decodes header: 2-byte magic + length N entries
- For each of N entries: reads 8-bit ID + 8-bit value pair; looks up ID in table at unaff_ESI[0x31] (size = unaff_ESI[8])
- Stores resolved entry pointer in unaff_ESI[0x49..0x49+N]
- Stores nibble-packed fields at each entry (bits 0-3 for value A, bits 4-7 for value B)
- Final footer: reads width, height, and 4 nibble fields (0x5a, 0x5b, 0x5c, 0x5d)
- Increments counter at unaff_ESI[0x1f]

**Calls:** virtual method through unaff_ESI[* + 0x14] (command dispatch) and unaff_ESI[* + 4] (write)

**Moddability:** `hardcoded`

---

<!-- target: docs/20-math-utilities.md -->
## FUN_00556790 — Fixed-Point Multiply with Rounding

Source: math_fixedpoint.cpp. 32-bit fixed-point multiplication with 16-bit rounding.

**Key logic:**
- lVar1 = (longlong)param_3 * (longlong)param_4 + 0x8000 (rounding bias)
- Returns upper 32 bits: (lVar1 >> 16) & 0xFFFF | (lVar1 >> 32) << 16
- Effective: (a * b + 0x8000) >> 16, giving Q16.16 fixed-point result

**Calls:** none

**Moddability:** `hardcoded`

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0058b59f — System Time Tick Capture

Source: timer_init.cpp. Captures GetSystemTimeAsFileTime as 64-bit tick.

**Key logic:**
- Calls GetSystemTimeAsFileTime(&local_c)
- Multiplies dwHighDateTime by 1 (via __allmul(high, 0, 0, 1)) → shifts high part up 32 bits
- Adds dwLowDateTime → 64-bit 100-ns interval timestamp
- Stores in _DAT_008d3ec0 (SystemTimeTick64, docs/12)

**Globals:**
- `_DAT_008d3ec0` — SystemTimeTick64 (docs/12), 64-bit tick from file time

**Calls:** GetSystemTimeAsFileTime (Win32), __allmul (CRT)

**Moddability:** `hardcoded`

---

<!-- target: docs/01-engine-architecture.md -->
## FUN_00587c03 — operator new (MSVC CRT)

Source: new.cpp. MSVC operator new(uint) → __nh_malloc.

**Key logic:**
- Calls __nh_malloc(param_1, 1) from MSVC CRT
- Returns allocated memory or null on failure

**Moddability:** `hardcoded`
