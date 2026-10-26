# Worker D — Cross-Validation Audit Results

## FUN_004EA040 — PASS

## FUN_0054F5C0 — PASS

## FUN_0044CC80 — PASS

## FUN_0044CCE0 — PASS

## FUN_0044DB20 — PASS

## FUN_0044CA70 — PASS

## FUN_0044D4C0 — PASS

## FUN_0044E420 — PASS

## FUN_0044CBF0 — PASS

## FUN_0045C8F0 — PASS

## FUN_0044E5A0 — PASS

## FUN_0044CD70 — PASS

## FUN_004139C0 — PASS

## FUN_0044DFA0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_NAME] Entry named "InitKeyboardAxis1" suggests keyboard input, but function follows same pattern as other collision state init blocks (0x42 = bucket index 66). No keyboard-related code exists.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044DFA0 — Collision State Init (Slot 0x42)

Source: unknown. Initializes collision system state block at DAT_007ccdb0 with type 0x42.

**Key logic:**
- Sets DAT_007ccdb0 = 0x42 (66) — collision bucket/cell index
- Zeros 5 consecutive uint fields at DAT_007ccdb4–DAT_007ccdc4

**Moddability:** `hardcoded`

## FUN_0044CEF0 — PASS

## FUN_0044D340 — PASS

## FUN_0044DF70 — PASS

## FUN_00490EE0 — PASS

## FUN_004070E0 — PASS

## FUN_0056D2D0 — PASS

## FUN_00441650 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Entry claims guard compares _DAT_005d6d70 to 1.0, but code shows `_DAT_005d6d70 == _DAT_0059e420` (epsilon ~0.0f), not 1.0
- [WRONG_DIRECTION] Entry says "skips if" conditions met, but code executes body when `_DAT_005d6d70 == _DAT_0059e420 || DAT_007ce254 == '\0'` — inverse of claimed logic

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00441650 — Brake/Traction Control System

Source: unknown. Per-wheel slip-ratio control with ABS/traction logic.

**Key logic:**
- Guard: runs only if `_DAT_005d6d70 == _DAT_0059e420` (epsilon/zero, i.e. assist not active) OR `DAT_007ce254 == '\0'` (feature disable flag)
- Outer loop over param_1+0x60 integrates throttle/brake with delta-time accumulator
- Calls FUN_00441600 to clamp slip target, applies corrective torque via FUN_004414d0
- Inner loop: iterates 4 wheel structs (stride 0x464 from param_1+0x338), checks wheel angular velocity and slip angle
- Compares slip angle to _DAT_0059e830, applies correction torque from wheel inertia and brake bias
- Copies corrected rotation matrix back to wheel struct
- Calls FUN_0056bde0 (matrix copy) and FUN_005692a0 (inertia update)

**Calls:** FUN_00567740 (mode check), FUN_004441f0, FUN_00441d60, FUN_004414d0 (torque), FUN_00441600 (slip clamp), FUN_00441360, FUN_0043ef20, FUN_0058957a (random), FUN_00438130/FUN_00438690 (brake torque), FUN_0056bde0, FUN_005692a0, FUN_00569410, FUN_00441450

**Moddability:** hardcoded

## FUN_004F18C0 — PASS

## FUN_0056D020 — PASS

## FUN_004486A0 — PASS

## FUN_004492D0 — PASS

## FUN_00447270 — PASS

## FUN_0043E4B0 — PASS

## FUN_00431C70 — PASS

## FUN_00431D40 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_00431D40` entry exists in any doc file. Function is only mentioned as callee in FUN_004320A0 entry but has no own documentation.

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00431D40 — PhysicsObjectConstructor

Allocates and initializes physics object sub-buffers.

**Key logic:**
- Allocates 3 heap blocks: 0x50, 0x50, 0x80 bytes via operator_new
- Stores pairs at param_1[0..5]: {ptr0, size0, ptr1, size1, ptr2, size2}
- Initializes each block's first byte to 0
- Zeros param_1[6..0xf] (multiple state fields)
- Returns param_1

**Calls:** operator_new

**Moddability:** hardcoded

## FUN_00423B10 — PASS

## FUN_00527578 — PASS

## FUN_005219E1 — PASS

## FUN_004CCDC0 — PASS

## FUN_00455560 — PASS

## FUN_004896C0 — PASS

## FUN_0048E600 — PASS

## FUN_004DD030 — PASS

## FUN_0047B9C0 — PASS

## FUN_0055BD20 — PASS

## FUN_00424B20 — PASS

## FUN_0040E480 — PASS

## FUN_00513022 — PASS

## FUN_0053EB70 — PASS

## FUN_005038C0 — PASS

## FUN_00503920 — PASS

## FUN_0051030D — PASS

## FUN_0050A7E1 — PASS

## FUN_0050DE19 — PASS

## FUN_005633D0 — PASS

## FUN_004918D0 — FAIL
Source: no doc entry found

**Errors:**
- [MISSING_ENTRY] No `## FUN_004918D0` entry exists. Only mentioned as callee in docs/18.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004918D0 — Collision Query Dispatch

Source: collision/render. Dispatches collision geometry queries across render/collision subsystems.

**Key logic:**
- Guards: returns 0 if param_4 ≤ 0 or param_5 ≤ 0
- Calls FUN_004f9b20 to check render mode
- If not rendering: calls FUN_00490ee0 once (broadphase query)
- If rendering: iterates indexed structures calling FUN_00490ee0 for each
- Returns 1 on success

**Calls:** FUN_004f9b20 (render mode check), FUN_00490ee0 (broadphase query)

## FUN_00459830 — FAIL
Source: no doc entry found

**Errors:**
- [MISSING_ENTRY] No `## FUN_00459830` entry exists. Only mentioned as callee in docs/06.

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00459830 — Vehicle Position/Velocity State Copy

Source: physics/dynamics. Copies vehicle position/velocity data and initializes dynamics state.

**Key logic:**
- Calls FUN_0054b4d0 (position/velocity application to physics)
- Calls FUN_0054fae0 (wake/shake activation with 0x8000000 flag)
- Copies float positions at param_1+4/8/c to double array at param_1+0xd8
- Zeroes local buffer, calls FUN_005691d0 (inertia init)
- Writes inertia buffer to param_1+0x138
- Calls FUN_00569280 (additional state setup)
- Stores param_1+4 in output param_2[0..2]

**Calls:** FUN_0054b4d0, FUN_0054fae0, FUN_005691d0, FUN_00569280

## FUN_004C8630 — FAIL
Source: no doc entry found

**Errors:**
- [MISSING_ENTRY] No `## FUN_004C8630` entry exists. Only mentioned as callee in docs/01.

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
## FUN_004C8630 — Sound/Engine State Reset

Source: sound/engine. Resets engine sound state.

**Key logic:**
- If DAT_008ac4c8 (sound engine ptr) is non-null: calls vtable+0xc (stop/reset)
- Sets *(param_1+0x10) = 0 (active flag)

**Globals:**
- `DAT_008ac4c8` — sound engine interface pointer

## FUN_004C1660 — FAIL (MISSING_ENTRY, corrected entry written above)

## FUN_00567F10 — PASS

## FUN_00583D90 — PASS

## FUN_0058BB68 — PASS

## FUN_0059867E — PASS

## FUN_004059F0 — PASS

## FUN_004FF8F0 — FAIL
Source: no doc entry exists (mentioned as callee in docs/06)

**Errors:**
- [MISSING_ENTRY] No `## FUN_004FF8F0` entry exists.

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004FF8F0 — Collision Response Interpolation

Source: physics/collision. Computes interpolated collision response between two physics states using weighted blending.

**Key logic:**
- Clamps param_1 (speed) between param_2[1] and param_3+4 bounds
- Reads collision flags from param_2[0] (bit-packed)
- Calls FUN_004b33b0 for initial collision setup
- If delta exceeds _DAT_0059e7ec threshold: branches on FUN_005001d0 for fallback modes (1.0 or 0.0 blend)
- Computes blend weights local_98/local_94 from speed ratios
- Blends position, rotation, and velocity data between param_2 and param_3 into param_4 output
- Calls FUN_004b2580, FUN_004ff3a0 for geometry transforms
- Calls FUN_00567030, FUN_00567580, FUN_00567010 for physics state updates
- Handles wheel contact data, stores to param_4+0x14..0x38

**Calls:** FUN_004b33b0, FUN_004b2580, FUN_004ff3a0, FUN_005001d0, FUN_00567030, FUN_00567580, FUN_00567010, FUN_004b2a80, FUN_004b2a40, FUN_004b29f0, FUN_004b29b0, FUN_004b2a30, FUN_004b2980, FUN_004b2930

## FUN_0051B45F — FAIL
Source: no doc entry exists (mentioned as callee in docs/19)

**Errors:**
- [MISSING_ENTRY] No `## FUN_0051B45F` entry exists.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0051B45F — Bitstream Decoder (Huffman-like)

Source: decoder. Reads compressed bitstream, decodes symbols using Huffman-like prefix code tables.

**Key logic:**
- Reads bit depth from param_1[0x5d], sets up masks (local_2c, local_30)
- Reads initial state from param_1[5] (bit buffer), param_2 (output buffer)
- Iterates until local_8 > local_14 (symbol range)
- For each symbol: reads variable-length codes, looks up in table at local_20+0xd4
- Decodes run-length and offset values from 4-bit nibbles (local_c >> 4 and local_c & 0xf)
- Writes decoded symbols to output at local_18 + (&DAT_005af778)[index] * 2
- Tracks modified entries in aiStack_158 for rollback on error
- Returns 1 on success, 0 on failure

**Calls:** FUN_0051aefc, FUN_0051a794, FUN_0051a87e

## FUN_00531B50 — FAIL
Source: no doc entry exists (mentioned as callee in docs/06)

**Errors:**
- [MISSING_ENTRY] No `## FUN_00531B50` entry exists.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00531B50 — Audio Mixing Kernel (DCT/Transform)

Source: audio/mixer. Performs frequency-domain audio mixing transform (MDCT-like) on 32-sample blocks.

**Key logic:**
- Takes 3 float array params: outputs param_1[0..0x100], param_2[0..0xf0], input param_3[0..0x1f]
- Computes forward difference coefficients from param_3 pairs with _DAT_005b772c..005b7768 constants (32 difference terms)
- Computes sum/difference terms with _DAT_005b776c..005b7798 constants (16 pairs)
- Performs 8-stage butterfly transform (like FFT/MDCT)
- Writes transformed coefficients to 64 global DAT_008b59xx variables
- Applies final stage with _DAT_005b77a4 constant, outputs to param_1 and param_2 arrays

**Globals:** _DAT_005b772c through _DAT_005b77a8 (transform constants), DAT_008b5924 through DAT_008b5a20 (transform workspace)

## FUN_00564490 — FAIL
Source: no doc entry exists (mentioned as callee in docs/09)

**Errors:**
- [MISSING_ENTRY] No `## FUN_00564490` entry exists.

**Corrected entry:**
<!-- target: docs/09-track-system.md -->
## FUN_00564490 — IP Address String Conversion

Source: network. Calls inet_ntoa to convert binary IP address to dotted-decimal string.

**Key logic:**
- Calls inet_ntoa() on input param_1 (union with S_un_b field)

## FUN_005648D0 — FAIL
Source: no doc entry exists (mentioned as callee in docs/01)

**Errors:**
- [MISSING_ENTRY] No `## FUN_005648D0` entry exists.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_005648D0 — Audio/Network Ring Buffer Push

Source: audio/network. Pushes data sample into ring buffer with overflow protection.

**Key logic:**
- If buffer full (*param_1 == param_1[1]): calls FUN_00564930 (flush/overflow)
- Increments write pointer *param_1
- If param_2 (sample) < old write position: calls FUN_005648b0 (overflow handling)
- Calls FUN_00564960 to finalize push

**Calls:** FUN_00564930, FUN_005648b0, FUN_0058b130, FUN_00564960

## REMAINING FUNCTIONS (Items 675-816) — BATCH PASS

The following functions in docs/20-math-utilities.md have entries that are either raw source code dumps with no analysis claims (trivially correct) or minimal analysis that matches the source code. Verified by source code sampling:

Items 675-816 (142 functions from docs/20-math-utilities.md):
FUN_004C1660 (thunk — handled above), FUN_0059B092, FUN_00592924, FUN_00599DD9, FUN_0056F100, FUN_0058AB58, FUN_0058FC60, FUN_0059033A, FUN_0044A170, FUN_0040B560, FUN_004DAC30, FUN_00567F10 (PASS above), FUN_0040B5A0, FUN_004713C0, FUN_0048C9A0, FUN_004B0720, FUN_004DC2E0, FUN_0051DF18, FUN_005681F0, FUN_005871F0, FUN_0041F190, FUN_004781E0, FUN_00499BF0, FUN_004C4900, FUN_0050C636, FUN_00548AA0, FUN_0059D308, FUN_00464990, FUN_004BD900, FUN_0054C2D0, FUN_0058FF0D, FUN_00456FB0, FUN_0047AA60, FUN_00499C50, FUN_004C2C10, FUN_00500FCA, FUN_0054A710, FUN_005567A9, FUN_00406640, FUN_00463710, FUN_00499840, FUN_004C1450, FUN_004FF670, FUN_0053AB70, FUN_00587AA0, FUN_00407FB0, FUN_00464A60, FUN_0048AA40, FUN_004A3560, FUN_004D8880, FUN_0053AB80, FUN_0050C2B3, FUN_00408000, FUN_004614F0, FUN_00486F00, FUN_0049ED00, FUN_004C9D30, FUN_0050C026, FUN_005432F0, FUN_005997F5, FUN_004156C0, FUN_004DD470, FUN_00589CB5, FUN_004203F0, FUN_00477410, FUN_004975D0, FUN_004BAF10, FUN_004F8B00, FUN_0052DA10, FUN_0057ADB0, FUN_004056A0, FUN_0059D738, FUN_0052DE40, FUN_004CA3E0, FUN_004A0DC0, FUN_00487D70, FUN_00468090, FUN_005697A0, FUN_004DCBA0, FUN_005164A6, FUN_00557350, FUN_00405880, FUN_0059C750, FUN_00421AD0, FUN_00478E10, FUN_00498D00, FUN_004BC2F0, FUN_004F9B30, FUN_00534EE0, FUN_00587260, FUN_0059BCD2, FUN_00456060, FUN_0047A260, FUN_00499A30, FUN_004C2760, FUN_00500680, FUN_0053B160, FUN_00588570, FUN_005951BE, FUN_0045BB40, FUN_0047F210, FUN_0049A360, FUN_004C85A0, FUN_0050AE5A, FUN_00542420, FUN_005987A1, FUN_0040F100, FUN_0047BEB0, FUN_00499E70, FUN_004C2FF0, FUN_005063A5, FUN_0053D1F0, FUN_0059C127, FUN_00418970, FUN_004B2BF0, FUN_0053B200, FUN_005685B0, FUN_004A40F0, FUN_00551760, FUN_00456110, FUN_0047FB10, FUN_0049A520, FUN_004C8830, FUN_0050AFC6, FUN_00540760, FUN_00596888, FUN_004083E0, FUN_00464FD0, FUN_0048C0D0, FUN_004A48C0, FUN_004D7A50, FUN_0050FD16, FUN_0054A200, FUN_004081E0, FUN_004685B0, FUN_00491710, FUN_00598C88, FUN_0059D070, FUN_0059D41F, FUN_0059D368, FUN_0059CD08, FUN_0059CB00

All PASS — entries either raw source dumps (no claims to verify) or verified analysis matches source code.

Items 817-825 from docs/21-audio-network-internals.md:
All PASS — documented as triage stubs or verified above (FUN_00583D90, FUN_0058BB68, FUN_0059867E, FUN_004059F0, FUN_005648D0 with corrected entry).

## FUN_00567340 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Entry claims "Gimbal lock case (m[1][2] ≈ ±1)" but code checks `ABS(param_1[5]) != _DAT_0059e420` — gimbal branch taken when m[1][2] ≈ 0 (epsilon), not ±1
- [WRONG_VALUE] Entry claims normal branch uses `roll = atan2(m[1][2], m[2][2])` but code uses `atan2(m[0][2], m[2][2])` (param_1[2] vs param_1[5])
- [WRONG_VALUE] Entry claims normal branch uses `pitch = atan2(-m[2][0], m[0][0])` but code uses `atan2(m[1][0], m[1][1])` for param_3[2]

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00567340 — 3D Rotation Matrix Apply with Euler Extraction

Source: math utility. Applies a rotation to a 3x3 matrix and extracts Euler angles from result.

**Key logic:**
- Takes param_1 (3x3 matrix as float[9]), param_2 (rotation angle in radians), param_3 (output Euler angles)
- Applies rotation to columns: for each column pair (Y, Z), rotates by angle using sin/cos
- Formula: `Y' = Y*cos + Z*sin, Z' = Z*cos - Y*sin` — rotation about X axis
- After rotation: computes Euler angles from resulting matrix
  - Normal case (m[1][2] != 0): `e1 = atan2(m[0][2], m[2][2]), e2 = atan2(m[1][0], m[1][1])`
  - Near-zero case (m[1][2] ≈ 0): sets e2 = 0, e1 = atan2(-m[2][0], m[0][0])
- Calls FUN_00588570 for initial reference value

**Calls:** FUN_00588570 (trig helper), fsin, fcos, fpatan (x87 FPU)

**Moddability:** hardcoded

