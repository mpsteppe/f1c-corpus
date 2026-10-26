# Cross-Validation Results: Functions 1071-1125
## Batch: worker_F_batch2

---

<!-- target: docs/19-renderer.md -->

## FUN_0055C070 — MISSING_ENTRY

Source: renderer. Render context push/pop with per-vehicle texture setup.

**Key logic:**
- Calls FUN_00553db0 (push context)
- Checks bitflag at param_2+0x24 & 4: if clear, gets viewport dimensions via FUN_005424e0, offsets origin, calls D3D via vtable at param_1[0x440]+0x90 to set viewport
- Checks param_3 & 0x10: if clear enters texture/vehicle render loop:
  - Sets clear color to 5, calls FUN_005546a0/FUN_00554790 (clear setup)
  - Calls D3D vtable at param_1[0x440]+200 to set render state (7,0)
  - Reads texture handle from vehicle struct at param_2+0x18, offset +0x138
  - Compares with cached at param_1[0x4f3], calls FUN_0054b9e0 on mismatch
  - Loops vehicle sub-parts (count at *(param_2+0x18)+0x118):
    - Checks flags at +0x14 bit 0x1000000 and +0x13c
    - Copies texture data via FUN_00540f00 (alloc) and block copy
    - Calls FUN_00540f90 (texture finalize)
    - Calls FUN_00554700 (per-part setup)
    - D3D draw call via vtable +0x154
    - Conditional render mode: checks sign byte at param_2+0x18+0x14 >> 8
      - Negative: D3D draw via vtable+0x11c mode 4
      - Non-negative: D3D draw via vtable+0x11c mode 5
  - Sets flag bit at +0x14 |= 0x1000000
  - Final D3D render state restore via vtable+200

**Calls:** FUN_00553db0, FUN_005424e0, FUN_005546a0, FUN_00554790, FUN_0054b9e0, FUN_00540f00, FUN_00540f90, FUN_00554700

**Moddability:** hardcoded — Direct3D render path

---

<!-- target: docs/19-renderer.md -->

## FUN_00475D90 — MISSING_ENTRY

Source: renderer/UI. Draws rectangle border/crosshair on render surface.

**Key logic:**
- Calls FUN_00487160(0, ...) and FUN_00487160(1, ...) to get two screen coordinates
- If both valid: sorts min/max for X and Y
- Gets color via FUN_00495150()
- Draws 4 border edges using FUN_00494c20:
  - Top edge, right edge, bottom edge, left edge
- Calls FUN_00475d30() (border fill)
- If *(param_1+0x118)==0: draws crosshair line:
  - Computes midpoint X = (local_c + local_8) >> 1
  - Draws vertical line with color 0xff
  - Checks _DAT_007cd458 < DAT_0059e440 for directional offset
  - Computes line start/end with __ftol()
  - Draws horizontal cross line with color 0xff0000
- Else: draws single horizontal line at computed Y offset

**Globals:** _DAT_007cd458, DAT_0059e440

**Calls:** FUN_00487160, FUN_00495150, FUN_00494c20, FUN_00475d30, __ftol

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00495BD0 — MISSING_ENTRY

Source: renderer/UI. Tooltip/popup render list.

**Key logic:**
- Sets initial positions: local_24=2, local_18=2, local_1c=0, local_20=0, local_28=0
- Gets color via FUN_00495150()
- Calls FUN_00498550() (pre-render)
- Loops up to 4 items calling FUN_00499a50() for availability:
  - Gets item dimensions via FUN_0049a2b0
  - Calls FUN_004983b0 (measure)
  - Accumulates total width and max height
- If items exist: computes layout:
  - Width cap at 800 (clamp at 0x31a - local_1c)
  - Height cap at 600 (clamp at 0x252 - local_20)
- Renders items:
  - First item (iVar4==0): draws background rect (0xaaff4444) and outline (0x222222)
  - Each item: calls FUN_0049a2b0 (get size), FUN_00494f10 (render text) at param_1+0x1518
  - Accumulates Y offset
- Calls FUN_00490920 and FUN_004918d0 (post-render cleanup)

**Calls:** FUN_00495150, FUN_00498550, FUN_00499a50, FUN_0049a2b0, FUN_004983b0, FUN_00494bf0, FUN_00494f10, FUN_00490920, FUN_004918d0

**Moddability:** hardcoded — UI layout

---

<!-- target: docs/19-renderer.md -->

## FUN_00518032 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_004B9000 — MISSING_ENTRY

Source: renderer/LOD. LOD node traversal and render dispatcher.

**Key logic:**
- Loops 0x68 (104) vehicle indices calling FUN_004b72a0(i, param_2) to get LOD node
- For each valid node: checks visibility via FUN_005001d0/FUN_005001f0:
  - Checks distance thresholds at offsets +0x24c and +0x9c
  - Calls thunk_FUN_00500170 if visible
- Calls FUN_004b5380 (LOD update)
- Walks linked list starting at param_1+0x71c (current LOD node):
  - If null: picks between param_1+0x714 (front) or param_1+0x718 (back) based on distance param_2 relative to param_1+0xf34/0xf30
- Traverses doubly-linked list forward/backward based on param_2 comparing to *pfVar6 (LOD distance key)
- Main render loop:
  - Calls FUN_00566db0 (set texture?), FUN_004b4450, FUN_004b44a0
  - Processes sub-objects via FUN_004b4360 at param_1+0x6e4
  - Checks bitmask (local_350[0] & 0xe0000000) for 0x20000000:
    - Extracts type from bits 18-23
    - Type 0: vehicle index sub-object, calls FUN_004fffb0
    - Types 1-6: calls FUN_004b54e0
  - Continuation checks via FUN_004b5460/FUN_004b54a0
  - Max 64 iterations
- Second pass: walks list backward to catch remaining nodes
- Calls FUN_004b5630, FUN_004b5760 (finalize)

**Struct offsets (param_1):**
| Offset | Use |
|--------|-----|
| +0x71c | Current LOD node pointer |
| +0x714 | LOD list head |
| +0x718 | LOD list tail |
| +0x720 | LOD count |
| +0x6e4 | Render context state |
| +0xf30 | Near distance threshold |
| +0xf34 | Far distance threshold |

**Calls:** FUN_004b72a0, FUN_005001d0, FUN_005001f0, thunk_FUN_00500170, FUN_004b5380, FUN_004b4450, FUN_004b44a0, FUN_004b4360, FUN_00566db0, FUN_004fffb0, FUN_004b54e0, FUN_004b5460, FUN_004b54a0, FUN_004b5630, FUN_004b5760

**Moddability:** LOD distance thresholds in struct

---

<!-- target: docs/19-renderer.md -->

## FUN_00531250 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_004906E0 — MISSING_ENTRY

Source: renderer. Render context/texture manager singleton initializer.

**Key logic:**
- Checks DAT_007cd9c8 & 1: if clear, enters init path:
  - Sets DAT_007cd9c8 |= 1
  - Allocates 0x20-byte manager struct via operator_new
  - Zeros all 8 fields
  - Creates sub-allocator: allocates 4-byte block header + 0x204-byte pool, initializes 0x20 slots via FUN_004912f0
  - Allocates 0xc-byte first-node block, initializes linked list
  - Loops 0x200/0x10=32 times: creates free list entries with stride 0x10
  - Sets DAT_007cd9cc = manager struct
  - Allocates 4-byte callback struct, calls FUN_00491710(1)
  - Registers cleanup via FUN_00587b3e(&LAB_00490850)
- Returns &DAT_007cd9cc

**Globals:** DAT_007cd9c8, DAT_007cd9cc, DAT_007cd9d0

**Calls:** operator_new, FUN_004912f0, FUN_00491710, FUN_00587b3e

**Moddability:** hardcoded — singleton init

---

<!-- target: docs/19-renderer.md -->

## FUN_0050B1F0 — MISSING_ENTRY

Source: unknown. Constructor — sets vtable and delegates to init.

**Key logic:**
- Calls FUN_00507496(param_2, 8, 1)
- Sets *param_1 = &PTR_FUN_005adccc

**Calls:** FUN_00507496

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_005426A0 — MISSING_ENTRY

Source: unknown. Struct default-values constructor.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor)
- Zeros fields at indices [0]..[5], [7]..[0xa], [0xd]
- Sets param_1[0xb] = 1
- Sets param_1[0xc] = 6

**Calls:** FUN_0053c2a0

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_005170C0 — MISSING_ENTRY

Source: renderer. Vtable dispatch table setup for renderer interface object.

**Key logic:**
- Sets ~20 vtable entries at param_1 indices 0..0x36:
  - Index 0: FUN_0051ec00 (main entry)
  - 0x1c: &LAB_00520c00
  - 0xd: &LAB_00520980
  - 0x1b: &LAB_00520a70
  - 0xb: &LAB_0051f7c0
  - 0x30: &LAB_0051f6a0
  - 0x2f: &LAB_0051f2c0
  - 0x11: &LAB_0051f560
  - 0x36: &LAB_0051f650
  - 0x35: &LAB_0051f350
  - 0x34: &LAB_0051f4c0
  - 0x33: &LAB_0051f5f0
  - 0x32: &LAB_0051f200
  - 0x31: &LAB_0051f400
  - 0x12: &LAB_00520500
  - 0x16: &LAB_0051f700
  - 0x19: &LAB_00520e00
  - 0x18: &LAB_00520ce0
  - 0x1f: &LAB_005208f0
  - 0x1e: &LAB_00520870
  - 0x13: &LAB_0051fbf0
  - 0x14: &LAB_0051fc80
  - 0x10: &LAB_005207c0
  - 0x15: &LAB_00520420
  - Index 8..1 in descending order for additional dispatch entries

**Moddability:** hardcoded — vtable initialization

---

<!-- target: docs/19-renderer.md -->

## FUN_0050B891 — MISSING_ENTRY

Source: unknown. Constructor — sets vtable and delegates to init.

**Key logic:**
- Calls FUN_0050a7e1(param_2)
- Sets *param_1 = &PTR_FUN_005ade2c

**Calls:** FUN_0050a7e1

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00552F20 — MISSING_ENTRY

Source: graphics/texture. Texture-loading filename parser and scale setup.

**Key logic:**
- Switch on *(param_1[0x19] + 0x30) (file format type):
  - Case 5/6: calls FUN_00552ba0()
  - Case 7/8: calls FUN_00552d70()
- Extracts filename from path using _strrchr(param_2, '\\') — strips directory prefix
- Copies filename characters up to '.' into param_1+0x14 (name buffer)
- Sets scale factors:
  - param_1[0] = _DAT_0059e43c / *(int*)(param_1[0x19] + 0x1c)  (width divisor)
  - param_1[1] = _DAT_0059e43c / *(int*)(param_1[0x19] + 0x20)  (height divisor)
- Sets *(param_1[0x19] + 0x34) = param_1[0xb] (some scale factor)

**Globals:** _DAT_0059e43c (physics scaling constant)

**Calls:** FUN_00552ba0, FUN_00552d70, _strrchr

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_00495190 — PASS

---

<!-- target: docs/19-renderer.md -->

## FUN_0046EEC0 — MISSING_ENTRY

Source: unknown. Constructor — parent init then vtable set.

**Key logic:**
- Calls FUN_004893c0 (parent constructor)
- Sets *param_1 = &PTR_FUN_0059fed0
- Sets param_1[0x5d] = -1

**Calls:** FUN_004893c0

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_004D4840 — MISSING_ENTRY

Source: unknown. Constructor — zero-init + vtable set.

**Key logic:**
- Zeros param_1[1], param_1[2], param_1[3]
- Sets *param_1 = &PTR_FUN_005acf08

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004B33B0 — MISSING_ENTRY

Source: math_utilities. Encodes parameters into hash/key for progress bar.

**Key logic:**
- Computes key: `*param_1 = (((DAT_007c56a4 + (param_7 + param_2 * 4) * 8) * 0x40 + param_3) * 0x400 + param_4) * 0x100 + param_5`
- Stores secondary value at param_1[1] = param_6
- Sets sentinel at param_1[0x6b] = -1

**Globals:** DAT_007c56a4 (SessionType)

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0055EB30 — MISSING_ENTRY

Source: unknown. Color-channel blending with alpha multiplication.

**Key logic:**
- Loops over count at param_1+8
- For each iteration: reads 4 source bytes (argb) from two buffers at stride 0x40 and 0x30
- Multiplies each color channel by DAT_008b8e40-based coefficients with DAT_008b6c20 blending factor
- Clamps results to 0-255 range
- Writes packed ARGB result

**Globals:** DAT_008b6c20, DAT_008b8e40

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058E22B — MISSING_ENTRY

Source: memory allocator. Bounds-checked indexed access with allocator lock/unlock.

**Key logic:**
- Checks param_1 < DAT_008d4a20 (allocator capacity)
- Checks bitmap at DAT_008d4920[param_1>>5] + 4 + (param_1&0x1f)*0x24 for flag bit 0
- If valid: calls FUN_00595a61 (lock), FUN_0058e290(param_1, param_2, param_3) (actual operation), FUN_00595ac0 (unlock)
- Returns result of FUN_0058e290
- On failure: sets error code 9 via FUN_0058afcf and 0 via FUN_0058afd8
- Returns 0xffffffff on error

**Globals:** DAT_008d4a20, DAT_008d4920

**Calls:** FUN_00595a61, FUN_0058e290, FUN_00595ac0, FUN_0058afcf, FUN_0058afd8

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0056C3A0 — MISSING_ENTRY

Source: math_utilities. Orthonormal basis construction from forward vector.

**Key logic:**
- Takes 4 double[3] parameters: param_1 (input forward), param_2 (normalized forward, out), param_3 (right, out), param_4 (up, out)
- If null inputs: uses local buffers
- Copies forward vector from param_1 to param_2
- Reads length at param_1+4 (double at offset 0x20)
- Normalizes forward using _DAT_0059e420 / sqrt(dot product)
- Checks ABS(forward.x) against _DAT_0059e830 for degenerate axis
- Computes right = normalize(cross(forward, reference_up)) where reference_up = (0,0,1) or (1,0,0)
- Computes up = cross(right, forward)
- Normalizes right and up

**Globals:** _DAT_0059e420, _DAT_0059e430, _DAT_0059e830

**Moddability:** hardcoded — pure 3D math

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0055D320 — MISSING_ENTRY

Source: animation/transform. Sets velocity/force components on physics body with scale factor.

**Key logic:**
- Switch on param_2 (axis/component selector):
  - 1: Set linear velocity: param_1+8..0x10 = param_3..5 * _DAT_0059e460 * *(param_1+0x14)
  - 2: Set angular velocity: param_1+0x18..0x20 = param_3..5 * _DAT_0059e460 * *(param_1+0x24)
  - 3: Set acceleration: param_1+0x28..0x30 = param_3..5 * _DAT_0059e460 * *(param_1+0x34)
- Calls FUN_005416a0(param_1, ...) to apply
- Sets flag bit at DAT_008b8f28 + 0xec |= 0x800

**Globals:** _DAT_0059e460, DAT_008b8f28

**Calls:** FUN_005416a0

**Moddability:** hardcoded — animation constant

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00558E70 — MISSING_ENTRY

Source: renderer/texture. Texture/surface blending with coordinate transform.

**Key logic:**
- If param_1+0x20 signed (<0): calls FUN_00558d80/FUN_0055cf50 for texture sub-region copy
- If *(param_1+0x30) == 0: early return
- Calls FUN_0053b130 (setup)
- If bit 0x20 at param_1+0x20: sets scale factors via FUN_00542490, negates
- If bit 0x10: same but sets Y=0 (horizontal only)
- Calls FUN_0053b240 (apply transform)
- Zeroes output arrays at param_1+0x44 and param_1+0x48
- Enters linked-list traversal:
  - For each node at param_1+0x38:
    - If flag 0x30 bits: copies matrix from node, calls FUN_0053b170/FUN_0053b200
    - If flag 0x4000: calls FUN_0053b1d0/FUN_0053b330
    - Renders via DAT_008b8f24 vtable call (draw primitive)
    - Performs alpha blending with multiplication
    - Accumulates widths/heights
  - Final render pass: calls FUN_00558d80, FUN_0055cf50
- Calls FUN_0053b160 (teardown)

**Globals:** DAT_008b8f24, DAT_008b8f28

**Calls:** FUN_00558d80, FUN_0055cf50, FUN_0053b130, FUN_00542490, FUN_0053b240, FUN_0053b170, FUN_0053b200, FUN_0053b1d0, FUN_0053b330, FUN_0053b350, FUN_0053b160, FUN_005457c0, FUN_0055d560, FUN_00558d10

**Moddability:** hardcoded — render path

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005503A0 — MISSING_ENTRY

Source: unknown. Vehicle AI state machine — speed/position adjustment.

**Key logic:**
- Walks linked list from param_1+0x204 (vehicle list head)
- For each vehicle with flag 0x80000 at +0x14:
  - Loops sub-parts (count at +0x118, array at +0x11c)
  - For each part: loops damage/position entries at stride 0x25
  - Checks if current position (at piVar7) < max (at piVar6):
    - With flag check at piVar6[-4] & 4
    - Switch on type at piVar6[1] & 0xffff000f:
      - 1: increments position by 1, caps at max
      - 2: increments by 1 but stays below max
      - 3: reverses sign if at boundary
      - 4: increments by 1, calls FUN_004c030 on overflow (trigger/reset)
  - Writes adjusted position

**Calls:** FUN_004c030 (trigger/reset)

**Moddability:** AI position/speed parameters in vehicle struct

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00564DD0 — MISSING_ENTRY

Source: hash/crypto. Block cipher core — AES-like round transformation with lookup tables.

**Key logic:**
- Initializes output state in param_1 buffer (+0x400..+0x4d0)
- Iterates 16 rounds using uVar3 bitmask (starts 0x8000, shifts right each round)
- For each bit of param_3 (key/control):
  - If bit clear (0): performs ADD/XOR/rotate round on uVar4 and uVar1
    - Stores uVar4, uVar1, and step counter at param_1+0x400/0x440/0x480
    - XORs with table lookup at param_1 + (index & 0xff) * 4
    - Byte-rotates values
    - Doubles counter iVar2
  - If bit set (1): performs complement/rotate round
    - Doubles counter iVar2 + 1
    - XORs complemented values with lookup table
    - Byte-rotates
- Stores final state: uVar1→+0x4c8, uVar4→+0x4c4, counter→+0x4cc, param_2→+0x4d0
- Returns uVar1 ^ uVar4

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x400..+0x43c | uVar4 history (16 entries) |
| +0x440..+0x47c | uVar1 history (16 entries) |
| +0x480..+0x4bc | Step counter history |
| +0x4c0 | History entry count |
| +0x4c4 | Final uVar4 |
| +0x4c8 | Final uVar1 |
| +0x4cc | Final step counter |
| +0x4d0 | Input param_2 |

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058FF65 — MISSING_ENTRY

Source: system/locale. Locale/language detection for system code page validation.

**Key logic:**
- Checks length of DAT_008d3fa8 string: if == 3 sets DAT_008d3fa4 = 1 (3-letter lang code)
- Checks length of DAT_008d3fac string: same pattern for DAT_008d3f9c
- Resets DAT_008d3f98 = 0
- If not 3-letter: calls FUN_00590616 to parse numeric locale, else sets to 2
- Calls EnumSystemLocalesA with callback FUN_0058ffec
- Validates DAT_008d3fb0 flag mask: requires bits 0x100, 0x200, and 0x7 all set
- If incomplete: resets DAT_008d3fb0 = 0

**Globals:** DAT_008d3fa8, DAT_008d3fac, DAT_008d3fa4, DAT_008d3f9c, DAT_008d3f98, DAT_008d3fa0, DAT_008d3fb0

**Calls:** _strlen, FUN_00590616, EnumSystemLocalesA

**Moddability:** hardcoded — system locale detection

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00401180 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00456150 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004DCF30 — MISSING_ENTRY

Source: math_utilities. Struct field getter — reads two fields.

**Key logic:**
- If param_2 != NULL: *param_2 = *(param_1 + 0x14)
- If param_3 != NULL: *param_3 = *(param_1 + 0x18)

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058BC56 — MISSING_ENTRY

Source: unknown. Wrapper — calls FUN_0059508d with constant args.

**Key logic:**
- Calls FUN_0059508d(0x10000, 0x30000)

**Calls:** FUN_0059508d

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004145C0 — MISSING_ENTRY

Source: math_utilities. Struct field copy (8 values).

**Key logic:**
- Copies 8 undefined4 values from param_2 to param_1 at indices [0]..[7] (offsets 0x00..0x1c)
- Order: [0], [2], [3], [4], [5], [6], [7], [1]

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00474BA0 — MISSING_ENTRY

Source: unknown. Constructor — renderer context/state init.

**Key logic:**
- Calls FUN_00466d60(1) (parent/global init)
- Sets vtable to &PTR_FUN_005a3fc0
- Sets param_1[199] = &DAT_007d0038 (game state pointer)
- Sets param_1[0xca] = 0, [0xc9] = 1, [0xcb] = 1, [0xcc] = 1 (default flags)
- Calls FUN_00486f30 on &PTR_DAT_005be704 and &DAT_005c32c8 (string/resource init)
- Sets param_1[0xcd] = 0x1b6 (some size/limit)

**Globals:** DAT_007d0038, PTR_DAT_005be704, DAT_005c32c8

**Calls:** FUN_00466d60, FUN_00486f30

**Moddability:** hardcoded — constructor

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0048EAA0 — MISSING_ENTRY

Source: unknown. Constructor — large struct initialization with many field defaults.

**Key logic:**
- Calls FUN_00485e30 (parent constructor)
- Zeroes fields at indices 0x38..0x5b (many)
- Sets individual bytes at +0x17d, +0x17e, +0x17f to 0
- Sets vtable to &PTR_LAB_005a4550
- Sets defaults:
  - param_1[0x40] = 1
  - param_1[0x41] = 4
  - param_1[0x42] = 0x3f000000 (0.5f)
  - param_1[0x5c] = -1
  - param_1[0x5e] = 10
  - *(param_1+0x5f) = 1

**Calls:** FUN_00485e30

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004B29B0 — MISSING_ENTRY

Source: renderer/LOD. Bitfield manipulation for LOD/render state.

**Key logic:**
- Computes: param_1[0x2c] ^= ((ROUND(param_2 * _DAT_005accd0) & 0xff) << 0xc) & 0x1f000
- Modifies 3 bits at mask 0x1f000 in bits 12-16

**Globals:** _DAT_005accd0

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004DEDB0 — MISSING_ENTRY

Source: unknown. Sorted array insertion with duplicate detection.

**Key logic:**
- Reads element count at param_1+0x18
- Duplicate check: compares 9 fields of param_2 against array at param_1+0x20 (stride 9 floats = 0x24 bytes)
- If duplicate found: calls FUN_004df110(..., -1), returns
- If array full (0x14 elements): finds worst-fit element for replacement
  - Evaluates cost function using flags at stride 0x24
  - Uses _DAT_005ad140 and _DAT_0059e670 as threshold constants
  - Shifts array left to remove worst element
- Insertion: finds position by sorting key (param_2[1] < *pfVar4)
  - Shifts elements right to make room
  - Copies 9 fields of param_2 into array
  - Increments count
  - Calls FUN_004df110(param_2[1], index)

**Globals:** _DAT_005ad140, _DAT_0059e670

**Calls:** FUN_004df110

**Struct offsets (param_1):**
| Offset | Field | Type |
|--------|-------|------|
| +0x18 | ElementCount | int |
| +0x1c | SortKey array | int[20] |
| +0x20 | Element array | float[9*20] |
| +0x40 | Insertion temp | undefined |

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0052A0A1 — MISSING_ENTRY

Source: compression. Huffman tree construction and code generation.

**Key logic:**
- Implements classic Huffman coding algorithm:
  - Counts symbol frequencies (max 16 symbols)
  - Checks for degenerate case (all same symbol)
  - Finds min/max used symbol indices
  - Validates Kraft inequality
  - Builds canonical Huffman code lengths
- Generates code table:
  - Assigns codewords in order of increasing length
  - Writes codes to param_9 output array
  - For each length group: assigns sequential codewords
- Builds encoding tree nodes:
  - Allocates tree nodes in output buffer at param_7+*param_8*8
  - Creates parent-child relationships
  - Populates left/right child indices
  - Returns 0 on success, error codes on failure (-3=invalid data, -4=out of buffer)

**Algorithm family:** Huffman coding

**Moddability:** hardcoded — compression utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005822B0 — MISSING_ENTRY

Source: memory. Linked list deallocation — frees all nodes and data.

**Key logic:**
- Walks linked list from *param_1 (head pointer)
- For each node: if node[2] (char) != 0 and *node != 0: calls FUN_00587bcf(*node) (free data)
- Frees node itself via FUN_00587bcf
- Zeros param_1[0..3] (list metadata)

**Calls:** FUN_00587bcf

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0058D7C3 — MISSING_ENTRY

Source: unknown. Sentinel-loop processor — repeats operation until sentinel found.

**Key logic:**
- Loops calling FUN_0058d78e(param_1, param_3, param_4)
- Decrements param_2 (max iterations)
- Exits when *param_4 == -1 or param_2 < 1

**Calls:** FUN_0058d78e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004530A0 — MISSING_ENTRY

Source: unknown. State machine dispatcher with resource management.

**Key logic:**
- Switch on *param_1 (state selector):
  - 0: calls FUN_004527e0(param_1[1], param_2) (init)
  - 1: calls FUN_00452b10(param_1[1], param_2 == 2) (check)
    - If returns non-zero: calls FUN_00452810(param_1[1]) (cleanup)

**Calls:** FUN_004527e0, FUN_00452b10, FUN_00452810

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00479D00 — MISSING_ENTRY

Source: renderer. Renderer resource dispatch via service provider.

**Key logic:**
- Calls vtable at *DAT_007cd8c0 + 0x1c with arg 0xe (service lookup)
- If result non-null: calls FUN_00477280(param_1)
- Calls same vtable with arg 0xf
- If result non-null: calls FUN_00477280(param_1)
- Returns 0

**Globals:** DAT_007cd8c0

**Calls:** FUN_00477280

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0049A990 — MISSING_ENTRY

Source: unknown. Destructor — vtable set + conditional free.

**Key logic:**
- Sets vtable to &PTR_LAB_005acab0
- If param_1[0xd] != 0: frees with FUN_00587bcf
- Calls FUN_004b0170() (cleanup)

**Calls:** FUN_00587bcf, FUN_004b0170

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004C8D60 — MISSING_ENTRY

Source: unknown. Vtable dispatch wrapper (scene manager).

**Key logic:**
- If DAT_008ac4c4 (scene manager) != NULL:
  - Calls vtable at *DAT_008ac4c4 + 0x14

**Globals:** DAT_008ac4c4

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0050E7CB — MISSING_ENTRY

Source: math_utilities. 2D coordinate transform with perspective divide.

**Key logic:**
- Reads 2D input from param_2 (x, y)
- Reads transform matrix from param_3 (16 floats, stride 4)
- Computes:
  - projected_x = m[0xc] + y*m[4] + x*m[0]
  - projected_y = m[0xd] + y*m[5] + x*m[1]
  - w = m[0xf] + y*m[7] + x*m[3]
- Checks w against 1.0 via FUN_0050c042
- If w != 0: divides x, y by w (perspective divide)

**Calls:** FUN_0050c042

**Moddability:** hardcoded — pure math utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0054C290 — MISSING_ENTRY

Source: runtime. Static initializer registration.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0054c2a0) — registers cleanup callback for at-exit execution

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00556650 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00474C70 — MISSING_ENTRY

Source: unknown. Constructor — vtable set + sub-init.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005a4080
- Calls FUN_0048c0d0()

**Calls:** FUN_0048c0d0

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004D0F00 — MISSING_ENTRY

Source: math_utilities. Simple setter — stores value.

**Key logic:**
- *param_1 = param_2

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00561FF0 — MISSING_ENTRY

Source: unknown. Wrapper — delegates to FUN_00562010.

**Key logic:**
- Calls FUN_00562010(param_2, 0)
- Returns 0

**Calls:** FUN_00562010

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00598E39 — MISSING_ENTRY

Source: unknown. Destructor with vtable swap and exception handling.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- Sets vtable to &PTR_FUN_005b9bcc
- If param_1[0x12] (char) != 0: calls FUN_00599495()
- If param_1[0x11] != 0: calls FUN_005993af(1) then FUN_00587bcf(free)
- Calls FUN_00598c70() (cleanup)
- Swaps vtable to &PTR_FUN_005b9c04
- Calls FUN_00598c70() again

**Calls:** FUN_0058a5d8, FUN_00599495, FUN_005993af, FUN_00587bcf, FUN_00598c70

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0045BE70 — MISSING_ENTRY

Source: runtime. Static initializer registration.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0045be80) — registers cleanup callback

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004855A0 — MISSING_ENTRY

Source: unknown. Destructor — vtable set + conditional free.

**Key logic:**
- Sets vtable to &PTR_FUN_005ab290
- Calls FUN_00487250()
- If (param_2 & 1): calls FUN_00587bcf(param_1)

**Calls:** FUN_00487250, FUN_00587bcf

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0049A9E0 — MISSING_ENTRY

Source: math_utilities. Rectangle dimension computation — subtracts origin.

**Key logic:**
- param_1[0x14] = param_2 - param_1[0xc] (width from right - left)
- param_1[0x18] = param_3 - param_1[4] (height from bottom - top)
- param_1[0x1c] = param_4 - param_1[0xc] (alternative width)
- param_1[0x20] = param_5 - param_1[4] (alternative height)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x04 | Top |
| +0x0c | Left |
| +0x14 | Width |
| +0x18 | Height |
| +0x1c | AltWidth |
| +0x20 | AltHeight |

**Moddability:** hardcoded — pure utility

---

<!-- target: docs/20-math-utilities.md -->

## FUN_004C8180 — MISSING_ENTRY

Source: unknown. Vtable dispatch wrapper (scene manager).

**Key logic:**
- If DAT_008ac4c4 (scene manager) != NULL:
  - Calls vtable at *DAT_008ac4c4 + 0x28 with args (0, 0, 0)

**Globals:** DAT_008ac4c4

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_005076FE — MISSING_ENTRY

Source: unknown. Constructor — vector array allocation with exception handling.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- If source size differs from current size:
  - Allocates array via operator_new(iVar1 << 4) (stride 0x10)
  - Populates with vector_constructor_iterator_ using LAB_005007ec
  - Stores array at +0x104c and size at +0x1048
- Returns 0 on success, 0x8007000e on allocation failure

**Calls:** FUN_0058a5d8, operator_new, _vector_constructor_iterator_

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00556700 — PASS

---

<!-- target: docs/20-math-utilities.md -->

## FUN_0059A86C — MISSING_ENTRY

Source: unknown. Destructor with reference count decrement.

**Key logic:**
- Calls FUN_0058a5d8 (SEH setup)
- Sets vtable to &PTR_FUN_005b9d3c
- Reads reference index at param_1[9]
- If index != 0: decrements DAT_008d463c[index]
- If ref count < 1: calls FUN_0059a980() (full cleanup)
- Calls FUN_00598c70() (cleanup)

**Globals:** DAT_008d463c

**Calls:** FUN_0058a5d8, FUN_0059a980, FUN_00598c70

**Moddability:** hardcoded

---

<!-- target: docs/20-math-utilities.md -->

## FUN_00408500 — PASS

---

## Summary

| # | Address | Result |
|---|---------|--------|
| 1071 | FUN_0055C070 | MISSING_ENTRY |
| 1072 | FUN_00475D90 | MISSING_ENTRY |
| 1073 | FUN_00495BD0 | MISSING_ENTRY |
| 1074 | FUN_00518032 | PASS |
| 1075 | FUN_004B9000 | MISSING_ENTRY |
| 1076 | FUN_00531250 | PASS |
| 1077 | FUN_004906E0 | MISSING_ENTRY |
| 1078 | FUN_0050B1F0 | MISSING_ENTRY |
| 1079 | FUN_005426A0 | MISSING_ENTRY |
| 1080 | FUN_005170C0 | MISSING_ENTRY |
| 1081 | FUN_0050B891 | MISSING_ENTRY |
| 1082 | FUN_00552F20 | MISSING_ENTRY |
| 1083 | FUN_00495190 | PASS |
| 1084 | FUN_0046EEC0 | MISSING_ENTRY |
| 1085 | FUN_004D4840 | MISSING_ENTRY |
| 1086 | FUN_004B33B0 | MISSING_ENTRY |
| 1087 | FUN_0055EB30 | MISSING_ENTRY |
| 1088 | FUN_0058E22B | MISSING_ENTRY |
| 1089 | FUN_0056C3A0 | MISSING_ENTRY |
| 1090 | FUN_0055D320 | MISSING_ENTRY |
| 1091 | FUN_00558E70 | MISSING_ENTRY |
| 1092 | FUN_005503A0 | MISSING_ENTRY |
| 1093 | FUN_00564DD0 | MISSING_ENTRY |
| 1094 | FUN_0058FF65 | MISSING_ENTRY |
| 1095 | FUN_00401180 | PASS |
| 1096 | FUN_00456150 | PASS |
| 1097 | FUN_004DCF30 | MISSING_ENTRY |
| 1098 | FUN_0058BC56 | MISSING_ENTRY |
| 1099 | FUN_004145C0 | MISSING_ENTRY |
| 1100 | FUN_00474BA0 | MISSING_ENTRY |
| 1101 | FUN_0048EAA0 | MISSING_ENTRY |
| 1102 | FUN_004B29B0 | MISSING_ENTRY |
| 1103 | FUN_004DEDB0 | MISSING_ENTRY |
| 1104 | FUN_0052A0A1 | MISSING_ENTRY |
| 1105 | FUN_005822B0 | MISSING_ENTRY |
| 1106 | FUN_0058D7C3 | MISSING_ENTRY |
| 1107 | FUN_004530A0 | MISSING_ENTRY |
| 1108 | FUN_00479D00 | MISSING_ENTRY |
| 1109 | FUN_0049A990 | MISSING_ENTRY |
| 1110 | FUN_004C8D60 | MISSING_ENTRY |
| 1111 | FUN_0050E7CB | MISSING_ENTRY |
| 1112 | FUN_0054C290 | MISSING_ENTRY |
| 1113 | FUN_00556650 | PASS |
| 1114 | FUN_00474C70 | MISSING_ENTRY |
| 1115 | FUN_004D0F00 | MISSING_ENTRY |
| 1116 | FUN_00561FF0 | MISSING_ENTRY |
| 1117 | FUN_00598E39 | MISSING_ENTRY |
| 1118 | FUN_0045BE70 | MISSING_ENTRY |
| 1119 | FUN_004855A0 | MISSING_ENTRY |
| 1120 | FUN_0049A9E0 | MISSING_ENTRY |
| 1121 | FUN_004C8180 | MISSING_ENTRY |
| 1122 | FUN_005076FE | MISSING_ENTRY |
| 1123 | FUN_00556700 | PASS |
| 1124 | FUN_0059A86C | MISSING_ENTRY |
| 1125 | FUN_00408500 | PASS |

**Stats:**
- PASS: 8 (verified entries match source)
- FAIL: 0 (no errors found in existing entries)
- MISSING_ENTRY: 47 (no `## FUN_` header in target doc)
- SKIP: 0
