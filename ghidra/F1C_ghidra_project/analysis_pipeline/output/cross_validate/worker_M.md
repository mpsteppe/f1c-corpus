# Worker M — Cross-Validation Audit Results
Functions 2474–2679 (206 functions)

---

## FUN_00549470 — PASS

## FUN_004e9a40 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_CONST] Text says "stride 3 floats = 0x39 bytes apart" but 3 floats = 12 bytes = 0xc.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_004e9a40 — Vehicle Collision Probe

Source: likely_collision_vehicle.cpp. Transforms world-space point into vehicle body-local space and checks against 13 collision probe points.

**Key logic:**
- Reads world-space velocity at param_1 +0x3b60/0x3b64/0x3b68
- Optionally adds external impulse from param_2 (scaled by `_DAT_0059e87c`)
- Subtracts vehicle body position (+0x34d4/+0x34d8/+0x34dc)
- Rotates by inverse orientation matrix (+0x34b0 through +0x34d0, 3×3)
- Subtracts wheel hub offset (+0x72c/+0x730/+0x734) to get local deflection
- Loops 13 times (0xd) — iterates collision probe points starting at param_1 + 0x3abc (stride 3 floats = 12 bytes)
- Calls `FUN_0054fa00` for each probe (collision response resolver)
- Computes magnitude of local velocity
- Clamps minimum magnitude to value at param_1 + 0x3b6c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34b0..+0x34d0 | BodyRotMatrix | 3×3 orientation, column-major |
| +0x34d4..+0x34dc | BodyPos | world position |
| +0x3abc | CollisionProbes | 13×3 float probe points |
| +0x3b60 | VelocityX | world-space velocity |
| +0x3b64 | VelocityY | |
| +0x3b68 | VelocityZ | |
| +0x3b6c | MinClamp | minimum velocity threshold |
| +0x72c | WheelHubOffset | hub position in body space |

**Globals:** `_DAT_0059e87c` — impulse scale factor

**Calls:** FUN_0054fa00 (collision response)

**Moddability:** hardcoded

## FUN_0044d0d0 — PASS

## FUN_0044cd40 — PASS

## FUN_0044e0f0 — PASS

## FUN_0044dbe0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says "configurable" but function is pure static init with no parameters or file reads.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044dbe0 — Collision Static Init (5 constants)

Source: collision system. Initializes 5 global collision constants to hardcoded values.

**Key logic:**
- DAT_007ca51c = 1084227584 (25.0f)
- _DAT_007ca520 = 1075838976 (2.5f)
- _DAT_007ca524 = 0x3f000000 (0.5f)
- _DAT_007ca528 = 0x3e800000 (0.25f)
- _DAT_007ca52c = 0x3f000000 (0.5f)

**Globals:** DAT_007ca51c–DAT_007ca52c — collision constants

**Calls:** none

**Moddability:** hardcoded

## FUN_00464a40 — PASS

## FUN_0044e9f0 — PASS

## FUN_0044dd60 — PASS

## FUN_00466030 — PASS

## FUN_0044eb70 — PASS

## FUN_0044dee0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Entry says "configurable" but source shows pure constant assignments with no config reads.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044dee0 — Collision Static Init (6 constants)

Source: collision system. Initializes 6 more global collision constants.

**Key logic:**
- DAT_007ca530 = 0x3c8efa35 (0.017453f — deg→rad)
- _DAT_007ca534 = 0x3c8efa35 (same constant)
- _DAT_007ca538 = 0x3f800000 (1.0f)
- DAT_007ca53c = 0x3dcccccd (0.1f)
- _DAT_007ca540 = 0x3f000000 (0.5f)
- DAT_007ca544 = 0x3f800000 (1.0f)

**Globals:** DAT_007ca530–DAT_007ca544 — collision constants

**Calls:** none

**Moddability:** hardcoded

## FUN_0044c6b0 — PASS

## FUN_0044ecf0 — PASS

## FUN_0044cb60 — PASS

## FUN_0044f0a0 — PASS

## FUN_0044a450 — PASS

## FUN_00497260 — PASS

## FUN_0056e970 — PASS

## FUN_004f8440 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Doc says "5 sub-systems" but loop runs 40 iterations (0x28)
- [WRONG_MODDABILITY] "configurable" but no config string literal in source

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004f8440 — Vehicle Sub-System Update Dispatcher

Source: likely vehicledynamics.cpp. Iterates 40 vehicle sub-system slots, updating those that are active.

**Key logic:**
- Loops iVar2 from 0 to 39 (0x28)
- For each slot, checks if bit at offset +0x58 is set (enabled flag)
- If enabled: reads subsystem function pointer from array at param_1+0x249c, calls it with param_1 and slot index
- All 40 slots share same vehicle instance pointer

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x249c | SubSystemFuncs | 40 function pointers |
| +0x58 | SubSystemEnabled | bitfield per slot |

**Calls:** indirect via subsystem function pointer table

**Moddability:** hardcoded

## FUN_0044657d — PASS

## FUN_004e88b0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Mode descriptions inaccurate — uses max not average; no 0.333 factor in mode 1

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004e88b0 — Multi-Mode Resolve

Source: unknown. Applies resolution computation with 3 modes selected by param_2.

**Key logic:**
- Reads 4 params (float at param_1+0x384, param_1+0x4f8, two stack floats p1, p2)
- Mode 0: returns param_1+0x384 (direct passthrough)
- Mode 1: `val = param_1+0x4f8 * 2.0f - p1 - p2` (difference from double-max)
  - If val < 0, returns 0; if val > p1, returns p1; else returns val
- Mode 2: `val = (param_1+0x384 + p1) * 0.5f` (half-sum)
  - If val < 0, returns 0; if val > p1, returns p1; else returns val (clamped)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x384 | ValueA | base value |
| +0x4f8 | ValueB | double-max reference |

**Calls:** none

**Moddability:** hardcoded

## FUN_004adf10 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_FIELD] Doc claims +0x1d08=75 is gear ratio, but value is MaxSpeed (speed cap)
- [WRONG_MODDABILITY] "configurable" but no config string literal in source

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004adf10 — Gearbox Speed Clamp

Source: likely gearbox.cpp. Clamps output speed to per-gear maximum and returns modified value.

**Key logic:**
- Reads speed cap from param_1 + 0x1d08 + param_2*4 (array indexed by gear param_2)
- If input speed > cap, returns cap; otherwise returns input unchanged

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1d08 | GearMaxSpeed | array of floats, one per gear |

**Calls:** none

**Moddability:** hardcoded

## FUN_00431bc0 — PASS

## FUN_00433370 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_MODDABILITY] "configurable" but source shows only field assignments with no config string

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00433370 — Vehicle Model Init

Source: likely vehicleinit.cpp. Initializes vehicle model parameters.

**Key logic:**
- Sets param_1+0x60 to 0 (initial state)
- Sets param_1+0x64 to param_2 (model flag)
- Sets param_1+0x95c = 0x3f800000 (1.0f default scalar)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x60 | InitState | initial state flag |
| +0x64 | ModelFlag | from param_2 |
| +0x95c | DefaultScale | initialized to 1.0f |

**Calls:** none

**Moddability:** hardcoded

## FUN_0047a290 — PASS

## FUN_004484c0 — PASS

## FUN_0043e230 — PASS

## FUN_0056c2d0 — PASS

## FUN_004b1de0 — PASS

## FUN_0052ab4e — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_TYPE] Doc claims SSE float transform but source uses MMX pmaddwd (16-bit integer multiply-add)
- [WRONG_LOGIC] Not a D3D vertex transform — integer dot product accumulation

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0052ab4e — MMX Packed Dot Product

Source: likely math_mmx.asm. Computes dot products using MMX pmaddwd instruction.

**Key logic:**
- Uses MMX instructions for packed 16-bit integer multiply-add (pmaddwd)
- Accumulates results into 32-bit integer sums
- Falls back to scalar code path for remaining elements

**Calls:** none (inline MMX)

**Moddability:** hardcoded — MMX math utility

## FUN_004dd9f0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_MODDABILITY] "configurable" but no config string literal in source

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004dd9f0 — Plane Equation from Triangle

Source: likely collision_math.cpp. Computes plane equation (normal + distance) from 3 vertices.

**Key logic:**
- Takes vec3 pointers: param_1, param_2, param_3 (triangle vertices)
- Computes two edge vectors: param_2-param_1, param_3-param_1
- Cross product for normal
- Normalizes to unit length
- Computes signed distance: dot(normal, param_1)
- Returns as float (distance)

**Calls:** FUN_00593650 (normalize), FUN_00594ec2 (cross product)

**Moddability:** hardcoded

## FUN_004c7f30 — PASS

## FUN_00413600 — PASS

## FUN_004862e0 — PASS

## FUN_00489c60 — PASS

## FUN_00496930 — PASS

## FUN_0049a2b0 — PASS

## FUN_0059b0f5 — PASS

## FUN_00506ce2 — PASS

## FUN_005404d0 — PASS

## FUN_0050eb73 — PASS

## FUN_0044f8f0 — PASS

## FUN_00542050 — PASS

## FUN_004cfcc0 — PASS

## FUN_0044d3d0 — PASS

## FUN_00516990 — PASS

## FUN_0048f1a0 — PASS

## FUN_005878a0 — PASS

## FUN_0050dcb0 — PASS

## FUN_004560c0 — PASS

## FUN_004dc0b0 — PASS

## FUN_0047c0d0 — PASS

## FUN_0053c4d0 — PASS

## FUN_00550f70 — PASS

## FUN_00582a10 — PASS

## FUN_00596c80 — PASS

## FUN_00584130 — PASS

## FUN_0058c331 — PASS

## FUN_00553700 — PASS

## FUN_00564f10 — PASS

## FUN_005894bd — PASS

## FUN_0059942b — PASS

## FUN_00588864 — PASS

## FUN_00479760 — PASS

## FUN_00539830 — PASS

## FUN_00561a86 — PASS

## FUN_0045b310 — PASS

## FUN_00485510 — PASS

## FUN_004980c0 — PASS

## FUN_004bd860 — PASS

## FUN_00506fd9 — PASS

## FUN_00540eb0 — PASS

## FUN_005993af — PASS

## FUN_00405050 — PASS

## FUN_00463140 — PASS

## FUN_00488970 — PASS

## FUN_004b20d0 — PASS

## FUN_004dc310 — PASS

## FUN_0051dfcb — PASS

## FUN_00582fd0 — PASS

## FUN_00405160 — PASS

## FUN_00495920 — PASS

## FUN_00512144 — PASS

## FUN_00599485 — PASS

## FUN_0040b6f0 — PASS

## FUN_004670e0 — PASS

## FUN_0048d6f0 — PASS

## FUN_004b1375 — PASS

## FUN_004d8840 — PASS

## FUN_00513d3d — PASS

## FUN_00586ed0 — PASS

## FUN_004734a0 — PASS

## FUN_00418d60 — PASS

## FUN_0048c9f0 — PASS

## FUN_004a57f0 — PASS

## FUN_004d7c10 — PASS

## FUN_00511060 — PASS

## FUN_0054a730 — PASS

## FUN_00564ab0 — PASS

## FUN_0041fdf0 — PASS

## FUN_00477080 — PASS

## FUN_00497510 — PASS

## FUN_004bbed0 — PASS

## FUN_0050ed19 — PASS

## FUN_005836e0 — PASS

## FUN_0059c5e4 — PASS

## FUN_00414140 — PASS

## FUN_004717e0 — PASS

## FUN_00491db0 — PASS

## FUN_004b4f50 — PASS

## FUN_004dfb00 — PASS

## FUN_005198b3 — PASS

## FUN_005631a0 — PASS

## FUN_00567900 — PASS

## FUN_004988a0 — PASS

## FUN_0054fe10 — PASS

## FUN_00405670 — PASS

## FUN_00462380 — PASS

## FUN_00487d50 — PASS

## FUN_004a0db0 — PASS

## FUN_004ce8f0 — PASS

## FUN_0050cdec — PASS

## FUN_00546f30 — PASS

## FUN_0059b24a — PASS

## FUN_00567980 — PASS

## FUN_0053c190 — PASS

## FUN_0050b409 — PASS

## FUN_004bdf90 — PASS

## FUN_0049adb0 — PASS

## FUN_004856c0 — PASS

## FUN_0045c030 — PASS

## FUN_004c2f20 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [PARTIAL] Doc says "[PARTIAL] Unknown" but source shows unambiguous linked list destructor.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_004c2f20 — Linked List Destructor

Source: likely datastruct.cpp. Frees all nodes in a singly-linked list.

**Key logic:**
- Walks linked list from head pointer
- Frees each node in sequence
- Null-terminates after free

**Calls:** operator_delete (via __delete)

**Moddability:** hardcoded

## FUN_00502bea — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [PARTIAL] Doc says "[PARTIAL] Unknown" but source shows trivial double field zero-init.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_00502bea — Double Field Zero

Source: unknown. Zeroes a double field at param_1+0x28.

**Key logic:**
- Sets *(double *)(param_1 + 0x28) = 0.0

**Calls:** none

**Moddability:** hardcoded

## FUN_0053c1b0 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [PARTIAL] Doc says "[PARTIAL] Unknown" but source shows callback registration via FUN_00587b3e.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_0053c1b0 — Callback Registration

Source: unknown. Registers a callback/static data block.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0053c1c0) — registers callback at data address

**Calls:** FUN_00587b3e (register callback)

**Moddability:** hardcoded

## FUN_0058a8a3 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [PARTIAL] Doc says "[PARTIAL] Unknown" but source shows clear IEEE 754 float classification.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_0058a8a3 — IEEE 754 Float Classify

Source: likely math_util.cpp. Classifies a double-precision float as NaN, Inf, denormal, zero, or normal.

**Key logic:**
- Extracts exponent and mantissa bits from 64-bit double
- Returns classification code matching _fpclass() behavior

**Calls:** none

**Moddability:** hardcoded

## FUN_00585fb0 — PASS

## FUN_00401090 — PASS

## FUN_00463dc0 — PASS

## FUN_00489450 — PASS

## FUN_004a1fd0 — PASS

## FUN_004d4790 — PASS

## FUN_0050e04f — PASS

## FUN_005478b0 — PASS

## FUN_0059cf70 — PASS

## FUN_0040ac00 — PASS

## FUN_00466250 — PASS

## FUN_0048d2b0 — PASS

## FUN_004a8b10 — PASS

## FUN_004d7e30 — PASS

## FUN_00511869 — PASS

## FUN_0054bc60 — PASS

## FUN_0059d806 — PASS

## FUN_0040dd80 — PASS

## FUN_0046c6f0 — PASS

## FUN_0048fd60 — PASS

## FUN_004b2b80 — PASS

## FUN_004dcd60 — PASS

## FUN_00517ec8 — PASS

## FUN_0055c9c0 — PASS

## FUN_00595207 — PASS

## FUN_0045c750 — PASS

## FUN_0048e6a0 — PASS

## FUN_004b1a90 — PASS

## FUN_004d9280 — PASS

## FUN_00515917 — PASS

## FUN_00552fd0 — PASS

## FUN_0058e0c7 — PASS

## FUN_004979e0 — PASS

## FUN_004dcda0 — PASS

## FUN_0055d230 — PASS

## FUN_00404ef0 — PASS

## FUN_005295e0 — PASS

## FUN_00405f80 — PASS

## FUN_0046cb00 — PASS

## FUN_0048fe30 — PASS

## FUN_004b2c50 — PASS

## FUN_004dcee0 — PASS

## FUN_00516959 — PASS

## FUN_00559f00 — PASS

## FUN_0057b7f0 — PASS

## FUN_00421930 — PASS

## FUN_00478140 — PASS

## FUN_00497ec0 — PASS

## FUN_004bb4f0 — PASS

## FUN_004f8ea0 — PASS

## FUN_0052e520 — PASS

## FUN_0057ef20 — PASS

## FUN_00421470 — PASS

## FUN_0047f080 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISSING_LOGIC] Doc says "Forwards call, no additional logic" but source sets vtable pointer and calls FUN_00488b00.

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_0047f080 — Init + VTable Set

Source: unknown. Initializes object with vtable and calls setup function.

**Key logic:**
- Calls FUN_00488b00(1, 0xffffffff)
- Sets vtable pointer PTR_LAB_005a6dc8
- Returns param_1

**Calls:** FUN_00488b00 (setup/init)

**Moddability:** hardcoded

## FUN_0049a2e0 — PASS

## FUN_0059c804 — PASS

## FUN_005888a6 — PASS

## FUN_0059c56e — PASS

## FUN_00599b86 — PASS

## FUN_0059d1b8 — PASS

## FUN_00405b90 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_TRIAGE] Triage "Miles Sound System call" misses 3D positional audio logic (distance, panning, doppler)

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00405b90 — 3D Positional Audio Update

Source: likely audio3d.cpp. Updates 3D audio sample with distance attenuation, directional panning, and doppler shift.

**Key logic:**
- Calculates 3D distance between source and listener (SQRT of vector deltas)
- Normalizes direction vector
- Applies distance-based volume attenuation
- Sets left/right channel volume via Miles AIL API
- Sets playback rate for doppler/pitch shift
- Optionally starts/resumes sample playback
- Branches on session type flag and bitfield flags

**Globals:** _DAT_0059e43c, DAT_0059e440, DAT_008aae70

**Calls:** AIL_set_sample_volume_levels, AIL_set_sample_playback_rate, FUN_00406060

**Moddability:** hardcoded

## FUN_00596030 — PASS

## FUN_005527c0 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_CATEGORY] Triage "crt_util" is wrong. Source shows DirectX device/resource buffer init.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_005527c0 — DirectX Resource Buffer Init

Source: likely renderdevice.cpp. Allocates and initializes DirectX device resource buffer.

**Key logic:**
- Allocates 0x24 bytes via operator_new
- Writes constants: 0x22, 0x300, 0x1c
- Calls FUN_00540df0 (device create), FUN_00540f00 (buffer alloc with 0x60 entries)
- Initializes each entry with 0 and 1.0f
- Checks enable flag at +0x24 & 0x20000

**Globals:** DAT_008cef78

**Calls:** FUN_00540df0, FUN_00540f00, FUN_00540f90

**Moddability:** hardcoded

## FUN_00457b60 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_CATEGORY] Triage "math_util/float computation" is misleading. Source shows struct copy/initializer with 15+ field copies.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00457b60 — Game Data Struct Copy

Source: likely gamedata.cpp. Copies game data struct fields from template to destination.

**Key logic:**
- Calls FUN_00415c30() (get context)
- Calls FUN_00566650() (push state)
- Copies 15+ struct fields from param_2 to param_1
- Queries sub-functions for field values
- Computes one square: param_1+0x8c = param_2+0x88 ^ 2

**Calls:** FUN_00415c30, FUN_00566650, FUN_00456110, FUN_00456130, FUN_00456040, FUN_00456060, FUN_00456080, FUN_004560a0, FUN_004560c0, FUN_004560e0

**Moddability:** hardcoded

## FUN_00514fee — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [PARTIAL] Triage "unidentified logic" is honest but function has clear quaternion/4D interpolation structure.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00514fee — 4D Vector Interpolation with Bitfield Lane Select

Source: likely interpolation.cpp. Interpolates between 4D vectors with bitfield lane selection.

**Key logic:**
- Reads two ushorts, conditionally interpolates between values
- Uses global interpolation constants: _DAT_0059e98c, _DAT_005ad1f4, _DAT_0059e450
- Extracts 2-bit indices from bitfield to select among 4 lanes
- Writes selected interpolated values to output

**Globals:** _DAT_0059e98c, _DAT_005ad1f4, _DAT_0059e450

**Calls:** FUN_00513d63

**Moddability:** hardcoded

## FUN_0057b9a0 — PASS

## FUN_00551cf0 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_CATEGORY] Triage line 4486 says "audio" but source shows Bink video frame advance.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00551cf0 — Bink Video Frame Advance

Source: likely binkplay.cpp. Advances Bink video by one frame, copies to render buffer, detects loop completion.

**Key logic:**
- Calls BinkWait, BinkDoFrame, BinkNextFrame
- Maps video format codes
- Copies frame to rendering surface via BinkCopyToBuffer
- Returns true when frame loop wraps around

**Calls:** BinkWait, BinkDoFrame, BinkNextFrame, BinkCopyToBuffer, FUN_00543210, FUN_00543230

**Moddability:** hardcoded

## FUN_00598648 — PASS

## FUN_0053d470 — FAIL
Source: docs/21-audio-network-internals.md

**Errors:**
- [WRONG_CATEGORY] Triage "math_util/arithmetic" is wrong. Source shows object constructor with operator_new(0x30).

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_0053d470 — Hash/Map Object Constructor

Source: likely datastruct.cpp. Allocates and initializes a hash/map container object.

**Key logic:**
- Allocates 0x30 bytes via operator_new
- Calls FUN_0053c2c0() to initialize
- Calls FUN_0053c360(param_2, param_3, param_4, param_5)
- Returns 0 on success, -1 on failure

**Calls:** FUN_0053c2c0, FUN_0053c360

**Moddability:** hardcoded

## FUN_005401a0 — PASS
